#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace String
{
    using namespace std;
    string ReadPassword();
    bool GuessPassword(string OriginalPassword);
    string EncryptText(string Text, short EncryptIOnKey);
    string DecryptText(string Text, short EncryptIOnKey);
    void PrintWordsFromAAAtoZZZ();
}

namespace String
{

    using namespace std;
    string ReadPassword()
    {
        string Password;
        cout << "Enter a 3-letter password (all capital): ";
        cin >> Password;
        return Password;
    }

    int StringLength(string s)
    {
        return s.length();
    }

    bool GuessPassword(string OriginalPassword)
    {
        string Word;
        int Counter = 0;
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    Word = string(1, char(i)) + char(j) + char(k);
                    Counter++;
                    cout << "Trial [" << Counter << "]: " << Word << endl;
                    if (Word == OriginalPassword)
                    {
                        cout << "Password found after " << Counter << " trials." << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    string EncryptText(string Text, short EncryptIOnKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptIOnKey);
        }
        return Text;
    }

    string DecryptText(string Text, short EncryptIOnKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptIOnKey);
        }
        return Text;
    }

    void PrintWordsFromAAAtoZZZ()
    {
        string Word;
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    Word = string(1, char(i)) + char(j) + char(k);
                    cout << Word << endl;
                }
            }
        }
    }

    void PrintFirstLetterOfEachWordInString(string Str)
    {
        cout << "Characters of Word : " << endl;
        bool InWord = false;

        for (int i = 0; i < Str.length(); i++)
        {
            if (Str[i] != ' ' && !InWord)
            {
                cout << Str[i] << endl;
                InWord = true;
            }

            if (Str[i] == ' ')
                InWord = false;
        }
    }

    void UppercaseFirstLetterOfEachWordInString(string &S1)
    {
        bool InWord = false;

        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && !InWord)
            {
                S1[i] = toupper(S1[i]);
                InWord = true;
            }
            InWord = S1[i] != ' ';
        }
    }

    string LowerAllString(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    string UpperAllString(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    char InvertCase(char ch)
    {
        return islower(ch) ? toupper(ch) : tolower(ch);
    }

    string InvertLetterCase(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertCase(S1[i]);
        }
        return S1;
    }

    int SmallLettersCount(string S1)
    {
        int small = 0;
        for (int i = 0; i < S1.length(); i++)
            small = islower(S1[i]) ? small + 1 : small;

        return small;
    }

    int CapitalLettersCount(string S1)
    {
        int Capital = 0;
        for (int i = 0; i < S1.length(); i++)
            Capital = isupper(S1[i]) ? Capital + 1 : Capital;
        return Capital;
    }

    int CharacterCountInString(string S1, char ch, bool MatchCase = true)
    {
        int counter = 0;
        if (MatchCase)
        {
            ch = tolower(ch);
            S1 = LowerAllString(S1);
        }

        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] == ch)
                counter++;
        }
        return counter;
    }

    bool isvowel(char ch)
    {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u');
    }

    int VowelCount(string S1)
    {
        int counter = 0;
        for (int i = 0; i < S1.length(); i++)
            counter = (isvowel(S1[i])) ? counter + 1 : counter;

        return counter;
    }

    void PrintVowelLetters(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            if (isvowel(S1[i]))
                cout << S1[i] << "\t";
        }
    }

    void PrintEatchWordInString(string S1, string delimiter = " ")
    {
        short pos = 0;
        string Word;

        while ((pos = S1.find(delimiter)) != std::string::npos)
        {
            Word = S1.substr(0, pos);

            if (Word != "")
                cout << Word << endl;

            S1.erase(0, pos + delimiter.length());
        }
        if (S1 != "")
            cout << S1 << endl;
    }

    int WordsCounter(string S1, string delimiter = " ")
    {
        int counter = 0;
        short pos = 0;
        string Word;

        while ((pos = S1.find(delimiter)) != std::string::npos)
        {
            Word = S1.substr(0, pos);

            if (Word != "")
                counter++;

            S1.erase(0, pos + delimiter.length());
        }
        if (S1 != "")
            counter++;

        return counter;
    }

    vector<string> SpletStringInVector(string S1, string Delimeter) //
    {
        vector<string> vStrWords;
        size_t pos = 0;
        string Word;

        while ((pos = S1.find(Delimeter)) != string::npos)
        {
            Word = S1.substr(0, pos);
            if (Word != "")
                vStrWords.push_back(Word);

            S1.erase(0, pos + Delimeter.length());
        }
        if (S1 != "")
            vStrWords.push_back(S1);

        return vStrWords;
    }

    string JoinString(vector<string> vString, string Delimiter)
    {
        string String = "";
        for (string &Str : vString)
        {
            String += Str + Delimiter;
        }

        return String.substr(0, String.length() - Delimiter.length());
    }

    string JoinStringWithReverseWords(vector<string> vString, string Delimiter)
    {
        string String = "";
        for (int i = vString.size() - 1; i >= 0; i--)
        {
            String += vString[i] + Delimiter;
        }
        return String.substr(0, String.length() - Delimiter.length());
    }

    string Trimleft(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
                return S1.substr(i, S1.length());
        }
        return "";
    }

    string TrimRight(string S1)
    {
        for (int i = S1.length() - 1; i > 0; i--)
        {
            if (S1[i] != ' ')
                return S1.substr(0, i);
        }
        return "";
    }

    string Trim(string S1)
    {
        return TrimRight(Trimleft(S1));
    }

    string ReverseString(string S1)
    {
        string Reverse = "";
        for (int i = 0; i < S1.length(); i++)
        {
            Reverse.push_back(S1[S1.length() - 1 - i]);
        }
        return Reverse;
    }

    string ReverseWordsInString(string S1)
    {
        string deli = " ";
        vector<string> vWords = SpletStringInVector(S1, deli);
        string S2 = "";
        vector<string>::iterator iter = vWords.end();
        while (iter != vWords.begin())
        {
            iter--;
            S2 += *iter + deli;
        }
        return S2.substr(0, S2.length() - deli.length());
    }

    string ReplaceWordInStringByDelimeter(string S1, string StrInS1, string StrToReplace, string deli = " ", bool IsMatchCase = true)
    {
        string tempS1 = S1;
        if (!IsMatchCase)
        {
            tempS1 = LowerAllString(S1);
            StrInS1 = LowerAllString(StrInS1);
        }
        short pos = tempS1.find(StrInS1);
        while ((pos = tempS1.find(StrInS1)) != std::string::npos)
        {
            S1.replace(pos, StrInS1.length(), StrToReplace);

            if (!IsMatchCase)
                tempS1 = LowerAllString(S1);
            else
                tempS1 = S1; // to Refrech String in temp String.
        }
        return S1;
    }

    string ReplaceWordInStringWhithVectorByDelimeter(string S1, string StrInS1, string StrToReplace, string deli = " ", bool IsMatchCase = true)
    {
        vector<string> vSWords = SpletStringInVector(S1, deli);
        for (string &S : vSWords)
        {
            if (IsMatchCase)
            {
                if (S == StrInS1)
                    S = StrToReplace;
            }
            else
            {
                if (LowerAllString(S) == LowerAllString(StrInS1))
                    S = StrToReplace;
            }
        }
        return JoinString(vSWords, deli);
    }

    string RemoveAllPunctuationsInString(string S1)
    {
        string S2 = "";
        for (char &ch : S1)
        {
            if (!ispunct(ch))
                S2.push_back(ch);
        }
        return S2;
    }

    string ReplaceWordInString(string Str, string StrInString, string StrToReplace, bool IsMatchCase = true)
    {
        string Temp = Str;

        if (!IsMatchCase)
        {
            Temp = UpperAllString(Str);
            StrInString = UpperAllString(StrInString);
        }

        short pos = Temp.find(StrInString);
        while ((pos = Temp.find(StrInString)) != std::string::npos)
        {
            Str.replace(pos, StrInString.length(), StrToReplace);

            if (!IsMatchCase)
                Temp = LowerAllString(Str);
            else
                Temp = Str; // to Refrech String in temp String.
        }

        return Str;
    }

}
