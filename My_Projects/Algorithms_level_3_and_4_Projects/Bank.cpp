#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <bitset>
#include "../../MyLiberary/ClientLib.h"
#include "../../MyLiberary/ReadLip.h"
#include "../../MyLiberary/patternLib.h"
#include "Users.h"

using namespace std;
using namespace Clients;
using namespace Pattern;
using namespace Users;

void ShowTransactionMenueScreen();
void ShowMainMenueScreen();
void ShowManageUserMenueScreen();
void LogIn();

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";
stUsers CurrentUser;

enum enMainMenueOption
{
    eShowClientsList = 1,
    eShowAddNewClient = 2,
    eShowDeleteClient = 3,
    eShowUpdateClientInfo = 4,
    eShowFindClient = 5,
    eTransactionMenue = 6,
    eManageUserMenue = 7,
    eExit = 8
};

enum enTransactionMenueOption
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eBack = 4
};

enum enManageUsersMenueOption
{
    eListUsers = 1,
    eAddNewUser = 2,
    eDeleteUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    eMainMenue = 6
};

enum enMainMenuOptionPermissions
{
    eClientsList = 1,
    eAddNewClient = 2,
    eDeleteClient = 4,
    eUpdateClientInfo = 8,
    eFindClient = 16,
    PTransactionMenue = 32,
    PManageUserMenue = 64,
    eAll = -1
};

// Prints a single client record in the client list
void PrintRecordInList(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber
         << "| " << setw(10) << left << Client.PINcode
         << "| " << setw(22) << left << Client.Name
         << "| " << setw(20) << left << Client.Phone
         << "| " << setw(8) << left << Client.AccountBalance << "|";
}

// Prints all client records in the client list
void PrintClientRecordsDataInList(vector<stClient> vClients)
{
    for (stClient C : vClients)
    {
        PrintRecordInList(C);
        cout << endl;
    }
}

// Prints a single client record in the balance list
void PrintRecordInBalanceList(stClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber
         << "| " << setw(22) << left << Client.Name
         << "| " << setw(8) << left << Client.AccountBalance << "|";
}

// Prints all client records in the balance list
void PrintClientRecordsDataInBalanceList(vector<stClient> vClients)
{

    for (stClient C : vClients)
    {
        PrintRecordInBalanceList(C);
        cout << endl;
    }
}

// Prints a single user record in the users list
void PrintUserRecordInUsersList(stUsers User)
{

    cout << "| " << setw(13) << left << User.UserName
         << "| " << setw(10) << left << User.Password
         << "| " << setw(13) << left << User.Permissions << "|";
}

// Prints all user records in the users list
void PrintUsersRecordsInUsersList(vector<stUsers> Users)
{
    for (stUsers U : Users)
    {
        PrintUserRecordInUsersList(U);
        cout << endl;
    }
}

// Shows the client list screen
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

// Prints a client card with details
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

// Shows the find client screen and prints client card if found
void FindClientScreen(vector<stClient> vClients)
{
    stClient Client;
    if (FindClientByAccountNumber(Read::ReadLine("Enter Account Number ? "), vClients, Client)) // return Client And is Found or not.
        PrintClientCard(Client);
    else
        cout << "Client Not Found!" << endl;
}

// Reads an account number from user input
string ReadAccountNumber()
{
    return Read::ReadLine("Enter Account Number ?");
}

// Shows the add client screen
void ShowAddClientsScreen()
{
    PrintLineByChar(40);
    cout << "         Add Client Screen" << endl;
    PrintLineByChar(40);

    AddNewClients(ClientsFileName);
}

// Shows the delete client screen
void ShowDeleteClientScreen()
{
    PrintLineByChar(40);
    cout << "         Delete Client Screen" << endl;
    PrintLineByChar(40);

    DeleteClintByAccountNumber(ClientsFileName, ReadAccountNumber());
}

// Shows the update client info screen
void ShowUpdateClientInfoScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintLineByChar(40);
    cout << "         Update Client Screen" << endl;
    PrintLineByChar(40);

    UpdateClintByAccountNumber(ClientsFileName, ReadAccountNumber(), vClients);
}

// Shows the find client screen
void ShowFindClientScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    PrintLineByChar(40);
    cout << "         Find Client Screen" << endl;
    PrintLineByChar(40);

    FindClientScreen(vClients);
}

// Returns to the main menu after a pause
void GoBackToMainMenue()
{
    cout << "\nPress any key to go to Main Menue.";
    system("pause>0");
    ShowMainMenueScreen();
}

// Returns to the transaction menu after a pause
void GoBackToTransactionMenue()
{
    cout << "\nPress any key to go to Transaction Menue.";
    system("pause>0");
    ShowTransactionMenueScreen();
}

// Returns to the manage user menu after a pause
void GoBackToManageUserMenue()
{
    cout << "\nPress any key to go to Manage User Screen Menue.";
    system("pause>0");
    ShowManageUserMenueScreen();
}

// Enum for transaction types (deposit/withdraw)
enum enTransactionType
{
    enDeposit = 0,
    enWithdraw = 1
};

// Performs a cash transaction (deposit/withdraw) for a client
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

// Shows the deposit screen
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

// Shows the withdraw screen
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
            Amount = Read::ReadPosNum("Enter the amount you want to Withdraw ? ");

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

// Calculates the total balance of all clients
double TotalClientsBalance(vector<stClient> vClients)
{
    double TotalBalance = 0;
    for (stClient &C : vClients)
    {
        TotalBalance += C.AccountBalance;
    }
    return TotalBalance;
}

// Shows the balance list screen
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

// Reads the transaction menu option from user input
enTransactionMenueOption ReadTransactionMenueOption()
{
    return (enTransactionMenueOption)Read::ReadNumber("\nChoose What do you want to do? [1 to 4]?");
}

// Reads the manage user menu option from user input
enManageUsersMenueOption ReadManageUserMenueOption()
{
    return (enManageUsersMenueOption)Read::ReadNumber("\nChoose What do you want to do? [1 to 6]?");
}

// Shows the users list screen
void ShowUsersListScreen()
{
    vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout << "          Users List (" << vUsers.size() << ") User(s)." << endl;
    string Title = "| User Name    | Password  | Permissions  |";
    PrintLineByChar(Title.length());
    cout << endl
         << Title << endl;
    PrintLineByChar(Title.length());
    PrintUsersRecordsInUsersList(vUsers);
    PrintLineByChar(Title.length());
}

// Shows the add user screen
void ShowAddUserScreen()
{
    PrintLineByChar(40);
    cout << "         Add User Screen" << endl;
    PrintLineByChar(40);

    AddNewUsers(UsersFileName);
}

// Shows the delete user screen
void ShowDeleteUserScreen()
{
    PrintLineByChar(40);
    cout << "         Delete User Screen" << endl;
    PrintLineByChar(40);

    DeleteUserByUserName(UsersFileName, ReadUserName());
}

// Shows the update user screen
void ShowUpdateUserScreen()
{
    vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

    PrintLineByChar(40);
    cout << "         Update User Screen" << endl;
    PrintLineByChar(40);

    UpdateUserByUserName(UsersFileName, ReadUserName(), vUsers);
}

// Shows the find user screen
void ShowFindUserScreen()
{
    vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
    PrintLineByChar(40);
    cout << "         Find User Screen" << endl;
    PrintLineByChar(40);

    FindUserScreen(vUsers);
}

// Performs the selected manage user menu option
void PerformManageUserMenueOption(enManageUsersMenueOption choice)
{
    system("cls");

    switch (choice)
    {
    case enManageUsersMenueOption::eListUsers:
    {
        ShowUsersListScreen();
        GoBackToManageUserMenue();
        break;
    }
    case enManageUsersMenueOption::eAddNewUser:
    {
        ShowAddUserScreen();
        GoBackToManageUserMenue();
        break;
    }
    case enManageUsersMenueOption::eDeleteUser:
    {
        ShowDeleteUserScreen();
        GoBackToManageUserMenue();
        break;
    }
    case enManageUsersMenueOption::eUpdateUser:
    {
        ShowUpdateUserScreen();
        GoBackToManageUserMenue();
        break;
    }
    case enManageUsersMenueOption::eFindUser:
    {
        ShowFindUserScreen();
        GoBackToManageUserMenue();
        break;
    }
    case enManageUsersMenueOption::eMainMenue:
    {
        ShowMainMenueScreen();
        break;
    }
    default:
    {
        cout << "Invalid Choice" << endl;
        GoBackToManageUserMenue();
        break;
    }
    }
}

// Shows the manage user menu screen
void ShowManageUserMenueScreen()
{
    short WidthLine = 50;

    system("cls");
    PrintLineByChar(WidthLine, '=');
    cout << "             Manage User Menue Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    cout << "        [1] List Users." << endl;
    cout << "        [2] Add New Users." << endl;
    cout << "        [3] Delete User." << endl;
    cout << "        [4] Update User." << endl;
    cout << "        [5] Find User." << endl;
    cout << "        [6] Main Menue." << endl;
    PrintLineByChar(WidthLine, '=');
    PerformManageUserMenueOption(ReadManageUserMenueOption());
}

// Performs the selected transaction menu option
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

// Shows the transaction menu screen
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

// Checks if the current user has the required permission for the main menu option
bool GetPermissionCaseforMainMenue(enMainMenuOptionPermissions Permission)
{
    if ((CurrentUser.Permissions & Permission) == Permission)
        return true;

    Pattern::PrintLineByChar(40, '-');
    cout << "Access Denied," << endl;
    cout << "You Don't Have Permission To Do This," << endl;
    cout << "Plese Conact Your Admin." << endl;
    Pattern::PrintLineByChar(40, '-');
    return false;
}

// Performs the selected main menu option
void PerformMainMenueOption(enMainMenueOption choice)
{
    system("cls");
    switch (choice)
    {
    case enMainMenueOption::eShowClientsList:
    {
        if (GetPermissionCaseforMainMenue(enMainMenuOptionPermissions::eClientsList))
            ShowClientListScreen();

        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowAddNewClient:
    {
        if (GetPermissionCaseforMainMenue(enMainMenuOptionPermissions::eAddNewClient))
            ShowAddClientsScreen();

        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowDeleteClient:
    {
        if (GetPermissionCaseforMainMenue(enMainMenuOptionPermissions::eDeleteClient))
            ShowDeleteClientScreen();

        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowUpdateClientInfo:
    {
        if (GetPermissionCaseforMainMenue(enMainMenuOptionPermissions::eUpdateClientInfo))
            ShowUpdateClientInfoScreen();

        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowFindClient:
    {
        if (GetPermissionCaseforMainMenue(enMainMenuOptionPermissions::eFindClient))
            ShowFindClientScreen();

        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eTransactionMenue:
    {
        if (GetPermissionCaseforMainMenue(enMainMenuOptionPermissions::PTransactionMenue))
            ShowTransactionMenueScreen();
        else
            GoBackToMainMenue();

        break;
    }
    case enMainMenueOption::eManageUserMenue:
    {
        if (GetPermissionCaseforMainMenue(enMainMenuOptionPermissions::PManageUserMenue))
            ShowManageUserMenueScreen();
        else
            GoBackToMainMenue();

        break;
    }
    case enMainMenueOption::eExit:
    {
        LogIn();
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

// Reads the main menu option from user input
enMainMenueOption ReadMainMenueOption()
{
    return (enMainMenueOption)Read::ReadNumber("\nChoose What do you want to do? [1 to 8]?");
}

// Shows the main menu screen
void ShowMainMenueScreen()
{
    short WidthLine = 50;
    system("cls");
    cout << "User Permissions ( " << CurrentUser.Permissions << " )" << endl;
    PrintLineByChar(WidthLine, '=');
    cout << "                Main Menue Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    cout << "        [1] Show Clients List." << endl;
    cout << "        [2] Add New Client." << endl;
    cout << "        [3] Delete Client." << endl;
    cout << "        [4] Update Client Info." << endl;
    cout << "        [5] Find Client." << endl;
    cout << "        [6] Transaction Manue Screen." << endl;
    cout << "        [7] Manage User Screen." << endl;
    cout << "        [8] Exit" << endl;
    PrintLineByChar(WidthLine, '=');
    PerformMainMenueOption(ReadMainMenueOption());
}

// Handles user login and returns true if successful
bool LoginInfo()
{
    string UserName = ReadUserName();
    string Password = Read::ReadString("Enter Password? ");
    vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);
    if (FindUserByUserNameAndPassword(vUsers, UserName, Password, CurrentUser))
    {
        return true;
    }
    return false;
}

// Shows the login screen and handles login process
void LogIn()
{
    PrintLineByChar(30, '-');
    cout << "      Login Screen" << endl;
    PrintLineByChar(30, '-');

    stUsers User;
    bool IsLogIn = LoginInfo();
    while (!IsLogIn)
    {
        cout << "Invalid Username/password!" << endl;
        IsLogIn = LoginInfo();
    }
    ShowMainMenueScreen();
}

// Program entry point
int main()
{
    LogIn();
}