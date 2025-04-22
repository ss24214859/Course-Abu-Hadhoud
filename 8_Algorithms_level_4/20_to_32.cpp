#include <iostream>
#include "..\MyLiberary\DateLip.h"
using namespace std;

int main()
{
    Date::stDate Date = Date::ReadDate();

    cout << "01-Adding One Day is : " << Date::DateToString(Date = Date::IncreaseDateByOneDay(Date)) << endl;
    cout << "02-Adding 10 Days is : " << Date ::DateToString(Date = Date::IncreaseDateByXDays(Date, 10)) << endl;
    cout << "03-Adding one Week is : " << Date ::DateToString(Date = Date::IncreaseDateByOneWeek(Date)) << endl;
    cout << "04-Adding 10 Weeks is : " << Date ::DateToString(Date = Date::IncreaseDateByXWeeks(Date, 10)) << endl;
    cout << "05-Adding one Month is : " << Date ::DateToString(Date = Date::IncreaseDateByOneMonth(Date)) << endl;
    cout << "06-Adding 5 Months is : " << Date ::DateToString(Date = Date::IncreaseDateByXMonths(Date, 5)) << endl;
    cout << "07-Adding one Year is : " << Date ::DateToString(Date = Date::IncreaseDateByOneYear(Date)) << endl;
    cout << "08-Adding 10 Years is : " << Date ::DateToString(Date = Date::IncreaseDateByXYears(Date, 10)) << endl;
    cout << "09-Adding 10 Years (Faster) is : " << Date ::DateToString(Date = Date::IncreaseDateByXYearsFaster(Date, 10)) << endl;
    cout << "10-Adding one Decade is : " << Date ::DateToString(Date = Date::IncreaseDateByOneDecade(Date)) << endl;
    cout << "11-Adding 10 Decades is : " << Date ::DateToString(Date = Date::IncreaseDateByXDecades(Date, 10)) << endl;
    cout << "12-Adding 10 Decades (Faster) is : " << Date ::DateToString(Date = Date::IncreaseDateByXDecadesFaster(Date, 10)) << endl;
    cout << "13-Adding one Century is : " << Date ::DateToString(Date = Date::IncreaseDateByOneCentury(Date)) << endl;
    cout << "14-Adding one Millennium is : " << Date ::DateToString(Date = Date::IncreaseDateByOneMillennium(Date)) << endl;
}