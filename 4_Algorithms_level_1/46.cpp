#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void PrintNumbersInRang(int from,int to)
{
    for(int i=from;i<=to;i++)
    {
        cout<<i<<endl;
    };
}

void PrintcharInRang(int from,int to)
{
    for(int i=from; i<=to ;i++)
    {
        cout<<char(i)<<endl;
    };
}

int main()
{
    PrintcharInRang(65,90);

}