#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum  enDayOfWeek{sunday=1,monday=2,tuseday=3,wednesday=4,thursday=5,friday=6,sturday=7};
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

enDayOfWeek ReadDayOfWeek()
{
    return (enDayOfWeek) ReadNumberRang(1,7,"enter Number Of Day in week ? ");
}

string GetDayOfWeek(enDayOfWeek DayOfWeek)
{
    switch (DayOfWeek)
    {
        case enDayOfWeek::friday:
        return "Friday";
        case enDayOfWeek::sturday:
        return "Sturday";
        case enDayOfWeek::sunday:
        return "Sunday";
        case enDayOfWeek::monday:
        return "Monday";
        case enDayOfWeek::thursday:
        return "Thursday";
        case enDayOfWeek::tuseday:
        return "Tuseday";
        default:
        return "Wednesday";                
    }
}
int main()
{
    cout<<"Its "<<GetDayOfWeek(ReadDayOfWeek())<<":-)";
}