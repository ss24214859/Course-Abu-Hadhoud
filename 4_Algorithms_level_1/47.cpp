#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ReadPositiveNumber(string massge)
{
    int num;
    do
    {
    cout<<massge;
    cin>>num;
    } while (num<0);

    return num;
}

float CalculatMonthsSettleLoan(float LoanAmount,float MonthlyPyment)
{
    return LoanAmount/MonthlyPyment;
}
int main()
{
    float LoanAmount=ReadPositiveNumber("enter Loan Amount? ")
    ,MonthlyPyment=ReadPositiveNumber("enter Monthly Pyment? ")
    ,Months=CalculatMonthsSettleLoan(LoanAmount,MonthlyPyment);

    cout<<endl<<"You Need "<<Months<<" Months to Settle The Loan."<<endl;

}