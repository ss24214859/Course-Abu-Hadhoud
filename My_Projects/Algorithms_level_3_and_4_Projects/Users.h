#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <bitset>

#include "../../MyLiberary/ReadLip.h"
#include "../../MyLiberary/StringLip.h"

namespace Users
{
    using namespace std;
    struct stUsers
    {
        string UserName;
        string Password;
        int Permissions;
        bool MarkForDelete;
    };

    stUsers ConvertUserLineToRecord(string LineRecord, string Saperator = "#//#")
    {
        stUsers User;
        vector<string> vUserssRecord = String::SpletStringInVector(LineRecord, Saperator);

        if (vUserssRecord.size() < 3)
        {
            User.UserName = "";
            User.Password = "";
            User.Permissions = 0;
        }

        User.UserName = vUserssRecord[0];
        User.Password = vUserssRecord[1];
        try
        {
            User.Permissions = stoi(vUserssRecord[2]);
        }
        catch (const std::exception &e)
        {
            User.Permissions = 0;
        }

        return User;
    }

    string ConvertUserRecordToLine(stUsers User, string Saperator = "#//#")
    {
        string UserDataStr = "";

        UserDataStr += User.UserName + Saperator;
        UserDataStr += User.Password + Saperator;
        UserDataStr += to_string(User.Permissions) + Saperator;
        return UserDataStr;
    }

    vector<stUsers> LoadUsersDataFromFile(string FileName) //
    {
        vector<stUsers> vUsers;

        fstream File;
        File.open(FileName, ios::in);
        if (File.is_open())
        {
            string Line;
            stUsers User;
            while (getline(File, Line))
            {
                User = ConvertUserLineToRecord(Line, "#//#");
                vUsers.push_back(User);
            }

            File.close();
        }
        return vUsers;
    }

    vector<stUsers> SaveUsersDataToFile(string FileName, vector<stUsers> vUsers) //
    {
        fstream file;
        file.open(FileName, ios::out);
        if (file.is_open())
        {
            for (stUsers C : vUsers)
            {
                if (C.MarkForDelete == false)
                    file << ConvertUserRecordToLine(C, "#//#") << endl;
            }
            file.close();
        }
        return vUsers;
    }

    bool UserExiestsByUserName(string FileName, string UserName)
    {
        vector<stUsers> vUsers = LoadUsersDataFromFile(FileName);

        for (stUsers U : vUsers)
        {
            if (U.UserName == UserName)
                return true;
        }
        return false;
    }

    stUsers ReadNewUser(string FileName)
    {
        stUsers User;
        User.UserName = Read::ReadLine("Enter User Name? ");
        while (UserExiestsByUserName(FileName, User.UserName))
        {
            cout << "User With '" << User.UserName << "'already exists, Enter Another Username ? ";
            User.UserName = Read::ReadLine();
        }

        User.Password = Read::ReadNumber("Enter Password? ");

        if (Read::ReadYesOrNo("Do You Want to give Full access? y/n ?"))
            User.Permissions = -1;

        bitset<7> command;
        cout << "Do you want to give access to : " << endl;
        command |= (Read::ReadYesOrNo("Clients List ?") << 0);
        command |= (Read::ReadYesOrNo("Add New Client?") << 1);
        command |= (Read::ReadYesOrNo("Delete Client ?") << 2);
        command |= (Read::ReadYesOrNo("Update Client ?") << 3);
        command |= (Read::ReadYesOrNo("Find Client ?") << 4);
        command |= (Read::ReadYesOrNo("Transaction Menue ?") << 5);
        command |= (Read::ReadYesOrNo("Manage Users?") << 6);

        User.Permissions = command.to_ulong();

        return User;
    }

    void AddDataLineToFile(string FileName, string DataLine)
    {
        fstream File;
        File.open(FileName, ios::out | ios::app);
        if (File.is_open())
        {
            File << DataLine << endl;
            File.close();
        }
    }

    void AddUserToFile(string FileName, stUsers User)
    {
        AddDataLineToFile(FileName, ConvertUserRecordToLine(User));
    }

    void AddNewUsers(string FileName)
    {
        do
        {
            AddUserToFile(FileName, ReadNewUser(FileName));
        } while (Read::ReadYesOrNo("Do you want to add more Users ? [y/n] ? "));
    }

}