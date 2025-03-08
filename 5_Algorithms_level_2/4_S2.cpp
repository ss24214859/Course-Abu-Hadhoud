
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
 
bool isPerfectNumber(int Number)
{
    int sum=0;
    for(int T=1;T<=Number/2;T++)
    {
        if(Number%T==0)
            sum=sum+T;
    }
    return sum==Number;
    
}

void PrintPerfectNumberFrom1ToN(int N)
{
    for(int i=1;i<=N;i++)
    {
        if(isPerfectNumber(i))
            cout<<i<<endl;
    }        
}

int main()
{
    PrintPerfectNumberFrom1ToN(ReadPositiveNumber("enter Positive Number? "));
}