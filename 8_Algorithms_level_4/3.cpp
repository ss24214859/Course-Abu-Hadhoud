#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
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

bool IsleapYear(int Year)
{
    return ( Year % 400 == 0 ) || ( Year % 100 != 0  &&  Year % 4 == 0 ) ;
}

int main()
{
    int Year=ReadPositiveNumber("Enter Year to Chack is Leap Year ?");
    if(IsleapYear(Year))
    cout<<"Yes, Year ["<<Year<<"] Is Leap Year."<<endl;
    else 
    cout<<"No, Year ["<<Year<<"] Is Not Leap Year."<<endl;
}
