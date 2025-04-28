#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../../MyLiberary/ClientLib.h"
#include "../../MyLiberary/ReadLip.h"
#include "../../MyLiberary/patternLib.h"
using namespace std;
using namespace Clients;
using namespace Pattern;

void ShowTransactionMenueScreen();
void ShowMainMenueScreen();

const string ClientsFileName = "C:/Users/ss242/Documents/repos/My_Projects/8_Algorithms_level_4/Clients.txt";

enum enMainMenueOption
{
    eShowClientsList = 1,
    eShowAddNewClient = 2,
    eShowDeleteClient = 3,
    eShowUpdateClientInfo = 4,
    eShowFindClient = 5,
    eTransactionMenue = 6,
    eExit = 7
};

enum enTransactionMenueOption
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eBack = 4
};

void PrintRecordInList(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber
         << "| " << setw(10) << left << Client.PINcode
         << "| " << setw(22) << left << Client.Name
         << "| " << setw(20) << left << Client.Phone
         << "| " << setw(8) << left << Client.AccountBalance << "|";
}

void PrintClientRecordsDataInList(vector<stClient> vClients)
{
    for (stClient C : vClients)
    {
        PrintRecordInList(C);
        cout << endl;
    }
}

void PrintRecordInBalanceList(stClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber
         << "| " << setw(22) << left << Client.Name
         << "| " << setw(8) << left << Client.AccountBalance << "|";
}

void PrintClientRecordsDataInBalanceList(vector<stClient> vClients)
{

    for (stClient C : vClients)
    {
        PrintRecordInBalanceList(C);
        cout << endl;
    }
}

void ShowClientListScreen()
{

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string length = " Balance ";
    cout << "                 Client List (" << vClients.size() << ") Clients(s)." << endl;
    string Title = "| Account Number | PIN Code  | Client Name           | Phone Number        | Balance |";
    Pattern::PrintLineByChar(Title.length());
    cout << endl
         << Title << endl;
    Pattern::PrintLineByChar(Title.length());
    PrintClientRecordsDataInList(vClients);
    Pattern::PrintLineByChar(Title.length());
}

void PrintClientCard(stClient Client)
{
    cout << "the Foloowing is the Client Card: " << endl;
    Pattern::PrintLineByChar(50);
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "PIN Code : " << Client.PINcode << endl;
    cout << "Name : " << Client.Name << endl;
    cout << "Phone : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
    Pattern::PrintLineByChar(50);
}

void FindClientScreen(vector<stClient> vClients)
{
    stClient Client;
    if (FindClientByAccountNumber(Read::ReadLine("Enter Account Number ? "), vClients, Client)) // return Client And is Found or not.
        PrintClientCard(Client);
    else
        cout << "Client Not Found!" << endl;
}

string ReadAccountNumber()
{
    return Read::ReadLine("Enter Account Number ?");
}

void ShowAddClientsScreen()
{
    PrintLineByChar(40);
    cout << "         Add Client Screen" << endl;
    PrintLineByChar(40);

    AddNewClients(ClientsFileName);
}

void ShowDeleteClientScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintLineByChar(40);
    cout << "         Delete Client Screen" << endl;
    PrintLineByChar(40);

    DeleteClintByAccountNumber(ClientsFileName, ReadAccountNumber(), vClients);
}

void ShowUpdateClientInfoScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintLineByChar(40);
    cout << "         Update Client Screen" << endl;
    PrintLineByChar(40);

    UpdateClintByAccountNumber(ClientsFileName, ReadAccountNumber(), vClients);
}

void ShowFindClientScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    PrintLineByChar(40);
    cout << "         Find Client Screen" << endl;
    PrintLineByChar(40);

    FindClientScreen(vClients);
}

void GoBackToMainMenue()
{
    cout << "\nPress any key to go to Main Menue.";
    system("pause>0");
    ShowMainMenueScreen();
}

void GoBackToTransactionMenue()
{
    cout << "\nPress any key to go to Transaction Menue.";
    system("pause>0");
    ShowTransactionMenueScreen();
}

enum enTransactionType
{
    enDeposit = 0,
    enWithdraw = 1
};

bool TransactionClientsCash(vector<stClient> &vClients, string AccountNumber, double Amount, enTransactionType TransactionType)
{
    Amount = (TransactionType == enDeposit) ? Amount : -Amount;

    char answer = 'n';
    cout << "Are you sure you want perform this transaction ? [y/n] ? ";
    cin >> answer;

    double NewBalance = 0;

    if (toupper(answer) == 'Y')
    {
        for (stClient &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                NewBalance = C.AccountBalance + Amount;
                C.AccountBalance = NewBalance;
                break;
            }
        }
        SaveClientsDataToFile(ClientsFileName, vClients);
        cout << "\nDone successfully New Balance = " << NewBalance << endl;

        return true;
    }

    return false;
}

void ShowDepositScreen()
{

    PrintLineByChar(40);
    cout << "         Deposit Screen" << endl;
    PrintLineByChar(40);

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    stClient Client;
    string AccountNumber = ReadAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "Enter the amount you want to deposit ? ";
        double Amount;
        cin >> Amount;

        TransactionClientsCash(vClients, AccountNumber, Amount, enDeposit);
    }
    else
    {
        cout << "Client Not Found!" << endl;
    }
    GoBackToTransactionMenue();
}

void ShowWithdrawScreen()
{

    PrintLineByChar(40);
    cout << "         Withdraw Screen" << endl;
    PrintLineByChar(40);

    stClient Client;
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        double Amount = 0;
        PrintClientCard(Client);
        do
        {
            cout << "Enter the amount you want to Withdraw ? ";
            cin >> Amount;

            if (Amount < 0 || Amount > Client.AccountBalance)
            {
                cout << "Amount must be more than [0] and less than Account Balance." << endl;
            }

        } while (Amount < 0 || Amount > Client.AccountBalance);

        TransactionClientsCash(vClients, AccountNumber, Amount, enWithdraw);
    }
    else
    {
        cout << "Account Number Not Found!" << endl;
    }

    GoBackToTransactionMenue();
}

double TotalClientsBalance(vector<stClient> vClients)
{
    double TotalBalance = 0;
    for (stClient &C : vClients)
    {
        TotalBalance += C.AccountBalance;
    }
    return TotalBalance;
}

void ShowBlanceListScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    cout << "                 Balance List (" << vClients.size() << ") Clients(s)." << endl;
    string Title = "| Account Number | Client Name           | Balance |";
    PrintLineByChar(Title.length());
    cout << endl
         << Title << endl;
    PrintLineByChar(Title.length());
    PrintClientRecordsDataInBalanceList(vClients);
    PrintLineByChar(Title.length());
    cout << "\n                Total Balance = " << TotalClientsBalance(vClients) << endl;

    GoBackToTransactionMenue();
}

enTransactionMenueOption ReadTransactionMenueOption()
{
    return (enTransactionMenueOption)Read::ReadNumber("\nChoose What do you want to do? [1 to 4]?");
}

void PerformTransactionMenueOption(enTransactionMenueOption choice)
{
    system("cls");

    switch (choice)
    {
    case enTransactionMenueOption::eDeposit:
    {
        ShowDepositScreen();
        break;
    }
    case enTransactionMenueOption::eWithdraw:
    {
        ShowWithdrawScreen();
        break;
    }
    case enTransactionMenueOption::eTotalBalance:
    {
        ShowBlanceListScreen();
        break;
    }
    case enTransactionMenueOption::eBack:
    {
        ShowMainMenueScreen();
        break;
    }
    default:
    {
        cout << "Invalid Choice" << endl;
        GoBackToTransactionMenue();
        break;
    }
    }
}

void ShowTransactionMenueScreen()
{
    short WidthLine = 50;

    system("cls");
    PrintLineByChar(WidthLine, '=');
    cout << "                Transaction Menue Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    cout << "        [1] Deposit." << endl;
    cout << "        [2] Withdraw." << endl;
    cout << "        [3] Total Balance." << endl;
    cout << "        [4] Back." << endl;
    PrintLineByChar(WidthLine, '=');
    PerformTransactionMenueOption(ReadTransactionMenueOption());
}

void PerformMainMenueOption(enMainMenueOption choice)
{
    system("cls");
    switch (choice)
    {
    case enMainMenueOption::eShowClientsList:
    {
        ShowClientListScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowAddNewClient:
    {
        ShowAddClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowDeleteClient:
    {
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowUpdateClientInfo:
    {
        ShowUpdateClientInfoScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowFindClient:
    {
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eTransactionMenue:
    {
        ShowTransactionMenueScreen();
        break;
    }
    case enMainMenueOption::eExit:
    {
        cout << "======================" << endl;
        cout << "     Good Bye :-)" << endl;
        cout << "======================" << endl;
        break;
    }
    default:
    {
        cout << "Invalid Choice" << endl;
        GoBackToMainMenue();
        break;
    }
    }
}

enMainMenueOption ReadMainMenueOption()
{
    return (enMainMenueOption)Read::ReadNumber("\nChoose What do you want to do? [1 to 7]?");
}

void ShowMainMenueScreen()
{
    short WidthLine = 50;

    system("cls");
    PrintLineByChar(WidthLine, '=');
    cout << "                Main Menue Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    cout << "        [1] Show Clients List." << endl;
    cout << "        [2] Add New Client." << endl;
    cout << "        [3] Delete Client." << endl;
    cout << "        [4] Update Client Info." << endl;
    cout << "        [5] Find Client." << endl;
    cout << "        [6] Transaction Manue Screen." << endl;
    cout << "        [7] Exit" << endl;
    PrintLineByChar(WidthLine, '=');
    PerformMainMenueOption(ReadMainMenueOption());
}

int main()
{
    ShowMainMenueScreen();
}