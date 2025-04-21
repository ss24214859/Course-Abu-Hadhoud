#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;
using namespace Date;
int main()
{
    cout << "Enter Period 1 : " << endl;
    stPeriod Period1 = ReadPeriod();
    cout << "\nEnter Date to Chack\n"
         << endl;
    stDate Date1 = ReadDate();
    if (IsDateinPeriod(Period1, Date1))
        cout << "yes,Date Within Period." << endl;
    else
        cout << "No,Date is Not Within Period." << endl;
}