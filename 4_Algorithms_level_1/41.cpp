#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float ReadPositiveNumber(string massge)
{
    float num;
    do
    {
    cout<<massge;
    cin>>num;
    } while (num<0);

    return num;
}

float HoursToDays(float Hours)
{
    return Hours/24;
}
float DaysToWeek(float Days)
{
    return Days/7;
}
float HoursToWeek(float Hours)
{
    return Hours/24/7;
}

int main()
{
    float NumberOfHours = ReadPositiveNumber("Enter Number Of Hours ? ");
    float NumberOfDays = HoursToDays(NumberOfHours);
    float NumberOfWeek = HoursToWeek(NumberOfHours);

    cout<<endl<<"Number Of Hours = "<<NumberOfHours<<endl;
    cout<<"Number Of Days = "<<NumberOfDays<<endl;
    cout<<"Number Of Weeks = "<<NumberOfWeek<<endl;
}