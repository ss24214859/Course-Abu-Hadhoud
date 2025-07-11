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
#include "clsLoginRegisterListScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "Global.h"

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
        eLoginRegister = 8,
        eCurrencyExchange = 9, 
        eLogout = 10
    };

    static void _ShowClientListScreen()
    {
        clsClientsListScreen::ShowClientListScreen();
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

    static void _ShowLoginRegisterListScreen()
    {
        clsLoginRegisterListScreen::ShowLoginRegisterListScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
        cout << "\n Bye :-)." << endl;
    }

    static void _GoBackToMainMenue()
    {
        cout << "\nPress any key to go to Main Menue.";
        system("pause>0");
        ShowMainMenueScreen();
    }

    static enMainMenueOption _ReadMainMenueOption()
    {
        return (enMainMenueOption)clsInputValidate::ReadShortNumberBetween(1, 10, "\nChoose What do you want to do? [1 to 10]?", "\nChoose What do you want to do? [1 to 10]?");
    }

    static void _PerformMainMenueOption(enMainMenueOption choice)
    {
        if (choice != enMainMenueOption::eLogout)
        {
            if (!ChackAccessRights(clsUser::enPermissions(choice)))
            {
                _GoBackToMainMenue();
                return; // If the user does not have access rights, exit the function.
            }
        }

        system("cls");
        switch (choice)
        {
            case enMainMenueOption::eShowClientsList:
            {
                _ShowClientListScreen();
                break;
            }
            case enMainMenueOption::eShowAddNewClient:
            {
                _ShowAddClientsScreen();
                break;
            }
            case enMainMenueOption::eShowDeleteClient:
            {
                _ShowDeleteClientScreen();            
                break;
            }
            case enMainMenueOption::eShowUpdateClientInfo:
            {
                _ShowUpdateClientInfoScreen();              
                break;
            }
            case enMainMenueOption::eShowFindClient:
            {
                _ShowFindClientScreen();       
                break;
            }
            case enMainMenueOption::eTransactionMenue:
            {
                _ShowTransactionMenueScreen();     
                break;
            }
            case enMainMenueOption::eManageUserMenue:
            {
                _ShowManageUserMenueScreen();
                break;
            }
            case enMainMenueOption::eLoginRegister:
            {
                _ShowLoginRegisterListScreen();
                break;
            }
            case enMainMenueOption::eCurrencyExchange:
            {
                _ShowCurrencyExchangeScreen();
                break;
            }
            case enMainMenueOption::eLogout:
            {
                _Logout();
                break;
            }
            default:
            {
                cout << "Invalid Choice" << endl;
                
                break;
            }
        }
      
        if (choice != enMainMenueOption::eLogout)
        {
            _GoBackToMainMenue();
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
        cout << setw(37) << left << "" << "        [8] Login Register List." << endl;
        cout << setw(37) << left << "" << "        [9] Currency Exchange." << endl;
        cout << setw(37) << left << "" << "        [10] Logout." << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        _PerformMainMenueOption(_ReadMainMenueOption());
    }
};
