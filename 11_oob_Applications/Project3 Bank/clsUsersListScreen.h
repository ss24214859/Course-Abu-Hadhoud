#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsUsersListScreen : protected clsScreen
{
public:
    static void ShowUsersListScreen()
    {
        cout << "Users list Screen was here" << endl;
    }
};