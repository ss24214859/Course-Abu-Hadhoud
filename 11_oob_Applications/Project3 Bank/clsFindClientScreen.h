#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtilClientUI.h"
#include "../../MyClasss/clsInputValidate.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
{
public:
    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("\t  Find Client Screen");
        cout << "\n\n";
        string AccountNumber = clsUtilClientUI::ReadExistingAccountNumber();

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }
        clsUtilClientUI::Print(Client1);
    }
};