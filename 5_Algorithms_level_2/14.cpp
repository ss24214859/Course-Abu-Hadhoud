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


void PrintInvertedPattern(int number)
{
    cout<<endl;
    for(int j=number; j>=1;j--)
    {
        for(int i=j;i>=1;i--)
        {
            cout<<char(j+64);
        }
        cout<<endl;
    }
}


int main()
{
PrintInvertedPattern(ReadPositiveNumber("enter Positive Number? "));
}