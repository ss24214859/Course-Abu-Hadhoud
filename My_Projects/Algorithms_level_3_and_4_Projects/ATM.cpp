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

void ShowQuickWithdrawScreen();
void ShowATMMainMenueScreen();
void Login();

enum enTransactionType
{
    enDeposit = 0,
    enWithdraw = 1
};

enum enATMMainMenueOptions
{
    eQuickWhithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eChackBalance = 4,
    eLogout = 5
};

enum enQuickWhithdrawOptions
{
    e20 = 1,
    e50 = 2,
    e100 = 3,
    e200 = 4,
    e400 = 5,
    e600 = 6,
    e800 = 7,
    e1000 = 8,
    eExit = 9
};
const string ClientsFileName = "Clients.txt";
stClient CurrentClient;

bool TransactionClientsCash(double Amount, enTransactionType TransactionType)
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    Amount = (TransactionType == enDeposit) ? Amount : -Amount;

    char answer = 'n';
    cout << "Are you sure you want perform this transaction ? [y/n] ? ";
    cin >> answer;
    if (toupper(answer) == 'Y')
    {
        for (stClient &C : vClients)
        {
            if (C.AccountNumber == CurrentClient.AccountNumber)
            {
                CurrentClient.AccountBalance = C.AccountBalance + Amount;
                C.AccountBalance = CurrentClient.AccountBalance;
                break;
            }
        }
        SaveClientsDataToFile(ClientsFileName, vClients);

        cout << "\nDone successfully New Balance = " << CurrentClient.AccountBalance << endl;

        return true;
    }

    return false;
}

int AmountOfQuickWithdraw(enQuickWhithdrawOptions WithdrawOP)
{

    switch (WithdrawOP)
    {
    case enQuickWhithdrawOptions::e20:
        return 20;
        break;
    case enQuickWhithdrawOptions::e50:
        return 50;
        break;
    case enQuickWhithdrawOptions::e100:
        return 100;
        break;
    case enQuickWhithdrawOptions::e200:
        return 200;
        break;
    case enQuickWhithdrawOptions::e400:
        return 400;
        break;
    case enQuickWhithdrawOptions::e600:
        return 600;
        break;
    case enQuickWhithdrawOptions::e800:
        return 800;
        break;
    case enQuickWhithdrawOptions::e1000:
        return 1000;
        break;
    default:
        return 0;
        break;
    }
}

void PerformQuickWithdrawOptions(enQuickWhithdrawOptions WithdrawOP)
{
    if (WithdrawOP == enQuickWhithdrawOptions::eExit)
        return;

    int Amount = AmountOfQuickWithdraw(WithdrawOP);

    if (Amount < 0 || Amount > CurrentClient.AccountBalance)
    {
        cout << "The Amount exceeds Your Balance, Make another choice." << endl;
        system("pause");
        ShowQuickWithdrawScreen();
    }

    else
        TransactionClientsCash(Amount, enTransactionType::enWithdraw);
}

void ShowQuickWithdrawScreen()
{
    system("cls");
    cout << "=========================================\n"
         << "        Quick Withdraw Screen\n"
         << "=========================================\n";
    cout << "     [1] 20         [2] 50" << endl;
    cout << "     [3] 100        [4] 200" << endl;
    cout << "     [5] 400        [6] 600" << endl;
    cout << "     [7] 800        [8] 1000" << endl;
    cout << "     [9] Exit" << endl;
    cout << "=========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance << endl;
    PerformQuickWithdrawOptions((enQuickWhithdrawOptions)Read::ReadIntNumberBetween(1, 9, "Choice What to withdraw from [1] to [8] ? "));
}

void ShowNormalWithdrawScreen()
{
    system("cls");
    short WidthLine = 40;
    PrintLineByChar(WidthLine, '=');
    cout << "            Normal Withdraw Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    int Amount = Read::ReadNumberMultipleOfX(5, "Enter An Amount Multiple Of ");

    if (Amount > CurrentClient.AccountBalance)
    {
        cout << "The Amount exceeds Your Balance." << endl;
        cout << "press any key to continue...";
        system("pause>0");
        ShowNormalWithdrawScreen();
        return;
    }
    TransactionClientsCash(Amount, enTransactionType::enWithdraw);
}

void ShowDepositScreen()
{
    system("cls");
    short WidthLine = 35;
    PrintLineByChar(WidthLine, '=');
    cout << "            Deposit Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    int Amount = Read::ReadNumberMultipleOfX(5, "Enter An Amount Multiple Of ");
    TransactionClientsCash(Amount, enTransactionType::enDeposit);
}

void ShowChackBalanceScreen()
{
    system("cls");
    short WidthLine = 40;
    PrintLineByChar(WidthLine, '=');
    cout << "            Chack Balance Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    cout << "Your Balance is " << CurrentClient.AccountBalance << endl;
    system("pause");
}

void GoBackToATMMainMenue()
{
    cout << "\nPress any key to go to Main Menue.";
    system("pause>0");
    ShowATMMainMenueScreen();
}

void PerformATMMainMenueOption(enATMMainMenueOptions Choice)
{
    switch (Choice)
    {
    case enATMMainMenueOptions::eQuickWhithdraw:
        ShowQuickWithdrawScreen();
        GoBackToATMMainMenue();
        break;
    case enATMMainMenueOptions::eNormalWithdraw:
        ShowNormalWithdrawScreen();
        GoBackToATMMainMenue();
        break;
    case enATMMainMenueOptions::eDeposit:
        ShowDepositScreen();
        GoBackToATMMainMenue();
        break;
    case enATMMainMenueOptions::eChackBalance:
        ShowChackBalanceScreen();
        GoBackToATMMainMenue();
        break;
    case enATMMainMenueOptions::eLogout:
        Login();
        break;
    default:
        cout << "Invalid Choice" << endl;
        GoBackToATMMainMenue();
        break;
    }
}

void ShowATMMainMenueScreen()
{
    short WidthLine = 50;
    system("cls");
    PrintLineByChar(WidthLine, '=');
    cout << "               ATM Main Menue Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    cout << "        [1] Quick Withdraw." << endl;
    cout << "        [2] Normal Withdraw." << endl;
    cout << "        [3] Deposit." << endl;
    cout << "        [4] Chack Balance." << endl;
    cout << "        [5] Logout." << endl;
    PrintLineByChar(WidthLine, '=');
    PerformATMMainMenueOption((enATMMainMenueOptions)Read::ReadNumber("Chice What do you want to do? [ 1 To 5 ]? "));
}

bool ChackLogin(string AccountNumber, string PINCode)
{
    fstream File;
    File.open(ClientsFileName, ios::in);
    if (File.is_open())
    {
        string Line;
        stClient C;
        while (getline(File, Line))
        {
            C = ConvertLineToRecord(Line);
            if ((C.AccountNumber == AccountNumber) && (C.PINcode == PINCode))
            {
                CurrentClient = C;
                File.close();
                return true;
            }
        }
        File.close();
    }
    return false;
}

void Login()
{
    short WidthLine = 35;
    system("cls");
    PrintLineByChar(WidthLine, '=');
    cout << "         Login Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    string AccountNumber = Read::ReadLine("Enter Account Number?");
    string PINCode = Read::ReadLine("Enter PINCode?");
    while (!ChackLogin(AccountNumber, PINCode))
    {
        cout << "Invalid Account Number/PIN Code!" << endl;
        AccountNumber = Read::ReadLine("Enter Account Number?");
        PINCode = Read::ReadLine("Enter PINCode?");
    }

    ShowATMMainMenueScreen();
}

int main()
{
    Login();
}