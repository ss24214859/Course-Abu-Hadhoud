
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

int countDigitFrequency(int Number,short Digit )
{
    int Reminder=0;
    int Frequency=0;
    do
    {
        Reminder=Number%10;
        Number/=10;
        if(Reminder==Digit)
            Frequency++;
    }while(Number>0);
    
    return Frequency;
}

void PrintDigitsFrequencyInNumber(int Number)
{
    for(int i=0;i<10;i++)
    {
        int DigitFrequency=0;
        DigitFrequency=countDigitFrequency(Number,i);
        if(DigitFrequency>=1)
            cout <<"\nDigit " <<i <<" Frequency is " <<DigitFrequency <<" Time(s).\n";
    }

}

int main()
{

    int Number=ReadPositiveNumber("enter The Main Number? ");
    PrintDigitsFrequencyInNumber(Number);

}