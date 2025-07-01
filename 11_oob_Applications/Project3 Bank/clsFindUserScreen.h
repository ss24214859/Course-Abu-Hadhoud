#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
{
public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");
        cout << "\n\n";
        string UserName = clsUtilUserUI::ReadExistingUserName();

        clsUser User1 = clsUser::Find(UserName);
        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
            clsUtilUserUI::Print(User1);
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }
    }
}; 