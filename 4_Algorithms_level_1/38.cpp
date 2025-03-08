#include <iostream>
#include <string>
using namespace std;

enum enTypeNumber{Prime=1,NotPrime=2};

float ReadPositiveNumber(string massge)
{
    float num=0;
    do
    {
        cout<<massge;
        cin>>num;
    }while(num<1);
    return num;
}

enTypeNumber ChackPrimeOrNotPrime(int number)
{
    int m=number/2;
    for(int counter=2;counter<=m;counter++)
    {
        if(number % counter ==0)
        {return enTypeNumber::NotPrime;}
    }
    return enTypeNumber::Prime;
}

void PrintTypeNumber(int number)
{
    
    switch (ChackPrimeOrNotPrime(number))
    {
    case enTypeNumber::Prime:
        cout<<"this is Prime Number"<<endl;
        break;
    case enTypeNumber::NotPrime:
        cout<<"this is Not Prime Number"<<endl;
        break;
    }
}

int main()
{
PrintTypeNumber(ReadPositiveNumber("Enter Postiv number?"));
}