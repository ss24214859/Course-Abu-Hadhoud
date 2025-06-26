#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsDepositScreen : protected clsScreen
{
public:
    static void ShowDepositScreen()
    {

        _DrawScreenHeader("       Deposit Screen");

        string AccountNumber = clsUtilClientUI::ReadExistingAccountNumber();
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        clsUtilClientUI::Print(Client);
        double Amount = clsInputValidate::ReadPosDouble("Please enter deposit amount ? ");

        if (clsInputValidate::ReadYesOrNo("Are you sure you want to perform this transction ?"))
        {
            Client.Deposit(Amount);
            cout << "\nAmount Deposited Successfully :-)\n"
                 << endl;
            cout << "New Balance Is: " << Client.AccountBalance() << endl;
        }
        else
            cout << "\nOperation Was Cancelled.\n"
                 << endl;
    }
};