#pragma once

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class clsRead
{
public:
    static string ReadLine(string Massage = "")
    {
        string Line;
        cout << Massage;
        getline(cin >> ws, Line);
        return Line;
    }

    static string ReadString(string Massage = "")
    {
        string String;
        cout << Massage;
        cin >> String;
        return String;
    }

    static int ReadNumber(string Message = "")
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

    static int ReadPosNum(string Message = "")
    {
        int Number = 0;
        do
        {
            Number = ReadNumber(Message);
        } while (Number <= 0);

        return Number;
    }

    static int ReadNumberInRang(int Min, int Max, string Message, string ErrorMessage = "Invalid Number")
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

    static int ReadNumberMultipleOfX(int X, string Massage = "")
    {
        int Number = 0;
        do
        {
            if (Massage != "")
                cout << Massage << X << "'s ? ";

            Number = ReadPosNum();
        } while (!(Number % X == 0));
        return Number;
    }
};