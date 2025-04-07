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

short DaysInMonth(short Month ,short Year )
{
    if(Month<1 ||Month>12)
    return 0;

    short arrDaysOfMonths[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    return (Month == 2 )? ( (IsleapYear(Year))? 29 : 28 ) : arrDaysOfMonths[Month-1] ;
}

struct stDate
{
    short Day,
    Month,
    Year;
};

short TotalDaysFromBeginningYear(int Year,short Month,short Day)
{
    short TotalDays=Day;

    for(short i=Month-1;i>=1;i--)
        TotalDays=TotalDays+DaysInMonth(i,Year);

    return TotalDays;
}


stDate ReadDate()
{
    stDate Date;
    Date.Year = ReadPositiveNumber("Enter a Year ?");
    Date.Month = ReadPositiveNumber("Enter a Month ?");
    Date.Day = ReadPositiveNumber("Enter a Day ?");
    return Date;
}

bool IsDate1EqualDate2(stDate Date1,stDate Date2)
{
    return (Date1.Year != Date2.Year)? false : (Date1.Month != Date2.Month)? false : (Date1.Day != Date2.Day)? false : true ; // 1 
}

int main()
{
    cout<<"Enter Date1 :\n";
    stDate Date1=ReadDate();
    cout<<"\nEnter Date2 :\n";
    stDate Date2=ReadDate();

    cout<<((IsDate1EqualDate2(Date1,Date2))? "yes:Date1 is Equal to Date2." : "No: Date1 is Not Equal to Date2.");
}
