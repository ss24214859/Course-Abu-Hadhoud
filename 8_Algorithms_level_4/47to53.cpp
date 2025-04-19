#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;

int main()
{
    Date::stDate Date = Date::ReadDate();
    cout << "\nToday is " << Date::DayShortName(Date::DayOfWeekOrder(Date)) << " , " << Date::DateInLine(Date) << endl;

    cout << "\nIs it End Of Week ? " << endl;
    cout << ((Date::IsEndOfWeek(Date)) ? "Yes it is End Of Week." : "No Not End Of Week.") << endl;

    cout << "\nIs it Weekend ? " << endl;
    cout << ((Date::IsWeekEnd(Date)) ? "Yes it is  a Week end." : "No Not a Week end.") << endl;

    cout << "\nIs it Business Day ? " << endl;
    cout << ((Date::IsBusinessDay(Date)) ? "Yes it is a Business Day." : "No Not Business Day.") << endl;

    cout << "\nDays until end of Week  : " << Date::DaysUntilTheEndOfWeek(Date) << " Days(s)." << endl;
    cout << "Days until end Of Month : " << Date::DaysUntilTheEndOfMonth(Date) << " Days(s)." << endl;
    cout << "Days until end of Year : " << Date::DaysUntilTheEndOfYear(Date) << " Days(s)." << endl;
}