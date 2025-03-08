// Creat ceil Function 
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

float GetFrectionPart(float number)
{
    return number-int(number);
}

int Myceil(float number)
{
    if(abs(GetFrectionPart(number))>0)
    {
    if(number>=0)
    return int(number)+1;
    else
    return int(number);
    }
    else{
    return number;
    }
}
int main()
{
    float Number=ReadNumber("enter Number ?");
    
    cout<<"C++ ceil result : "<<ceil(Number)<<endl;
    cout<<"My ceil result : "<<Myceil(Number);
    
}