#pragma

#include <IOstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std; // استخدام using namespace std مرة واحدة في البداية

// Forward DeclaratIOns for IO
namespace IO {
    int ReadNumber(string);
    int ReadPositiveNumber(string Message);
    int ReadNumberInRang(int From,int To ,string Message);
    bool ReadYesOrNo(string massage);
    bool IsPrimeNumber(int Number);
    bool IsPerfectNumber(int Number);
    int SumOfDigits(int Number);
    int ReverseNumber(int Number);
    bool IsPalindromeNumber(int Number);
    int CountDigitFrequency(short DigitToCheck, int Number);
    void PrintDigitsInReverseOrder(int Number);
    void PrintDigits(int Number);
    void PrintAllDigitsFrequency(int Number);
}

// Forward DeclaratIOns for Math
namespace Math {
    float MyABS(float Number);
    float GetFractIOnPart(float Number);
    int MyRound(float Number);
    int MyFloor(float Number);
    int MyCeil(float Number);
    float MySqrt(float Number);
}

// Forward DeclaratIOns for Arr
namespace Arr {
    void ReadArray(int arr[100], int& arrLength);
    void PrintArray(int arr[100], int arrLength);
    int TimesRepeated(int Number, int arr[100], int arrLength);
    void FillArrayWithRandomNumbers(int arr[100], int& arrLength);
    int MaxNumberInArray(int arr[100], int arrLength);
    int MinNumberInArray(int arr[100], int arrLength);
    int SumArray(int arr[100], int arrLength);
    float ArrayAverage(int arr[100], int arrLength);
    void CopyArray(int arrSource[100], int arrDestinatIOn[100], int arrLength);
    void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int& arr2Length);
    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength);
    void ShuffleArray(int arr[100], int arrLength);
    void CopyArrayInReverseOrder(int arrSource[100], int arrDestinatIOn[100], int arrLength);
    short FindNumberPositIOnInArray(int Number, int arr[100], int arrLength);
    void PrintNumberPositIOn(int Number, int arr[100], int arrLength);
    bool IsNumberInArray(int Number, int arr[100], int arrLength);
    void PrintFoundOrNotFound(int Number, int arr[100], int arrLength);
    void AddArrayElement(int Number, int arr[100], int& arrLength);
    void InputUserNumbersInArray(int arr[100], int& arrLength);
    void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestinatIOn[100], int arrLength, int& arrDestinatIOnLength);
    void CopyOddNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int& arrDestinatIOnLength);
    void CopyPrimeNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int& arrDestinatIOnLength);
    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestinatIOn[100], int SourceLength, int& DestinatIOnLength);
    bool IsPalindromeArray(int arr[100], int Length);
    int OddCount(int arr[100], int arrLength);
    int EvenCount(int arr[100], int arrLength);
    int PositiveCount(int arr[100], int arrLength);
    int NegativeCount(int arr[100], int arrLength);
}

// Forward DeclaratIOns for String
namespace String {
    string ReadPassword();
    bool GuessPassword(string OriginalPassword);
    string ReadText();
    string EncryptText(string Text, short EncryptIOnKey);
    string DecryptText(string Text, short EncryptIOnKey);
    void PrintWordsFromAAAtoZZZ();
}

// Forward DeclaratIOns for Pattern
namespace Pattern {
    void PrintInvertedNumberPattern(int Number);
    void PrintNumberPattern(int Number);
    void PrintInvertedLetterPattern(int Number);
    void PrintLetterPattern(int Number);
}

// Forward DeclaratIOns for Random
namespace Random {
    int RandomNumber(int From, int To);
    char GetRandomCharacter(int CharType);
    string GenerateWord(int CharType, short Length);
    string GenerateKey();
    void GenerateKeys(short NumberOfKeys);
    void FillArrayWithKeys(string arr[100], int arrLength);
    void PrintStringArray(string arr[100], int arrLength);
}

// ImplementatIOns of vector FunctIOns
namespace vect 
{

}


// ImplementatIOns of FunctIOns
namespace IO {

    int ReadNumber(string Message)
    {

        int Number = 0;
        cout << Message << endl;
        cin >> Number;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

            cout<<"Invalid Number :-( \n"
            <<Message;
            cin>>Number;
            
        } 
        return Number;
    }

    int ReadNumberInRang(int From,int To,string Message)
    {
        int Number;
        do {
            Number = IO::ReadNumber(Message);
        } while (Number < From||Number>To);
        return Number;

    }

    int ReadPositiveNumber(string Message) {
        int Number = 0;
        do {
            Number = IO::ReadNumber(Message);
        } while (Number <= 0);

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

    bool IsPrimeNumber(int Number) {
        if (Number <= 1) return false;
        for (int i = 2; i <= Number / 2; i++) {
            if (Number % i == 0) return false;
        }
        return true;
    }

    bool IsPerfectNumber(int Number) {
        int Sum = 0;
        for (int i = 1; i < Number; i++) {
            if (Number % i == 0) Sum += i;
        }
        return Number == Sum;
    }

    int SumOfDigits(int Number) {
        int Sum = 0, Remainder = 0;
        while (Number > 0) {
            Remainder = Number % 10;
            Number = Number / 10;
            Sum += Remainder;
        }
        return Sum;
    }

    int ReverseNumber(int Number) {
        int Remainder = 0, ReversedNumber = 0;
        while (Number > 0) {
            Remainder = Number % 10;
            Number = Number / 10;
            ReversedNumber = ReversedNumber * 10 + Remainder;
        }
        return ReversedNumber;
    }

    bool IsPalindromeNumber(int Number) {
        return Number == ReverseNumber(Number);
    }

    int CountDigitFrequency(short DigitToCheck, int Number) {
        int Frequency = 0, Remainder = 0;
        while (Number > 0) {
            Remainder = Number % 10;
            Number = Number / 10;
            if (Remainder == DigitToCheck) Frequency++;
        }
        return Frequency;
    }

    void PrintDigitsInReverseOrder(int Number) {
        int Remainder = 0;
        while (Number > 0) {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }

    void PrintDigits(int Number) {
        int Remainder = 0;
        while (Number > 0) {
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << endl;
        }
    }

    void PrintAllDigitsFrequency(int Number) {
        cout << endl;
        for (int i = 0; i < 10; i++) {
            short DigitFrequency = CountDigitFrequency(i, Number);
            if (DigitFrequency > 0) {
                cout << "Digit " << i << " Frequency is " << DigitFrequency << " Time(s)." << endl;
            }
        }
    }
}

// ImplementatIOns of Math FunctIOns
namespace Math {
    float MyABS(float Number) {
        return (Number > 0) ? Number : -Number;
    }

    float GetFractIOnPart(float Number) {
        return Number - (int)Number;
    }

    int MyRound(float Number) {
        int IntPart = (int)Number;
        float FractIOnPart = GetFractIOnPart(Number);
        if (FractIOnPart >= 0.5) return (Number > 0) ? IntPart + 1 : IntPart - 1;
        else return IntPart;
    }

    int MyFloor(float Number) {
        return (Number > 0) ? (int)Number : (int)Number - 1;
    }

    int MyCeil(float Number) {
        if (GetFractIOnPart(Number) > 0) return (Number > 0) ? (int)Number + 1 : (int)Number;
        else return (int)Number;
    }

    float MySqrt(float Number) {
        return sqrt(Number);
    }
}

// ImplementatIOns of Arr FunctIOns
namespace Arr {

    void ReadArray(int arr[100], int& arrLength) {
        
        for (int i = 0; i < arrLength; i++) {
            cout << "Element [" << i + 1 << "]: ";
            cin >> arr[i];
        }
    }

    void PrintArray(int arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int TimesRepeated(int Number, int arr[100], int arrLength) {
        int Count = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] == Number) Count++;
        }
        return Count;
    }

    void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {
        cout << "Enter number of elements: ";
        cin >> arrLength;
        for (int i = 0; i < arrLength; i++) {
            arr[i] = rand() % 100 + 1; // Random numbers between 1 and 100
        }
    }

    int MaxNumberInArray(int arr[100], int arrLength) {
        int Max = arr[0];
        for (int i = 1; i < arrLength; i++) {
            if (arr[i] > Max) Max = arr[i];
        }
        return Max;
    }

    int MinNumberInArray(int arr[100], int arrLength) {
        int Min = arr[0];
        for (int i = 1; i < arrLength; i++) {
            if (arr[i] < Min) Min = arr[i];
        }
        return Min;
    }

    int SumArray(int arr[100], int arrLength) {
        int Sum = 0;
        for (int i = 0; i < arrLength; i++) {
            Sum += arr[i];
        }
        return Sum;
    }

    float ArrayAverage(int arr[100], int arrLength) {
        return (float)SumArray(arr, arrLength) / arrLength;
    }

    void CopyArray(int arrSource[100], int arrDestinatIOn[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            arrDestinatIOn[i] = arrSource[i];
        }
    }

    void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int& arr2Length) {
        arr2Length = 0;
        for (int i = 0; i < arrLength; i++) {
            if (IO::IsPrimeNumber(arrSource[i])) {
                arrDestinatIOn[arr2Length] = arrSource[i];
                arr2Length++;
            }
        }
    }

    void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }

    void ShuffleArray(int arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            int RandomIndex = rand() % arrLength;
            swap(arr[i], arr[RandomIndex]);
        }
    }

    void CopyArrayInReverseOrder(int arrSource[100], int arrDestinatIOn[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            arrDestinatIOn[i] = arrSource[arrLength - 1 - i];
        }
    }

    short FindNumberPositIOnInArray(int Number, int arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] == Number) return i;
        }
        return -1;
    }

    void PrintNumberPositIOn(int Number, int arr[100], int arrLength) {
        short PositIOn = FindNumberPositIOnInArray(Number, arr, arrLength);
        if (PositIOn == -1) {
            cout << "Number not found." << endl;
        }
        else {
            cout << "Number found at positIOn: " << PositIOn + 1 << endl;
        }
    }

    bool IsNumberInArray(int Number, int arr[100], int arrLength) {
        return FindNumberPositIOnInArray(Number, arr, arrLength) != -1;
    }

    void PrintFoundOrNotFound(int Number, int arr[100], int arrLength) {
        if (IsNumberInArray(Number, arr, arrLength)) {
            cout << "Number found." << endl;
        }
        else {
            cout << "Number not found." << endl;
        }
    }

    void AddArrayElement(int Number, int arr[100], int& arrLength) {
        arr[arrLength] = Number;
        arrLength++;
    }

    void InputUserNumbersInArray(int arr[100], int& arrLength) {
        bool AddMore = true;
        do {
            int Number;
            cout << "Enter a number: ";
            cin >> Number;
            AddArrayElement(Number, arr, arrLength);
            cout << "Do you want to add more numbers? [0]: No, [1]: Yes: ";
            cin >> AddMore;
        } while (AddMore);
    }

    void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestinatIOn[100], int arrLength, int& arrDestinatIOnLength) {
        for (int i = 0; i < arrLength; i++) {
            AddArrayElement(arrSource[i], arrDestinatIOn, arrDestinatIOnLength);
        }
    }

    void CopyOddNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int& arrDestinatIOnLength) {
        for (int i = 0; i < arrLength; i++) {
            if (arrSource[i] % 2 != 0) {
                AddArrayElement(arrSource[i], arrDestinatIOn, arrDestinatIOnLength);
            }
        }
    }

    void CopyPrimeNumbers(int arrSource[100], int arrDestinatIOn[100], int arrLength, int& arrDestinatIOnLength) {
        for (int i = 0; i < arrLength; i++) {
            if (IO::IsPrimeNumber(arrSource[i])) {
                AddArrayElement(arrSource[i], arrDestinatIOn, arrDestinatIOnLength);
            }
        }
    }

    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestinatIOn[100], int SourceLength, int& DestinatIOnLength) {
        for (int i = 0; i < SourceLength; i++) {
            if (!IsNumberInArray(arrSource[i], arrDestinatIOn, DestinatIOnLength)) {
                AddArrayElement(arrSource[i], arrDestinatIOn, DestinatIOnLength);
            }
        }
    }

    bool IsPalindromeArray(int arr[100], int Length) {
        for (int i = 0; i < Length / 2; i++) {
            if (arr[i] != arr[Length - 1 - i]) return false;
        }
        return true;
    }

    int OddCount(int arr[100], int arrLength) {
        int Count = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] % 2 != 0) Count++;
        }
        return Count;
    }

    int EvenCount(int arr[100], int arrLength) {
        int Count = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] % 2 == 0) Count++;
        }
        return Count;
    }

    int PositiveCount(int arr[100], int arrLength) {
        int Count = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] >= 0) Count++;
        }
        return Count;
    }

    int NegativeCount(int arr[100], int arrLength) {
        int Count = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] < 0) Count++;
        }
        return Count;
    }
}

// ImplementatIOns of String FunctIOns
namespace String {
    string ReadPassword() {
        string Password;
        cout << "Enter a 3-letter password (all capital): ";
        cin >> Password;
        return Password;
    }

    bool GuessPassword(string OriginalPassword) {
        string Word;
        int Counter = 0;
        for (int i = 65; i <= 90; i++) {
            for (int j = 65; j <= 90; j++) {
                for (int k = 65; k <= 90; k++) {
                    Word = string(1, char(i)) + char(j) + char(k);
                    Counter++;
                    cout << "Trial [" << Counter << "]: " << Word << endl;
                    if (Word == OriginalPassword) {
                        cout << "Password found after " << Counter << " trials." << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    string ReadText() {
        string Text;
        cout << "Enter text: ";
        getline(cin, Text);
        return Text;
    }

    string EncryptText(string Text, short EncryptIOnKey) {
        for (int i = 0; i < Text.length(); i++) {
            Text[i] = char((int)Text[i] + EncryptIOnKey);
        }
        return Text;
    }

    string DecryptText(string Text, short EncryptIOnKey) {
        for (int i = 0; i < Text.length(); i++) {
            Text[i] = char((int)Text[i] - EncryptIOnKey);
        }
        return Text;
    }

    void PrintWordsFromAAAtoZZZ() {
        string Word;
        for (int i = 65; i <= 90; i++) {
            for (int j = 65; j <= 90; j++) {
                for (int k = 65; k <= 90; k++) {
                    Word = string(1, char(i)) + char(j) + char(k);
                    cout << Word << endl;
                }
            }
        }
    }
}

// ImplementatIOns of Pattern FunctIOns
namespace Pattern {
    void PrintInvertedNumberPattern(int Number) {
        for (int i = Number; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                cout << i;
            }
            cout << endl;
        }
    }

    void PrintNumberPattern(int Number) {
        for (int i = 1; i <= Number; i++) {
            for (int j = 1; j <= i; j++) {
                cout << i;
            }
            cout << endl;
        }
    }

    void PrintInvertedLetterPattern(int Number) {
        for (int i = 65 + Number - 1; i >= 65; i--) {
            for (int j = 1; j <= Number - (65 + Number - 1 - i); j++) {
                cout << char(i);
            }
            cout << endl;
        }
    }

    void PrintLetterPattern(int Number) {
        for (int i = 65; i <= 65 + Number - 1; i++) {
            for (int j = 1; j <= i - 65 + 1; j++) {
                cout << char(i);
            }
            cout << endl;
        }
    }
}

// ImplementatIOns of Random FunctIOns
namespace Random {
    int RandomNumber(int From, int To) {
        return rand() % (To - From + 1) + From;
    }

    char GetRandomCharacter(int CharType) {
        switch (CharType) {
        case 1: return char(RandomNumber(97, 122)); // Small letter
        case 2: return char(RandomNumber(65, 90));  // Capital letter
        case 3: return char(RandomNumber(33, 47));  // Special character
        case 4: return char(RandomNumber(48, 57));  // Digit
        default: return ' ';
        }
    }

    string GenerateWord(int CharType, short Length) {
        string Word;
        for (int i = 1; i <= Length; i++) {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }

    string GenerateKey() {
        return GenerateWord(2, 4) + "-" + GenerateWord(2, 4) + "-" + GenerateWord(2, 4) + "-" + GenerateWord(2, 4);
    }

    void GenerateKeys(short NumberOfKeys) {
        for (int i = 1; i <= NumberOfKeys; i++) {
            cout << "Key [" << i << "]: " << GenerateKey() << endl;
        }
    }

    void FillArrayWithKeys(string arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            arr[i] = GenerateKey();
        }
    }

    void PrintStringArray(string arr[100], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            cout << "Array[" << i << "]: " << arr[i] << endl;
        }
    }
}

// ImplementatIOns of vector FunctIOns
namespace vect
{

}