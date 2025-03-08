#include<iostream>
using namespace std;

enum enOperatorType{Add='+',Subtract='-',Multiply='*',Divide='/'};

enOperatorType ReadOperatorType()
{
char opt='+';
cout<<"enter the operator Type from(/,*,-,+)";
cin >>opt;
return enOperatorType(opt);
}

float ReadNumber(string Massage)
{
float num=0;
cout<<Massage;
cin>>num;
return num;
}

float Calculat(float number1,float number2,enOperatorType OperatorType)
{
switch (OperatorType)
{
case enOperatorType::Add:
return number1+number2;

case enOperatorType::Subtract:
return number1-number2;

case enOperatorType::Multiply:
return number1*number2;

case enOperatorType::Divide:
return number1/number2;
default: 
return number1+number2;
}
}

int main()
{
enOperatorType OperatorType;
float Number1=ReadNumber("Enter Number1?");
float Number2=ReadNumber("Enter Number2?");
OperatorType=ReadOperatorType();

cout<<"Result= "<<Calculat(Number1,Number2,OperatorType);
}