#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;

int main()
{
    Date::stDate Date = Date::ReadDate();
    short DayOrder = Date::DayOfWeekOrder(Date);
    cout << "\nToday is " << Date::DayShortName(DayOrder) << " , " << Date::DateInLine(Date) << endl;

    cout << "\nIs it End Of Week ? " << endl;
    cout << ((Date::IsEndOfWeek(DayOrder)) ? "Yes it is End Of Week." : "No Not End Of Week.") << endl;

    cout << "\nIs it Weekend ? " << endl;
    cout << ((Date::IsWeekEnd(DayOrder)) ? "Yes it is  a Week end." : "No Not a Week end.") << endl;

    cout << "\nIs it Business Day ? " << endl;
    cout << ((Date::IsBusinessDay(DayOrder)) ? "Yes it is a Business Day." : "No Not Business Day.") << endl;

    cout << "Days until end of Week : " << Date::DaysUntilTheEndOfWeek(Date) << endl;
}