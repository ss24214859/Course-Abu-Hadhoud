#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

enum enMonths
{
    January = 1, February = 2, March = 3, April = 4,
    May = 5, June = 6, July = 7, August = 8, September = 9,
    October = 10, November = 11, December = 12
};

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

bool IsleapYear(int Month)
{
    return ( Month % 400 == 0 ) || ( Month % 100 != 0  &&  Month % 4 == 0 ) ;
}

int DaysInMonth(int Month , int Year)
{
    switch(Month)
    {
        case enMonths::January :
        return 31;
    case enMonths::February :
        return IsleapYear(Year)? 29 : 28;
    case enMonths::March :
        return 31;
    case enMonths::April :
        return 30;
    case enMonths::May :
        return 31;
    case enMonths::June :
        return 30;
    case enMonths::July :
        return 31;
    case enMonths::August :
        return 31;
    case enMonths::September :
        return 30;
    case enMonths::October :
        return 31;
    case enMonths::November :
        return 30;
    case enMonths::December :
        return 31;
    default:
        return 0; 
}
    
}

int HoursInMonth(int Month , int Year)
{
    return DaysInMonth(Month,Year)*24;
}

int MinutesInMonth(int Month , int Year)
{
    return HoursInMonth(Month,Year)*60;
}

int secondsInMonth(int Month , int Year)
{
    return MinutesInMonth(Month,Year)*60;
}

int main()
{
    int Year=ReadPositiveNumber("Enter a Year to Chack ?");
    int Month=ReadPositiveNumber("Enter a Month to Chack ?");
    
    cout<< "Number Of Days    in Month ["<<Month<<"] is "<<DaysInMonth(Month,Year)<<endl;
    cout<< "Number Of Hours   in Month ["<<Month<<"] is "<<HoursInMonth(Month,Year)<<endl;
    cout<< "Number Of Minutes in Month ["<<Month<<"] is "<<MinutesInMonth(Month,Year)<<endl;
    cout<< "Number Of Seconds in Month ["<<Month<<"] is "<<secondsInMonth(Month,Year)<<endl;
}
