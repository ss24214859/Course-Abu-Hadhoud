
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
PrintDigits(ReadPositiveNumber("enter Positive Number? "));
}