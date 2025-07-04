#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "../../MyClasss/clsString.h"
#include "../../MyClasss/clsUtil.h"
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsLoginRegisterListScreen : protected clsScreen
{
    private:
    
    static void  _PrintRecordDataInList(clsUser::stLoginRegisterRecord & Record)
    {
        cout << "\t\t" << setw(35) << left << "| "+ Record.DateTime// Date/time
             << setw(20) << left << "| "+ Record.UserName // Username
             << setw(12) << left << "| "+ Record.Password// Password
             << "| "<< setw(13) << left << Record.Permissions // Permissions
             << "|" << endl;
    }

    static void _PrintAllRecordsDataInList(vector<clsUser::stLoginRegisterRecord> & vRecords)
    {
        // Iterate through the vector and print each record
        for (clsUser::stLoginRegisterRecord & Record : vRecords)
        {
            _PrintRecordDataInList(Record);
        }
    }


public:
    static void ShowLoginRegisterListScreen()
    {
        // Get all users and prepare screen titles
        vector<clsUser::stLoginRegisterRecord> vRecords = clsUser::LoadLoginRegisterRecords();
        string TitleOfScreen = "\t   Login Register List Screen";
        string SubTitleOfScreen = "\t    (" + to_string(vRecords.size()) + ") Record(s).";
        string LineOfList = "\t\t" + clsUtil::PrintLineByChar(35+20+12+15+1);

        // Draw header and print the list
        clsScreen::_DrawScreenHeader(TitleOfScreen, SubTitleOfScreen);
        cout << "\n"
             << LineOfList << "\n\n";
        cout <<"\t\t"<< setw(35) << left << "| Date/time" // Align the date/time column
             << setw(20) << left << "| Username" // Align the username column
             << setw(12) << left << "| Password" // Align the password column
             << setw(15) << left << "| Permissions" <<"|" // Align the permissions column
             << endl;
        cout << LineOfList << "\n";

        // Print user records or a message if none exist
        if (vRecords.size() == 0)
            cout << "\n\t\t\t\tNo users available in the system!" << endl;
        else
            _PrintAllRecordsDataInList(vRecords);

        cout << LineOfList << "\n";

    }
};