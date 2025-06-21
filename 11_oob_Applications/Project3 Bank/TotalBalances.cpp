#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "../../MyClasss/clsInputValidate.h"
#include "../../MyClasss/clsString.h"
#include "../../MyClasss/clsUtil.h"
using namespace std;

void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << setw(12) << left << Client.AccountNumber()
         << "| " << setw(22) << left << Client.FullName()
         << "| " << setw(8) << left << Client.AccountBalance() << "|";
}

void PrintClientsBalanceListScreen()
{

    vector<clsBankClient> vClients = clsBankClient::GetClientsList();
    string length = " Balance ";
    cout << "              Balance List (" << vClients.size() << ") Clients(s)." << endl;
    string Title = "|  Account Number   | Client Name           | Balance |";
    clsUtil::PrintLineByChar(Title.length());
    cout << endl;

    cout << Title << endl; // This Is The Title Of The List in This String.
    clsUtil::PrintLineByChar(Title.length());

    if (vClients.size() == 0)
        cout << "\n\t\tNo Clients Available in the System!" << endl;
    else
    {
        short counter = 1;
        for (clsBankClient C : vClients)
        {
            cout << "|" << setw(3) << right << counter << "- | ";
            PrintClientRecordBalanceLine(C);
            cout << endl;
            counter++;
        }
        clsUtil::PrintLineByChar(Title.length());
        double TotalBalance = clsBankClient::GetTotalBalances();
        cout << "\n\t\tTotal Balances = " << TotalBalance << endl;
        cout << "( " << clsUtil::NumberToText(TotalBalance) << ")" << endl;
    }
}

int main()
{
    PrintClientsBalanceListScreen();
}