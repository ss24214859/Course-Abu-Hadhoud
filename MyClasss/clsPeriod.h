#pragma once

#include <iostream>
#include "../MyClasss/clsDate.h"

class clsPeriod
{
private:
    clsDate _StartDate;
    clsDate _EndDate;

public:
    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        _StartDate = StartDate;
        _EndDate = EndDate;
    }

    static void Print(clsPeriod Period)
    {
        cout << "Start Date : " << clsDate::DateToString(Period._StartDate) << endl;
        cout << "End Date   : " << clsDate::DateToString(Period._EndDate) << endl;
    }
    void Print()
    {
        Print(*this);
    }

    static bool IsOverLapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        return !((clsDate::CompareDates(Period1._EndDate, Period2._StartDate) == clsDate::enDateCompare::Before) ||
                 (clsDate::CompareDates(Period1._StartDate, Period2._EndDate) == clsDate::enDateCompare::After));
    }
    bool IsOverLapPeriods(clsPeriod Period2)
    {
        return IsOverLapPeriods(*this, Period2);
    }

    static int PeriodLength(clsPeriod Period, bool IncludingEnd_Day = false)
    {
        return clsDate::GetDifferenceInDays(Period._StartDate, Period._EndDate, IncludingEnd_Day);
    }
    int PeriodLength(bool IncludingEndDay = false)
    {
        return PeriodLength(*this, IncludingEndDay);
    }

    static bool IsDateInPeriod(clsPeriod Period, clsDate Date)
    {
        return !((clsDate::CompareDates(Date, Period._StartDate) == clsDate::enDateCompare::Before) ||
                 (clsDate::CompareDates(Date, Period._EndDate) == clsDate::enDateCompare::After));
    }
    bool IsDateInPeriod(clsDate Date)
    {
        return IsDateInPeriod(*this, Date);
    }

    static void SwapPeriods(clsPeriod &Period1, clsPeriod &Period2)
    {
        clsPeriod temp = Period2;
        Period2 = Period1;
        Period1 = temp;
    }

    static int OverlapDaysCounter(clsPeriod Period1, clsPeriod Period2)
    {
        clsPeriod OverLapPeriod((clsDate::IsDate1BeforeDate2(Period1._StartDate, Period2._StartDate)) ? Period2._StartDate : Period1._StartDate, (clsDate::IsDate1BeforeDate2(Period1._EndDate, Period2._EndDate)) ? Period1._EndDate : Period2._EndDate);
        if (clsDate::IsDate1BeforeDate2(OverLapPeriod._EndDate, OverLapPeriod._StartDate))
            return 0;

        return PeriodLength(OverLapPeriod);
    }
    int OverlapDaysCounter(clsPeriod Period2)
    {
        return OverlapDaysCounter(*this, Period2);
    }
};