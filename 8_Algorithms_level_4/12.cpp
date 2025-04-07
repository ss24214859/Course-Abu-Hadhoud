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

stDate ReadDate()
{
    stDate Date;
    Date.Year = ReadPositiveNumber("Enter a Year ?");
    Date.Month = ReadPositiveNumber("Enter a Month ?");
    Date.Day = ReadPositiveNumber("Enter a Day ?");
    return Date;
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

stDate AddDaysToDate(int DaysToAdd , stDate Date)
{
    int RemainingDays = DaysToAdd + TotalDaysFromBeginningYear(Date.Year,Date.Month,Date.Day);
    short MonthDays=0;
    Date.Month=1;

    while(true)
    {
        MonthDays=DaysInMonth(Date.Month,Date.Year);

        if(MonthDays<RemainingDays)
        {
            RemainingDays-=MonthDays;
            Date.Month++;

            if(Date.Month > 12)
            {
                Date.Month=1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day=RemainingDays;
            break;
        }
    }
    return Date;
}

int main()
{
    stDate Date=ReadDate();
    int DaysToAdd = ReadPositiveNumber("Enter How many Days to Add ?");

    Date= AddDaysToDate(DaysToAdd,Date);
    printf("Date After Adding [%d] days is : %d/%d/%d \n",DaysToAdd,Date.Day,Date.Month,Date.Year);
}
