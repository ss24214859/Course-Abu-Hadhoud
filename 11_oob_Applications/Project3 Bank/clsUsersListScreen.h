#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
#include "clsUser.h"
using namespace std;

class clsUsersListScreen : protected clsScreen
{
public:

private:
    /**
      Prints a single user's record in a formatted list row.
     r The user object whose data will be printed.
     */
    static void _PrintUserRecordInList( clsUser& User)
    {
        // Print the details of a single user in a formatted row
        cout << "| " << setw(20) << left << User.UserName()
             << "| " << setw(22) << left << (User.FirstName() + " " + User.LastName())
             << "| " << setw(25) << left << User.Email()
             << "| " << setw(15) << left << User.Phone()
             << "| " << setw(12) << left << User.Password()
             << "| " << setw(12) << left << User.Permissions() << "|";
    }

    /**
     * @brief Prints all user records from a vector in a formatted list.a
     * @param vUsers Vector containing all user objects to be printed.
     */
    static void _PrintUsersRecordDataInList( vector<clsUser>& vUsers)
    {
        // Iterate through the vector and print each user record
        for ( clsUser& U : vUsers)
        {
            cout << "\t\t";
            _PrintUserRecordInList(U);
            cout << endl;
        }
    }

public:
    /**
     * @brief Displays the user list screen, including headers and all user records.
     */
    static void ShowUsersListScreen()
    {
        // Get all users and prepare screen titles
        vector<clsUser> vUsers = clsUser::GetUsers();
        string TitleOfScreen = "\t     Users List Screen";
        string SubTitleOfScreen = "\t      (" + to_string(vUsers.size()) + ") User(s).";
        string TitleOfList = "\t\t| Username            | Full Name             | Email                    | Phone          | Password    | Permissions |";
        string LineOfList = "\t\t" + clsUtil::PrintLineByChar(TitleOfList.length() - 2);

        // Draw header and print the list
        clsScreen::_DrawScreenHeader(TitleOfScreen, SubTitleOfScreen);
        cout << "\n"
             << LineOfList << "\n\n";
        cout << TitleOfList << endl; // Print the list header
        cout << LineOfList << "\n";

        // Print user records or a message if none exist
        if (vUsers.size() == 0)
            cout << "\n\t\t\t\tNo users available in the system!" << endl;
        else
            _PrintUsersRecordDataInList(vUsers);

        cout << LineOfList << "\n";
    }
};