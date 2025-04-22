#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

string ReadString(string Massage)
{
    string Input = "";
    cout << Massage;
    getline(cin, Input);
    return Input;
}

char ReadChar(string Massage)
{
    char Input;
    cout << Massage;
    cin >> Input;
    return Input;
}

void PrintFirstLetterOfEachWordInString(string Str)
{
    cout << "Characters of Word : " << endl;
    bool InWord = false;

    for (int i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ' && !InWord)
        {
            cout << Str[i] << endl;
            InWord = true;
        }

        if (Str[i] == ' ')
            InWord = false;
    }
}
/*                   Mytoupper()
.
bool IsUppercase(char ch)
{
    return int(ch)>=65&&int(ch)<=90;
}

char Mytoupper(char ch)
{
    if(!IsUppercase(ch))
        return char(int(ch)-32);
    else
        return ch;
}*/

string UppercaseFirstLetterOfEachWordInString(string S1)
{
    bool IsFirstLetter = true;

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && IsFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }
        IsFirstLetter = (S1[i] == ' ') ? true : false;
    }
    return S1;
}

string LowerAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

string UpperAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

char InvertCase(char ch)
{

    return islower(ch) ? toupper(ch) : tolower(ch);
}

string InvertLetterCaseInString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertCase(S1[i]);
    }
    return S1;
}

int SmallLettersCount(string S1)
{
    int small = 0;
    for (int i = 0; i < S1.length(); i++)
        small = islower(S1[i]) ? small + 1 : small;
    return small;
}

int CapitalLettersCount(string S1)
{
    int Capital = 0;
    for (int i = 0; i < S1.length(); i++)
        Capital = isupper(S1[i]) ? Capital + 1 : Capital;
    return Capital;
}

int CharacterCountInString(string S1, char ch, bool MatchCase = true)
{
    int counter = 0;
    if (MatchCase)
    {
        for (int i = 0; i < S1.length(); i++)
            counter = (S1[i] == ch) ? counter + 1 : counter;
        return counter;
    }
    else
    {
        for (int i = 0; i < S1.length(); i++)
            counter = (tolower(S1[i]) == tolower(ch)) ? counter + 1 : counter;
        return counter;
    }
}

bool isvowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u');
}

int VowelCount(string S1)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
        counter = (isvowel(S1[i])) ? counter + 1 : counter;

    return counter;
}

void PrintVowelLetters(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (isvowel(S1[i]))
            cout << S1[i] << "\t";
    }
}

void PrintVector(vector<string> Vec)
{
    for (string &str : Vec)
    {
        cout << str << endl;
    }
}

string Trimleft(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
            return S1.substr(i, S1.length());
    }
    return "";
}

string TrimRight(string S1)
{
    for (int i = S1.length() - 1; i > 0; i--)
    {
        if (S1[i] != ' ')
            return S1.substr(0, i);
    }
    return "";
}

string Trim(string S1)
{
    return TrimRight(Trimleft(S1));
}
string ReverseString(string S1)
{
    string Reverse = "";
    for (int i = 0; i < S1.length(); i++)
    {
        Reverse.push_back(S1[S1.length() - 1 - i]);
    }
    return Reverse;
}

string JoinStringWithReverseWords(vector<string> vString, string Delimiter)
{
    string String = "";
    for (int i = vString.size() - 1; i >= 0; i--)
    {
        String += vString[i] + Delimiter;
    }
    return String.substr(0, String.length() - Delimiter.length());
}

string JoinStringWithArr(string ArrStr[], short length, string Delimiter)
{
    string String = "";
    for (int i = 0; i < length; i++)
    {
        String = String + ArrStr[length - 1 - i] + Delimiter;
    }
    return String.substr(0, String.length() - Delimiter.length());
}

string JoinString(vector<string> vString, string Delimiter)
{
    string String = "";
    for (string &Str : vString)
    {
        String += Str + Delimiter;
    }

    return String.substr(0, String.length() - Delimiter.length());
}

vector<string> SplitStringInVector(string S1, string delimiter)
{
    vector<string> vStrWords;
    short pos = 0;
    string Word;

    while ((pos = S1.find(delimiter)) != std::string::npos)
    {
        Word = S1.substr(0, pos);

        if (Word != "")
            vStrWords.push_back(Word);

        S1.erase(0, pos + delimiter.length());
    }
    if (S1 != "")
        vStrWords.push_back(S1);

    return vStrWords;
}

string ReverseWordsInString(string S1)
{
    string deli = " ";
    vector<string> vWords = SplitStringInVector(S1, deli);
    string S2 = "";
    vector<string>::iterator iter = vWords.end();
    while (iter != vWords.begin())
    {
        iter--;
        S2 += *iter + deli;
    }
    return S2.substr(0, S2.length() - deli.length());
}

string ReplaceWordInString(string S1, string OldStr, string StrReplaceTo, string deli = " ", bool IsMatchCase = true)
{

    vector<string> vSWords = SplitStringInVector(S1, deli);
    string TempS1 = S1;
    string TempOldStr = OldStr;
    if (IsMatchCase)
    {
        string TempS1 = LowerAllString(S1);
        TempOldStr = LowerAllString(OldStr);
    }

    short pos = 0;

    while ((pos = TempS1.find(OldStr)) != std::string::npos)
    {
        S1.replace(pos, OldStr.length(), StrReplaceTo);
    }

    return S1;
}

string ReplaceWordInStringWhithVector(string S1, string OldStr, string StrReplaceTo, bool IsMatchCase = true)
{
    string deli = " ";
    vector<string> vSWords = SplitStringInVector(S1, deli);
    for (string &S : vSWords)
    {
        if (IsMatchCase)
        {
            if (S == OldStr)
                S = StrReplaceTo;
        }
        else
        {
            if (LowerAllString(S) == LowerAllString(OldStr))
                S = StrReplaceTo;
        }
    }
    return JoinString(vSWords, deli);
}

int main()
{
    string S1 = "hi Are you Mohamed Shaaban? yes,I'm Mohamed_Shaaban. mohamed"; // ReadString("enter String ?");
    //  cout<<"String After Reverse Words."<<endl;
    //  cout<<"Revers Words :"<<ReverseWords(S1)<<endl;
    cout << "Is Matchcase:" << ReplaceWordInString(S1, "Mohamed", "Reda") << endl;
    cout << "Is don't Matchcase:" << ReplaceWordInString(S1, "Mohamed", "Reda", 0) << endl;

    cout << "\nwith vector\nIs Matchcase:" << ReplaceWordInStringWhithVector(S1, "Mohamed", "Reda") << endl;
    cout << "Is don't Matchcase:" << ReplaceWordInStringWhithVector(S1, "Mohamed", "Reda", 0) << endl;

    return 0;
}