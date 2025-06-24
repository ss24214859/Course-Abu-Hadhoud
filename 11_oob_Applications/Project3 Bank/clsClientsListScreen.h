#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "../../MyClasss/clsString.h"
#include "../../MyClasss/clsUtil.h"
#include "clsScreen.h"
using namespace std;

class clsClientsListScreen : protected clsScreen
{

private:
    static void _PrintClientRecordInList(clsBankClient Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber()
             << "| " << setw(22) << left << Client.FullName()
             << "| " << setw(20) << left << Client.Phone()
             << "| " << setw(22) << left << Client.Email()
             << "| " << setw(10) << left << Client.PINCode()
             << "| " << setw(8) << left << Client.AccountBalance() << "|";
    }

    static void _PrintClientsRecordDataInList(vector<clsBankClient> vClients)
    {
        for (clsBankClient C : vClients)
        {
            cout << "\t\t";
            _PrintClientRecordInList(C);
            cout << endl;
        }
    }

public:
    static void PrintClientListScreen()
    {

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string TitleOfScreen = "\t     Client List Screen";
        string SubTitleOfScreen = "\t      (" + to_string(vClients.size()) + ") Clients(s).";
        string TitleOfList = "\t\t| Account Number | Client Name           | Phone Number        |  Email                | PIN Code  | Balance |";
        string LineOfList = "\t\t" + clsUtil::PrintLineByChar(TitleOfList.length() - 2);

        clsScreen::_DrawScreenHeader(TitleOfScreen, SubTitleOfScreen);
        cout << "\n"
             << LineOfList << "\n\n";
        cout << TitleOfList << endl; // This Is The Title Of List Of The List in This String.
        cout << LineOfList << "\n";

        if (vClients.size() == 0)
            cout << "\n\t\t\t\tNo Clients Available in the System!" << endl;
        else
            _PrintClientsRecordDataInList(vClients);

        cout << LineOfList << "\n";
    }
};