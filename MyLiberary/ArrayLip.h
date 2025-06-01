#pragma once

#include <iostream>
#include "MathLip.h"

namespace Arr
{
    using namespace std;
    void ReadArray(int arr[100], int &arrLength);
    void PrintArray(int arr[100], int arrLength);
    int TimesRepeated(int Number, int arr[100], int arrLength);
    void FillArrayWithRandomNumbers(int arr[100], int &arrLength);
    int MaxNumberInArray(int arr[100], int arrLength);
    int MinNumberInArray(int arr[100], int arrLength);
    int SumArray(int arr[100], int arrLength);
    float ArrayAverage(int arr[100], int arrLength);
    void CopyArray(int arrSource[100], int arrDestinatIOn[100], int arrLength);
    void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int &arr2Length);
    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength);
    void ShuffleArray(int arr[100], int arrLength);
    void CopyArrayInReverseOrder(int arrSource[100], int arrDestinatIOn[100], int arrLength);
    short FindNumberPositIOnInArray(int Number, int arr[100], int arrLength);
    void PrintNumberPositIOn(int Number, int arr[100], int arrLength);
    bool IsNumberInArray(int Number, int arr[100], int arrLength);
    void PrintFoundOrNotFound(int Number, int arr[100], int arrLength);
    void AddArrayElement(int Number, int arr[100], int &arrLength);
    void InputUserNumbersInArray(int arr[100], int &arrLength);
    void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestinatIOn[100], int arrLength, int &arrDestinatIOnLength);
    void CopyOddNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int &arrDestinatIOnLength);
    void CopyPrimeNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int &arrDestinatIOnLength);
    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestinatIOn[100], int SourceLength, int &DestinatIOnLength);
    bool IsPalindromeArray(int arr[100], int Length);
    int OddCount(int arr[100], int arrLength);
    int EvenCount(int arr[100], int arrLength);
    int PositiveCount(int arr[100], int arrLength);
    int NegativeCount(int arr[100], int arrLength);
}

// ImplementatIOns of Arr FunctIOns
namespace Arr
{

    using namespace std;

    void ReadArray(int arr[100], int &arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "]: ";
            cin >> arr[i];
        }
    }

    void PrintArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int TimesRepeated(int Number, int arr[100], int arrLength)
    {
        int Count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                Count++;
        }
        return Count;
    }

    void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
    {
        cout << "Enter number of elements: ";
        cin >> arrLength;
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = rand() % 100 + 1; // Random numbers between 1 and 100
        }
    }

    int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = arr[0];
        for (int i = 1; i < arrLength; i++)
        {
            if (arr[i] > Max)
                Max = arr[i];
        }
        return Max;
    }

    int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = arr[0];
        for (int i = 1; i < arrLength; i++)
        {
            if (arr[i] < Min)
                Min = arr[i];
        }
        return Min;
    }

    int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }
        return Sum;
    }

    float ArrayAverage(int arr[100], int arrLength)
    {
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    void CopyArray(int arrSource[100], int arrDestinatIOn[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrDestinatIOn[i] = arrSource[i];
        }
    }

    void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int &arr2Length)
    {
        arr2Length = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (Math::IsPrimeNumber(arrSource[i]))
            {
                arrDestinatIOn[arr2Length] = arrSource[i];
                arr2Length++;
            }
        }
    }

    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)//To Sum the values in 2 array in one array.
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }

    void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            int RandomIndex = rand() % arrLength;
            swap(arr[i], arr[RandomIndex]);
        }
    }

    void CopyArrayInReverseOrder(int arrSource[100], int arrDestinatIOn[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrDestinatIOn[i] = arrSource[arrLength - 1 - i];
        }
    }

    short FindNumberPositIOnInArray(int Number, int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i;
        }
        return -1;
    }

    void PrintNumberPositIOn(int Number, int arr[100], int arrLength)
    {
        short PositIOn = FindNumberPositIOnInArray(Number, arr, arrLength);
        if (PositIOn == -1)
        {
            cout << "Number not found." << endl;
        }
        else
        {
            cout << "Number found at positIOn: " << PositIOn + 1 << endl;
        }
    }

    bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return FindNumberPositIOnInArray(Number, arr, arrLength) != -1;
    }

    void PrintFoundOrNotFound(int Number, int arr[100], int arrLength)
    {
        if (IsNumberInArray(Number, arr, arrLength))
        {
            cout << "Number found." << endl;
        }
        else
        {
            cout << "Number not found." << endl;
        }
    }

    void AddArrayElement(int Number, int arr[100], int &arrLength)
    {
        arr[arrLength] = Number;
        arrLength++;
    }

    void InputUserNumbersInArray(int arr[100], int &arrLength)
    {
        bool AddMore = true;
        do
        {
            int Number;
            cout << "Enter a number: ";
            cin >> Number;
            AddArrayElement(Number, arr, arrLength);
            cout << "Do you want to add more numbers? [0]: No, [1]: Yes: ";
            cin >> AddMore;
        } while (AddMore);
    }

    void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestinatIOn[100], int arrLength, int &arrDestinatIOnLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            AddArrayElement(arrSource[i], arrDestinatIOn, arrDestinatIOnLength);
        }
    }

    void CopyOddNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int &arrDestinatIOnLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arrSource[i] % 2 != 0)
            {
                AddArrayElement(arrSource[i], arrDestinatIOn, arrDestinatIOnLength);
            }
        }
    }

    void CopyPrimeNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int &arrDestinatIOnLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (Math::IsPrimeNumber(arrSource[i]))
            {
                AddArrayElement(arrSource[i], arrDestinatIOn, arrDestinatIOnLength);
            }
        }
    }

    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestinatIOn[100], int SourceLength, int &DestinatIOnLength)
    {
        for (int i = 0; i < SourceLength; i++)
        {
            if (!IsNumberInArray(arrSource[i], arrDestinatIOn, DestinatIOnLength))
            {
                AddArrayElement(arrSource[i], arrDestinatIOn, DestinatIOnLength);
            }
        }
    }

    bool IsPalindromeArray(int arr[100], int Length)
    {
        for (int i = 0; i < Length / 2; i++)
        {
            if (arr[i] != arr[Length - 1 - i])
                return false;
        }
        return true;
    }

    int OddCount(int arr[100], int arrLength)
    {
        int Count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0)
                Count++;
        }
        return Count;
    }

    int EvenCount(int arr[100], int arrLength)
    {
        int Count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0)
                Count++;
        }
        return Count;
    }

    int PositiveCount(int arr[100], int arrLength)
    {
        int Count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0)
                Count++;
        }
        return Count;
    }

    int NegativeCount(int arr[100], int arrLength)
    {
        int Count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0)
                Count++;
        }
        return Count;
    }

}
