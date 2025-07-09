#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../../MyClasss/clsString.h"
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsDate.h"
using namespace std;


class clsCurrency 
{
private:
    enum enMode
    {
        EmptyM = 0,
        UpdateM = 1
    };

    // Private members
    enMode _Mode ;
    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLineToCurrencyObject(string Line)
    {
        vector<string> vParts = clsString::Split(Line, "#//#");
        if (vParts.size() == 4)
        {
            return clsCurrency(enMode::UpdateM, vParts[0], vParts[1], vParts[2], stof(vParts[3]));
        }
        return _EmptyObject();
    }

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency)
    {
        string Sepretor = "#//#";
        return Currency.Country() + Sepretor +
               Currency.CurrencyCode() + Sepretor +
               Currency.CurrencyName() + Sepretor +
               to_string(Currency.Rate());
    }

    // Loads all currency data from the file into a vector
    static vector<clsCurrency> _LoadCurrenciesDataFromFile()
    {
        vector<clsCurrency> vCurrencies;
        fstream File;
        File.open("Currencies.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                vCurrencies.push_back(Currency);
            }
            File.close();
        }
        return vCurrencies;
    }
    // Saves the currency data to the file
    static void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrencies)
    {
        fstream File;
        File.open("Currencies.txt", ios::out);
        if (File.is_open())
        {
            for (clsCurrency &C : vCurrencies)
            {
                File << _ConvertCurrencyObjectToLine(C) << endl;
            }
            File.close();
        }
    }

    void _UpdateRate()
    {
        vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
        for (clsCurrency &C : vCurrencies)
        {
            if (C.Country() == _Country && C.CurrencyCode() == _CurrencyCode)
            {
                C.SetRate(_Rate);
                _SaveCurrenciesDataToFile(vCurrencies);
                return;
            }
        }
        
    }

    // Returns a new empty currency object
    static clsCurrency _EmptyObject()
    {
        return clsCurrency(enMode::EmptyM, "", "", "", 0.0f);
    }

public:
    // Constructors
    clsCurrency(enMode Mode ,string country, string currencyCode, string currencyName, float Rate)
    {
        _Mode = Mode;
        _Country = country;
        _CurrencyCode = currencyCode;
        _CurrencyName = currencyName;
        _Rate = Rate;
        
    }

    //Seters and Getters
    string Country() { return _Country; }

    string CurrencyCode() { return _CurrencyCode; }

    string CurrencyName() { return _CurrencyName; }

    void SetRate(float Rate) 
    { 
        _Rate = Rate; 
    }
    float Rate() 
    { 
        return _Rate; 
    }

    // public Methods

    bool IsEmpty()
    {
        return _Mode == enMode::EmptyM;
    }

    static bool IsCurrencyExist(string currencyCode)
    {
        clsCurrency Currency = FindByCurrencyCode(currencyCode);
        if (!Currency.IsEmpty())
        {
            return true;
        }

        return false;
    }

    static clsCurrency FindByCountry(string country)
    {
        fstream File;
        File.open("Currencies.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                // Check if the currency code matches
                if (clsUtil::UpperAllString(Currency.Country()) == clsUtil::UpperAllString(country))
                {
                    File.close();
                    return Currency;
                }
            }
            
            File.close();
        }

        return _EmptyObject();
    }

    static clsCurrency FindByCurrencyCode(string currencyCode)
    {
        fstream File;
        File.open("Currencies.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                // Check if the currency code matches
                if (Currency.CurrencyCode() == clsUtil::UpperAllString(currencyCode))
                {
                    File.close();
                    return Currency;
                }
            }
            
            File.close();
        }

        return _EmptyObject();
    }



    static vector<clsCurrency> GetAllCurrencies()
    {
        return _LoadCurrenciesDataFromFile();
    }
    
    enum enSaveResult
    {
        svSucceeded,
        svFaildCurrencyObjectIsEmpty,
        svFailed
    };

    // Updates the rate of the currency
    enSaveResult UpdateRate(float NewRate)
    {
        _Rate=NewRate;
        return Save();

    }

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyM:
            return svFaildCurrencyObjectIsEmpty;
        case enMode::UpdateM:
            _UpdateRate();
            return svSucceeded;
        }
        return svFailed;
    }

};