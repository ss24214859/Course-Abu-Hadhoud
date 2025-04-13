#pragma once

#include <iostream>
#include <string>

namespace String
{
    using namespace std;
    string ReadPassword();
    bool GuessPassword(string OriginalPassword);
    string ReadText();
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

    string ReadText()
    {
        string Text;
        cout << "Enter text: ";
        getline(cin, Text);
        return Text;
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

}
