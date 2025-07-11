#pragma once
#include <iostream>
#include "clsScreen.h"
#include <vector>
#include <string>
#include "clsCurrency.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsCurrencyUtil.h"

class clsUpdateRateScreen : protected clsScreen
{
    static void _UpdateRate(clsCurrency &Currency)
    {
            if(clsInputValidate::ReadYesOrNo("Are you sure you want to update the rate? (Y/N)"))
            {
                cout<<"\nUpdate Currency Rate\n";
                cout<<"_______________________________\n";
                float NewRate = clsInputValidate::ReadPosFloat( "Enter New Rate: ");
                if(Currency.UpdateRate(NewRate) == clsCurrency::enSaveResult::svSucceeded)
                {
                    cout<<"\nCurrency Rate Updated Successfully :-) \n";
                    clsCurrencyUtil::PrintCurrency(Currency);

                }
                else
                {
                    cout<<"\nFailed to Update Currency Rate.\n";
                }
            }

    }

public:
    static void ShowUpdateRateScreen()
    {
        _DrawScreenHeader("\t\tUpdate Currency Screen");
       clsCurrency Currency = clsCurrency::FindByCurrencyCode( clsInputValidate::ReadString("Enter Currency Code: "));
       if(!Currency.IsEmpty())
       {
            clsCurrencyUtil::PrintCurrency(Currency);
            _UpdateRate(Currency);
       }
       else
       {
            cout<<"\nCurrency Not Found.\n";
       }
    }

}; 