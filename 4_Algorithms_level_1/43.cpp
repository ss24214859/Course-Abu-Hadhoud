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


stTaskDuration SecondsToTaskDuration(int Seconds)
{
    stTaskDuration TaskDuration;


    TaskDuration.days=Seconds/(60*60*24);
    int remainder=Seconds%(60*60*24);
    TaskDuration.hours=remainder/(60*60);
    remainder=remainder%(60*60);
    TaskDuration.minutes=remainder/60;
    remainder%=60;
    TaskDuration.seconds=remainder;

    return  TaskDuration ;
}
void PrintTaskDuration(stTaskDuration TaskDuration)
{
    cout<<"TaskDuration"<<TaskDuration.days<<":"<<TaskDuration.hours<<":"<<TaskDuration.minutes<<":"<<TaskDuration.seconds<<endl;
}
int main()
{
    int Seconds= ReadPositiveNumber("Enter Total Seconds? ");

    PrintTaskDuration(SecondsToTaskDuration(Seconds));
}