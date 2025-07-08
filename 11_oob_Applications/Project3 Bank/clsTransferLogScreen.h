#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
    static void _PrintRecordDataInList(clsBankClient::stTransferLogRecord &Record)
    {
        cout << "\t\t" << setw(35) << left << "| " + Record.DateTime // Date/time
             << setw(20) << left << "| " + Record.From_AccNum        // From Account Number
             << setw(20) << left << "| " + Record.To_AccNum          // To Account Number
             << "| " << setw(20) << left << Record.Amount            // Amount
             << "| " << setw(20) << left << Record.From_BalanceAfter      // From Balance
             << "| " << setw(20) << left << Record.To_BalanceAfter        // To Balance
             << setw(14) << left << "| " + Record.User               // User
             << "|" << endl;
    }

    static void _PrintAllRecordsDataInList(vector<clsBankClient::stTransferLogRecord> &vRecords)
    {
        // Iterate through the vector and print each record
        for (clsBankClient::stTransferLogRecord &Record : vRecords)

        {
            _PrintRecordDataInList(Record);
        }
    }

public:
    static void ShowTransferLogScreen()
    {
        // Get all transfer log records and prepare screen titles
        vector<clsBankClient::stTransferLogRecord> vRecords = clsBankClient::LoadTransferLogRecords();
        string TitleOfScreen = "\t   Transfer Log List Screen";
        string SubTitleOfScreen = "\t    (" + to_string(vRecords.size()) + ") Record(s).";
        string LineOfList = "\t\t" + clsUtil::PrintLineByChar(35 + 20 + 20 + 20 + 20 + 20 + 20 + 1);

        // Draw header and print the list
        clsScreen::_DrawScreenHeader(TitleOfScreen, SubTitleOfScreen);
        cout << "\n"
             << LineOfList << "\n\n";
        cout << "\t\t" << setw(35) << left << "| Date/time"
             << setw(20) << left << "| From AccNum"
             << setw(20) << left << "| To AccNum"
             << "| " << setw(20) << left << "Amount"
             << "| " << setw(20) << left << "From Balance"
             << "| " << setw(20) << left << "To Balance"
             << setw(14) << left << "| User"
             << "|" << endl;
        cout << LineOfList << "\n";

        // Print transfer log records or a message if none exist
        if (vRecords.size() == 0)
            cout << "\n\t\t\t\tNo transfer logs available in the system!" << endl;
        else
            _PrintAllRecordsDataInList(vRecords);

        cout << LineOfList << "\n";
    }
};
