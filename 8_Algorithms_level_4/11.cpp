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

short DaysInMonth(short Month ,short Year )
{
    if(Month<1 ||Month>12)
    return 0;

    short arrDaysOfMonths[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2 )? ( (IsleapYear(Year))? 29 : 28 ) : arrDaysOfMonths[Month-1] ;
}

short TotalDaysFromBeginningYear(int Year,short Month,short Day)
{
    short TotalDays=Day;

    for(short i=Month-1;i>=1;i--)
        TotalDays=TotalDays+DaysInMonth(i,Year);

    return TotalDays;
}

struct stDate
{
    short Year
    ,Month
    ,Day;
};

stDate GetDateFromDayOrderInYear(short Year ,short DateOrderInYear)
{
    stDate Date;
    short daysInMonth=0;
    short RemainingDays=DateOrderInYear;
    short Month=1;
    
    while((daysInMonth = DaysInMonth(Month,Year)) < RemainingDays)
    {
        RemainingDays -= daysInMonth;
        Month++;
    }

    Date.Day=RemainingDays;
    Date.Month=Month;
    Date.Year=Year;

    return Date;
}

int main()
{
    short Year = ReadPositiveNumber("Enter a Year ?");
    short Month = ReadPositiveNumber("Enter a Month ?");
    short Day = ReadPositiveNumber("Enter a Day ?");
    short TotalDays = TotalDaysFromBeginningYear(Year,Month,Day);

    cout<<"Number of days From beginning of the year is "<<TotalDays<<endl;

    stDate Date= GetDateFromDayOrderInYear(Year,TotalDays);
    printf("Date for [%d] is : %d/%d/%d \n",TotalDays,Date.Day,Date.Month,Date.Year);
}
