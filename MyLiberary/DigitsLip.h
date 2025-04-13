#pragma once

#include <iostream>

namespace Digits
{
    using namespace std;

    void PrintDigitsInReverseOrder(int Number);
    void PrintDigits(int Number);
    void PrintAllDigitsFrequency(int Number);
    int CountDigitFrequency(short Digit, int Number);
    int SumOfDigits(int);
    int ReverseNumber(int);
}

namespace Digits
{
    using namespace std;

    void PrintDigitsInReverseOrder(int Number)
    {
        int Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }

    void PrintDigits(int Number)
    {
        int Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }

    void PrintAllDigitsFrequency(int Number)
    {
        cout << endl;
        for (int i = 0; i < 10; i++)
        {
            short DigitFrequency = CountDigitFrequency(i, Number);
            if (DigitFrequency > 0)
            {
                cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s)." << endl;
            }
        }
    }

    int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int Frequency = 0, Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            if (Remainder == DigitToCheck)
                Frequency++;
        }
        return Frequency;
    }

    int SumOfDigits(int Number)
    {
        int Sum = 0, Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Sum += Remainder;
        }
        return Sum;
    }

    int ReverseNumber(int Number)
    {
        int Remainder = 0, ReversedNumber = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            ReversedNumber = ReversedNumber * 10 + Remainder;
        }
        return ReversedNumber;
    }

}