#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrencyExhangeMenueOption
    {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateRate = 3,
        eCurrencyCalculator = 4,
        eMainMenue = 5

    };

    static void _ShowCurrenciesListScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static enCurrencyExhangeMenueOption _ReadManageUserMenueOption()
    {
        return (enCurrencyExhangeMenueOption)clsInputValidate::ReadShortNumberBetween(1, 6, "\nChoose What do you want to do? [1 to 5]?");
    }
    static void _GoBackToCurrencyExhangeMenue()
    {
        cout << "\nPress any key to go to Manage User Screen Menue.";
        system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _PerformManageUserMenueOption(enCurrencyExhangeMenueOption choice)
    {
        system("cls");
        switch (choice)
        {
        case enCurrencyExhangeMenueOption::eListCurrencies:
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        case enCurrencyExhangeMenueOption::eFindCurrency:
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        case enCurrencyExhangeMenueOption::eUpdateRate:
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        case enCurrencyExhangeMenueOption::eCurrencyCalculator:
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExhangeMenue();
            break;
        case enCurrencyExhangeMenueOption::eMainMenue:
            break;

        default:
            cout << "Invalid Choice" << endl;
            _GoBackToCurrencyExhangeMenue();
            break;
        }
    }
public:
    
    static void ShowCurrencyExchangeScreen()
    {
        // Draw the screen header
        _DrawScreenHeader("Currency Exchange", "Exchange Rates and Transactions");
        short WidthLine = 50;

        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        cout << setw(37) << left << "" << "         Currency Exchange Menue Screen" << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;

        cout << setw(37) << left << "" << "        [1] List Currencies." << endl;
        cout << setw(37) << left << "" << "        [2] Find Currency." << endl;
        cout << setw(37) << left << "" << "        [3] Update Rate." << endl;
        cout << setw(37) << left << "" << "        [4] Currency Calculator." << endl;
        cout << setw(37) << left << "" << "        [5] Main Menue." << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        _PerformManageUserMenueOption(_ReadManageUserMenueOption());
    }    
};