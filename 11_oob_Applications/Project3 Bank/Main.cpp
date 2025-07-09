#include <iostream>
#include "clsCurrency.h"
#include "clsCurrencyUtil.h"




int main()

{
    clsCurrency Currency1 = Currency1.FindByCurrencyCode("jod");

    if (Currency1.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        clsCurrencyUtil::PrintCurrency(Currency1);
    }

    clsCurrency Currency2 = Currency2.FindByCountry("Egypt");

    if (Currency2.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        clsCurrencyUtil::PrintCurrency(Currency2);
    }

    cout << "Currency1 after updating Rate:\n";
    Currency2.UpdateRate(0.02014);
    clsCurrencyUtil::PrintCurrency(Currency2);


    return 0;
}

