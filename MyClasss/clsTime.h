#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include "clsString.h"
using namespace std;

class clsTime
{
private:
    short _Hour;
    short _Minute;
    short _Second;

public:
    // Constructors
    clsTime()
    {
        time_t t = time(nullptr);
        tm now;
        // Get the current local time
        localtime_s(&now, &t);
        _Hour = now.tm_hour;
        _Minute = now.tm_min;
        _Second = now.tm_sec;
    }
    clsTime(short Hour, short Minute, short Second)
    {
        _Hour = Hour;
        _Minute = Minute;
        _Second = Second;
    }
    clsTime(string TimeStr)
    {
        *this = StringToTime(TimeStr);
    }

    // Setters & Getters
    void SetHour(short Hour) { _Hour = Hour; }
    short Hour() const { return _Hour; }

    void SetMinute(short Minute) { _Minute = Minute; }
    short Minute() const { return _Minute; }

    void SetSecond(short Second) { _Second = Second; }
    short Second() const { return _Second; }

    // Static Methods
    static bool IsValidTime(short Hour, short Minute, short Second)
    {
        return (Hour >= 0 && Hour < 24 && Minute >= 0 && Minute < 60 && Second >= 0 && Second < 60);
    }

    bool IsValidTime() const
    {
        return IsValidTime(_Hour, _Minute, _Second);
    }

    static string TimeToString(clsTime Time)
    {
        ostringstream timeStr;
        timeStr << setfill('0')
                << setw(2) << to_string(Time._Hour) << ":"
                << setw(2) << to_string(Time._Minute) << ":"
                << setw(2) << to_string(Time._Second);
        return timeStr.str();
    }
    string TimeToString() const
    {
        return TimeToString(*this);
    }

    static clsTime StringToTime(string TimeStr)
    {
        vector<string> vTimeStr = clsString::Split(TimeStr, ":");
        clsTime time(stoi(vTimeStr[0]),
                     stoi(vTimeStr[1]),
                     stoi(vTimeStr[2]));
        return time;
    }

    static clsTime GetSystemTime()
    {
        return clsTime();
    }

    static string TimeFromMinutesTostring(int Minutes)
    {
        if (Minutes < 60)
            return to_string(Minutes) + " Minutes";

        short hours = 0;
        while (Minutes >= 60)
        {
            hours++;
            Minutes -= 60;
        }
        if (Minutes == 0)
            return to_string(hours) + " Hours";
        else
            return to_string(hours) + " Hours And " + to_string(Minutes) + " Minutes";
    }
};