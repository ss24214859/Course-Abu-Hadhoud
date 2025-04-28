#pragma once

#include <iostream>

namespace Read
{
    using namespace std;
    int ReadNumber(string);
    int ReadPosNum(string);
    int ReadNumberInRang(int, int, string, string);
    bool ReadYesOrNo(string);

}

namespace Read
{
    using namespace std;
    int ReadNumber(string Message)
    {
        int Number = 0;
        cout << Message;
        cin >> Number;
        return Number;
    }

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

    int ReadPosNum(string Message)
    {
        int Number = 0;
        do
        {
            Number = ReadNumber(Message);
        } while (Number <= 0);

        return Number;
    }

    int ReadNumberInRang(int Min, int Max, string Message, string ErrorMessage = "INvalid Number")
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

}