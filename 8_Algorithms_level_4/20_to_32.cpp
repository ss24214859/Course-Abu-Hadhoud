#include <iostream>
#include "..\MyLiberary\DateLip.h"
using namespace std;

int main()
{
    Date::stDate Date = Date::ReadDate();

    cout << "01-Adding One Day is : " << Date::DateInLine(Date = Date::IncreaseDateByOneDay(Date)) << endl;
    cout << "02-Adding X Days is : " << Date ::DateInLine(Date = Date::IncreaseDateByXDays(Date, 10)) << endl;
    cout << "03-Adding one Week is : " << Date ::DateInLine(Date = Date::IncreaseDateByOneWeek(Date)) << endl;
}