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

int DaysInYear(int Year)
{
    return (IsleapYear(Year))? 366 : 365;
}

int HoursInYear(int Year)
{
    return DaysInYear(Year)*24;
}

int MinutesInYear(int Year)
{
    return HoursInYear(Year)*60;
}

int secondsInYear(int Year)
{
    return MinutesInYear(Year)*60;
}

int main()
{
    int Year=ReadPositiveNumber("Enter a Year to Chack ?");
    
    cout<< "Number Of Days    in Year ["<<Year<<"] is "<<DaysInYear(Year)<<endl;
    cout<< "Number Of Hours   in Year ["<<Year<<"] is "<<HoursInYear(Year)<<endl;
    cout<< "Number Of Minutes in Year ["<<Year<<"] is "<<MinutesInYear(Year)<<endl;
    cout<< "Number Of Seconds in Year ["<<Year<<"] is "<<secondsInYear(Year)<<endl;
}
