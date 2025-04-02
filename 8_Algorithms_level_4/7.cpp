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

short DayOrder(int year , short month, short day)
{
    short a =(14-month)/12;
    int   y = year-a;
    short m = month + (12*a)-2;
    short d = ( day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;
    
    return d;
}

string DayName(short DayOrder)
{
    string arr[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    return arr[DayOrder];
}

int main()
{
    short Year = ReadPositiveNumber("Enter a Year ?");
    short Month = ReadPositiveNumber("Enter a Month ?");
    short Day = ReadPositiveNumber("Enter a Day ?");

    cout<<"Date      : "<<Day<<"/"<<Month<<"/"<<Year<<endl;
    cout<<"Day Order : "<<DayOrder(Year,Month,Day)<<endl;
    cout<<"Day Name  : "<<DayName(DayOrder(Year,Month,Day))<<endl;

}
