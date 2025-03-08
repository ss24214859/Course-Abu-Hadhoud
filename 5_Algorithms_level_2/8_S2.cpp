
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
            
int DigitFrequencyInNumber(int Number,int Digit )
{
    int Reminder=0;
    int Frequency=0;
    do
    {
        Reminder=Number%10;
        Number=Number/10;
        if(Reminder==Digit)
            Frequency++;
    }while(Number!=0);
    return Frequency;
}

int main()
{

int Number=ReadPositiveNumber("enter The Main Number? ");
int Digit=ReadPositiveNumber("enter The one Digit To Chack? ");

cout<<"\nDigit "<<Digit<<" Frecquency is "
<<DigitFrequencyInNumber(Number,Digit)<<" Time(s).\n";
}