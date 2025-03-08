// Creat sqrt Function 
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

float power(float number,int power)
{
    /*int result=1;
    for(int i=0;i<power;i++)

    result=result*number;

    return result;*/
    

    double n =number; // We want 5^4
    int e = power;
    double T = 1;

    for(int k=1; k<=abs(e); k++)
	T = T*n;
    T = (e<0) ? 1/T : T;

    return T ;

}

int Mysqrt(float number)
{
    return pow(number,0.5);
}
int main()
{
    float Number=ReadNumber("enter Number ?");
    
    cout<<"C++ sqrt result : "<<sqrt(Number)<<endl;
    cout<<"My sqrt result : "<<Mysqrt(Number);
    // bool clearScreen;
    // cout<<"do you want to Clear Screen? yes:[1],no:[0]?";
    // cin>>clearScreen;

    // if(clearScreen)
    // system ("CLS");
    

    
}