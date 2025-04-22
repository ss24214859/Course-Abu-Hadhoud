#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;
using namespace Date;
int main()
{
    // cout << "Enter Period 1 : " << endl;
    stPeriod Period1 = {{1, 1, 2022}, {10, 1, 2022}};
    // cout << "\nEnter Period 2 : " << endl;
    stPeriod Period2 = {{5, 1, 2022}, {30, 12, 2055}};
    cout << "Period 1 = " << DateInLine(Period1.StartDate) << " , " << DateInLine(Period1.EndDate) << endl;
    cout << "Period 2 = " << DateInLine(Period2.StartDate) << " , " << DateInLine(Period2.EndDate) << endl;
    cout << "\nOverLap Days Count Is : " << OverlapDaysCounter(Period1, Period2) << endl;
}