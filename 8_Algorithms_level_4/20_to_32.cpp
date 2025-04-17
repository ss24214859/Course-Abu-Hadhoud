#include <iostream>
#include "..\MyLiberary\DateLip.h"
using namespace std;

int main()
{
    Date::stDate Date = Date::ReadDate();

    cout << "01-Adding One Day is : " << Date::DateInLine(Date = Date::IncreaseDateByOneDay(Date)) << endl;
    cout << "02-Adding 10 Days is : " << Date ::DateInLine(Date = Date::IncreaseDateByXDays(Date, 10)) << endl;
    cout << "03-Adding one Week is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneWeek(Date)) << endl;
    cout << "04-Adding 10 Week is : " << Date ::DateInLine(Date = Date::IncreaseDateByXWeek(Date, 10)) << endl;
    cout << "05-Adding one Month is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneMonth(Date)) << endl;
    cout << "06-Adding 5 Month is : " << Date ::DateInLine(Date = Date::IncreaseDateByXMonth(Date, 5)) << endl;
    cout << "07-Adding one Year is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneYear(Date)) << endl;
    cout << "08-Adding 10 Year is : " << Date ::DateInLine(Date = Date::IncreaseDateByXYear(Date, 10)) << endl;
}