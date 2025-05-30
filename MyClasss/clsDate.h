#pragma once

#include <iostream>
#include "clsString.h"
#include <vector>
#include <limits>
#include <ctime>
#include "clsRead.h"

using namespace std;

class clsDate
{

private:
    // Values --------------
    short _Day;
    short _Month;
    short _Year;

public:
    // constructors --------------
    clsDate()
    {
        time_t t;
        time(&t);
        tm now;
        localtime_s(&now, &t);

        _Year = now.tm_year + 1900;
        _Month = now.tm_mon + 1;
        _Day = now.tm_mday;
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }
    clsDate(string Date)
    {
        *this = StringToDate(Date);
    }
    clsDate(short DayOrder, short Year)
    {
        *this = DateByDayOrderInYear(DayOrder, Year);
    }

    // Set & Get --------------

    void SetDay(short Day)
    {
        _Day = Day;
    }
    short Day()
    {
        return _Day;
    }

    void SetMonth(short Month)
    {
        _Month = Month;
    }
    short Month()
    {
        return _Month;
    }

    void SetYear(short Year)
    {
        _Year = Year;
    }
    short Year()
    {
        return _Year;
    }

    // Methods --------------

    static void Print(clsDate Date)
    {
        cout << DateToString(Date) << endl;
    }

    void Print()
    {
        return Print(*this);
    }

    static bool IsLeapYear(short Year)
    {
        return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
    }

    bool IsLeapYear()
    {
        return IsLeapYear(_Year);
    }

    static bool IsValideDate(clsDate Date)
    {
        return (Date._Month < 1 || Date._Month > 12) ? false : (Date._Day < 1 || Date._Day > DaysInMonth(Date._Month, Date._Year)) ? false
                                                                                                                                   : true;
    }

    bool IsValideDate()
    {
        return IsValideDate(clsDate(_Day, _Month, _Year));
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return ((Date1._Year < Date2._Year) ? true : (Date1._Year != Date2._Year) ? false
                                                                                  : ((Date1._Month < Date2._Month) ? true : (Date1._Month != Date2._Month) ? false
                                                                                                                                                           : ((Date1._Day < Date2._Day) ? true : false)));
    }

    bool IsDate1BeforeDate2(clsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1SameAsDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year != Date2._Year) ? false : (Date1._Month != Date2._Month) ? false
                                                  : (Date1._Day == Date2._Day)       ? true
                                                                                     : false;
    }

    bool IsDate1SameAsDate2(clsDate Date2)
    {
        return IsDate1SameAsDate2(*this, Date2);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1SameAsDate2(Date1, Date2);
    }

    bool IsDate1AfterDate2(clsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return (DaysInMonth(Date._Month, Date._Year) == Date._Day);
    }

    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }

    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(_Month);
    }

    static bool IsEndOfWeek(clsDate Date)
    {
        return DayOfWeekOrder(Date) == 6;
    }

    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        return (DayOfWeekOrder(Date) == 5) || (DayOfWeekOrder(Date) == 6); // Fri || Sat
    }

    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    //--------------------------------
    static short DaysInMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;

        short arrDaysOfMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : arrDaysOfMonths[Month - 1];
    }

    short DaysInMonth()
    {
        return DaysInMonth(_Month, _Year);
    }

    static short DayOfWeekOrder(clsDate Date)
    {
        short a = (14 - Date._Month) / 12;
        int y = Date._Year - a;
        short m = Date._Month + (12 * a) - 2;
        // Gregorian
        // 0-Sun 1-Mon 2-Tue ....
        return (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder()
    {
        return DayOfWeekOrder(*this);
    }

    static short DaysFromYearStart(clsDate Date)
    {
        short Total_Days = Date._Day;

        for (short i = Date._Month - 1; i >= 1; i--)
            Total_Days = Total_Days + DaysInMonth(i, Date._Year);

        return Total_Days;
    }

    short DaysFromYearStart()
    {
        return DaysFromYearStart(*this);
    }

    static clsDate ReadDate()
    {
        clsDate Date;
        Date._Year = clsRead::ReadPosNum("Enter a _Year ?");
        Date._Month = clsRead::ReadNumberInRang(1, 12, "Enter a _Month ?", "Wrong _Month :-(\n");
        Date._Day = clsRead::ReadNumberInRang(1, clsDate::DaysInMonth(Date._Month, Date._Year), "Enter a _Day ?", "This _Day is not exisit in this _Month :-( \n");
        return Date;
    }

    static void SwapDates(clsDate &Date1, clsDate &Date2)
    {
        clsDate TempDate = {Date1._Day, Date1._Month, Date1._Year};
        Date1 = {Date2._Day, Date2._Month, Date2._Year};
        Date2 = {TempDate._Day, TempDate._Month, TempDate._Year};
    }

    void SwapDates(clsDate &OtherDate)
    {
        return SwapDates(*this, OtherDate);
    }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IsIncludingEnd_Day = false)
    {
        int _Days = 0;
        short SwapFlagValue = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Date1 = IncreaseDateByOneDay(Date1);
            _Days++;
        }
        return (IsIncludingEnd_Day) ? ++_Days * SwapFlagValue : _Days * SwapFlagValue;
    }

    int GetDifferenceInDays(clsDate Date2, bool IsIncludingEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IsIncludingEndDay);
    }

    static clsDate GetSystemDate()
    {
        time_t t;
        time(&t);
        tm now;
        localtime_s(&now, &t);

        clsDate SystemDate;

        SystemDate._Year = now.tm_year + 1900;
        SystemDate._Month = now.tm_mon + 1;
        SystemDate._Day = now.tm_mday;

        return SystemDate;
    }

    static int GetAgeInDays(clsDate BirthDate)
    {
        return GetDifferenceInDays(BirthDate, GetSystemDate(), true);
    }

    int GetAgeInDays()
    {
        return GetAgeInDays(*this);
    }

    static clsDate StringToDate(string DateString)
    {
        vector<string> vDate = clsString::Split(DateString, "/");
        return clsDate(static_cast<short>(stoi(vDate[0])), static_cast<short>(stoi(vDate[1])), static_cast<short>(stoi(vDate[2])));
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
    }

    string DateTostring()
    {
        return DateToString(*this);
    }

    static string FormatDate(clsDate Date, string Format = "dd/mm/yyyy")
    {
        Format = clsString::ReplaceWord(Format, "dd", to_string(Date._Day));
        Format = clsString::ReplaceWord(Format, "mm", to_string(Date._Month));
        Format = clsString::ReplaceWord(Format, "yyyy", to_string(Date._Year));
        return Format;
    }

    string FormatDate(string Format = "dd/mm/yyyy")
    {
        return FormatDate(*this, Format);
    }

    static string MonthShortName(short MonthNumber)
    {
        string arr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        return arr[MonthNumber - 1];
    }

    string MonthShortName()
    {
        return MonthShortName(_Month);
    }

    static string DayShortName(short DayOfWeekOrder)
    {
        string arr[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        return arr[DayOfWeekOrder];
    }

    string DayShortName()
    {
        return DayShortName(_Day);
    }

    static void PrintMonthCleander(int Year, short Month)
    {
        short Days = DaysInMonth(Month, Year);
        short dayOrder = DayOfWeekOrder(clsDate(1, Month, Year));
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

    void PrintMonthCleander()
    {
        return PrintMonthCleander(_Year, _Month);
    }

    static void PrintYearCleander(int Year)
    {
        printf("\n  __________________________________\n\n");
        printf("             Cleander - %d ", Year);
        printf("\n  __________________________________\n\n");

        for (short i = 1; i <= 12; i++)
            PrintMonthCleander(Year, i);
    }

    void PrintYearCleander()
    {
        return PrintYearCleander(_Year);
    }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {

        /*  SL-01
        short _Days=0;
        while (!IsEndOfWeek(_DayOfWeekOrder(Date)))
        {
            Date = IncreaseDateByOneDay(Date);
            _Days++;
        }
        return _Days; */

        // SL-02
        return 6 - DayOfWeekOrder(Date);
    }

    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static int CalculatVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        int _DaysCount = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                _DaysCount++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return _DaysCount;
    }

    int CalculatVacationDays(clsDate DateTo)
    {
        return CalculatVacationDays(*this, DateTo);
    }

    static clsDate GetVacationReturnDate(clsDate Date, int VacationDays)
    {
        while (VacationDays > 0 || IsWeekEnd(Date))
        {
            if (IsBusinessDay(Date))
                VacationDays--;

            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    clsDate GetVacationReturnDate(int VacationDays)
    {
        return GetVacationReturnDate(*this, VacationDays);
    }

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1
    };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        return (IsDate1BeforeDate2(Date1, Date2)) ? enDateCompare::Before : (IsDate1SameAsDate2(Date1, Date2)) ? enDateCompare::Equal
                                                                                                               : enDateCompare::After;
    }

    enDateCompare CompareDates(clsDate Date2)
    {
        return CompareDates(*this, Date2);
    }

    static clsDate DateByDayOrderInYear(short DayOrder, short Year)
    {
        return IncreaseDateByXDays(clsDate(1, 1, Year), DayOrder);
    }

    clsDate DateByDayOrderInYear(short DayOrder)
    {
        return DateByDayOrderInYear(DayOrder, _Year);
    }

    ///////////////// Increase ////////////////

    static clsDate IncreaseDateByOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date._Month))
            {
                Date._Year++;
                Date._Month = 1;
            }
            else
            {
                Date._Month++;
            }

            Date._Day = 1;
        }
        else
        {
            Date._Day++;
        }

        return Date;
    }

    // Member overload
    void IncreaseDateByOneDay()
    {
        *this = IncreaseDateByOneDay(*this);
    }

    static clsDate IncreaseDateByXDays(clsDate Date, int XDays)
    {
        for (int i = 0; i < XDays; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    // Member overload
    void IncreaseDateByXDays(int XDays)
    {
        *this = IncreaseDateByXDays(*this, XDays);
    }

    static clsDate IncreaseDateByOneWeek(clsDate Date)
    {
        return IncreaseDateByXDays(Date, 7);
    }
    // Member overload
    void IncreaseDateByOneWeek()
    {
        *this = IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeeks(clsDate Date, int XWeek)
    {
        for (int i = 0; i < XWeek; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }
    // Member overload
    void IncreaseDateByXWeeks(int XWeek)
    {
        *this = IncreaseDateByXWeeks(*this, XWeek);
    }

    static clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (IsLastMonthInYear(Date._Month))
        {
            Date._Month = 1;
            Date._Year++;
        }
        else
        {
            Date._Month++;
        }

        short NumberOf_DaysInCurrent_Month = DaysInMonth(Date._Month, Date._Year);

        if (NumberOf_DaysInCurrent_Month < Date._Day)
            Date._Day = NumberOf_DaysInCurrent_Month;

        return Date;
    }
    // Member overload
    void IncreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXMonths(clsDate Date, int XMonth)
    {
        for (int i = 0; i < XMonth; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    // Member overload
    void IncreaseDateByXMonths(int XMonth)
    {
        *this = IncreaseDateByXMonths(*this, XMonth);
    }

    static clsDate IncreaseDateByOneYear(clsDate Date)
    {
        Date._Year++;
        return Date;
    }
    // Member overload
    void IncreaseDateByOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYears(clsDate Date, int XYear)
    {
        for (int i = 0; i < XYear; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    // Member overload
    void IncreaseDateByXYears(int XYear)
    {
        *this = IncreaseDateByXYears(*this, XYear);
    }

    static clsDate IncreaseDateByXYearsFaster(clsDate Date, int XYear)
    {
        Date._Year += XYear;
        return Date;
    }
    // Member overload
    void IncreaseDateByXYearsFaster(int XYear)
    {
        *this = IncreaseDateByXYearsFaster(*this, XYear);
    }

    static clsDate IncreaseDateByOneDecade(clsDate Date)
    {
        Date._Year += 10;
        return Date;
    }
    // Member overload
    void IncreaseDateByOneDecade()
    {
        *this = IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecades(clsDate Date, int XDecade)
    {
        for (int i = 0; i < XDecade; i++)
        {
            Date = IncreaseDateByOneDecade(Date);
        }
        return Date;
    }
    // Member overload
    void IncreaseDateByXDecades(int XDecade)
    {
        *this = IncreaseDateByXDecades(*this, XDecade);
    }

    static clsDate IncreaseDateByXDecadesFaster(clsDate Date, int XDecade)
    {
        Date._Year += XDecade * 10;
        return Date;
    }
    // Member overload
    void IncreaseDateByXDecadesFaster(int XDecade)
    {
        *this = IncreaseDateByXDecadesFaster(*this, XDecade);
    }

    static clsDate IncreaseDateByOneCentury(clsDate Date)
    {
        Date._Year += 100;
        return Date;
    }
    // Member overload
    void IncreaseDateByOneCentury()
    {
        *this = IncreaseDateByOneCentury(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate Date)
    {
        Date._Year += 1000;
        return Date;
    }
    // Member overload
    void IncreaseDateByOneMillennium()
    {
        *this = IncreaseDateByOneMillennium(*this);
    }

    ////////////////// Decrease ////////////////

    static clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Year--;
                Date._Month = 12;
            }
            else
            {
                Date._Month--;
            }

            Date._Day = DaysInMonth(Date._Month, Date._Year);
        }
        else
        {
            Date._Day--;
        }

        return Date;
    }
    // Member overload
    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByXDays(clsDate Date, int XDays)
    {
        for (int i = 0; i < XDays; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    // Member overload
    void DecreaseDateByXDays(int XDays)
    {
        *this = DecreaseDateByXDays(*this, XDays);
    }

    static clsDate DecreaseDateByOneWeek(clsDate Date)
    {
        return DecreaseDateByXDays(Date, 7);
    }
    // Member overload
    void DecreaseDateByOneWeek()
    {
        *this = DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeeks(clsDate Date, int XWeek)
    {
        for (int i = 0; i < XWeek; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }
    // Member overload
    void DecreaseDateByXWeeks(int XWeek)
    {
        *this = DecreaseDateByXWeeks(*this, XWeek);
    }

    static clsDate DecreaseDateByOneMonth(clsDate Date)
    {
        if (Date._Month == 1)
        {
            Date._Month = 12;
            Date._Year--;
        }
        else
        {
            Date._Month--;
        }

        short NumberOf_DaysInCurrent_Month = DaysInMonth(Date._Month, Date._Year);

        if (NumberOf_DaysInCurrent_Month < Date._Day)
            Date._Day = NumberOf_DaysInCurrent_Month;

        return Date;
    }
    // Member overload
    void DecreaseDateByOneMonth()
    {
        *this = DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonths(clsDate Date, int XMonth)
    {
        for (int i = 0; i < XMonth; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }
    // Member overload
    void DecreaseDateByXMonths(int XMonth)
    {
        *this = DecreaseDateByXMonths(*this, XMonth);
    }

    static clsDate DecreaseDateByOneYear(clsDate Date)
    {
        Date._Year--;
        return Date;
    }
    // Member overload
    void DecreaseDateByOneYear()
    {
        *this = DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(clsDate Date, int XYear)
    {
        for (int i = 0; i < XYear; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }
    // Member overload
    void DecreaseDateByXYears(int XYear)
    {
        *this = DecreaseDateByXYears(*this, XYear);
    }

    static clsDate DecreaseDateByXYearsFaster(clsDate Date, int XYear)
    {
        Date._Year -= XYear;
        return Date;
    }
    // Member overload
    void DecreaseDateByXYearsFaster(int XYear)
    {
        *this = DecreaseDateByXYearsFaster(*this, XYear);
    }

    static clsDate DecreaseDateByOneDecade(clsDate Date)
    {
        Date._Year -= 10;
        return Date;
    }
    // Member overload
    void DecreaseDateByOneDecade()
    {
        *this = DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecades(clsDate Date, int XDecade)
    {
        for (int i = 0; i < XDecade; i++)
        {
            Date = DecreaseDateByOneDecade(Date);
        }
        return Date;
    }
    // Member overload
    void DecreaseDateByXDecades(int XDecade)
    {
        *this = DecreaseDateByXDecades(*this, XDecade);
    }

    static clsDate DecreaseDateByXDecadesFaster(clsDate Date, int XDecade)
    {
        Date._Year -= XDecade * 10;
        return Date;
    }
    // Member overload
    void DecreaseDateByXDecadesFaster(int XDecade)
    {
        *this = DecreaseDateByXDecadesFaster(*this, XDecade);
    }

    static clsDate DecreaseDateByOneCentury(clsDate Date)
    {
        Date._Year -= 100;
        return Date;
    }
    // Member overload
    void DecreaseDateByOneCentury()
    {
        *this = DecreaseDateByOneCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate Date)
    {
        Date._Year -= 1000;
        return Date;
    }
    // Member overload
    void DecreaseDateByOneMillennium()
    {
        *this = DecreaseDateByOneMillennium(*this);
    }
};
