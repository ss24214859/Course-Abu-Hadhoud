#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;

int main()
{
    Date::stDate Date = Date::ReadDate();
    short DayOrder = Date::DayOfWeekOrder(Date);
    cout << "Today is " << Date::DayShortName(DayOrder) << " , " << Date::DateInLine(Date) << endl;

    cout << "Is it End Week ? " << endl;
    cout << ((Date::IsEndOfWeek(DayOrder)) ? "Yes is it End Of Week." : "No Not End Of Week.") << endl;
}