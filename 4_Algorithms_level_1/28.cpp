#include <iostream>
using namespace std;
enum enOodOrEven{ood=1,even=2};
int ReadNumber()                 
{
    int num;
    cout<<"To Print From 1 To N Enter \'N\' ?";
    cin>>num;   
    return num;
}

enOodOrEven ChackOodOrEven(int Number)
{
    if(Number%2==0)
    {
        return enOodOrEven::even;
    }
    else
    {
        return enOodOrEven::ood;
    }
}

int SumOODNumbersFrom1ToNUsingForLoop(int N)
{   
    int sum=0;
    for(int counter=1 ; counter<= N;counter++)
    {
        if(ChackOodOrEven(counter)==enOodOrEven::ood)
        {
            sum=sum+counter;
        }
    }

    return sum;
}

int SumOODNumbersFrom1ToNUsingWhileLoop(int N)
{   int counter=1;
    int sum=0;
    while( counter<= N)
    {
        if(ChackOodOrEven(counter)==enOodOrEven::ood)
        {
            sum=sum+counter;
        }
        counter++;
    }

    return sum;
}

int SumOODNumbersFrom1ToNUsingDoWhileLoop(int N)
{   int counter=1;
    int sum=0;
    do
    {
        if(ChackOodOrEven(counter)==enOodOrEven::ood)
        {
            sum=sum+counter;
        }
        counter++;
    }while( counter<= N);

    return sum;
}

void PrintResult(int result)
{
    cout<<"\nResult = "<<result<<endl;

}
int main()
{
    int N=ReadNumber();
    PrintResult(SumOODNumbersFrom1ToNUsingForLoop(N));
    PrintResult(SumOODNumbersFrom1ToNUsingWhileLoop(N));
    PrintResult(SumOODNumbersFrom1ToNUsingDoWhileLoop(N));
}