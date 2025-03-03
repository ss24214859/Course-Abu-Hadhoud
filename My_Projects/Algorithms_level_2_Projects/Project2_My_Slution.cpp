#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum enQuesLevel{Easy=1,Med=2,Hard=3,Mix=4};
enum enOpType{Add=1,Sub=2,Mul=3,Div=4,mix=5};

struct stQuesInFo
{
    
    short element1;
    short element2;
    int UserAnswer;
    int RightAnswer;
    enOpType OpType;
    enQuesLevel Queslevel;
    bool ChackuserAnswer;
};
struct stFinalResultInFo
{
    short NumberOfQuestions;
    string QueslevelName;
    string OpTypeName;
    short NumberOfRightAnswers;
    short NumberOfWrongAnswers;
    bool ChackFinalQuesTionsResult;
    string FinalQuesTionsResult;
};

string QuesLevelName(enQuesLevel QuesLevel)
{
    string arr[4]={"Easy","Med","Hard","Mix"};
    return arr[QuesLevel-1];
}
string OpTypeName(enOpType OpType)
{
    string arr[5]={"Add","Sub","Mul","Div","Mix"};
    return arr[OpType-1];
}
char OpTypeSymbol(enOpType OpType)
{
    char arr[5]={'+','-','x','/'};
    return arr[OpType-1];
}

bool ReadYesOrNo(string massage)
{
    char c='h';
    while(c!='y'||c!='n'||c!='Y' || c!='N')
    {
    cout<<massage;
    cin>>c;

    if(c=='y'||c=='Y')
    return true;
    else if(c=='n'||c=='N')
    {
    return false;
    }
    }
    return 0;
}

short ReadNumberInRang(short from,short to,string massge)
{
    short num=0;
    do
    {
        cout<<massge;
        cin>>num;
    }while(from>num||num>to);
    return num;
}
short RandomNumber(short From,short To)
{
    short Random=rand()%(To-From+1)+From;
    return Random;

}

enQuesLevel ReadQuesLevel()
{
    short QuesLevel=ReadNumberInRang(1,4,"Enter Question Level : Easy:[1],Med:[2],Hard:[3],Mix:[4] ? \n");
    return enQuesLevel (QuesLevel);
}
enQuesLevel GetQuesLevel(enQuesLevel QuesLevel)
{
    if (QuesLevel==enQuesLevel::Mix)
        return (enQuesLevel)RandomNumber(1,3);
    else
    return QuesLevel;
}


enOpType ReadOpType()
{
    enOpType OpType = enOpType(ReadNumberInRang(1,5,"Enter Operation Type : Add:[1],Sub:[2],Mul:[3],Div:[4],Mix:[5] ?\n"));
    return OpType;
}
enOpType GetOpType(enOpType OpType)
{
    if (OpType==enOpType::mix)
        return (enOpType)RandomNumber(1,4);
    else
    return OpType;
}

short GetQuesElement(enQuesLevel QuesLevel)
{
    switch (QuesLevel)
    {
        case enQuesLevel::Easy:
        return RandomNumber(1,10);
        break;

        case enQuesLevel::Med:
        return RandomNumber(10,30);
        break;

        case enQuesLevel::Hard:
        return RandomNumber(30,100);
        break;
    
    }
}

int ReadUserAnswer(stQuesInFo QuesInFo)
{
    cout<<endl<<QuesInFo.element1<<endl;
    cout<<QuesInFo.element2<<"  "<<OpTypeSymbol(QuesInFo.OpType)<<endl;
    cout<<"________________\n";
    cin>>QuesInFo.UserAnswer;
    return QuesInFo.UserAnswer;
} 
int GetRightAnswer(stQuesInFo QuesInFo)
{
    switch (QuesInFo.OpType)
    {
    case enOpType::Add:
        return QuesInFo.element1+QuesInFo.element2;
        break;
    case enOpType::Sub:
        return QuesInFo.element1-QuesInFo.element2;
        break;
    case enOpType::Mul:
        return QuesInFo.element1*QuesInFo.element2;
        break;
    case enOpType::Div:
        return QuesInFo.element1/QuesInFo.element2;
        break;
    }
}
bool ChackUserAnswer(int UserAnswer,int RightAnswer)
{
    return UserAnswer==RightAnswer;
}
void PrintResultOfQues(stQuesInFo QuesInFo)
{
    if(ChackUserAnswer( QuesInFo.UserAnswer,QuesInFo.RightAnswer))
    cout<<"Right Answer :-)"<<endl;
    else
    cout<<"Wrong Answer :-( \nThe Right Answer is : "<< QuesInFo.RightAnswer<<endl;
}

bool ChackFinalQuesTionResult(short NumOfRightAnswer,short NumOfWrongAnswer)
{
    return NumOfRightAnswer>=NumOfWrongAnswer;
}
string FinalQuesTionsResult(bool ChackFinalQuesTionsResult)
{

   if(ChackFinalQuesTionsResult)
   return "Pass :-)";
   else
   return "Fail :-(";
}

void setColorScreen(bool Right)
{
    if(Right)
    system("color 2F");
    else
    system("color 4F")&& cout<<"\a";
    
}

stFinalResultInFo FillFinalResultInFo(enQuesLevel QuesLevel,enOpType OpType,short NumOfRightAnswer,short NumOfWrongAnswer)
{
    stFinalResultInFo FinalResultInFo;
    FinalResultInFo.ChackFinalQuesTionsResult=ChackFinalQuesTionResult(NumOfRightAnswer,NumOfWrongAnswer);
    FinalResultInFo.FinalQuesTionsResult=FinalQuesTionsResult(FinalResultInFo.ChackFinalQuesTionsResult);
    FinalResultInFo.NumberOfQuestions=NumOfRightAnswer+NumOfWrongAnswer;
    FinalResultInFo.NumberOfRightAnswers=NumOfRightAnswer;
    FinalResultInFo.NumberOfWrongAnswers=NumOfWrongAnswer;
    FinalResultInFo.OpTypeName=OpTypeName(OpType);
    FinalResultInFo.QueslevelName=QuesLevelName(QuesLevel);

    return FinalResultInFo;

}

void PrintFinalResultInFo(stFinalResultInFo FinalResultInFo)
{
    cout<<"____________________________________________\n\n";
    cout<<"     Final Result is : "<<FinalResultInFo.FinalQuesTionsResult<<endl;
    cout<<"\n____________________________________________\n\n";
    cout<<"Number Of Questions : "<<FinalResultInFo.NumberOfQuestions<<endl;
    cout<<"Questions Level     : "<<FinalResultInFo.QueslevelName<<endl;
    cout<<"Operation Type      : "<<FinalResultInFo.OpTypeName<<endl;
    cout<<"Number Of Right Answer : "<<FinalResultInFo.NumberOfRightAnswers<<endl;
    cout<<"Number Of Wrong Answer : "<<FinalResultInFo.NumberOfWrongAnswers<<endl;
    cout<<"\n____________________________________________\n";
    setColorScreen(FinalResultInFo.ChackFinalQuesTionsResult);
}

stFinalResultInFo RunExam(short HowManyQuesTions,enQuesLevel QuesLevel ,enOpType OpType)
{
    stQuesInFo QuesInFo;
    short NumOfRightAnswer=0;
    short NumOfWrongAnswer=0;

    for(short QuesNumber=1;QuesNumber<=HowManyQuesTions;QuesNumber++)
    {
        QuesInFo.OpType=GetOpType(OpType);
        QuesInFo.Queslevel=GetQuesLevel(QuesLevel);
        QuesInFo.element1=GetQuesElement(QuesInFo.Queslevel);
        QuesInFo.element2=GetQuesElement(QuesInFo.Queslevel);
        QuesInFo.RightAnswer=GetRightAnswer(QuesInFo);

        cout<<"\n\nQuestion ["<<QuesNumber<<"/"<<HowManyQuesTions<<"] "<<endl;
        QuesInFo.UserAnswer=ReadUserAnswer(QuesInFo);
        
        PrintResultOfQues(QuesInFo);
        setColorScreen(ChackUserAnswer( QuesInFo.UserAnswer,QuesInFo.RightAnswer));

        if(ChackUserAnswer( QuesInFo.UserAnswer,QuesInFo.RightAnswer))
        NumOfRightAnswer++;
        else
        NumOfWrongAnswer++;

    }

    return FillFinalResultInFo(QuesLevel,OpType,NumOfRightAnswer,NumOfWrongAnswer);

}

void ResetScreen()
{
    system("CLS");
    system("Color 0F");
}

void StartExam()
{
    stFinalResultInFo FinalResultInFo;
    do
    {
    ResetScreen();
    int HowManyQues=ReadNumberInRang(1,10,"How Many Question Do You want To Answer? [1]To[10]?");
    FinalResultInFo=RunExam(HowManyQues,ReadQuesLevel(),ReadOpType());
    PrintFinalResultInFo(FinalResultInFo);
     
    } while(ReadYesOrNo("Do you Want Play Again ? "));
}

int main()
{
    srand((unsigned)time(NULL));
    StartExam();
}