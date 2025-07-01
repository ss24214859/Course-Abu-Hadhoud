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

    static void ReadUserInfo(clsUser &User)
    {
        User.setFirstName(clsInputValidate::ReadString("Enter First Name : "));
        User.setLastName(clsInputValidate::ReadString("Enter Last Name : "));
        User.setEmail(clsInputValidate::ReadString("Enter Email : "));
        User.setPhone(clsInputValidate::ReadString("Enter Phone : "));
        User.setPassword(clsInputValidate::ReadString("Enter Password : "));
        User.setPermissions(clsInputValidate::ReadDblNumber("Enter Permissions : "));
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