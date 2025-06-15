
#pragma once

#include <iostream>
using namespace std;

class clsPerson
{

private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Property Set
    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    // Property Get
    string FirstName()
    {
        return _FirstName;
    }

    // Property Set
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }

    // Property Get
    string LastName()
    {
        return _LastName;
    }

    // Property Set
    void setEmail(string Email)
    {
        _Email = Email;
    }

    // Property Get
    string Email()
    {
        return _Email;
    }

    // Property Set
    void setPhone(string Phone)
    {
        _Phone = Phone;
    }

    // Property Get
    string Phone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    /*    void Print()
        {
            cout << "\nInfo:";
            cout << "\n___________________";
            cout << "\nFirstName: " << _FirstName;
            cout << "\nLastName : " << _LastName;
            cout << "\nFull Name: " << FullName();
            cout << "\nEmail    : " << _Email;
            cout << "\nPhone    : " << _Phone;
            cout << "\n___________________\n";
        }

            void SendEmail(string Subject, string Body)
            {

                cout << "\nThe following message sent successfully to email: " << _Email;
                cout << "\nSubject: " << Subject;
                cout << "\nBody: " << Body << endl;

            }

            void SendSMS(string TextMessage)
            {
                cout << "\nThe following SMS sent successfully to phone: " << _Phone;
                cout << "\n" << TextMessage << endl;
            }

        */
};
