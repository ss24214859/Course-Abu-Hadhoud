#include <iostream>
#include <cstdlib>
using namespace std;

enum enTypeChar{SmallLatters=1,CapetalLatters=2,SpecialCharacter=3,Digit=4};

int ReadPositiveNumber(string massge)
{
    int num=0;
    do
    {
        cout<<massge;
        cin>>num;
    }while(num<1);
    return num;
}

int RandomNumber(int From,int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char GetRandomCharacter(enTypeChar TypeChar)
{
    switch (TypeChar)
    {
        case enTypeChar::SmallLatters:
            return char(RandomNumber(97,122));
        case enTypeChar::CapetalLatters:
            return char(RandomNumber(65,90));
        case enTypeChar::SpecialCharacter:
            return char(RandomNumber(33,47));
        case enTypeChar::Digit:
            return char(RandomNumber(48,57));
    }
    return 0;
}

string GenerateWord(enTypeChar TypeChar,int length)
{
    string word="";
    for(int i=1;i<=length;i++)
    { 
        word+=GetRandomCharacter(TypeChar);
    }
    return word;
}
string GenerateKey()
{
    string Key="";
    for(int i=1;i<=4;i++)
    {

        Key+=GenerateWord(enTypeChar::CapetalLatters,4);


        if(i<=3)
        Key+="-";
    }
    return Key;
}
void Generatekeys(int NumberOfKeys)
{
for(int i=1; i<=NumberOfKeys;i++)
{
     cout<<"Key["<<i<<"] : "<<GenerateKey()<<endl;
}
}

int main()
{
    srand((unsigned)time(NULL));
    int NumberOfKeys=ReadPositiveNumber("enter Number Of Keys ? ");
    Generatekeys(NumberOfKeys);    
}