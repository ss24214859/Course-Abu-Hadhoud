#include <iostream>
#include <string>
#include <vector>
#include "StringLip.h"
#include "ReadLip.h"
namespace Clients
{
    using namespace std;

    struct stClient
    {
        string AccountNumber;
        string PINcode;
        string Name;
        string Phone;
        double AccountBalance;
        bool MarkForDelete = false;
    };

    stClient ReadNewClient()
    {
        stClient ClientData;
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

    stClient ExtructClientRecord(string LineRecord, string Saperator)
    {
        stClient ClientData;
        vector<string> vClientRecord = String::SpletStringInVector(LineRecord, Saperator);

        ClientData.AccountNumber = vClientRecord[0];
        ClientData.PINcode = vClientRecord[1];
        ClientData.Name = vClientRecord[2];
        ClientData.Phone = vClientRecord[3];
        ClientData.AccountBalance = stod(vClientRecord[4]);

        return ClientData;
    }

    void PrintClientData(stClient ClientData)
    {
        cout << "Account Number  : " << ClientData.AccountNumber << endl;
        cout << "PIN Code        : " << ClientData.PINcode << endl;
        cout << "Name            : " << ClientData.Name << endl;
        cout << "Phone           : " << ClientData.Phone << endl;
        cout << "Account Balance : " << ClientData.AccountBalance << endl;
    }

    string ConvertRecordToLine(stClient ClientData, string Saperator = "/##/")
    {
        string ClientDataStr = "";

        ClientDataStr += ClientData.AccountNumber + Saperator;
        ClientDataStr += ClientData.PINcode + Saperator;
        ClientDataStr += ClientData.Name + Saperator;
        ClientDataStr += ClientData.Phone + Saperator;
        ClientDataStr += to_string(ClientData.AccountBalance);

        return ClientDataStr;
    }

    stClient ConvertLineToRecord(string LineRecord, string Saperator = "/##/")
    {
        stClient ClientData;
        vector<string> vClientRecord = String::SpletStringInVector(LineRecord, Saperator);

        ClientData.AccountNumber = vClientRecord[0];
        ClientData.PINcode = vClientRecord[1];
        ClientData.Name = vClientRecord[2];
        ClientData.Phone = vClientRecord[3];
        ClientData.AccountBalance = stod(vClientRecord[4]);

        return ClientData;
    }

    bool ClientExistsByAccountNumber(string FileName, string AccountNumber)
    {
        fstream File;
        File.open(FileName, ios::in);
        if (File.is_open())
        {
            string Line;
            stClient Client;
            while (getline(File, Line))
            {
                Client = ConvertLineToRecord(Line);
                if (Client.AccountNumber == AccountNumber)
                {
                    File.close();
                    return true;
                }
            }

            File.close();
        }
        return false;
    }

    stClient ReadClient(string FileName)
    {
        cout << "Add Clients:\n"
             << endl;

        stClient Client;
        Client.AccountNumber = Read::ReadLine("Enter Account Number ?");

        while (ClientExistsByAccountNumber(FileName, Client.AccountNumber))
        {
            cout << "Account Number \'" << Client.AccountNumber << "\' already exists. Please enter another Account Number? ";
            Client.AccountNumber = Read::ReadLine();
        }
        cin, Client.PINcode = Read::ReadLine("Enter PIN Code ?");
        cin, Client.Name = Read::ReadLine("Enter Name ?");
        cin, Client.Phone = Read::ReadLine("Enter Phone ?");
        Client.AccountBalance = Read::ReadNumber("Enter Account Balance ?");

        return Client;
    }

    stClient ChanchClientRecord(string AccountNumber)
    {
        stClient Client;
        Client.AccountNumber = AccountNumber;
        cin, Client.PINcode = Read::ReadLine("Enter PIN Code ?");
        cin, Client.Name = Read::ReadLine("Enter Name ?");
        cin, Client.Phone = Read::ReadLine("Enter Phone ?");
        Client.AccountBalance = Read::ReadNumber("Enter Account Balance ?");
        return Client;
    }

    //////////  Files  ////////////

    vector<stClient> LoadClientsDataFromFile(string FileName) //
    {
        vector<stClient> vClients;

        fstream File;
        File.open(FileName, ios::in);
        if (File.is_open())
        {
            string Line;
            stClient Client;
            while (getline(File, Line))
            {
                Client = ConvertLineToRecord(Line);
                vClients.push_back(Client);
            }

            File.close();
        }
        return vClients;
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

    vector<stClient> SaveClientsDataToFile(string FileName, vector<stClient> vClients) //
    {
        fstream file;
        file.open(FileName, ios::out);
        if (file.is_open())
        {
            for (stClient C : vClients)
            {
                if (C.MarkForDelete == false)
                    file << ConvertRecordToLine(C) << endl;
            }
            file.close();
        }
        return vClients;
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

    void AddClient(string FileName, stClient Client)
    {
        fstream file;
        file.open(FileName, ios::app | ios::out);
        if (file.is_open())
        {
            file << ConvertRecordToLine(Client) << endl;
            file.close();
        }
    }

    void AddNewClients(string FileName)
    {
        do
        {
            AddClient(FileName, ReadClient(FileName));
        } while (Read::ReadYesOrNo("Do you want to add more Client ? [y/n] ? "));
    }

    bool FindClientByAccountNumber(string AccountNumber, vector<stClient> vClientsData, stClient &Client)
    {
        for (stClient &c : vClientsData)
        {
            if (c.AccountNumber == AccountNumber)
            {
                Client = c;
                return true;
            }
        }
        return false;
    }

    bool MarkClintForDeleteByAccountNumber(string AccountNumber, vector<stClient> &ClientsData)
    {
        for (stClient &C : ClientsData)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.MarkForDelete = true;
                return true;
            }
        }
        return false;
    }

    bool DeleteClintByAccountNumber(string FileName, string AccountNumber)
    {
        vector<stClient> ClientsData = LoadClientsDataFromFile(FileName);
        stClient Client;
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
            cout << "Client With Account Number (" << AccountNumber << ") Not Found!" << endl;

        return false;
    }

    stClient ChangeClientRecord(string AccountNumber)
    {
        stClient ClientData;

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

    bool UpdateClintByAccountNumber(string FileName, string AccountNumber, vector<stClient> &ClientsData)
    {
        stClient Client;
        char Delete = 'n';
        if (FindClientByAccountNumber(AccountNumber, ClientsData, Client))
        {
            PrintClientData(Client);

            cout << "\ndo you want to update it ?[y,n]? ";
            cin >> Delete;

            if (toupper(Delete) == 'Y')
            {
                for (stClient &C : ClientsData)
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