#pragma once
#include <iostream>
#include "clsScreen.h"
#include <vector>
#include <string>

class clsCurrenciesListScreen : protected clsScreen
{
    private:
    
    static void  _PrintRecordDataInList(clsCurrency & Record)
    {
        cout << "\t" << setw(55) << left << "| "+ Record.Country()// Country
             << setw(15) << left << "| "+ Record.CurrencyCode() // Code
             << setw(55) << left << "| "+ Record.CurrencyName()// Name
             << "| "<< setw(15) << left << Record.Rate() // Rate
             << "|" << endl;
    }

    static void _PrintAllRecordsDataInList(vector<clsCurrency> & vRecords)
    {
        // Iterate through the vector and print each record
        for (clsCurrency & Record : vRecords)
        {
            _PrintRecordDataInList(Record);
        }
    }


public:
    static void ShowCurrenciesListScreen()
    {
        // Get all users and prepare screen titles
        vector<clsCurrency> vRecords =clsCurrency::GetAllCurrencies();
        string TitleOfScreen = "\t   Currencies List Screen";
        string SubTitleOfScreen = "\t    (" + to_string(vRecords.size()) + ") Currency.";
        string LineOfList = "\t" + clsUtil::PrintLineByChar(55+15+55+17+1);

        // Draw header and print the list
        clsScreen::_DrawScreenHeader(TitleOfScreen, SubTitleOfScreen);
        cout << "\n"
             << LineOfList << "\n\n";
        cout <<"\t"<< setw(55) << left << "| Country" // Align the Country column
             << setw(15) << left << "| Code" // Align the Code column
             << setw(55) << left << "| Name" // Align the Name column
             << setw(17) << left << "| Rate(1$)" <<"|" // Align the Rate column
             << endl;
        cout << LineOfList << "\n";

        // Print user records or a message if none exist
        if (vRecords.size() == 0)
            cout << "\n\t\t\tNo users available in the system!" << endl;
        else
            _PrintAllRecordsDataInList(vRecords);

        cout << LineOfList << "\n";

    }

};