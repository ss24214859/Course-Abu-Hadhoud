#include <iostream>
using namespace std;

int ReadPositiveNumber(string Massage)                 
{
    int number;
    do
    {
        cout<<Massage<<endl;
        cin>>number;
    }while(number<=0);
    return number;
}

int FactorialOfNumberFrom1ToN(int Number)
{   int F=1;
    for(int counter=Number ; counter>=1 ;counter--)
    {
        F=F*counter;
    }
    return F;
}

int main()
{
    cout<<FactorialOfNumberFrom1ToN(ReadPositiveNumber("Please enter a Positive Number?"));
}