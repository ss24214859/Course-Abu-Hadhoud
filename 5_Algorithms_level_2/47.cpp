// Creat round Function 
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
int MYround(float number)
{
    int IntPart;
    IntPart = int(number);
    float FractionPart=GetFrectionPart(number);

    if(abs(FractionPart)>=.5)
    {
        if(number<0)
        return--IntPart;
        else
        return++IntPart;
    }
    else 
    {
    return IntPart;
    }
}
int main()
{
    float Number=ReadNumber("enter Number ?");
    
    cout<<"C++ round result : "<<round(Number)<<endl;
    cout<<"My round result : "<<MYround(Number);
    
}