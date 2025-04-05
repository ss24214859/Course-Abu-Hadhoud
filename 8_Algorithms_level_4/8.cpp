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

short DayOrder(int year , short month, short day)
{
    short a =(14-month)/12;
    int   y = year-a;
    short m = month + (12*a)-2;
    short d = ( day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;
    
    return d;
}
string MonthName(short MonthNumber)
{
    string arr[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    return arr[MonthNumber-1];
}

string DayName(short DayOrder)
{
    string arr[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    return arr[DayOrder];
}

void PrintMonthCleander(int Year , short Month)
{
    short Days=DaysInMonth(Month,Year);
    short dayOrder= DayOrder(Year,Month,1);
    cout<<"______________"<<MonthName(Month)<<"________________\n"<<endl;
    cout<<"Sun  Mon  Tue  Wed  Thu  Fri  Sat"<<endl;
    short NextWeek=0;
    for(short i=0;i<Days+dayOrder;i++)
    {
        if(i>=dayOrder)
        {
            cout<<setw(3)<<i-dayOrder+1<<"  ";
        }
        else
        {
            cout<<"     ";
        }

        NextWeek++;
        if(NextWeek==7)
        {
            cout<<"\n";
            NextWeek=0;
        }
    }
    cout<<"\n__________________________________"<<endl;
}

int main()
{
    short Year = ReadPositiveNumber("Enter a Year ?");
    short Month = ReadPositiveNumber("Enter a Month ?");

    PrintMonthCleander(Year,Month);
}
