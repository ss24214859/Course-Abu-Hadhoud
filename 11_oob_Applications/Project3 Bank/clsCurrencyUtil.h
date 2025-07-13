#pragma once
#include <iostream>
#include "clsCurrency.h"

using namespace std;

class clsCurrencyUtil
{
public:
    static clsCurrency ReadExistingCurrencyObject(string Massage)
    {
        string CurrencyCode = clsInputValidate::ReadString(Massage);
        clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
        while(Currency.IsEmpty())
        {
            cout<<"\nCurrency Not Found :-(\n"<<endl;
            string CurrencyCode = clsInputValidate::ReadString(Massage);
            Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
            
        }
        return Currency;

    }

    // Function to print currency details
    static void PrintCurrency(clsCurrency& currency,string Title="Currency Details:")
    {
        cout <<"\n"<<Title<<"\n";
        cout << "-----------------------------\n";
        cout << "Country: " << currency.Country() << endl;
        cout << "Code: " << currency.CurrencyCode() << endl;
        cout << "Name: " << currency.CurrencyName() << endl;
        cout << "Rate (1$): " << currency.Rate() << endl;
        cout << "-----------------------------\n";
    }

};