#pragma once
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

    // Converts a client object to a line for file storage
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

    // Converts a line from file to a client object
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

    // Loads all clients data from the file into a vector
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

    // Saves all clients data to the file
    void _SaveClientsDataToFile(vector<clsBankClient> vClients) //
    {
        fstream file;
        file.open("Clients.txt", ios::out);
        if (file.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkForDelete() == false)
                {
                    file << _ConvertClientObjectToLine(C) << endl;
                }
            }
            file.close();
        }
    }

    // Updates the current client in the file
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

    // Adds a new client data line to the file
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

    // Adds the current client as a new client in the file
    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    // Returns an empty client object
    static clsBankClient _EmptyClientObject()
    {
        return clsBankClient(enMode::EmptyM, "", "", "", "", "", "", 0.0);
    }

        string _PrepareTransferRecord(clsBankClient To, double Amount, string Sep="#//#")
    {
        return clsDate::GetSystemDateTimeString() + Sep +
                _AccountNumber + Sep +
                To.AccountNumber() + Sep +
                to_string(Amount)+Sep+
                to_string(_AccountBalance)+Sep+
                to_string(To.AccountBalance())+Sep+
                CurrentUser.UserName();
    }

public:
    struct stTransferLogRecord
    {
        string DateTime;
        string From_AccNum;
        string To_AccNum;
        double Amount;
        double From_BalanceAfter; //After Transfer.
        double To_BalanceAfter;  //After Transfer.
        string User;
    };

private:
    static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line)
    {
        vector<string> vParts = clsString::Split(Line, "#//#");
        if (vParts.size() == 7)
        {
            stTransferLogRecord Record;
            Record.DateTime = vParts[0];
            Record.From_AccNum = vParts[1];
            Record.To_AccNum = vParts[2];
            Record.Amount = stod(vParts[3]);
            Record.From_BalanceAfter = stod(vParts[4]);
            Record.To_BalanceAfter = stod(vParts[5]);
            Record.User = vParts[6];
            return Record;
        }
        return stTransferLogRecord({"", "", "", 0,0,0,""});
    }

public:
    // Constructor for clsBankClient
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PINCode, double AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PINCode = PINCode;
        _AccountBalance = AccountBalance;
    }

    // Returns the account number
    string AccountNumber()
    {
        return _AccountNumber;
    }
    // Returns the mark for delete flag
    bool MarkForDelete()
    {
        return _MarkForDelete;
    }

    // Returns the PIN code
    string PINCode()
    {
        return _PINCode;
    }
    // Sets the PIN code
    void SetPINCode(string pinCode)
    {
        _PINCode = pinCode;
    }

    // Returns the account balance
    double AccountBalance()
    {
        return _AccountBalance;
    }
    // Sets the account balance
    void SetAccountBalance(double accountBalance)
    {
        _AccountBalance = accountBalance;
    }

    //-------------------------------------------------------
    // Checks if the client object is empty
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyM);
    }

    // Checks if a client exists by account number
    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient C = Find(AccountNumber);
        return !C.IsEmpty();
    }

    // Prints the client information to the console
    /*
        No UI Related code Inside Object.
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
     */

    // Deletes the client and returns true if successful
    bool Delete()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                break;
            }
        }

        _SaveClientsDataToFile(_vClients);

        *this = _EmptyClientObject();

        return true;
    }

    // Finds and returns a client by account number
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

    // Finds and returns a client by account number and PIN code
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

    // Returns the total balance of all clients
    static double GetTotalBalances()
    {
        double TotalBalance = 0;
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        for (clsBankClient C : vClients)
        {
            TotalBalance += C.AccountBalance();
        }
        return TotalBalance;
    }

    // Returns a new client object for adding a new client
    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewM, "", "", "", "", AccountNumber, "", 0.0);
    }

    // Returns a list of all clients
    static vector<clsBankClient> GetClients()
    {
        return _LoadClientsDataFromFile();
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
        }
        return true;
    }

    bool Transfer(clsBankClient &To ,double Amount)
    {
        if(!Withdraw(Amount)) return false;
        To.Deposit(Amount);
        return true;
    }

    enum enSaveResult
    {
        svFaildEmptyObject = 0,
        svSucceeded = 1,
        svFaildAccountisExist = 2
    };
    // Saves the client object to the file (add or update)
    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyM:
            return svFaildEmptyObject;
        case enMode::UpdateM:
            _Update();
            return svSucceeded;
        case enMode::AddNewM:
            if (IsClientExist(this->AccountNumber()))
                return svFaildAccountisExist;
            else
            {
                _AddNew();
                _Mode = enMode::UpdateM;
                return svSucceeded;
            }
        }
        return svSucceeded;
    }
    
    void SaveInTransferLog(clsBankClient To ,double Amount)
    {
        string TransferRecord = _PrepareTransferRecord(To,Amount);
        // Save the current user information to a file or database
        fstream file;
        file.open("TransferLog.txt", ios::out | ios::app);
        if(file.is_open())
        {
            file <<TransferRecord<< endl;
            file.close();
        }
        else
            cout << "Error opening file to save Transfer info." << endl;
    }

    // Loads transfer log records from the file into a vector
    static vector<stTransferLogRecord> LoadTransferLogRecords()
    {
        vector<stTransferLogRecord> vRecords;
        fstream File;
        File.open("TransferLog.txt", ios::in);
        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                stTransferLogRecord Record = _ConvertLineToTransferLogRecord(Line);
                if (Record.DateTime != "")
                {
                    vRecords.push_back(Record);
                }
            }
            File.close();
        }
        return vRecords;
    }
};