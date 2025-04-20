#include <iostream>
#include "../MyLiberary/DateLip.h"
using namespace std;
using namespace Date;
int main()
{
    cout << "Enter Date1 : " << endl;
    stDate Date1 = ReadDate();
    cout << "Enter Date2 : " << endl;
    stDate Date2 = ReadDate();
    cout << "\nCompare Result = " << CompareDates(Date1, Date2) << endl;
}