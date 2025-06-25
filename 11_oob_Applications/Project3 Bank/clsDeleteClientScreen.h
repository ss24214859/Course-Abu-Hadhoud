#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
public:
    // Displays the Delete Client screen, prompts for account number, confirms deletion, and deletes the client if confirmed.
    static void ShowDeleteClientScreen()
    {
        clsScreen::_DrawScreenHeader("\t  Delete Client Screen");
        cout << "\n\n";
        string AccountNumber = clsUtilClientUI::ReadExistingAccountNumber();
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        clsUtilClientUI::Print(Client);
        if (clsInputValidate::ReadYesOrNo("Are you Sure you want delete this Client? y/n ?"))
        {
            if (Client.Delete())
            {
                cout << "Client Delete Successfully :-) " << endl;
                clsUtilClientUI::Print(Client);
            }
            else
                cout << "Faild Client is Not Delete :-( " << endl;
        }
    }
};
