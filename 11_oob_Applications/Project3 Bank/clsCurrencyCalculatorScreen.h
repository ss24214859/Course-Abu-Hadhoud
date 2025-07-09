#pragma once
#include <iostream>
#include "clsScreen.h"
#include <vector>
#include <string>
#include "clsCurrency.h"
#include "../../MyClasss/clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{

public:
    static void ShowCurrencyCalculatorScreen()
    {
        cout<<"Currency Calculator Screen Will be Here."<<endl;
    }

}; 