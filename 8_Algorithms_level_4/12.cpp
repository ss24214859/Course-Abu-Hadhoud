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

struct stDate
{
    short Day,
    Month,
    Year;
};

short TotalDaysFromBeginningYear(int Year,short Month,short Day)
{
    short TotalDays=Day;

    for(short i=Month-1;i>=1;i--)
        TotalDays=TotalDays+DaysInMonth(i,Year);

    return TotalDays;
}

stDate GetDateFromDayOrderInYear(short Year ,short DateOrderInYear)
{
    stDate Date;
    short daysInMonth=0;
    short RemainingDays=DateOrderInYear;
    Date.Month=1;
    Date.Year=Year;

    while(true)
    {
        daysInMonth = DaysInMonth(Date.Month,Year);
        if(daysInMonth < RemainingDays)
        {
            RemainingDays -= daysInMonth;
            Date.Month++;
        }
        else
        {
            Date.Day=RemainingDays;
            break;
        }
    }

    return Date;
}

stDate AddDaysToDate(int DaysToAdd , short Year , short Month , short Day)
{
    int RemainingDays = DaysToAdd + TotalDaysFromBeginningYear(Year,Month,Day);
    stDate DateAfterAddDays;
    DateAfterAddDays.Year=Year;
    short DaysInYear=0;

    while(true)
    {
        DaysInYear=(IsleapYear(DateAfterAddDays.Year))? 366 : 365 ;

        if(DaysInYear<RemainingDays)
        {
            RemainingDays-=DaysInYear;
            DateAfterAddDays.Year++;
        }
        else
        {
            DateAfterAddDays=GetDateFromDayOrderInYear(DateAfterAddDays.Year,RemainingDays);
            break;
        }
    }
    return DateAfterAddDays;
}

int main()
{
    short Year = ReadPositiveNumber("Enter a Year ?");
    short Month = ReadPositiveNumber("Enter a Month ?");
    short Day = ReadPositiveNumber("Enter a Day ?");
    int DaysToAdd = ReadPositiveNumber("Enter How many Days to Add ?");

    stDate Date= AddDaysToDate(DaysToAdd,Year,Month,Day);
    printf("Date After Adding [%d] days is : %d/%d/%d \n",DaysToAdd,Date.Day,Date.Month,Date.Year);
}
