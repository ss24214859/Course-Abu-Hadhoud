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
    static bool _Login()
    {
        bool FaildLogin = false;
        short Trails = 3;
        // Loop until the user successfully logs in or chooses to exit
        do
        {
            if (FaildLogin)
            {
                Trails--;
                cout << "\nLogin Failed!,Invlaid Username/Password." << endl;
                cout << "You Have " << Trails << " Trails To Login.\n"<< endl;
            }
            if (Trails == 0)
            {
                cout << "\nYou are Locked after 3 Faild Trails." << endl;
                system("pause>0");
                return false;
            }
            string UserName = clsInputValidate::ReadString("Enter User Name : ");
            string Password = clsInputValidate::ReadString("Enter Password : ");
            CurrentUser = clsUser::Find(UserName, Password);
            FaildLogin = CurrentUser.IsEmpty();

        } while (FaildLogin);
        // If login is successful, show the main menu screen
        clsMainScreen::ShowMainMenueScreen();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\tLogin Screen");
        return _Login();
    }
};