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
    int c=4;
    string Key="";
    for(int i=1;i<=c;i++)
    {

        Key+=GenerateWord(enTypeChar::CapetalLatters,c);


        if(i<=c-1)
        Key+="-";
    }
    return Key;
}

void fillArray(string arr[100] ,int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
        
         arr[i]=GenerateKey();
    }
}

void PrintArray(string arr[100],int Quantity)
{
    for(int i=0;i<Quantity;i++)
    {
        cout<<"Array["<<i+1<<"] : "<<arr[i]<<endl;
    }
}


int main()
{
    string Array[100];
    int Quantity = ReadPositiveNumber("enter the elements of Array ? ");
    fillArray(Array,Quantity);
    PrintArray(Array,Quantity);

}