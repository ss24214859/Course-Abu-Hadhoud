#include <iostream>
#include "../MyLiberary/DateLip.h"
#include "../MyLiberary/ReadLip.h"
using namespace std;
using namespace Date;
int main()
{
    cout << "\nEnter Date to Chack\n"
         << endl;
    stDate Date1 = {Read::ReadNumber("Enter a Day:"), Read::ReadNumber("Enter a Month:"), Read::ReadNumber("Enter a Year:")};
    if (IsValideDate(Date1))
        cout << "Yes,Date Is a Valide Date." << endl;
    else
        cout << "No,Date is Not a Valide Date." << endl;
}