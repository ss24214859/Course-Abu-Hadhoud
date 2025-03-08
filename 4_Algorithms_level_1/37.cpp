#include<iostream>
using namespace std;


float ReadNumber(string Massage, int count)
{
float num;
cout<<Massage<<count<<"?";
cin>>num;
return num;
}

float ReadSumNumbersforMinus99(string Massage)
{
float sum=0;
float num=0;
int count=1;
do
{
sum=num+sum;
num=ReadNumber(Massage,count);
count++;
}while(num!=-99);
return sum;
}

int main()
{
cout<<ReadSumNumbersforMinus99("enter Number");
}