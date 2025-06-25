#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsClientsListScreen.h"
#include "clsAddClientsScreen.h"

using namespace std;

// Main screen class for the banking application
class clsMainScreen : protected clsScreen
{
private:
    // Enum for main menu options
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

    // Show the clients list screen
    static void _ShowClientListScreen()
    {
        // [Commit] Show the clients list screen
        clsClientsListScreen::PrintClientListScreen();
    }

    // Show the add new client screen (placeholder)
    static void _ShowAddClientsScreen()
    {
        // [Commit] Show the add new client screen (placeholder)
        clsAddCientsScreen::ShowAddNewClientScreen();
    }

    // Show the delete client screen (placeholder)
    static void _ShowDeleteClientScreen()
    {
        // [Commit] Show the delete client screen (placeholder)
        cout << "ShowDeleteClientScreen Will be Here" << endl;
    }

    // Show the update client info screen (placeholder)
    static void _ShowUpdateClientInfoScreen()
    {
        // [Commit] Show the update client info screen (placeholder)
        cout << "ShowUpdateClientInfoScreen Will be Here" << endl;
    }

    // Show the find client screen (placeholder)
    static void _ShowFindClientScreen()
    {
        // [Commit] Show the find client screen (placeholder)
        cout << "ShowFindClientScreen Will be Here" << endl;
    }

    // Show the transaction menu screen (placeholder)
    static void _ShowTransactionMenueScreen()
    {
        // [Commit] Show the transaction menu screen (placeholder)
        cout << "ShowTransactionMenueScreen Will be Here" << endl;
    }

    // Show the manage user menu screen (placeholder)
    static void _ShowManageUserMenueScreen()
    {
        // [Commit] Show the manage user menu screen (placeholder)
        cout << "ShowManageUserMenueScreen Will be Here" << endl;
    }

    // Go back to the main menu
    static void _GoBackToMainMenue()
    {
        // [Commit] Go back to the main menu
        cout << "\nPress any key to go to Main Menue.";
        system("pause>0");
        ShowMainMenueScreen();
    }

    // Read the main menu option from the user
    static enMainMenueOption _ReadMainMenueOption()
    {
        // [Commit] Read the main menu option from the user
        return (enMainMenueOption)clsInputValidate::ReadShortNumberBetween(1, 8, "\nChoose What do you want to do? [1 to 8]?", "\nChoose What do you want to do? [1 to 8]?");
    }

    // Perform the selected main menu option
    static void _PerformMainMenueOption(enMainMenueOption choice)
    {
        // [Commit] Perform the selected main menu option
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
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eManageUserMenue:
        {
            _ShowManageUserMenueScreen();
            _GoBackToMainMenue();
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
    // Show the main menu screen
    static void ShowMainMenueScreen()
    {
        // [Commit] Show the main menu screen
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