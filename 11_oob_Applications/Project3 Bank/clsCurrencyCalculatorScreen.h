#pragma once
#include <iostream>
#include "clsScreen.h"
#include <vector>
#include <string>
#include "../../MyClasss/clsUtil.h"
#include "clsCurrency.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsCurrencyUtil.h"
class clsCurrencyCalculatorScreen : protected clsScreen
{


    static void _PrintCalculationsResults(clsCurrency &Currency1, clsCurrency &Currency2, double Amount)
    {
        double ConvertedAmount;

        ConvertedAmount = Currency1.ConvertToUSD(Amount);
        clsCurrencyUtil::PrintCurrency(Currency1,"Convert From :");
        cout <<Amount<<" "<<Currency1.CurrencyCode()<< " = " << ConvertedAmount << " USD" << endl;
        
        if(Currency2.CurrencyCode() != "USD")
        {
            ConvertedAmount = Currency1.ConvertToAnotherCurrency(Currency2,Amount);
            cout<<"\nConverting From USD to : "<<endl;
            clsCurrencyUtil::PrintCurrency(Currency2,"To :");
            cout <<Amount<<" "<<Currency1.CurrencyCode()<< " = " << ConvertedAmount << " " << Currency2.CurrencyCode() << endl;

        }

    }    

public:
    static void ShowCurrencyCalculatorScreen()
    {
        bool Continue =true;
        while(Continue)
        _DrawScreenHeader("\t\tCurrency Calculator Screen");

        clsCurrency Currency1= clsCurrencyUtil::ReadExistingCurrencyObject("Enter First Currency Code: ");
        clsCurrency Currency2 = clsCurrencyUtil::ReadExistingCurrencyObject("Enter Second Currency Code: ");
        double Amount=clsInputValidate::ReadPosDouble("Enter Amount to Exchange : ");
        _PrintCalculationsResults(Currency1, Currency2, Amount);

        Continue =clsInputValidate::ReadYesOrNo("Do you want to Perform Another Calculation? (Y/N)");
    }

}; 