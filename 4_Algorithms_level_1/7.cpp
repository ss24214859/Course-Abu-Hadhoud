#include <iostream>
#include <string>
using namespace std;

float ReadNumber()                 
{
    int num;
    cout<<"Please enter Number?";
    cin>>num;
    return num;
}

float CalculatHalfNumber(int num)
{
    
    return (float) num/2;
}

void PrintResult(int num)
{
    string Result="the Half Number of "+ to_string(num) + " is "+ to_string(CalculatHalfNumber(num));
    cout<<endl<<Result<<endl;
}

int main()
{
    PrintResult(ReadNumber());
}