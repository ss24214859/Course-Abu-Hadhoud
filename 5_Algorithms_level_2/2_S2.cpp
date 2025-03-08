#include <iostream>
#include <string>
using namespace std;

enum enPrimeOrNot{Prime=1,NotPrime=2};
int ReadPositiveNumber(string massge)
{
    int num;
    do
    {
    cout<<massge;
    cin>>num;
    } while (num<0);

    return num;
}
enPrimeOrNot ChackPrimeNumber(int number)
{
    for(int i=2;i<=number/2;i++)  //if (i>=Number/2) loop will stop than Number will be Prime
    {
        if(number%i==0)           
        {
            return enPrimeOrNot::NotPrime;
        }
        

    }
       return enPrimeOrNot::Prime;
}
void PrintPrimeNumberFrom1ToN(int N)
{
    for(int i=1;i<=N;i++)
    {
    if(ChackPrimeNumber(i)==enPrimeOrNot::Prime)
    {
        cout<<i<<endl;
    }

    }
}

int main()
{
    int num=ReadPositiveNumber("eneter Positive Number?");
    PrintPrimeNumberFrom1ToN(num);

}
    