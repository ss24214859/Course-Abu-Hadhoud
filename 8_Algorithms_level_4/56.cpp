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

    if (IsDate1AfterDate2(Date1, Date2))
        cout << "Yes,Date1 is After Date2." << endl;
    else
        cout << "No,Date1 is Not After Date2" << endl;
}