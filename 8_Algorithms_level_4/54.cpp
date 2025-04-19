#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;

int main()
{
    cout << "Vacation Starts: " << endl;
    Date::stDate DateFrom = Date::ReadDate();
    cout << "Vacation Ends:" << endl;
    Date::stDate DateTo = Date::ReadDate();

    cout << "\nVaction From : " << Date::DayShortName(Date::DayOfWeekOrder(DateFrom)) << " , " << Date::DateInLine(DateFrom) << endl;
    cout << "Vaction To : " << Date::DayShortName(Date::DayOfWeekOrder(DateTo)) << " , " << Date::DateInLine(DateTo) << endl;

    cout << "\nActucal Vacation Days is: " << Date::CalculatVacationDays(DateFrom, DateTo) << endl;
}
