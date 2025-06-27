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
        cout << "\nShowFindUserScreen will be here\n";
    }
}; 