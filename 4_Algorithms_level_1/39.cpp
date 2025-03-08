#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float ReadPositiveNumber(string massge)
{
    float num;
    do
    {
    cout<<massge;
    cin>>num;
    } while (num<0);

    return num;
}

float CalculatRemainder(float TotalBill,float CashPaid)
{
 return CashPaid-TotalBill;
}
string L()
{
    return "****************************\n";
}


int main()
{
    float TotalBill=ReadPositiveNumber("Enter Total Bill? ");
    float CashPaid=ReadPositiveNumber("Enter Cash Paid? ");

    cout<<endl<<"Toral Bill = "<<TotalBill<<endl;
    cout<<"Cash Paid = "<<CashPaid<<endl;
    cout<<L();
    cout<<"Remainder = "<<CalculatRemainder(TotalBill,CashPaid)<<endl;

}