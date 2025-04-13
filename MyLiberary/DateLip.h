#pragma once

#include <iostream>
#include "ReadLip.h"

namespace Date
{
    using namespace std;

    struct stDate
    {
        short Day, Month;
        int Year;
    };

    bool IsleapYear(short Year);
    short DaysInMonth(short Month, short Year);
    short TotalDaysFromBeginningYear(stDate Date);
    stDate ReadDate();
    bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
    bool IsLastDayInMonth(stDate Date);
    bool IsLastMonthInYear(short Month);
    stDate IncreaseDateByOneDay(stDate Date);
    int GetDifferenceInDays(stDate, stDate, bool);
    stDate GetSystemDate();
    int GetAgeInDays(stDate BirthDate);

}

namespace Date
{
    using namespace std;
    bool IsleapYear(short Year)
    {
        return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
    }

    short DaysInMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;

        short arrDaysOfMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2) ? ((IsleapYear(Year)) ? 29 : 28) : arrDaysOfMonths[Month - 1];
    }

    short TotalDaysFromBeginningYear(stDate Date)
    {
        short TotalDays = Date.Day;

        for (short i = Date.Month - 1; i >= 1; i--)
            TotalDays = TotalDays + DaysInMonth(i, Date.Year);

        return TotalDays;
    }

    stDate ReadDate()
    {
        stDate Date;
        Date.Year = Read::ReadPosNum("Enter a Year ?");
        Date.Month = Read::ReadNumberInRang(1, 12, "Enter a Month ?", "Wrong Month :-(\n");
        Date.Day = Read::ReadNumberInRang(1, Date::DaysInMonth(Date.Month, Date.Year), "Enter a Day ?", "This Day is not exisit in this Month :-( \n");
        return Date;
    }

    bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
    {
        return ((Date1.Year < Date2.Year) ? true : (Date1.Year != Date2.Year) ? false
                                                                              : ((Date1.Month < Date2.Month) ? true : (Date1.Month != Date2.Month) ? false
                                                                                                                                                   : ((Date1.Day < Date2.Day) ? true : false)));
    }

    bool IsDate1SameAsDate2(stDate Date1, stDate Date2)
    {
        return (Date1.Year != Date2.Year) ? false : (Date1.Month != Date2.Month) ? false
                                                : (Date1.Day == Date2.Day)       ? true
                                                                                 : false;
    }

    bool IsLastDayInMonth(stDate Date)
    {
        return (DaysInMonth(Date.Month, Date.Year) == Date.Day);
    }

    bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    stDate IncreaseDateByOneDay(stDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Year++;
                Date.Month = 1;
            }
            else
            {
                Date.Month++;
            }

            Date.Day = 1;
        }
        else
        {
            Date.Day++;
        }

        return Date;
    }

    int GetDiffrenceInDays(stDate Date1, stDate Date2, bool IsIncludingEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;
        while (!IsDate1SameAsDate2(Date1, Date2))
        {
            if (IsDate1BeforeDate2(Date1, Date2))
                Date1 = IncreaseDateByOneDay(Date1);
            else
            {
                Date2 = IncreaseDateByOneDay(Date2);
                SwapFlagValue = -1;
            }
            Days++;
        }
        return (IsIncludingEndDay) ? ++Days * SwapFlagValue : Days * SwapFlagValue;
    }

    stDate GetSystemDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);

        stDate SystemDate;

        SystemDate.Year = now->tm_year + 1900;
        SystemDate.Month = now->tm_mon + 1;
        SystemDate.Day = now->tm_mday;

        return SystemDate;
    }

    int GetAgeInDays(stDate BirthDate)
    {
        return GetDiffrenceInDays(BirthDate, Date::GetSystemDate(), true);
    }

}
