#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

short ReadPositiveNumber(string massge)
{
    short num;
    do
    {
        cout << massge;
        cin >> num;
    } while (num < 0);

    return num;
}

bool IsleapYear(short Month)
{
    return (Month % 400 == 0) || (Month % 100 != 0 && Month % 4 == 0);
}

short DaysInMonth(short Month, short Year)
{
    if(Month<1 ||Month>12)
    return 0;

    short arrDaysOfMonths[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2 )? ( (IsleapYear(Year))? 29 : 28 ) : arrDaysOfMonths[Month-1] ;
}

int HoursInMonth(short Month, short Year)
{
    return DaysInMonth(Month, Year) * 24;
}

int MinutesInMonth(short Month, short Year)
{
    return HoursInMonth(Month, Year) * 60;
}

int secondsInMonth(short Month, short Year)
{
    return MinutesInMonth(Month, Year) * 60;
}

int main()
{
    short Year = ReadPositiveNumber("Enter a Year to Chack ?");
    short Month = ReadPositiveNumber("Enter a Month to Chack ?");

    cout << "Number Of Days    in Month [" << Month << "] is " << DaysInMonth(Month, Year) << endl;
    cout << "Number Of Hours   in Month [" << Month << "] is " << HoursInMonth(Month, Year) << endl;
    cout << "Number Of Minutes in Month [" << Month << "] is " << MinutesInMonth(Month, Year) << endl;
    cout << "Number Of Seconds in Month [" << Month << "] is " << secondsInMonth(Month, Year) << endl;
}
