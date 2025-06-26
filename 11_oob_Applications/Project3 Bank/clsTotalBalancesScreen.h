#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:
    // Prints a single client record in the balance list
    static void _PrintRecordInBalanceList(clsBankClient Client)
    {

        cout << setw(37) << left << "" << "| " << setw(15) << left << Client.AccountNumber()
             << "| " << setw(22) << left << Client.FullName()
             << "| " << setw(8) << left << Client.AccountBalance() << "|";
    }

    // Prints all client records in the balance list
    static void _PrintClientRecordsDataInBalanceList(vector<clsBankClient> vClients)
    {

        for (clsBankClient C : vClients)
        {
            _PrintRecordInBalanceList(C);
            cout << endl;
        }
    }

public:
    static void ShowBlanceListScreen()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClients();

        _DrawScreenHeader("\t       Total Balance List", "\t\t[" + to_string(vClients.size()) + "] Clients(s).");

        string Title = "| Account Number | Client Name           | Balance |";

        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(Title.length()) << "\n\n";
        cout << setw(37) << left << "" << Title << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(Title.length()) << endl;

        _PrintClientRecordsDataInBalanceList(vClients);

        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(Title.length()) << "\n\n";

        double TotalBalance = clsBankClient::GetTotalBalances();
        cout << setw(37) << left << "" << "                Total Balance = " << TotalBalance << endl;
        cout << setw(37) << left << "" << "( " << clsUtil::NumberToText(TotalBalance) << ")" << endl;
    }
};