#pragma once

#include <iostream>

namespace Pattern
{
    using namespace std;
    void PrintInvertedNumberPattern(int Number);
    void PrintNumberPattern(int Number);
    void PrintInvertedLetterPattern(int Number);
    void PrintLetterPattern(int Number);
}

namespace Pattern
{
    void PrintLineByChar(int width, char ch = '_')
    {

        for (int i = 0; i < width; i++)
            cout << ch;

        cout << "\n";
    }

    using namespace std;
    void PrintInvertedNumberPattern(int Number)
    {
        for (int i = Number; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    void PrintNumberPattern(int Number)
    {
        for (int i = 1; i <= Number; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    void PrintInvertedLetterPattern(int Number)
    {
        for (int i = 65 + Number - 1; i >= 65; i--)
        {
            for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

    void PrintLetterPattern(int Number)
    {
        for (int i = 65; i <= 65 + Number - 1; i++)
        {
            for (int j = 1; j <= i - 65 + 1; j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

}
