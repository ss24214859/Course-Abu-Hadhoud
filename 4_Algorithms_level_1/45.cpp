#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum  enMonthOfYear{January=1,Febraury=2,March=3,April=4,May=5,June=6,July=7,August=8,Septamber=9,October=10,November=11,December=12};
int ReadNumberRang(int from,int to,string massge)
{
    int num=from;
    do
    {
    if(num<from || num>to)
    cout<<"\nWrong Number PLese Try Again :-( \n\n";
    
    cout<<massge;
    cin>>num;
    } while (num<from || num>to);

    return num;
}

enMonthOfYear ReadMonthOfYear()
{
    return (enMonthOfYear) ReadNumberRang(1,12,"enter Number Of Month in Year ? ");
}

string GetMonthOfYear(enMonthOfYear MonthOfYear)
{
    switch (MonthOfYear)
    {
        case enMonthOfYear::April:
        return "April";
        case enMonthOfYear::January:
        return "January";
        case enMonthOfYear::Febraury:
        return "Febraury";
        case enMonthOfYear::March:
        return "March";
        case enMonthOfYear::May:
        return "May";
        case enMonthOfYear::July:
        return "July";
        case enMonthOfYear::August:
        return "August";
        case enMonthOfYear::Septamber:
        return "Septamber";
        case enMonthOfYear::October:
        return "October";
        case enMonthOfYear::November:
        return "November";
        case enMonthOfYear::June:
        return "June";
        default:
        return "December";                
    }
}
int main()
{
    cout<<"Its "<<GetMonthOfYear(ReadMonthOfYear())<<":-)";
}
