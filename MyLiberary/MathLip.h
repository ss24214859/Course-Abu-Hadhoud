#pragma once

#include <iostream>
#include <cmath>

namespace Math
{
    using namespace std;
    float MyABS(float Number);
    float GetFracTionPart(float Number);
    bool IsPrimeNumber(int Number);
    bool IsPerfectNumber(int Number);
    bool IsNumberMultipleOfX(int Num, int X);
    int SumOfDigits(int Number);
    int ReverseNumber(int Number);
    bool IsPalindromeNumber(int Number);
    int CountDigitFrequency(short Digit, int Number);
    void PrintDigitsInReverseOrder(int Number);
    void PrintDigits(int Number);
    void PrintAllDigitsFrequency(int Number);
    int MyRound(float Number);
    int MyFloor(float Number);
    int MyCeil(float Number);
    float MySqrt(float Number);
} // namespace Math

namespace Math
{
    using namespace std;
    float MyABS(float Number)
    {
        return (Number > 0) ? Number : -Number;
    }

    float GetFracTionPart(float Number)
    {
        return Number - (int)Number;
    }

    bool IsPrimeNumber(int Number)
    {
        if (Number <= 1)
            return false;
        for (int i = 2; i <= Number / 2; i++)
        {
            if (Number % i == 0)
                return false;
        }
        return true;
    }

    bool IsNumberMultipleOfX(int Num, int X)
    {
        return (Num % 5) == 0;
    }

    bool IsPerfectNumber(int Number)
    {
        int Sum = 0;
        for (int i = 1; i < Number; i++)
        {
            if (Number % i == 0)
                Sum += i;
        }
        return Number == Sum;
    }

    bool IsPalindromeNumber(int Number)
    {
        int OriginalNumber = Number;
        int ReversedNumber = 0;
        while (Number > 0)
        {
            int Remainder = Number % 10;
            Number = Number / 10;
            ReversedNumber = ReversedNumber * 10 + Remainder;
        }
        return OriginalNumber == ReversedNumber;
    }

    int MyRound(float Number)
    {
        int IntPart = (int)Number;
        float FractIOnPart = GetFracTionPart(Number);
        if (FractIOnPart >= 0.5)
            return (Number > 0) ? IntPart + 1 : IntPart - 1;
        else
            return IntPart;
    }

    int MyFloor(float Number)
    {
        return (int)Number;
    }

    int MyCeil(float Number)
    {
        return (int)Number + ((Number > 0 && GetFracTionPart(Number) > 0) ? 1 : 0);
    }

    float MySqrt(float Number)
    {
        return sqrt(Number);
    }

}