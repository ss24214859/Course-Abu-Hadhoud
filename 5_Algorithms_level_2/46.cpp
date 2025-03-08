// Creat abs Function 
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadNumber(string Massage)                 
{
    int num;
    cout<<Massage;
    cin>>num;   
    return num;
}
int MYabs(int number)
{
    if(number<0)
    return -1*number;
    else
    return number;
}
int main()
{
    int Number=ReadNumber("enter Number ?");

    cout<<"My abs result : "<<MYabs(Number)<<endl;
    cout<<"C++ abs result : "<<abs(Number);
    
}