#pragma once
#include <iostream>
#include "clsCurrency.h"

using namespace std;

class clsCurrencyUtil
{
public:
    // Function to print currency details
    static void PrintCurrency(clsCurrency& currency)
    {
        cout << "\nCurrency Details:\n";
        cout << "Country: " << currency.Country() << endl;
        cout << "Code: " << currency.CurrencyCode() << endl;
        cout << "Name: " << currency.CurrencyName() << endl;
        cout << "Rate (1$): " << currency.Rate() << endl;
        cout << "-----------------------------\n";
    }

};