#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUser.h"
#include "Global.h"

using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
    static void _Login()
    {
        bool FaildLogin = false;
        // Loop until the user successfully logs in or chooses to exit
        do
        {
            if(FaildLogin)
            {
                cout << "\nLogin Failed!,Invlaid Username/Password.\n" << endl;
            }
            string UserName = clsInputValidate::ReadString("Enter User Name : ");
            string Password = clsInputValidate::ReadString("Enter Password : ");
            CurrentUser = clsUser::Find(UserName, Password);
            FaildLogin = CurrentUser.IsEmpty();
        }while(FaildLogin);
        // If login is successful, show the main menu screen
        clsMainScreen::ShowMainMenueScreen();
    }

public:

    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\tLogin Screen");
        _Login();
    }

};