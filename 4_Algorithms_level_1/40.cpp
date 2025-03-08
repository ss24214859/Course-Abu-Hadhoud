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


float TotalBillAfterServicesFeeAndTax(float BillValue)
{
    BillValue=BillValue*1.10;
    return BillValue*1.16;
}

int main()
{
    float BillValue=ReadPositiveNumber("Enter Bill Value? ");
    cout<<endl<<"Total Bill = "<<BillValue;
    cout<<"\nTotal Bill After Services Fee And Bill Tax = "<<TotalBillAfterServicesFeeAndTax(BillValue);

}