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
            
void PrintDigits(int number)
{
    int Reminder=0;
    do
    {
        Reminder=number%10;
        number=number/10;
        cout<<Reminder<<endl;    
    }while(number>=1);
}

int main()
{
PrintDigits(ReverseNumber(ReadPositiveNumber("enter Positive Number? ")));
}