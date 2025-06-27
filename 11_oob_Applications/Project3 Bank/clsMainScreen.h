#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsClientsListScreen.h"
#include "clsAddClientsScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOption
    {
        eShowClientsList = 1,
        eShowAddNewClient = 2,
        eShowDeleteClient = 3,
        eShowUpdateClientInfo = 4,
        eShowFindClient = 5,
        eTransactionMenue = 6,
        eManageUserMenue = 7,
        eExit = 8
    };

    static void _ShowClientListScreen()
    {
        clsClientsListScreen::PrintClientListScreen();
    }

    static void _ShowAddClientsScreen()
    {
        clsAddCientsScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientInfoScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        // cout << "ShowFindClientScreen Will be Here" << endl;
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionMenueScreen()
    {
        clsTransactionsScreen::ShowTransactionMenueScreen();
    }

    static void _ShowManageUserMenueScreen()
    {
        clsManageUserScreen::ShowManageUserScreen();
    }

    static void _GoBackToMainMenue()
    {
        cout << "\nPress any key to go to Main Menue.";
        system("pause>0");
        ShowMainMenueScreen();
    }

    static enMainMenueOption _ReadMainMenueOption()
    {
        return (enMainMenueOption)clsInputValidate::ReadShortNumberBetween(1, 8, "\nChoose What do you want to do? [1 to 8]?", "\nChoose What do you want to do? [1 to 8]?");
    }

    static void _PerformMainMenueOption(enMainMenueOption choice)
    {
        system("cls");
        switch (choice)
        {
        case enMainMenueOption::eShowClientsList:
        {
            _ShowClientListScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eShowAddNewClient:
        {
            _ShowAddClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eShowDeleteClient:
        {
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eShowUpdateClientInfo:
        {
            _ShowUpdateClientInfoScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eShowFindClient:
        {
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eTransactionMenue:
        {
            _ShowTransactionMenueScreen();
            ShowMainMenueScreen();
            break;
        }
        case enMainMenueOption::eManageUserMenue:
        {
            _ShowManageUserMenueScreen();
            ShowMainMenueScreen();
            break;
        }
        case enMainMenueOption::eExit:
        {
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
            _GoBackToMainMenue();
            break;
        }
        }
    }

public:
    static void ShowMainMenueScreen()
    {
        short WidthLine = 50;
        system("cls");
        clsScreen::_DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        cout << setw(37) << left << "" << "                \tMain Menue" << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        cout << setw(37) << left << "" << "        [1] Show Clients List." << endl;
        cout << setw(37) << left << "" << "        [2] Add New Client." << endl;
        cout << setw(37) << left << "" << "        [3] Delete Client." << endl;
        cout << setw(37) << left << "" << "        [4] Update Client Info." << endl;
        cout << setw(37) << left << "" << "        [5] Find Client." << endl;
        cout << setw(37) << left << "" << "        [6] Transaction Manue Screen." << endl;
        cout << setw(37) << left << "" << "        [7] Manage User Screen." << endl;
        cout << setw(37) << left << "" << "        [8] Exit" << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        _PerformMainMenueOption(_ReadMainMenueOption());
    }
};
