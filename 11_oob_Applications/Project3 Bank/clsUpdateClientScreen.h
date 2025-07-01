#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
public:
    static void ShowUpdateClientScreen()
    {

        clsScreen::_DrawScreenHeader("\t   Update Client Screen");
        cout << "\n\n";
        string AccountNumber = clsUtilClientUI::ReadExistingAccountNumber();

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        clsUtilClientUI::Print(Client);

        clsUtilClientUI::ReadClientInfo(Client);

        clsBankClient::enSaveResult SaveResult = Client.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svFaildEmptyObject:
            cout << "Save Faild Empty Object :-( " << endl;
            break;

        case clsBankClient::enSaveResult::svSucceeded:
            cout << "Account update successfully :-) " << endl;
            clsUtilClientUI::Print(Client);
            break;
        }
    }
};
