#include <iostream>
#include "C:\Courses Mohamed Abu Hadoud\MyLiberary\MyLib.h"

using namespace std;

enum enOpType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    MixOp = 5
};
enum enQuestionLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    Mix = 4
};

short HowManyQuestion()
{
    return IO::ReadIntNumberBetween(1, 10, "How Many Question Do You want To Answer? [1]To[10] ? ");
}

enOpType ReadOpType()
{
    return (enOpType)IO::ReadIntNumberBetween(1, 5, "Enter Operation Type : Add:[1],Sub:[2],Mul:[3],Div:[4],Mix:[5] ?\n");
}

enQuestionLevel ReadQuestionLevel()
{
    return (enQuestionLevel)IO::ReadIntNumberBetween(1, 4, "Enter Question Level : Easy:[1],Med:[2],Hard:[3],Mix:[4] ? \n");
}

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOpType OpType;
    enQuestionLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool IsRight = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions = 0;
    enOpType OpType;
    enQuestionLevel QuestionLevel;
    short NumberOfRightAnswer = 0;
    short NumberOfWrongAnswer = 0;
    bool IsPass = false;
};

string GetQuestionLevelName(enQuestionLevel QuestionLevel)
{
    string arrQuestionLevelName[5] = {"Easy", "Med", "Hard", "Mix"};
    return arrQuestionLevelName[QuestionLevel - 1];
}
string GetOpTypeSembol(enOpType OpType)
{
    string arrOpTypeSembol[5] = {"+", "-", "x", "/", "Mix"};
    return arrOpTypeSembol[OpType - 1];
}

enOpType GetOpTypeOfQuestion(enOpType OpType)
{
    if (OpType == enOpType::MixOp)
        return (enOpType)Random::RandomNumber(1, 4);
    else
        return OpType;
}
enQuestionLevel GetQuestionLevelOfQuestion(enQuestionLevel QuestionLevel)
{
    if (QuestionLevel == enQuestionLevel::Mix)
        return (enQuestionLevel)Random::RandomNumber(1, 3);
    else
        return QuestionLevel;
}
int GenerationNumberinLevel(enQuestionLevel Level)
{
    switch (Level)
    {
    case enQuestionLevel::Easy:
        return Random::RandomNumber(1, 10);
        break;
    case enQuestionLevel::Med:
        return Random::RandomNumber(10, 40);
        break;

    default:
        return Random::RandomNumber(40, 100);
        break;
    }
}

int SimpleCalculator(int Number1, int Number2, enOpType OpType)
{
    switch (OpType)
    {
    case enOpType::Add:
        return Number1 + Number2;
        break;
    case enOpType::Sub:
        return Number1 - Number2;
        break;
    case enOpType::Mul:
        return Number1 * Number2;
        break;
    default:
        return Number1 / Number2; // Div
        break;
    }
}

stQuestion GeneratQuestion(enOpType &OpType, enQuestionLevel &QuestionLevel)
{
    stQuestion Question;

    Question.OpType = GetOpTypeOfQuestion(OpType);
    Question.QuestionLevel = GetQuestionLevelOfQuestion(QuestionLevel);
    Question.Number1 = GenerationNumberinLevel(Question.QuestionLevel);
    Question.Number2 = GenerationNumberinLevel(Question.QuestionLevel);
    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpType);

    return Question;
}

void GeneratQuizzQuestions(stQuizz &Quizz, short NumberOfQuestion)
{
    for (int QuestionNumber = 0; QuestionNumber < NumberOfQuestion; QuestionNumber++)
    {
        Quizz.QuestionList[QuestionNumber] = GeneratQuestion(Quizz.OpType, Quizz.QuestionLevel);
    }
}

void setColorScreen(bool Right)
{
    if (Right)
        system("color 2F");
    else
        system("color 4F") && cout << "\a";
}

void PrintQuizzQuestions(stQuizz Quizz, short QuestionNumber)
{
    printf("\n Question [%d/%d]\n\n", QuestionNumber + 1, Quizz.NumberOfQuestions);
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " " << GetOpTypeSembol(Quizz.QuestionList[QuestionNumber].OpType) << endl;
    cout << "__________________";
}

void CorrectTheAnswer(stQuizz &Quizz, short QuestionNumber)
{
    Quizz.QuestionList[QuestionNumber].IsRight = (Quizz.QuestionList[QuestionNumber].CorrectAnswer == Quizz.QuestionList[QuestionNumber].PlayerAnswer);

    if (Quizz.QuestionList[QuestionNumber].IsRight)
    {
        cout << "Right Answer :-)";
        Quizz.NumberOfRightAnswer++;
    }
    else
    {
        cout << "Wrong Answer :-(\n";
        cout << "The Right Answer is : " << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
        Quizz.NumberOfWrongAnswer++;
    }

    setColorScreen(Quizz.QuestionList[QuestionNumber].IsRight);
}

void AskAndCorrectAnswers(stQuizz &Quizz, short NumberOfQuestion)
{
    for (short QuestionNumber = 0; QuestionNumber < NumberOfQuestion; QuestionNumber++)
    {
        PrintQuizzQuestions(Quizz, QuestionNumber);
        Quizz.QuestionList[QuestionNumber].PlayerAnswer = IO::ReadIntNumber("");
        CorrectTheAnswer(Quizz, QuestionNumber);
    }
    Quizz.IsPass = Quizz.NumberOfRightAnswer >= Quizz.NumberOfWrongAnswer;
}

string PassOrFail(bool Right)
{
    if (Right)
        return "Pass";
    else
        return "Fail";
}

void PrintFinalQuizzResult(stQuizz Quizz)
{
    cout << "\n_____________________________________________\n\n";
    cout << "        Final Result is :  " << PassOrFail(Quizz.IsPass) << endl;
    cout << "\n_____________________________________________\n\n";
    printf("Number Of Questions      : %3d\n", Quizz.NumberOfQuestions);
    cout << "Question Level           :  " << GetQuestionLevelName(Quizz.QuestionLevel) << endl;
    cout << "Operation Type           :  (" << GetOpTypeSembol(Quizz.OpType) << ")" << endl;
    printf("Number Of Right Question : %3d\n", Quizz.NumberOfRightAnswer);
    printf("Number Of Wrong Question : %3d\n", Quizz.NumberOfWrongAnswer);
    cout << "\n______________________________________________\n\n";
}

void PlayMathGame(stQuizz Quizz)
{
    Quizz.NumberOfQuestions = HowManyQuestion();
    Quizz.OpType = ReadOpType();
    Quizz.QuestionLevel = ReadQuestionLevel();

    GeneratQuizzQuestions(Quizz, Quizz.NumberOfQuestions);
    AskAndCorrectAnswers(Quizz, Quizz.NumberOfQuestions);
    PrintFinalQuizzResult(Quizz);

    setColorScreen(Quizz.IsPass);
}

void Start()
{
    stQuizz Quizz;
    do
    {
        PlayMathGame(Quizz);
    } while (IO::ReadYesOrNo("Do you want play again ?"));
}

int main()
{
    srand((unsigned)time(NULL));
    Start();
}