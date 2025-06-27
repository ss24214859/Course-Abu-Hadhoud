#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsAddUserScreen : protected clsScreen
{
public:
    static void ShowAddUserScreen()
    {
        cout << "\nShowAddUserScreen will be here\n";
    }
}; 