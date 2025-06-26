#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
public:
    static void ShowWithdrawScreen()
    {

        _DrawScreenHeader("       Withdraw Screen");

        string AccountNumber = clsUtilClientUI::ReadExistingAccountNumber();
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        clsUtilClientUI::Print(Client);

        // Prompt the user to enter a withdrawal amount between 1 and the current account balance
        double Amount = clsInputValidate::ReadDblNumberBetween(1, Client.AccountBalance(), "Please enter Withdraw amount ? ", "Amount must be between 1 and your current balance!\n Try Again : ");

        if (clsInputValidate::ReadYesOrNo("Are you sure you want to perform this transction ?"))
        {
            if (Client.Withdraw(Amount))
            {
                cout << "\nAmount Withdrawed Successfully :-)\n"
                     << endl;
                cout << "New Balance Is: " << Client.AccountBalance() << endl;
            }
            else
            {
                cout << "Cannot Withdraw, Insuffecient Balance!" << endl;
                cout << "Amount to Withdraw is : " << Amount << endl;
                cout << "Your Balance is : " << Client.AccountBalance() << endl;
            }
        }
        else
            cout << "\nOperation Was Cancelled.\n"
                 << endl;
    }
};