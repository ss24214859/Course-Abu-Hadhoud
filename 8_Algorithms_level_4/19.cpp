#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;

int main()
{
    cout << "Enter Date:\n";
    Date::stDate Date1 = Date::ReadDate();

    cout << "Diffrence is : " << Date::GetDifferenceInDays(Date1, Date::GetSystemDate()) << " day(s)." << endl;
    cout << "Diffrence (Including End Day) Is : " << Date::GetDifferenceInDays(Date1, Date::GetSystemDate(), true) << "Days" << endl;
}
