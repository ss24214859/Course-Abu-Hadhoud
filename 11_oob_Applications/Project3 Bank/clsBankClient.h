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
        EmptyM = 0,
        UpdateM = 1,
        AddNewM = 2,
    };
    enMode _Mode;
    string _AccountNumber;
    string _PINCode;
    double _AccountBalance;
    bool _MarkForDelete = false;

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
            enMode::UpdateM,
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

    void _SaveClientsDataToFile(vector<clsBankClient> vClients) //
    {
        fstream file;
        file.open("Clients.txt", ios::out);
        if (file.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C._MarkForDelete = true)
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
        _SaveClientsDataToFile(vClients);
    }

    void _AddDataLineToFile(string StrDateLine)
    {
        fstream File;
        File.open("Clients.txt", ios::out | ios::app);
        if (File.is_open())
        {
            File << StrDateLine << endl;
            File.close();
        }
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    void _Delete()
    {
        vector<clsBankClient> ClientsData = _LoadClientsDataFromFile();
        for (clsBankClient &C : ClientsData)
        {
            if (C.AccountNumber() == _AccountNumber)
                _MarkForDelete = true;
        }
        _SaveClientsDataToFile(ClientsData);
    }

    static clsBankClient _EmptyClientObject()
    {
        return clsBankClient(enMode::EmptyM, "", "", "", "", "", "", 0.0);
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
    // Get For _MarkForDelete
    bool MarkForDelete()
    {
        return _MarkForDelete;
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
        return (_Mode == enMode::EmptyM);
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

    bool Delete()
    {
        _Delete();
        if (!IsClientExist(_AccountNumber))
        {
            *this = _EmptyClientObject();
            return true;
        }
        return false;
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

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewM, "", "", "", "", AccountNumber, "", 0.0);
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    enum enSaveResult
    {
        SvFaildEmptyObject = 0,
        SvSucceeded = 1,
        svFaildAccountisExist = 2
    };
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
            if (IsClientExist(this->AccountNumber()))
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