#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "../../MyClasss/clsInputValidate.h"
#include "../../MyClasss/clsString.h"
#include "../../MyClasss/clsUtil.h"
using namespace std;

void PrintClientRecordInList(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber()
         << "| " << setw(22) << left << Client.FullName()
         << "| " << setw(20) << left << Client.Phone()
         << "| " << setw(22) << left << Client.Email()
         << "| " << setw(10) << left << Client.PINCode()
         << "| " << setw(8) << left << Client.AccountBalance() << "|";
}

void PrintClientsRecordDataInList(vector<clsBankClient> vClients)
{
    for (clsBankClient C : vClients)
    {
        PrintClientRecordInList(C);
        cout << endl;
    }
}

void PrintClientListScreen()
{

    vector<clsBankClient> vClients = clsBankClient::GetClientsList();
    string length = " Balance ";
    cout << "                 Client List (" << vClients.size() << ") Clients(s)." << endl;
    string Title = "| Account Number | Client Name           | Phone Number        |  Email                | PIN Code  | Balance |";
    clsUtil::PrintLineByChar(Title.length());
    cout << endl;

    cout << Title << endl; // This Is The Title Of The List in This String.
    clsUtil::PrintLineByChar(Title.length());

    if (vClients.size() == 0)
        cout << "\n\t\t\t\tNo Clients Available in the System!" << endl;
    else

        PrintClientsRecordDataInList(vClients);
    clsUtil::PrintLineByChar(Title.length());
}

int main()
{
    PrintClientListScreen();
}