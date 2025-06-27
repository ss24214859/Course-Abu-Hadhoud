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
        cout << "\nShowDeleteUserScreen will be here\n";
    }
}; 