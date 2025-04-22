#include <iostream>
#include <string>
#include <vector>
#include "StringLip.h"
namespace Clients
{
    using namespace std;

    struct stClientData
    {
        string AccountNumber;
        string PINcode;
        string Name;
        string Phone;
        double AccountBalance;
        bool MarkForDelete = false;
    };

    stClientData ReadNewClient()
    {
        stClientData ClientData;
        cout << "Enter Account Number : ";
        getline(cin, ClientData.AccountNumber);
        cout << "Enter PIN Code : ";
        getline(cin, ClientData.PINcode);
        cout << "Enter Name : ";
        getline(cin, ClientData.Name);
        cout << "Enter Phone  : ";
        getline(cin, ClientData.Phone);
        cout << "Enter Account Balance : ";
        cin >> ClientData.AccountBalance;

        return ClientData;
    }

    string ConvertRecordToLine(stClientData ClientData, string Saperator = "#//#")
    {
        string ClientDataStr = "";

        ClientDataStr += ClientData.AccountNumber + Saperator;
        ClientDataStr += ClientData.PINcode + Saperator;
        ClientDataStr += ClientData.Name + Saperator;
        ClientDataStr += ClientData.Phone + Saperator;
        ClientDataStr += (to_string(ClientData.AccountBalance));

        return ClientDataStr;
    }

    stClientData ExtructClientRecord(string LineRecord, string Saperator)
    {
        stClientData ClientData;
        vector<string> vClientRecord = String::SplitStringInVector(LineRecord, Saperator);

        ClientData.AccountNumber = vClientRecord[0];
        ClientData.PINcode = vClientRecord[1];
        ClientData.Name = vClientRecord[2];
        ClientData.Phone = vClientRecord[3];
        ClientData.AccountBalance = stod(vClientRecord[4]);

        return ClientData;
    }

    void PrintClientData(stClientData ClientData)
    {
        cout << "Account Number  : " << ClientData.AccountNumber << endl;
        cout << "PIN Code        : " << ClientData.PINcode << endl;
        cout << "Name            : " << ClientData.Name << endl;
        cout << "Phone           : " << ClientData.Phone << endl;
        cout << "Account Balance : " << ClientData.AccountBalance << endl;
    }

    string ConvertRecordToLine(stClientData ClientData, string Saperator = "#//#")
    {
        string ClientDataStr = "";

        ClientDataStr += ClientData.AccountNumber + Saperator;
        ClientDataStr += ClientData.PINcode + Saperator;
        ClientDataStr += ClientData.Name + Saperator;
        ClientDataStr += ClientData.Phone + Saperator;
        ClientDataStr += to_string(ClientData.AccountBalance);

        return ClientDataStr;
    }

    stClientData ConvertLineToRecord(string LineRecord, string Saperator = "#//#")
    {
        stClientData ClientData;
        vector<string> vClientRecord = String::SplitStringInVector(LineRecord, Saperator);

        ClientData.AccountNumber = vClientRecord[0];
        ClientData.PINcode = vClientRecord[1];
        ClientData.Name = vClientRecord[2];
        ClientData.Phone = vClientRecord[3];
        ClientData.AccountBalance = stod(vClientRecord[4]);

        return ClientData;
    }

    //////////  Files  ////////////

    vector<stClientData> LoadClientsDataFromFile(string FileName)
    {
        vector<stClientData> vFileData;
        fstream File;
        File.open(FileName, ios::in);

        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                vFileData.push_back(ConvertLineToRecord(Line));
            }
            File.close();
        }
        return vFileData;
    }

    void PrintContantFromFile(string FileName)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                cout << Line << endl;
            }
            MyFile.close();
        }
    }

    vector<stClientData> SaveClientsDataToFile(string FileName, vector<stClientData> vClientsData)
    {
        fstream File;
        File.open(FileName, ios::out);
        string line;
        if (File.is_open())
        {

            for (stClientData Client : vClientsData)
            {
                if (Client.MarkForDelete == false)
                {
                    line = ConvertRecordToLine(Client);
                    File << line << endl;
                }
            }
            File.close();
        }
        return vClientsData;
    }

    void PrintVector(vector<string> vect)
    {
        for (string &line : vect)
        {
            cout << line << endl;
        }
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

    void AddClientToFile(string FileName)
    {
        stClientData Client = ReadNewClient();

        AddDataLineToFile(FileName, ConvertRecordToLine(Client));
    }

    void AddClients(string FileName)
    {

        char AddMore = 'y';

        while (tolower(AddMore == 'y'))
        {
            system("cls");
            cout << "Add Client :\n"
                 << endl;
            AddClientToFile(FileName);
            cout << "Client Added Successfully , do you want to Add More Clients ?";
            cin >> AddMore;
        }
    }

    bool FindClientByAccountNumber(string AccountNumber, vector<stClientData> vClientsData, stClientData &Client)
    {
        for (stClientData &c : vClientsData)
        {
            if (c.AccountNumber == AccountNumber)
            {
                Client = c;
                return true;
            }
        }
        return false;
    }

    bool MarkClintForDeleteByAccountNumber(string AccountNumber, vector<stClientData> &ClientsData)
    {
        for (stClientData &C : ClientsData)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.MarkForDelete = true;
                return true;
            }
        }
        return false;
    }

    bool DeleteClintByAccountNumber(string FileName, string AccountNumber, vector<stClientData> &ClientsData)
    {
        string FileName;

        stClientData Client;
        char Delete = 'n';
        if (FindClientByAccountNumber(AccountNumber, ClientsData, Client))
        {
            PrintClientData(Client);

            cout << "do you want to delete it ?[y,n]? ";
            cin >> Delete;

            if (toupper(Delete) == 'Y')
            {
                MarkClintForDeleteByAccountNumber(AccountNumber, ClientsData);

                SaveClientsDataToFile(FileName, ClientsData);

                ClientsData = LoadClientsDataFromFile(FileName);

                cout << "Client Deleted Successfully. " << endl;

                return true;
            }
        }
        else
        {
            cout << "Client With Account Number (" << AccountNumber << ") Not Found!" << endl;
            return false;
        }
    }

    stClientData ChangeClientRecord(string AccountNumber)
    {
        stClientData ClientData;

        ClientData.AccountNumber = AccountNumber;
        cout << "Enter PIN Code : ";
        getline(cin >> ws, ClientData.PINcode);
        cout << "Enter Name : ";
        getline(cin, ClientData.Name);
        cout << "Enter Phone  : ";
        getline(cin, ClientData.Phone);
        cout << "Enter Account Balance : ";
        cin >> ClientData.AccountBalance;

        return ClientData;
    }

    bool UpdateClintByAccountNumber(string AccountNumber, vector<stClientData> &ClientsData)
    {
        string FileName;

        stClientData Client;
        char Delete = 'n';
        if (FindClientByAccountNumber(AccountNumber, ClientsData, Client))
        {
            PrintClientData(Client);

            cout << "\ndo you want to update it ?[y,n]? ";
            cin >> Delete;

            if (toupper(Delete) == 'Y')
            {
                for (stClientData &C : ClientsData)
                {
                    if (C.AccountNumber == AccountNumber)
                    {
                        C = ChangeClientRecord(AccountNumber);
                        break;
                    }
                }

                SaveClientsDataToFile(FileName, ClientsData);

                ClientsData = LoadClientsDataFromFile(FileName);

                cout << "\nClient updated Successfully. \n"
                     << endl;

                return true;
            }
        }
        else
        {
            cout << "\n\nClient With Account Number (" << AccountNumber << ") Not Found!" << endl;
        }
        return false;
    }

}