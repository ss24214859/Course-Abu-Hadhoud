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
    clsPerson(string FirstName, string LastName, string Email, string Phone) // Constructor: initializes person data
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    // Property Set
    void setFirstName(string FirstName) // Set the first name
    {
        _FirstName = FirstName;
    }

    // Property Get
    string FirstName() // Get the first name
    {
        return _FirstName;
    }

    // Property Set
    void setLastName(string LastName) // Set the last name
    {
        _LastName = LastName;
    }

    // Property Get
    string LastName() // Get the last name
    {
        return _LastName;
    }

    // Property Set
    void setEmail(string Email) // Set the email
    {
        _Email = Email;
    }

    // Property Get
    string Email() // Get the email
    {
        return _Email;
    }

    // Property Set
    void setPhone(string Phone) // Set the phone number
    {
        _Phone = Phone;
    }

    // Property Get
    string Phone() // Get the phone number
    {
        return _Phone;
    }

    string FullName() // Get the full name (first + last)
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
