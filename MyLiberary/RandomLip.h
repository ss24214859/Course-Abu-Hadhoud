#pragma once

#include <iostream>

namespace Random
{
    using namespace std;
    int RandomNumber(int From, int To);
    char GetRandomCharacter(int CharType);
    string GenerateWord(int CharType, short Length);
    string GenerateKey();
    void GenerateKeys(short NumberOfKeys);
    void FillArrayWithKeys(string arr[100], int arrLength);
    void PrintStringArray(string arr[100], int arrLength);
}

namespace Random
{
    using namespace std;
    void Srand()
    {
        srand((unsigned)time(NULL));
    }
    int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    char GetRandomCharacter(int CharType)
    {
        switch (CharType)
        {
        case 1:
            return char(RandomNumber(97, 122)); // Small letter
        case 2:
            return char(RandomNumber(65, 90)); // Capital letter
        case 3:
            return char(RandomNumber(48, 57)); // Digit
        case 4:
            return char(RandomNumber(33, 47)); // Special character
        default:
            return ' ';
        }
    }

    string GenerateWord(int CharType, short Length)
    {
        string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }

    string GenerateKey()
    {
        return GenerateWord(2, 4) + "-" + GenerateWord(2, 4) + "-" + GenerateWord(2, 4) + "-" + GenerateWord(2, 4);
    }

    void GenerateKeys(short NumberOfKeys)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "]: " << GenerateKey() << endl;
        }
    }

    void FillArrayWithKeys(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey();
        }
    }

    void PrintStringArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "]: " << arr[i] << endl;
        }
    }

}
