#include <iostream>
#include "../MyLiberary/DateLip.h"
#include "../MyLiberary/ReadLip.h"
using namespace std;
using namespace Date;
int main()
{
     string DateString = Read::ReadLine("Enter Date dd/mm/yyyy? ");

     stDate Date1 = StringToDate(DateString);
     cout << "Day : " << Date1.Day << endl;
     cout << "Month : " << Date1.Month << endl;
     cout << "Year : " << Date1.Year << endl;
     cout << "\n You Entered : " << DateToString(Date1) << endl;
}