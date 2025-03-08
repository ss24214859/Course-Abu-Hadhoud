#include <iostream>
using namespace std;

int ReadNumber()                 
{
    int num;
    cout<<"To Print From 1 To N Enter \'N\' ?";
    cin>>num;   
    return num;
}

void PrintFrom1ToNUsingForLoop(int N)
{   
    for(int i=1 ; i<= N;i++)
    {
        cout<<i<<endl;
    }
}

void PrintFrom1ToNUsingWhileLoop(int N)
{   int i=1;
    while( i<= N)
    {
        cout<<i<<endl;
        i++;
    }
}

void PrintFrom1ToNUsingDoWhileLoop(int N)
{   int i=1;
    do
    {
        cout<<i<<endl;
        i++;
    }while( i<= N);
}

int main()
{
    int N=ReadNumber();
    PrintFrom1ToNUsingForLoop(N);
    PrintFrom1ToNUsingWhileLoop(N);
    PrintFrom1ToNUsingDoWhileLoop(N);
}