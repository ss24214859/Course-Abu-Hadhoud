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

/*int RepitNumber(int Number1)
{
    int Number2=0;
    int Reminder=0;
    for(int i=1;i<=Number1;i++)
    {
        Reminder=Number1%10;
        Number2=(Number2*10)+Reminder;
    }
    return Number2;
}
            
void PrintInvertedPattern(int number)
{
    for(int i=number; i>=1;i--)
    {
        cout<<RepitNumber(i)<<endl;
    }
}*/

void PrintInvertedPattern(int number)
{
    cout<<endl;
    for(int j=number; j>=1;j--)
    {
        for(int i=j;i>=1;i--)
        {
            cout<<j;
        }
        cout<<endl;
    }
}


int main()
{
PrintInvertedPattern(ReadPositiveNumber("enter Positive Number? "));
}