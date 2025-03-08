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

float CalculatMonthlyPayment(float LoanAmount,float MonthsSettleLoan)
{
    return LoanAmount/MonthsSettleLoan;
}
int main()
{
    float LoanAmount=ReadPositiveNumber("enter Loan Amount? ")
    ,MonthsSettleLoan=ReadPositiveNumber("enter Monthly Pyment? ")
    ,MonthlyPyment=CalculatMonthlyPayment(LoanAmount,MonthsSettleLoan);

    cout<<endl<<"Monthly Pyment = "<<MonthlyPyment<<endl;

}