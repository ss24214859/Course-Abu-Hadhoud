#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ReadPositiveNumber(string massge)
{
    int num;
    do
    {
    cout<<massge;
    cin>>num;
    } while (num<0);

    return num;
}

struct stTaskDuration
{
int seconds,minutes,hours,days;
};

stTaskDuration ReadTaskDuration()
{
    stTaskDuration TaskDuration;
    TaskDuration.days=ReadPositiveNumber("Enter Number Of days? ");
    TaskDuration.hours=ReadPositiveNumber("Enter Number Of hours? ");
    TaskDuration.minutes=ReadPositiveNumber("Enter Number Of minutes? ");
    TaskDuration.seconds=ReadPositiveNumber("Enter Number Of Seconds? ");
    return TaskDuration;
}

int CalculatTaskDurationInSecounds(stTaskDuration TaskDuration)
{
    int DurationInSeconds=0;
    DurationInSeconds=TaskDuration.days*24*60*60;
    DurationInSeconds+=TaskDuration.hours*60*60;
    DurationInSeconds+=TaskDuration.minutes*60;
    DurationInSeconds+=TaskDuration.seconds;

    return DurationInSeconds;
}

int main()
{
    cout<<endl<<"the total Task Duration In Seconds = "<<CalculatTaskDurationInSecounds(ReadTaskDuration());
}