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

void PrintInvertedLattersPattern(int number)
{
    
    cout<<endl;
    for(int j=64; j<=number+64;j++)
    {
        for(int i=j-64;i>=1;i--)
        {
            cout<<char(j);
        }
        cout<<endl;
    }
}


int main()
{
PrintInvertedLattersPattern(ReadPositiveNumber("enter Positive Number? "));
}