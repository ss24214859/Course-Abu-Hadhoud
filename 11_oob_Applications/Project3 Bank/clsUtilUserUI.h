#pragma once
#include <iostream>
#include "clsUser.h"
#include "../../MyClasss/clsInputValidate.h"

using namespace std;

class clsUtilUserUI
{
public:
    static string ReadExistingUserName()
    {
        string UserName = clsInputValidate::ReadString("Please Enter User Name : ");
        while (!clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidate::ReadString("User Name does not exist, please enter another one : ");
        }
        return UserName;
    }

    static string ReadNewUserName()
    {
        string UserName = clsInputValidate::ReadString("Please Enter User Name : ");
        while (clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidate::ReadString("User Name already exists, please enter another one : ");
        }
        return UserName;
    }

    enum enPermissions {
        eClientsList = 1,
        eAddNewClient = 2,
        eDeleteClient = 4,
        eUpdateClientInfo = 8,
        eFindClient = 16,
        eTransactionMenue = 32,
        eManageUserMenue = 64,
    };
    static int ReadPermissions()
    {
        /*  This code is commented out because it is not used in the current implementation.

        int Permissions = 0;

        if (Read::ReadYesOrNo("Do You Want to give Full access? y/n ?"))
            Permissions = -1;
        else
        {
            bitset<7> command;
            cout << "Do you want to give access to : " << endl;
            command += (Read::ReadYesOrNo("Clients List ?") << 0);
            command += (Read::ReadYesOrNo("Add New Client?") << 1);
            command += (Read::ReadYesOrNo("Delete Client ?") << 2);
            command += (Read::ReadYesOrNo("Update Client ?") << 3);
            command += (Read::ReadYesOrNo("Find Client ?") << 4);
            command += (Read::ReadYesOrNo("Transaction Menue ?") << 5);
            command += (Read::ReadYesOrNo("Manage Users?") << 6);

            Permissions = command.to_ulong();
        }
        return Permissions; 
        */


        int Permissions = 0;

        if(clsInputValidate::ReadYesOrNo("Do You Want to give Full access? y/n ?"))
            Permissions = -1;
        else
        {
            cout << "Do you want to give access to : " << endl;
            if (clsInputValidate::ReadYesOrNo("Clients List ?"))
                Permissions += enPermissions::eClientsList;

            if (clsInputValidate::ReadYesOrNo("Add New Client?"))
                Permissions += enPermissions::eAddNewClient;

            if (clsInputValidate::ReadYesOrNo("Delete Client ?"))
                Permissions += enPermissions::eDeleteClient;

            if (clsInputValidate::ReadYesOrNo("Update Client ?"))
                Permissions += enPermissions::eUpdateClientInfo;

            if (clsInputValidate::ReadYesOrNo("Find Client ?"))
                Permissions += enPermissions::eFindClient;

            if (clsInputValidate::ReadYesOrNo("Transaction Menue ?"))
                Permissions += enPermissions::eTransactionMenue;

            if (clsInputValidate::ReadYesOrNo("Manage Users?"))
                Permissions += enPermissions::eManageUserMenue;
        }
        return Permissions;
        
    }

    static void ReadUserInfo(clsUser &User)
    {
        User.setFirstName(clsInputValidate::ReadString("Enter First Name : "));
        User.setLastName(clsInputValidate::ReadString("Enter Last Name : "));
        User.setEmail(clsInputValidate::ReadString("Enter Email : "));
        User.setPhone(clsInputValidate::ReadString("Enter Phone : "));
        User.setPassword(clsInputValidate::ReadString("Enter Password : "));
        User.setPermissions(ReadPermissions());
    }

    static void Print(clsUser User)
    {
        cout << "\n" << clsUtil::PrintLineByChar(50) << endl;
        cout << "\nUser Card: " << endl;
        cout << clsUtil::PrintLineByChar(50) << endl;
        cout << "FirstName       : " << User.FirstName() << endl;
        cout << "LastName        : " << User.LastName() << endl;
        cout << "Name            : " << User.FullName() << endl;
        cout << "Email           : " << User.Email() << endl;
        cout << "Phone           : " << User.Phone() << endl;
        cout << "User Name       : " << User.UserName() << endl;
        cout << "Password        : " << User.Password() << endl;
        cout << "Permissions     : " << User.Permissions() << endl;
        cout << clsUtil::PrintLineByChar(50) << endl;
    }
}; 