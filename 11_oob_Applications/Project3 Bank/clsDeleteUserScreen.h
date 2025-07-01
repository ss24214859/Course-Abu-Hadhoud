#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
public:
    static void ShowDeleteUserScreen()
    {
        clsScreen::_DrawScreenHeader("\t  Delete User Screen");
        cout << "\n\n";
        string UserName = clsUtilUserUI::ReadExistingUserName();
        clsUser User = clsUser::Find(UserName);
        clsUtilUserUI::Print(User);
        if (clsInputValidate::ReadYesOrNo("Are you sure you want to delete this User? y/n ?"))
        {
            if (User.Delete())
            {
                cout << "User Deleted Successfully :-) " << endl;
                clsUtilUserUI::Print(User);
            }
            else
            {
                cout << "Failed, User was not deleted :-( " << endl;
            }
        }
    }
}; 