#pragma once

#include <iostream>
#include <limits>
#include "MathLip.h"
namespace Read
{
    using namespace std;
    int ReadNumber(string);
    int ReadPosNum(string);
    int ReadIntNumberBetween(int, int, string, string);
    bool ReadYesOrNo(string);

}

namespace Read
{
    using namespace std;
    string ReadLine(string Massage = "")
    {
        string Line;
        cout << Massage;
        getline(cin >> ws, Line);
        return Line;
    }

    string ReadString(string Massage = "")
    {
        string String;
        cout << Massage;
        cin >> String;
        return String;
    }

    int ReadNumber(string Message = "")
    {
        int Number = 0;
        do
        {
            cout << Message;
            cin >> Number;
            if (cin.fail())
            {
                cout << "Error! This is Not Number.Try again";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
                break;

        } while (true);

        return Number;
    }

    int ReadPosNum(string Message = "")
    {
        int Number = 0;
        do
        {
            Number = ReadNumber(Message);
        } while (Number <= 0);

        return Number;
    }

    int ReadIntNumberBetween(int Min, int Max, string Message, string ErrorMessage = "Invalid Number")
    {
        int Number = 0;
        do
        {
            Number = ReadNumber(Message);
            if (Number < Min || Number > Max)
                cout << ErrorMessage;
        } while (Number < Min || Number > Max);

        return Number;
    }

    bool ReadYesOrNo(string massage)
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

    int ReadNumberMultipleOfX(int X, string Massage = "")
    {
        int Number = 0;
        do
        {
            if (Massage != "")
                cout << Massage << X << "'s ? ";

            Number = ReadPosNum();
        } while (!Math::IsNumberMultipleOfX(Number, X));
        return Number;
    }

}