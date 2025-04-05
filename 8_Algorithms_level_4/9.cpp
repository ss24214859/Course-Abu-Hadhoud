#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

short ReadPositiveNumber(string massge)
{
    short num;
    do
    {
        cout << massge;
        cin >> num;
    } while (num < 0);

    return num;
}

bool IsleapYear(short Month)
{
    return (Month % 400 == 0) || (Month % 100 != 0 && Month % 4 == 0);
}

short DaysInMonth(short Month, short Year)
{
    if(Month<1 ||Month>12)
    return 0;

    short arrDaysOfMonths[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2 )? ( (IsleapYear(Year))? 29 : 28 ) : arrDaysOfMonths[Month-1] ;
}

short DayOfWeekOrder(int year , short month, short day)
{
    short a =(14-month)/12;
    int   y = year-a;
    short m = month + (12*a)-2;
    //Gregorian
    //0-Sun 1-Mon 2-Tue ....
    return ( day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;
    
}

string MonthShortName(short MonthNumber)
{
    string arr[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    return arr[MonthNumber-1];
}

void PrintMonthCleander(int Year , short Month)
{
    short Days=DaysInMonth(Month,Year);
    short dayOrder= DayOfWeekOrder(Year,Month,1);
    printf("\n  ______________%s________________\n",MonthShortName(Month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short i=0;
    for(i=0;i<dayOrder;i++)
        printf("     ");
    
    for(short j=1;j<Days;j++)
    {
        printf("%5d",j);
        if(++i==7)
        {
            printf("\n");
            i=0;
        }
    }
    
    printf("\n  __________________________________\n");
}

void PrintYearCleander(int Year)
{
    printf("\n  __________________________________\n\n");
    printf("             Cleander - %d " , Year );
    printf("\n  __________________________________\n\n");

    for(short i=1;i<=12;i++)
        PrintMonthCleander(Year,i);
}
int main()
{
    short Year = ReadPositiveNumber("Enter a Year ?");
    PrintYearCleander(Year);
}
