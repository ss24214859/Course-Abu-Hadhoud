#include <iostream>
#include <string>
using namespace std;

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

int ReverseNumber(int Number1)
{
    int Number2=0;
    int Reminder=0;
    while(Number1>0)
    {
        Reminder=Number1%10;
        Number1/=10;
        Number2=(Number2*10)+Reminder;

    }
}

bool ChackIfNumberIsPalndrom(int Number)
{
    return ReverseNumber(Number)==Number;
}
            
void PrintResult(int Number)
{
    if(ChackIfNumberIsPalndrom(Number))
        cout<<endl<<"Yes , it is a Palndrom Number"<<endl;
    else
        cout<<endl<<"No , it is Not a Palndrom Number"<<endl;
    
}

int main()
{
PrintResult(ReadPositiveNumber("enter Positive Number? "));
}