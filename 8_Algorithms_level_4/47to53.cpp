#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;

int main()
{
    Date::stDate Date = Date::ReadDate();
    short DayOrder = Date::DayOfWeekOrder(Date);
    cout << "Today is " << Date::DayShortName(DayOrder) << " , " << Date::DateInLine(Date);
}