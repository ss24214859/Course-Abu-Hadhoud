#include <iostream>
using namespace std;

int ReadAge()                 
{

    int num;
    cout<<"enter your Age ?";
    cin>>num;   
    return num;
}

bool ValidateNumberInRang(int Number,int From,int to)
{
    return (Number>=From && Number<=to);
}


int ReadAgeUntilAgeBetween(int From ,int To)
{
    int Age=0;
    do
    {
    Age =ReadAge();

    if(!ValidateNumberInRang(Age,From,To))  
    cout<<Age<<" is  not avalide Please Try Againe.\n"<<endl;
           
    } while(!ValidateNumberInRang(Age,From,To));

    return Age;
}


void printResult(int Age)
{
cout<<Age<<" is  avalide Age";
}
int main()
{
    printResult(ReadAgeUntilAgeBetween(18,45));
}
