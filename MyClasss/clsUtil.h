#pragma once

#include <iostream>
#include "clsDate.h"
#include "clsString.h"
using namespace std;

class clsUtil
{

public:
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }
    static int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        SpecialChar = 4,
        Mix = 0
    };

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == enCharType::Mix)
            CharType = (enCharType)RandomNumber(1, 3);

        switch (CharType)
        {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122)); // Small letter
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90)); // Capital letter
        case enCharType::Digit:
            return char(RandomNumber(48, 57)); // Digit
        case enCharType::SpecialChar:
            return char(RandomNumber(33, 47)); // Special character
        default:
            return ' ';
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType)
    {
        return GenerateWord(CharType, 4) + "-" + GenerateWord(CharType, 4) + "-" + GenerateWord(CharType, 4) + "-" + GenerateWord(CharType, 4);
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "]: " << GenerateKey(CharType) << endl;
        }
    }

    static void FillArrayWithKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey(CharType);
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int FromNumber, int ToNumber)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = RandomNumber(FromNumber, ToNumber);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLenth)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateWord(CharType, WordLenth);
        }
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey(CharType);
        }
    }

    static void PrintStringArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "]: " << arr[i] << endl;
        }
    }

    static void Swap(clsDate &Date1, clsDate &Date2)
    {
        clsDate tDate = Date2;
        Date2 = Date1;
        Date1 = tDate;
    }

    static void Swap(int &Date1, int &Date2)
    {
        int tDate = Date2;
        Date2 = Date1;
        Date1 = tDate;
    }

    static void Swap(double &Date1, double &Date2)
    {
        double tDate = Date2;
        Date2 = Date1;
        Date1 = tDate;
    }

    static void Swap(bool &Date1, bool &Date2)
    {
        bool tDate = Date2;
        Date2 = Date1;
        Date1 = tDate;
    }

    static void Swap(char &Date1, char &Date2)
    {
        char tDate = Date2;
        Date2 = Date1;
        Date1 = tDate;
    }

    static void Swap(string &Date1, string &Date2)
    {
        string tDate = Date2;
        Date2 = Date1;
        Date1 = tDate;
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        Srand();
        for (int i = 0; i < arrLength - 1; i++)
        {
            int RandomIndex = RandomNumber(0, arrLength - 1);
            Swap(arr[i], arr[RandomIndex]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        Srand();
        for (int i = 0; i < arrLength - 1; i++)
        {
            int RandomIndex = RandomNumber(0, arrLength - 1);
            Swap(arr[i], arr[RandomIndex]);
        }
    }

    static string Tabs(short Length)
    {
        string Tabs = "";
        for (short i = 0; i < Length; i++)
        {
            Tabs += "    ";
        }
        return Tabs;
    }

    static string EncryptText(string Text, short EncryptIOnKey)
    {
        return clsString::Encrypt(Text, EncryptIOnKey);
    }

    static string DecryptText(string Text, short EncryptIOnKey)
    {
        return clsString::Decrypt(Text, EncryptIOnKey);
    }
};