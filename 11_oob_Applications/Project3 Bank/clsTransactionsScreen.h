#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsDepositScreen.h"
using namespace std;

class clsTransactionsScreen : clsScreen
{
private:
    enum enTransactionMenueOption
    {
        eDeposit = 1,
        eWithdraw = 2,
        eTotalBalance = 3,
        eBack = 4
    };

    // Shows the deposit screen
    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    // Shows the withdraw screen
    static void _ShowWithdrawScreen()
    {
        cout << "\n[Withdraw Screen]\n";
        // Add withdraw logic here
    }

    // Shows the total balance list screen
    static void _ShowBlanceListScreen()
    {
        cout << "\n[Total Balance Screen]\n";
        // Add total balance logic here
    }

    // Returns to the transaction menu after a pause
    static void _GoBackToTransactionMenue()
    {
        cout << "\nPress any key to go to Transaction Menue.";
        system("pause>0");
        ShowTransactionMenueScreen();
    }

    // Reads the user's menu option selection
    static enTransactionMenueOption _ReadTransactionMenueOption()
    {
        short choice;
        cout << "\n\t\tChoose an option [1-4]: ";
        choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter a valid option between 1 and 4: ");
        return (enTransactionMenueOption)choice;
    }

    // Performs the selected transaction menu option
    static void _PerformTransactionMenueOption(enTransactionMenueOption choice)
    {
        system("cls");

        switch (choice)
        {
        case enTransactionMenueOption::eDeposit:
        {
            _ShowDepositScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransactionMenueOption::eWithdraw:
        {
            _ShowWithdrawScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransactionMenueOption::eTotalBalance:
        {
            _ShowBlanceListScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case enTransactionMenueOption::eBack:
        {
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
            _GoBackToTransactionMenue();
            break;
        }
        }
    }

public:
    static void ShowTransactionMenueScreen()
    {
        short WidthLine = 50;

        system("cls");
        _DrawScreenHeader("\t Transaction Menue Screen");
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        cout << setw(37) << left << "" << "                Transaction Menue " << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=') << endl;
        cout << setw(37) << left << "" << "        [1] Deposit." << endl;
        cout << setw(37) << left << "" << "        [2] Withdraw." << endl;
        cout << setw(37) << left << "" << "        [3] Total Balance." << endl;
        cout << setw(37) << left << "" << "        [4] Back." << endl;
        cout << setw(37) << left << "" << clsUtil::PrintLineByChar(WidthLine, '=');
        _PerformTransactionMenueOption(_ReadTransactionMenueOption());
    }
};