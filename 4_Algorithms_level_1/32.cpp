#include<iostream>
#include<string>
#include<cmath>
using namespace std;



float ReadNumber(string massage)
{
    float number;
    cout<<massage<<endl;
    cin>>number;
    return number;
}


float Pow(float number,float power)
{
float pow=1;

 for (int i=power;i >=1;i--)
 {
 pow=pow*number;
 }
 return pow;
}

void printresult(float number)
{
    cout<<number<<endl;
    
}
int main()
{

printresult(pow(ReadNumber("Enter Number?"),ReadNumber("Enter Power of The Number?")));

}