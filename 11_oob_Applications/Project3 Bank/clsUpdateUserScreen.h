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
        cout << "\nShowUpdateUserScreen will be here\n";
    }
}; 