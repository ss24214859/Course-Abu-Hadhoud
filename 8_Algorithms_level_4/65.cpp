#include <iostream>
#include "../MyLiberary/DateLip.h"
#include "../MyLiberary/ReadLip.h"
using namespace std;
using namespace Date;

int main()
{
     string DateString = Read::ReadLine("Enter Date dd/mm/yyyy ? ");
     stDate Date = StringToDate(DateString);
     cout << "\n"
          << FormatDate(Date) << endl;
     cout << "\n"
          << FormatDate(Date, "yyyy/mm/dd") << endl;
     cout << "\n"
          << FormatDate(Date, "mm/dd/yyyy") << endl;
     cout << "\n"
          << FormatDate(Date, "mm-dd-yyyy") << endl;
     cout << "\n"
          << FormatDate(Date, "dd-mm-yyyy") << endl;
     cout << "\n"
          << FormatDate(Date, "Days:dd, Months:mm, Years = yyyy") << endl;
}