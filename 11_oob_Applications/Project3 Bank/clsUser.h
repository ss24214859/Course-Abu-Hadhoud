#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../../MyClasss/clsPerson.h"
#include "../../MyClasss/clsString.h"
#include "../../MyClasss/clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
private:
    enum enMode
    {
        EmptyM = 0,
        UpdateM = 1,
        AddNewM = 2,
    };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkForDelete = false;

    // Converts a user Object to a line for file storage
    static string _ConvertUserObjectToLine(clsUser User)
    {
        string Sepretor = "#//#";
        string Line = User.FirstName() + Sepretor +
                      User.LastName() + Sepretor +
                      User.Email() + Sepretor +
                      User.Phone() + Sepretor +
                      User.UserName() + Sepretor +
                      User.Password() + Sepretor +
                      to_string(User.Permissions());
        return Line;
    }

    // Converts a line from file to a user Object
    static clsUser _ConvertLineToUserObject(string Line)
    {
        vector<string> vUser = clsString::Split(Line, "#//#");
        return clsUser(
            enMode::UpdateM,
            vUser[0],      // FirstName
            vUser[1],      // LastName
            vUser[2],      // Email
            vUser[3],      // Phone
            vUser[4],      // UserName
            vUser[5],      // Password
            stoi(vUser[6]) // Permissions
        );
    }

    // Loads all users data from the file into a vector
    static vector<clsUser> _LoadUsersDataFromFile() //
    {
        vector<clsUser> vUsers;

        fstream File;
        File.open("Users.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                vUsers.push_back(User);
            }

            File.close();
        }
        return vUsers;
    }

    // Saves all users data to the file
    void _SaveUsersDataToFile(vector<clsUser> vUsers) //
    {
        fstream file;
        file.open("Users.txt", ios::out);
        if (file.is_open())
        {
            for (clsUser U : vUsers)
            {
                if (U.MarkForDelete() == false)
                {
                    file << _ConvertUserObjectToLine(U) << endl;
                }
            }
            file.close();
        }
    }

    // Updates the current user in the file
    void _Update()
    {
        vector<clsUser> vUsers = _LoadUsersDataFromFile();
        for (clsUser &U : vUsers)
        {
            if (U.UserName() == _UserName)
            {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(vUsers);
    }

    // Adds a new user data line to the file
    void _AddDataLineToFile(string StrDateLine)
    {
        fstream File;
        File.open("Users.txt", ios::out | ios::app);
        if (File.is_open())
        {
            File << StrDateLine << endl;
            File.close();
        }
    }

    // Adds the current user as a new user in the file
    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

    static clsUser _EmptyUserObject()
    {
        return clsUser(enMode::EmptyM, "", "", "", "", "", "", 0);
    }

public:
    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
        _Mode = Mode;
    }

    // Getter and Setter for UserName
    string UserName()
    {
        return _UserName;
    }

    void setUserName(string UserName)
    {
        _UserName = UserName;
    }

    // Getter and Setter for Password
    string Password()
    {
        return _Password;
    }

    void setPassword(string Password)
    {
        _Password = Password;
    }

    // Getter and Setter for Permissions
    int Permissions()
    {
        return _Permissions;
    }

    void setPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    bool MarkForDelete()
    {
        return _MarkForDelete;
    }

    //-------------------------------------------------------
    // Checks if the user Object is empty
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyM);
    }

    // Checks if a user exists by username
    static bool IsUserExist(string UserName)
    {
        clsUser U = Find(UserName);
        return !U.IsEmpty();
    }

    // Finds and returns a user by username
    static clsUser Find(string UserName)
    {
        fstream File;
        File.open("Users.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsUser U = _ConvertLineToUserObject(Line);
                if (U.UserName() == UserName)
                {
                    File.close();
                    return U;
                }
            }
            File.close();
        }

        return _EmptyUserObject();
    }

    // Finds and returns a user by username and password
    static clsUser Find(string UserName, string Password)
    {
        fstream File;
        File.open("Users.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsUser U = _ConvertLineToUserObject(Line);
                if ((U.UserName() == UserName) && (U.Password() == Password))
                {
                    File.close();
                    return U;
                }
            }
            File.close();
        }

        return _EmptyUserObject();
    }

    // Returns a new user object for adding a new user
    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewM, "", "", "", "", UserName, "", 0);
    }

    // Returns a list of all users
    static vector<clsUser> GetUsers()
    {
        return _LoadUsersDataFromFile();
    }

    bool Delete()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser &U : _vUsers)
        {
            if (U.UserName() == _UserName)
            {
                U._MarkForDelete = true;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);

        *this = _EmptyUserObject();

        return true;
    }

    enum enSaveResult
    {
        SvFaildEmptyObject = 0,
        SvSucceeded = 1,
        svFaildAccountisExist = 2
    };
    // Saves the client object to the file (add or update)
    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyM:
            return SvFaildEmptyObject;
        case enMode::UpdateM:
            _Update();
            return SvSucceeded;
        case enMode::AddNewM:
            if (IsUserExist(this->UserName()))
                return svFaildAccountisExist;
            else
            {
                _AddNew();
                _Mode = enMode::UpdateM;
                return SvSucceeded;
            }
        }
        return SvSucceeded;
    }
};
