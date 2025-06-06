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

bool IsleapYear(short Year)
{
    return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
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

bool IsDate1BeforeDate2(stDate Date1,stDate Date2)
{
    return ( (Date1.Year<Date2.Year)? true : (Date1.Year != Date2.Year)? false : ( (Date1.Month<Date2.Month)? true : (Date1.Month!=Date2.Month)? false : ( (Date1.Day<Date2.Day)? true : false ) ) );
}

bool IsLastDayInMonth(stDate Date)
{
    return (DaysInMonth(Date.Month,Date.Year)==Date.Day);
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12 );
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if(IsLastDayInMonth(Date))
    {
        if(IsLastMonthInYear(Date.Month))
        {
            Date.Year++;
            Date.Month=1;
        }
        else
        {
            Date.Month++;
        }

        Date.Day=1;
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

int GetDiffrenceInDays(stDate Date1,stDate Date2,bool IsIncludingEndDay=false)
{
    int Days=0;
    while(IsDate1BeforeDate2(Date1,Date2))
    {
        Date1=IncreaseDateByOneDay(Date1);
        Days++;
    }
    return ((!IsIncludingEndDay)? Days : Days+1);
}

int main()
{
    cout<<"Enter Date1 :\n";
    stDate Date1=ReadDate();
    stDate Date2;
    bool NotValid=0;
    do
    {
    cout<<"\nEnter Date2 :\n";
    Date2=ReadDate();
    NotValid=!IsDate1BeforeDate2(Date1,Date2);

    if(NotValid)
        cout<<"\n\nDate2 is Not after Date1 Try Again :-("<<endl;

    } while(NotValid);

    cout<<"Diffrence Is : "<< GetDiffrenceInDays(Date1,Date2)<<"Days" <<endl;
    cout<<"Diffrence (Including End Day) Is : "<< GetDiffrenceInDays(Date1,Date2,true)<<"Days" <<endl;

}
