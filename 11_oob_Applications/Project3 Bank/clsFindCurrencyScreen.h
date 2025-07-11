#pragma once
#include <iostream>
#include "clsScreen.h"
#include <vector>
#include <string>
#include "clsCurrency.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsCurrencyUtil.h"

class clsFindCurrencyScreen : protected clsScreen
{
    enum enFindBy
    {
        eFindByCode = 1,
        eFindByCountry = 2
        
    };
    static enFindBy _ReadFindByOption()
    {
        return (enFindBy)clsInputValidate::ReadShortNumberBetween(1, 2, "\nFind By: [1] Code Or [2] Country ? ");
    }

    static void _FindByCountry()
    {
        clsCurrency Currency = clsCurrency::FindByCountry(clsInputValidate::ReadString("\nEnter Country Name: "));
        if (!Currency.IsEmpty())
        {
            cout << "Currency Found :-) " << endl;
            clsCurrencyUtil::PrintCurrency(Currency);
        }
        else
            cout << "Currency Not Found :-( " << endl;
    }

    static void _FindByCode()
    {
        clsCurrency Currency = clsCurrency::FindByCurrencyCode(clsInputValidate::ReadString("\nEnter Currency Code : "));
        if (!Currency.IsEmpty())
        {
            cout << "Currency Found :-) " << endl;
            clsCurrencyUtil::PrintCurrency(Currency);
        }
        else
            cout << "Currency Not Found :-( " << endl;
    }

public:
    static void ShowFindCurrencyScreen()
    {
        
        _DrawScreenHeader("\t\tFind Currency Screen");
        switch (_ReadFindByOption())
        {
            case enFindBy::eFindByCode:
                _FindByCode();
                break;
            case enFindBy::eFindByCountry:
                _FindByCountry();
                break;
            
        }
    }
};