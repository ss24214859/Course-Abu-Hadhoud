#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
public:
    static void ShowUpdateUserScreen()
    {
        clsScreen::_DrawScreenHeader("\t   Update User Screen");
        cout << "\n\n";
        string UserName = clsUtilUserUI::ReadExistingUserName();

        clsUser User = clsUser::Find(UserName);
        clsUtilUserUI::Print(User);

        clsUtilUserUI::ReadUserInfo(User);

        clsUser::enSaveResult SaveResult = User.Save();
        switch (SaveResult)
        {
        case clsUser::enSaveResult::svFaildEmptyObject:
            cout << "Save Failed: Empty Object :-( " << endl;
            break;

        case clsUser::enSaveResult::svSucceeded:
            cout << "User updated successfully :-) " << endl;
            clsUtilUserUI::Print(User);
            break;
        }
    }
}; 