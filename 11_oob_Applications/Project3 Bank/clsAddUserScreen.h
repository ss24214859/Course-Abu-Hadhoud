#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilUserUI.h"
#include "clsUser.h"

using namespace std;

class clsAddUserScreen : protected clsScreen
{
public:
    static void ShowAddUserScreen()
    {
        _DrawScreenHeader("\t\tAdd New User Screen");
        string UserName = clsUtilUserUI::ReadNewUserName();
        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
        clsUtilUserUI::ReadUserInfo(NewUser);
        clsUser::enSaveResult SaveResult = NewUser.Save();
        switch (SaveResult)
        {
        case clsUser::enSaveResult::svSucceeded:
            cout << "User Added Successfully :-) " << endl;
            clsUtilUserUI::Print(NewUser);
            break;
        case clsUser::enSaveResult::svFaildUserNameIsExist:
            cout << "Save Failed Because User Name is Already Used :-( " << endl;
            break;
        case clsUser::enSaveResult::svFaildEmptyObject:
            cout << "Save Failed Because User Is Empty :-( " << endl;
            break;
        }
    }
}; 