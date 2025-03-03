#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void PrintFibonacciSeriesInSize(int Size,int prev1=0,int prev2=1)
{
    
    int Fibonacci=0;
    
    if(Size>0)
    {
    Fibonacci=prev1+prev2;
    prev2=prev1;
    prev1=Fibonacci;
    cout<<setw(4)<<Fibonacci<<"  ";
    
    PrintFibonacciSeriesInSize(Size-1,prev1,prev2);
    }
    
}
int main()
{
    cout << "Fibonacci Series :";
    PrintFibonacciSeriesInSize(10);
    cout<< endl;
    return 0;
}