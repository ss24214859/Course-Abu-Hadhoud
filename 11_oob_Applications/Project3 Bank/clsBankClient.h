#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../../MyClasss/clsPerson.h"
#include "../../MyClasss/clsString.h"
#include "../../MyClasss/clsUtil.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        Empty = 0,
        Update = 1
    };
    enMode _Mode;
    string _AccountNumber;
    string _PINCode;
    double _AccountBalance;

    static string _ConvertClientObjectToLine(clsBankClient Client)
    {
        string Sepretor = "#//#";
        string Line = Client.FirstName() + Sepretor +
                      Client.LastName() + Sepretor +
                      Client.Email() + Sepretor +
                      Client.Phone() + Sepretor +
                      Client.AccountNumber() + Sepretor +
                      Client.PINCode() + Sepretor +
                      to_string(Client.AccountBalance());
        return Line;
    }

    static clsBankClient _ConvertLineToClientobject(string Line)
    {
        vector<string> vClient = clsString::Split(Line, "#//#");
        return clsBankClient(
            enMode::Update,
            vClient[0],      // FirstName
            vClient[1],      // LastName
            vClient[2],      // Email
            vClient[3],      // Phone
            vClient[4],      // AccountNumber
            vClient[5],      // PINCode
            stod(vClient[6]) // AccountBalance
        );
    }

    static vector<clsBankClient> _LoadClientsDataFromFile() //
    {
        vector<clsBankClient> vClients;

        fstream File;
        File.open("Clients.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsBankClient Client = _ConvertLineToClientobject(Line);
                vClients.push_back(Client);
            }

            File.close();
        }
        return vClients;
    }

    void SaveClientsDataToFile(vector<clsBankClient> vClients) //
    {
        fstream file;
        file.open("Clients.txt", ios::out);
        if (file.is_open())
        {
            for (clsBankClient C : vClients)
            {
                file << _ConvertClientObjectToLine(C) << endl;
            }
            file.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        for (clsBankClient &C : vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C = *this;
                break;
            }
        }
        SaveClientsDataToFile(vClients);
    }

    void AddDataLineToFile(string StrDateLine)
    {
        fstream File;
        File.open("Client.txt", ios::out | ios::app);
        if (File.is_open())
        {
            File << StrDateLine << endl;
            File.close();
        }
    }
    static clsBankClient _EmptyClientObject()
    {
        return clsBankClient(enMode::Empty, "", "", "", "", "", "", 0.0);
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PINCode, double AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PINCode = PINCode;
        _AccountBalance = AccountBalance;
    }

    // Get for _AccountNumber
    string AccountNumber()
    {
        return _AccountNumber;
    }

    // Getter and Setter for _PINCode
    string PINCode()
    {
        return _PINCode;
    }
    void SetPINCode(string pinCode)
    {
        _PINCode = pinCode;
    }

    // Getter and Setter for _AccountBalance
    double AccountBalance()
    {
        return _AccountBalance;
    }
    void SetAccountBalance(double accountBalance)
    {
        _AccountBalance = accountBalance;
    }

    //-------------------------------------------------------
    bool IsEmpty()
    {
        return (_Mode == enMode::Empty);
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient C = Find(AccountNumber);
        return !C.IsEmpty();
    }

    void Print()
    {
        cout << "\nClient Card: " << endl;
        clsUtil::PrintLineByChar(50);
        cout << "FirstName       : " << FirstName() << endl;
        cout << "LastName        : " << LastName() << endl;
        cout << "Name            : " << FullName() << endl;
        cout << "Email           : " << Email() << endl;
        cout << "Phone           : " << Phone() << endl;
        cout << "Account Number  : " << _AccountNumber << endl;
        cout << "PIN Code        : " << _PINCode << endl;
        cout << "Account Balance : " << _AccountBalance << endl;
        clsUtil::PrintLineByChar(50);
    }

    static void Print(clsBankClient Client)
    {
        Client.Print();
    }

    static clsBankClient Find(string AccountNumber)
    {
        fstream File;
        File.open("Clients.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsBankClient C = _ConvertLineToClientobject(Line);
                if (C.AccountNumber() == AccountNumber)
                {
                    File.close();
                    return C;
                }
            }
            File.close();
        }

        return _EmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PINCode)
    {
        fstream File;
        File.open("Clients.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                clsBankClient C = _ConvertLineToClientobject(Line);
                if ((C.AccountNumber() == AccountNumber) && (C.PINCode() == PINCode))
                {
                    File.close();
                    return C;
                }
            }
            File.close();
        }

        return _EmptyClientObject();
    }

    enum enSaveResult
    {
        SvFaildEmptyObject = 0,
        SvSucced = 1
    };
    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::Empty:
            return SvFaildEmptyObject;
        case enMode::Update:
            _Update();
            return SvSucced;
        }
        return SvSucced;
    }
};