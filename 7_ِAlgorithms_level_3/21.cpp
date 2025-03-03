#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void PrintFibonacciSeriesInSize(int Size)
{
    short prev1=0,prev2=1;
    int Fibonacci=0;
    cout<<setw(4)<<prev2<<"  ";
    for(short i=1;i<Size;i++)
    {
        
        Fibonacci=prev1+prev2;
        cout<<setw(4)<<Fibonacci<<"  ";
        
        prev1=prev2;
        prev2=Fibonacci;
    }
}
int main()
{
    cout << "Fibonacci Series :";
    PrintFibonacciSeriesInSize(10);
    cout<< endl;
    return 0;
}                