#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
#include "clsUsersListScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsMainScreen.h"
using namespace std;

class clsManageUserScreen : protected clsScreen
{
private:
    enum enManageUsersMenueOption
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenue = 6
    };

    static void _ShowUsersListScreen()
    {
        clsUsersListScreen::ShowUsersListScreen();
    }

    static void _ShowAddUserScreen()
    {
        clsAddUserScreen::ShowAddUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static enManageUsersMenueOption _ReadManageUserMenueOption()
    {
        return (enManageUsersMenueOption)clsInputValidate::ReadShortNumberBetween(1, 6, "\nChoose What do you want to do? [1 to 6]?");
    }

    static void _GoBackToManageUserMenue()
    {
        cout << "\nPress any key to go to Manage User Screen Menue.";
        system("pause>0");
        ShowManageUserScreen();
    }
    static void _PerformManageUserMenueOption(enManageUsersMenueOption choice)
    {
        system("cls");

        switch (choice)
        {
        case enManageUsersMenueOption::eListUsers:
        {
            _ShowUsersListScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUsersMenueOption::eAddNewUser:
        {
            _ShowAddUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUsersMenueOption::eDeleteUser:
        {
            _ShowDeleteUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUsersMenueOption::eUpdateUser:
        {
            _ShowUpdateUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUsersMenueOption::eFindUser:
        {
            _ShowFindUserScreen();
            _GoBackToManageUserMenue();
            break;
        }
        case enManageUsersMenueOption::eMainMenue: 
        {
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
            _GoBackToManageUserMenue();
            break;
        }
        }
    }

public:
    static void ShowManageUserScreen()
    {
        short WidthLine = 50;

        system("cls");
        _DrawScreenHeader("\tManage User Menue Screen");

        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        cout << setw(37) << left << "" << "             Manage User Menue Screen" << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;

        cout << setw(37) << left << "" << "        [1] List Users." << endl;
        cout << setw(37) << left << "" << "        [2] Add New Users." << endl;
        cout << setw(37) << left << "" << "        [3] Delete User." << endl;
        cout << setw(37) << left << "" << "        [4] Update User." << endl;
        cout << setw(37) << left << "" << "        [5] Find User." << endl;
        cout << setw(37) << left << "" << "        [6] Main Menue." << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        _PerformManageUserMenueOption(_ReadManageUserMenueOption());
    }
};