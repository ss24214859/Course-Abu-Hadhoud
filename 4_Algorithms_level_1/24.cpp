#include <iostream>
using namespace std;

int ReadAge()                 
{

    int num;
    cout<<"Please enter Age ?";
    cin>>num;   
    return num;
}

bool ValidateNumberInRang(int Number,int From,int to)
{
    return (Number>=From && Number<=to);
}

void printResult(int Age)
{
    if(ValidateNumberInRang(Age,18,45))
    {
        cout<<Age<<" is avalide Age.";
    }
    else
    {
        cout<<Age<<" is not avalide Age.";
    }
}

int main()
{
    printResult(ReadAge());
}
