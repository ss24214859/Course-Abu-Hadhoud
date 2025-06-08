#pragma once

#include <iostream>
#include "clsDate.h"
#include "clsperiod.h"

using namespace std;

class clsInputValidate
{
public:
    static bool IsNumberBetween(int Num, int from, int to)
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

    static int ReadIntNumber(string Message, string Errormassage = "Error! This is Not Number.Try again ")
    {
        int Number = 0;
        cout << Message;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Errormassage;
        }
        return Number;
    }

    static double ReadDblNumber(string Message, string Errormassage = "Error! This is Not Number.Try again ")
    {
        double Number = 0;
        cout << Message;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Errormassage;
        }
        return Number;
    }

    static int ReadPosNum(string Message)
    {
        int Number = 0;
        do
        {
            Number = ReadIntNumber(Message);
        } while (Number <= 0);

        return Number;
    }

    static int ReadIntNumberBetween(int Min, int Max, string Message, string ErrorMessage = "Invalid Number")
    {
        int Number = 0;
        Number = ReadIntNumber(Message);
        while (!IsNumberBetween(Number, Min, Max))
        {
            cout << ErrorMessage << endl;
            Number = ReadIntNumber("");
        };
        return Number;
    }

    static double ReadDblNumberBetween(int Min, int Max, string Message, string ErrorMessage = "Invalid Number")
    {
        double Number = 0;
        Number = ReadDblNumber(Message);
        while (!IsNumberBetween(Number, Min, Max))
        {
            cout << ErrorMessage << endl;
            Number = ReadDblNumber("");
        };
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

    static int ReadNumberMultipleOfX(int X, string Massage)
    {
        int Number = 0;
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
        Date.SetMonth(clsInputValidate::ReadIntNumberBetween(1, 12, "Enter a _Month ?", "Wrong _Month :-(\n"));
        Date.SetDay(clsInputValidate::ReadIntNumberBetween(1, clsDate::DaysInMonth(Date.Month(), Date.Year()), "Enter a _Day ?", "This _Day is not exisit in this _Month :-( \n"));
        return Date;
    }
};