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
    // Leap year is Perfectly divisible by 400
    if( (Year % 400) == 0 )
        return true;

    //Not a Leap Year if Divisible by 100
    //but Not divisible by 400
    if( (Year % 100) == 0 )
        return false;
    
    // Leap Year if Not divisible by 100
    // but divisible by 4
    if( (Year % 4) == 0 )
        return true;

    //All ohter Years is not leap year.
    return false;
}

int main()
{
    int Year=ReadPositiveNumber("Enter Year to Chack is Leap Year ?");
    if(IsleapYear(Year))
    cout<<"Yes, Year ["<<Year<<"] Is Leap Year."<<endl;
    else 
    cout<<"No, Year ["<<Year<<"] Is Not Leap Year."<<endl;
}