// Creat floor Function 
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

float ReadNumber(string Massage)                 
{
    float num;
    cout<<Massage;
    cin>>num;   
    return num;
}

int MyFloor(float number)
{
    if(number>=0)
    return int(number);
    else
    return int(number)-1;
}
int main()
{
    float Number=ReadNumber("enter Number ?");
    
    cout<<"C++ floor result : "<<floor(Number)<<endl;
    cout<<"My floor result : "<<MyFloor(Number);
    
}