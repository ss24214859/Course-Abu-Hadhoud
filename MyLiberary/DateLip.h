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
    bool IsNumberOfDaysInCurrntMonthInMonth(stDate Date);
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

    short DayOfWeekOrder(int year, short month, short day)
    {
        short a = (14 - month) / 12;
        int y = year - a;
        short m = month + (12 * a) - 2;
        // Gregorian
        // 0-Sun 1-Mon 2-Tue ....
        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder(stDate Date)
    {
        return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
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

    bool IsNumberOfDaysInCurrntMonthInMonth(stDate Date)
    {
        return (DaysInMonth(Date.Month, Date.Year) == Date.Day);
    }

    bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    bool IsEndOfWeek(stDate Date)
    {
        return DayOfWeekOrder(Date) == 6;
    }

    bool IsWeekEnd(stDate Date)
    {
        return (DayOfWeekOrder(Date) == 5) || (DayOfWeekOrder(Date) == 6); // Fri || Sat
    }

    bool IsBusinessDay(stDate Date)
    {
        return !IsWeekEnd(Date);
    }

    short DaysUntilTheEndOfWeek(stDate Date)
    {

        /*  SL-01
        short Days=0;
        while (!IsEndOfWeek(DayOfWeekOrder(Date)))
        {
            Date = IncreaseDateByOneDay(Date);
            Days++;
        }
        return Days; */

        // SL-02
        return 6 - DayOfWeekOrder(Date);
    }

    short DaysUntilTheEndOfMonth(stDate Date)
    {
        /////// My SL ///
        // return DaysInMonth(Date.Month, Date.Year) - Date.Day + 1;

        stDate EndOfMonthDate{DaysInMonth(Date.Month, Date.Year), Date.Month, Date.Year};
        return GetDifferenceInDays(Date, EndOfMonthDate, true);
    }

    short DaysUntilTheEndOfYear(stDate Date)
    {
        /////// My SL ////
        // return ((IsleapYear(Date.Year)) ? 366 : 365) - TotalDaysFromBeginningYear(Date) + 1;

        stDate EndOfYearDate = {31, 12, Date.Year};
        return GetDifferenceInDays(Date, EndOfYearDate, true);
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

    string MonthShortName(short MonthNumber)
    {
        string arr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        return arr[MonthNumber - 1];
    }

    string DayShortName(short DayOfWeekOrder)
    {
        string arr[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        return arr[DayOfWeekOrder];
    }

    void PrintMonthCleander(int Year, short Month)
    {
        short Days = DaysInMonth(Month, Year);
        short dayOrder = DayOfWeekOrder(Year, Month, 1);
        printf("\n  ______________%s________________\n", MonthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        short i = 0;
        for (i = 0; i < dayOrder; i++)
            printf("     ");

        for (short j = 1; j < Days; j++)
        {
            printf("%5d", j);
            if (++i == 7)
            {
                printf("\n");
                i = 0;
            }
        }

        printf("\n  __________________________________\n");
    }

    void PrintYearCleander(int Year)
    {
        printf("\n  __________________________________\n\n");
        printf("             Cleander - %d ", Year);
        printf("\n  __________________________________\n\n");

        for (short i = 1; i <= 12; i++)
            PrintMonthCleander(Year, i);
    }

    //////////////////// Increase //////////////////

    stDate IncreaseDateByOneDay(stDate Date)
    {
        if (IsNumberOfDaysInCurrntMonthInMonth(Date))
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

    stDate IncreaseDateByXWeeks(stDate Date, int XWeek)
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

        short NumberOfDaysInCurrentMonth = DaysInMonth(Date.Month, Date.Year);

        if (NumberOfDaysInCurrentMonth < Date.Day)
            Date.Day = NumberOfDaysInCurrentMonth;

        return Date;
    }

    stDate IncreaseDateByXMonths(stDate Date, int XMonth)
    {
        for (int i = 0; i < XMonth; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    stDate IncreaseDateByOneYear(stDate Date)
    {
        Date.Year++;
        return Date;
    }

    stDate IncreaseDateByXYears(stDate Date, int XYear)
    {
        for (int i = 0; i < XYear; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate IncreaseDateByXYearsFaster(stDate Date, int XYear)
    {
        Date.Year += XYear;
        return Date;
    }

    stDate IncreaseDateByOneDecade(stDate Date)
    {
        Date.Year += 10;
        return Date;
    }

    stDate IncreaseDateByXDecades(stDate Date, int XDecade)
    {
        for (int i = 0; i < XDecade; i++)
        {
            Date = IncreaseDateByOneDecade(Date);
        }
        return Date;
    }

    stDate IncreaseDateByXDecadesFaster(stDate Date, int XDecade)
    {
        Date.Year += XDecade * 10;
        return Date;
    }

    stDate IncreaseDateByOneCentury(stDate Date)
    {
        Date.Year += 100;
        return Date;
    }

    stDate IncreaseDateByOneMillennium(stDate Date)
    {
        Date.Year += 1000;
        return Date;
    }

    ////////////////// Decrease ////////////////

    stDate DecreaseDateByOneDay(stDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Year--;
                Date.Month = 12;
            }
            else
            {
                Date.Month--;
            }

            Date.Day = DaysInMonth(Date.Month, Date.Year);
        }
        else
        {
            Date.Day--;
        }

        return Date;
    }

    stDate DecreaseDateByXDays(stDate Date, int XDays)
    {
        for (int i = 0; i < XDays; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    stDate DecreaseDateByOneWeek(stDate Date)
    {
        return DecreaseDateByXDays(Date, 7);
    }

    stDate DecreaseDateByXWeeks(stDate Date, int XWeek)
    {
        for (int i = 0; i < XWeek; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    stDate DecreaseDateByOneMonth(stDate Date)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }

        short NumberOfDaysInCurrentMonth = DaysInMonth(Date.Month, Date.Year);

        if (NumberOfDaysInCurrentMonth < Date.Day)
            Date.Day = NumberOfDaysInCurrentMonth;

        return Date;
    }

    stDate DecreaseDateByXMonths(stDate Date, int XMonth)
    {
        for (int i = 0; i < XMonth; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    stDate DecreaseDateByOneYear(stDate Date)
    {
        Date.Year--;
        return Date;
    }

    stDate DecreaseDateByXYears(stDate Date, int XYear)
    {
        for (int i = 0; i < XYear; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    stDate DecreaseDateByXYearsFaster(stDate Date, int XYear)
    {
        Date.Year -= XYear;
        return Date;
    }

    stDate DecreaseDateByOneDecade(stDate Date)
    {
        Date.Year -= 10;
        return Date;
    }

    stDate DecreaseDateByXDecades(stDate Date, int XDecade)
    {
        for (int i = 0; i < XDecade; i++)
        {
            Date = DecreaseDateByOneDecade(Date);
        }
        return Date;
    }

    stDate DecreaseDateByXDecadesFaster(stDate Date, int XDecade)
    {
        Date.Year -= XDecade * 10;
        return Date;
    }

    stDate DecreaseDateByOneCentury(stDate Date)
    {
        Date.Year -= 100;
        return Date;
    }

    stDate DecreaseDateByOneMillennium(stDate Date)
    {
        Date.Year -= 1000;
        return Date;
    }

}
