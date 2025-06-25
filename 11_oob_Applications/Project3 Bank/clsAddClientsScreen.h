#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "../../MyClasss/clsInputValidate.h"
#include "../../MyClasss/clsString.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsAddCientsScreen : protected clsScreen
{
public:
    static void ShowAddNewClientScreen()
    {
        string AccountNumber = clsUtilClientUI::ReadNewAccountNumber();
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        clsUtilClientUI::ReadClientInfo(NewClient);
        clsBankClient::enSaveResult SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::SvSucceeded:
            cout << "Account Added Successfully :-) " << endl;
            clsUtilClientUI::Print(NewClient);
            break;
        case clsBankClient::enSaveResult::svFaildAccountisExist:
            cout << "Save Faild BeCause Account Number is Already Used :-( " << endl;
            break;
        case clsBankClient::enSaveResult::SvFaildEmptyObject:
            cout << "Save Faild BeCuase Client Is Empty :-( " << endl;
            break;
        }
    }
};