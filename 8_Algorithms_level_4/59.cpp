#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;
using namespace Date;
int main()
{
    cout << "Enter Period 1 : " << endl;
    stPeriod Period1 = ReadPeriod();
    cout << "Period Length is : " << PeriodLength(Period1) << endl;
    cout << "Period Length (Including End Date) is : " << PeriodLength(Period1, true) << endl;
}