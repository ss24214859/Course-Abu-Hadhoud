#pragma once

#include <iostream>
#include "clsDate.h"
#include "clsperiod.h"
#include "clsUtil.h"

using namespace std;

template <typename T>
class clsInputValidate
{

public:
    static bool IsNumberBetween(T Num, T from, T to)
    {
        return (!(Num < from || Num > to)) ? true : false;
    }

    static bool IsDateBetween(clsDate Date, clsDate from, clsDate to)
    {
        if (clsDate::CompareDates(from, to) == clsDate::After)
            clsUtil::Swap(from, to);

        return clsPeriod::IsDateInPeriod(clsPeriod(from, to), Date);
    }

    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValideDate(Date);
    }

    static string ReadString(string Massage = "")
    {
        cout << Massage << endl;
        string S1;
        getline(cin >> ws, S1);
        return S1;
    }


    static T ReadNumber(string Message, string Errormassage = "Error! This is Not Number.Try again ")
    {
        T Number = 0;
        cout << Message;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Errormassage;
        }
        return Number;
    }

    static T ReadPosNum(string Message)
    {
        T Number = 0;
        do
        {
            Number = ReadNumber(Message);
        } while (Number <= 0);

        return Number;
    }

    static T ReadNumberBetween(T Min, T Max, string Message, string ErrorMessage = "Invalid Number")
    {
        T Number = 0;
        Number = ReadNumber(Message);
        while (!IsNumberBetween(Number, Min, Max))
        {
            cout << ErrorMessage << endl;
            Number = ReadNumber("");
        }
        return Number;
    }

    static bool ReadYesOrNo(string massage)
    {
        char c = 'h';
        while (c != 'y' && c != 'n' && c != 'Y' && c != 'N')
        {
            cout << massage;
            cin >> c;

            if (c == 'y' || c == 'Y')
                return true;
            else if (c == 'n' || c == 'N')
                return false;
        }
        return 0;
    }

    static T ReadNumberMultipleOfX(T X, string Massage)
    {
        T Number = 0;
        do
        {
            if (Massage != "")
                cout << Massage << X << "'s ? ";

            Number = ReadPosNum(Massage);
        } while (!(Number % X == 0));
        return Number;
    }

    static clsDate ReadDate()
    {
        clsDate Date;
        Date.SetYear(clsInputValidate::ReadPosNum("Enter a _Year ?"));
        Date.SetMonth(clsInputValidate::ReadNumberBetween(1, 12, "Enter a _Month ?", "Wrong _Month :-(\n"));
        Date.SetDay(clsInputValidate::ReadNumberBetween(1, clsDate::DaysInMonth(Date.Month(), Date.Year()), "Enter a _Day ?", "This _Day is not exisit in this _Month :-( \n"));
        return Date;
    }
};