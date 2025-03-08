#include <iostream>
using namespace std;

enum enNumberType{ood=1,Even=2};
int ReadNumber()                 //Problem 3
{
    int num;
    cout<<"Please enter Number?";
    cin>>num;
    return num;
}

enNumberType ChackNumberType(int num)           //Problem 3
{
    int Result = num % 2;
    if(Result == 0)
    {
        return enNumberType::Even;
    } else
    {
        return enNumberType::ood;
    }
}

void PrintNumberType(enNumberType NumberType)         //Problem 3
{
    if(NumberType == enNumberType::Even)
    {
        cout<<"\nThis Number is Even "<<endl;
    }
    else
    {
        cout<<"\nThis Number is ood "<<endl;
    }
}

int main()
{
    PrintNumberType(ChackNumberType(ReadNumber()));                    //Problem 3
}