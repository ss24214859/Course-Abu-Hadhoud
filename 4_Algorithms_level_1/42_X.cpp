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

float minutesToSeconds(int min)
{
    return min*60;
}

float hoursToSeconds(int hours)
{
    return hours*60*60;
}

float DaysToSeconds(int Days)
{
    return Days*24*60*60;
}

float CalculatTotalSecond(float Sec, float Min ,float hours,float days)
{
    Min=minutesToSeconds(Min);
    hours=hoursToSeconds(hours);
    days=DaysToSeconds(days);
    return Sec+Min+hours+days;
}

int main()
{
    float Days=ReadPositiveNumber("Enter Number Of days? ");
    float Hours=ReadPositiveNumber("Enter Number Of hours? ");
    float Minutes=ReadPositiveNumber("Enter Number Of minutes? ");
    float Seconds=ReadPositiveNumber("Enter Number Of seconds? ");

    cout<<endl<< "The Total Seconds = "<<CalculatTotalSecond(Seconds,Minutes,Hours,Days)<<endl;

}