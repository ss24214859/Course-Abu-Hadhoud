#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "../../MyClasss/clsString.h"
#include "../../MyClasss/clsUtil.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsClientsListScreen : protected clsScreen
{

private:
    /**
     * @brief Prints a single client's record in a formatted list row.
     * @param Client The client object whose data will be printed.
     */
    static void _PrintClientRecordInList(clsBankClient Client)
    {
        // Print the details of a single client in a formatted row
        cout << "| " << setw(15) << left << Client.AccountNumber()
             << "| " << setw(22) << left << Client.FullName()
             << "| " << setw(20) << left << Client.Phone()
             << "| " << setw(22) << left << Client.Email()
             << "| " << setw(10) << left << Client.PINCode()
             << "| " << setw(8) << left << Client.AccountBalance() << "|";
    }

    /**
     * @brief Prints all client records from a vector in a formatted list.
     * @param vClients Vector containing all client objects to be printed.
     */
    static void _PrintClientsRecordDataInList(vector<clsBankClient> vClients)
    {
        // Iterate through the vector and print each client record
        for (clsBankClient C : vClients)
        {
            cout << "\t\t";
            _PrintClientRecordInList(C);
            cout << endl;
        }
    }

public:
    /**
     * @brief Displays the client list screen, including headers and all client records.
     */
    static void ShowClientListScreen()
    {
        // Get all clients and prepare screen titles
        vector<clsBankClient> vClients = clsBankClient::GetClients();
        string TitleOfScreen = "\t     Client List Screen";
        string SubTitleOfScreen = "\t      (" + to_string(vClients.size()) + ") Clients(s).";
        string TitleOfList = "\t\t| Account Number | Client Name           | Phone Number        |  Email                | PIN Code  | Balance |";
        string LineOfList = "\t\t" + clsUtil::PrintLineByChar(TitleOfList.length() - 2);

        // Draw header and print the list
        clsScreen::_DrawScreenHeader(TitleOfScreen, SubTitleOfScreen);
        cout << "\n"
             << LineOfList << "\n\n";
        cout << TitleOfList << endl; // Print the list header
        cout << LineOfList << "\n";

        // Print client records or a message if none exist
        if (vClients.size() == 0)
            cout << "\n\t\t\t\tNo Clients Available in the System!" << endl;
        else
            _PrintClientsRecordDataInList(vClients);

        cout << LineOfList << "\n";
    }
};