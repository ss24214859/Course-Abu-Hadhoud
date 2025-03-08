#include<iostream>
#include<string>
#include<cmath>
using namespace std;



void ReadNumbers(float &A,float &B,float &C)
{
    
    cout<<"enter A ?";
    cin>>A;
    cout<<"enter B ?";
    cin>>B;
    cout<<"enter C ?";
    cin>>C;    
}


float CircaleAreaByArbitraryTriangle(float a,float b,float c)
{
const float pi=3.14159265359;
float p;
p=(a+b+c)/2;
float T;
T=(a*b*c)/( 4 * sqrt(p * (p-a) * (p-b) * (p-c) ) );

float Area= pi* pow(T,2);
return (float) Area;
}

void printResult(float result)
{
    cout<<"\n Result ="<<result;
}
int main()
{
float a,b,c;
ReadNumbers(a,b,c);
printResult(CircaleAreaByArbitraryTriangle(a,b,c));
}