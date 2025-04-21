#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;
using namespace Date;
int main()
{
    cout << "Enter Period 1 : " << endl;
    stPeriod Period1 = ReadPeriod();
    cout << "\nEnter Period 2 : " << endl;
    stPeriod Period2 = ReadPeriod();

    if (IsPeriodsOverLap(Period1, Period2))
        cout << "Yes, Periods Overlap" << endl;
    else
        cout << "NO, Periods Not Overlap" << endl;
}