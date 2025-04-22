#include <iostream>
#include "../MyLiberary/ReadLip.h"
#include "../MyLiberary/DateLip.h"
using namespace std;

int main()
{
    cout << "Vacation Starts: " << endl;
    Date::stDate DateFrom = Date::ReadDate();
    int VacationDays = Read::ReadPosNum("Please Enter Vacation Days ? ");

    DateFrom = Date::CalculatVacationReturnDate(DateFrom, VacationDays);
    cout << "Return Date : " << Date::DayShortName(Date::DayOfWeekOrder(DateFrom)) << " , " << Date::DateToString(DateFrom) << endl;
}