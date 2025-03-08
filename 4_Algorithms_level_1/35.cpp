#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct stAmount
{
int Dollar,Quarter,Dime,Nickel,Penny;
};

int ReadNumber(string massage)
{
    int number;
    cout<<massage<<endl;
    cin>>number;
    return number;
}

stAmount ReadAmount()
{
 stAmount Amount;
 Amount.Dollar=ReadNumber("enter Dollars? ");
 Amount.Quarter=ReadNumber("enter Quarter? ");
 Amount.Dime=ReadNumber("enter Dime? ");
 Amount.Nickel=ReadNumber("enter Nickel? ");
 Amount.Penny=ReadNumber("enter Penny?");
return Amount;
}

float TotalPennies(stAmount Amount)
{
return Amount.Penny+(Amount.Nickel*5)+(Amount.Dime*10)+(Amount.Quarter*25)+(Amount.Dollar*100);
}

float TotalDollars(stAmount Amount)
{
  return TotalPennies(Amount)/100;
}


void printResult(stAmount Amount)
{
    cout<<"Total Pennies ="<<TotalPennies(Amount)<<endl;    
    cout<<"Total Dollars ="<<TotalDollars(Amount)<<endl;
}

int main()
{


printResult(ReadAmount());

}