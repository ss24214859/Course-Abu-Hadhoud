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

bool ChackMarkPass(int num)
{
    return (num>=50);
}

void PrintResult(int mark)
{
    if(ChackMarkPass(mark))
    cout<<"you are --Pass--";
    else
    cout<<"you are --Fail--";
}

int main()
{
    PrintResult(ReadNumber());
}