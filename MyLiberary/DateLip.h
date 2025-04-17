#pragma once

#include <iostream>
#include "ReadLip.h"
#include <string>

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
    void SwapDates(stDate &Date1, stDate &Date2);
    int GetDifferenceInDays(stDate, stDate, bool);
    stDate GetSystemDate();
    int GetAgeInDays(stDate BirthDate);
    string DateInLine(stDate Date);
    stDate IncreaseDateByXDays(stDate Date, int XDays);

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

    void SwapDates(stDate &Date1, stDate &Date2)
    {
        stDate TempDate = {Date1.Day, Date1.Month, Date1.Year};
        Date1 = {Date2.Day, Date2.Month, Date2.Year};
        Date2 = {TempDate.Day, TempDate.Month, TempDate.Year};
    }

    int GetDifferenceInDays(stDate Date1, stDate Date2, bool IsIncludingEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Date1 = IncreaseDateByOneDay(Date1);
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
        return GetDifferenceInDays(BirthDate, Date::GetSystemDate(), true);
    }

    string DateInLine(stDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
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

    stDate IncreaseDateByXDays(stDate Date, int XDays)
    {
        for (int i = 0; i < XDays; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    stDate IncreaseDateByOneWeek(stDate Date)
    {
        return IncreaseDateByXDays(Date, 7);
    }

    stDate IncreaseDateByXWeek(stDate Date, int XWeek)
    {
        for (int i = 0; i < XWeek; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    stDate IncreaseDateByOneMonth(stDate Date)
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }

        return Date;
    }

    stDate IncreaseDateByXMonth(stDate Date, int XMonth)
    {
        for (int i = 0; i < XMonth; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    stDate IncreaseDateByOneYear(stDate Date)
    {
        return {Date.Day, Date.Month, Date.Year + 1};
    }

    stDate IncreaseDateByXYear(stDate Date, int XYear)
    {
        for (int i = 0; i < XYear; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate IncreaseDateByXYearFaster(stDate Date, int XYear)
    {
        return {Date.Day, Date.Month, Date.Year + XYear};
    }

}
