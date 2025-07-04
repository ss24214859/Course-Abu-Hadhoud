#pragma once
#include <iostream>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsDate.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;

// Base class for all screen classes in the application
class clsScreen
{

private:

    static void _ShowCurrentUser()
    {
        cout<<"\t\t\t\t\tUser: " << CurrentUser.UserName()<<endl;
    }
    static void _ShowDate()
    {
        cout<<"\t\t\t\t\tDate: " <<clsDate::DateToString(clsDate()) << endl;
    }

protected:
    // Draws a formatted screen header with a title and optional subtitle
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        // Print a line separator
        cout << "\t\t\t\t\t" << clsUtil::PrintLineByChar(45) << endl;
        // Print the main title
        cout << "\n\t\t\t\t\t" << Title << endl;
        // Print the subtitle if provided
        if (SubTitle != "")
            cout << "\t\t\t\t\t" << SubTitle << endl;

        // Print another line separator
        cout << "\t\t\t\t\t" << clsUtil::PrintLineByChar(45) << endl;

        _ShowCurrentUser();
        _ShowDate();
    }

    static bool ChackAccessRights(clsUser::enPermissions Permission)
    {
        if(!CurrentUser.ChackAccessPermission(Permission))
        {
            // Clear the console screen
            system("cls");
            // Print a line separator
            cout << "\t\t\t\t\t" << clsUtil::PrintLineByChar(55) << endl;
            // Print the main title
            cout << "\n\t\t\t\t\t" << "       Access Denied! Contact Your Admin." << endl;
            // Print another line separator
            cout << "\t\t\t\t\t" << clsUtil::PrintLineByChar(55) << endl;
            return false;
        }
        else
        return true;
    }
};