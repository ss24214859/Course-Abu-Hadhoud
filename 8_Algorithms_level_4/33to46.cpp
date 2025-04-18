#include <iostream>
#include "..\MyLiberary\DateLip.h"
using namespace std;

int main()
{
    Date::stDate Date = Date::ReadDate();

    cout << "01-Substracting One Day is : " << Date::DateInLine(Date = Date::DecreaseDateByOneDay(Date)) << endl;
    cout << "02-Substracting 10 Days is : " << Date ::DateInLine(Date = Date::DecreaseDateByXDays(Date, 10)) << endl;
    cout << "03-Substracting one Week is : " << Date ::DateInLine(Date = Date::DecreaseDateByOneWeek(Date)) << endl;
    cout << "04-Substracting 10 Weeks is : " << Date ::DateInLine(Date = Date::DecreaseDateByXWeeks(Date, 10)) << endl;
    // cout << "05-Substracting one Month is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneMonth(Date)) << endl;
    // cout << "06-Substracting 5 Months is : " << Date ::DateInLine(Date = Date::IncreaseDateByXMonths(Date, 5)) << endl;
    // cout << "07-Substracting one Year is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneYear(Date)) << endl;
    // cout << "08-Substracting 10 Years is : " << Date ::DateInLine(Date = Date::IncreaseDateByXYears(Date, 10)) << endl;
    // cout << "09-Substracting 10 Years (Faster) is : " << Date ::DateInLine(Date = Date::IncreaseDateByXYearsFaster(Date, 10)) << endl;
    // cout << "10-Substracting one Decade is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneDecade(Date)) << endl;
    // cout << "11-Substracting 10 Decades is : " << Date ::DateInLine(Date = Date::IncreaseDateByXDecades(Date, 10)) << endl;
    // cout << "12-Substracting 10 Decades (Faster) is : " << Date ::DateInLine(Date = Date::IncreaseDateByXDecadesFaster(Date, 10)) << endl;
    // cout << "13-Substracting one Century is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneCentury(Date)) << endl;
    // cout << "14-Substracting one Millennium is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneMillennium(Date)) << endl;
}