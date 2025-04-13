#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;

int main()
{
    cout << "Enter Your Date Of Birth :\n";
    Date::stDate BirthDate = Date::ReadDate();

    cout << "Your Age Is : " << Date::GetAgeInDays(BirthDate) << " day(s)." << endl;
}
