#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "../../MyClasss/clsInputValidate.h"

using namespace std;

class clsUtilClientUI
{
public:
    static string ReadExistingAccountNumber()
    {
        string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number : ");
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidate::ReadString("Account number Not exists, please enter another one : ");
        }
        return AccountNumber;
    }

    static string ReadNewAccountNumber()
    {
        string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number : ");
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidate::ReadString("Account number is Exists, please enter another one : ");
        }
        return AccountNumber;
    }

    static void ReadClientInfo(clsBankClient &Client)
    {
        Client.setFirstName(clsInputValidate::ReadString("Enter First Name : "));
        Client.setLastName(clsInputValidate::ReadString("Enter Last Name : "));
        Client.setEmail(clsInputValidate::ReadString("Enter Email : "));
        Client.setPhone(clsInputValidate::ReadString("Enter Phone : "));
        Client.SetPINCode(clsInputValidate::ReadString("Enter PIN Code : "));
        Client.SetAccountBalance(clsInputValidate::ReadDblNumber("Enter Account Balance : "));
    }

    static void Print(clsBankClient Client)
    {
        cout << "\nClient Card: " << endl;
        clsUtil::PrintLineByChar(50);
        cout << "FirstName       : " << Client.FirstName() << endl;
        cout << "LastName        : " << Client.LastName() << endl;
        cout << "Name            : " << Client.FullName() << endl;
        cout << "Email           : " << Client.Email() << endl;
        cout << "Phone           : " << Client.Phone() << endl;
        cout << "Account Number  : " << Client.AccountNumber() << endl;
        cout << "PIN Code        : " << Client.PINCode() << endl;
        cout << "Account Balance : " << Client.AccountBalance() << endl;
        clsUtil::PrintLineByChar(50);
    }
};
