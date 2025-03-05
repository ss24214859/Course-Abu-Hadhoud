#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <C:\Users\ss242\Documents\repos\MyLiberary\MyLib.h>
using namespace std;

void ShowMainMenueScreen();

const string ClientsFileName = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PINcode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

void PrintLineByChar(int width, char ch = '_')
{

    for (int i = 0; i < width; i++)
        cout << ch;

    cout << "\n";
}

vector<string> SpletStringInVector(string S1, string Delimeter)
{
    vector<string> vStrWords;
    short pos = 0;
    string Word;

    while ((pos = S1.find(Delimeter)) != string::npos)
    {
        Word = S1.substr(0, pos);

        if (Word != "")
            vStrWords.push_back(Word);

        S1.erase(0, pos + Delimeter.length());
    }
    if (S1 != "")
        vStrWords.push_back(S1);

    return vStrWords;
}

stClient ConvertLineToRecord(string Line, string Delimeter = "/##/")
{
    vector<string> ClientData = SpletStringInVector(Line, Delimeter); // to split the line of client data into vector

    stClient Client;
    Client.AccountNumber = ClientData[0];
    Client.PINcode = ClientData[1];
    Client.Name = ClientData[2];
    Client.Phone = ClientData[3];
    Client.AccountBalance = stod(ClientData[4]);
    Client.MarkForDelete = false;

    return Client;
}

string ConvertRecordToLine(stClient Client, string Delimeter = "/##/")
{

    string Line = "";

    Line += Client.AccountNumber + Delimeter;
    Line += Client.PINcode + Delimeter;
    Line += Client.Name + Delimeter;
    Line += Client.Phone + Delimeter;
    Line += to_string(Client.AccountBalance);

    return Line;
}

vector<stClient> LoadClientsDataFromFile(string FileName)
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

vector<stClient> SaveClientsDataToFile(string FileName, vector<stClient> vClients)
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

void PrintRecordInList(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber
         << "| " << setw(10) << left << Client.PINcode
         << "| " << setw(22) << left << Client.Name
         << "| " << setw(20) << left << Client.Phone
         << "| " << setw(8) << left << Client.AccountBalance << "|";
}

void PrintClientCardsDataInList(vector<stClient> vClients)
{
    for (stClient C : vClients)
    {
        PrintRecordInList(C);
        cout << endl;
    }
}

void ShowClientListScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string length = " Balance ";
    cout << "                 Client List (" << vClients.size() << ") Clients(s)." << endl;
    string Title = "| Account Number | PIN Code  | Client Name           | Phone Number        | Balance |";
    PrintLineByChar(Title.length());
    cout << endl
         << Title << endl;
    PrintLineByChar(Title.length());
    PrintClientCardsDataInList(vClients);
    PrintLineByChar(Title.length());
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

stClient ReadClient()
{
    cout << "Add Clients:\n" << endl;

    stClient Client;
    cout << "Enter Account Number ?";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(ClientsFileName, Client.AccountNumber))
    {
        cout << "Account Number \'"<<Client.AccountNumber<<"\' already exists. Please enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    } 

    cout << "Enter PIN Code ?";
    getline(cin, Client.PINcode);
    cout << "Enter Name ?";
    getline(cin, Client.Name);
    cout << "Enter Phone ?";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance ?";
    cin >> Client.AccountBalance;

    return Client;
}

stClient ChanchClientRecord(string AccountNumber)
{
    stClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "Enter PIN Code ?";
    getline(cin >> ws, Client.PINcode);
    cout << "Enter Name ?";
    getline(cin, Client.Name);
    cout << "Enter Phone ?";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance ?";
    cin >> Client.AccountBalance;

    return Client;
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

void AddNewClients()
{
    do
    {
        AddClient(ClientsFileName, ReadClient());
    } while (IO::ReadYesOrNo("Do you want to add more Client ? [y/n] ? "));
}

string ReadAccountNumber()
{
    string AccountNumber;
    cout << "Enter Account Number ?";
    getline(cin >> ws, AccountNumber);
    return AccountNumber;
}

bool FindCLientByAccountNumber(string AccountNumber, vector<stClient> vClients, stClient &Client)
{
    for (stClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void PrintClientCard(stClient Client)
{
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "PIN Code : " << Client.PINcode << endl;
    cout << "Name : " << Client.Name << endl;
    cout << "Phone : " << Client.Phone << endl;
    cout << "Account Balance : " << Client.AccountBalance << endl;
}

void FindClientScreen(vector<stClient> vClients)
{
    stClient Client;
    if (FindCLientByAccountNumber(ReadAccountNumber(), vClients, Client)) // return Client And is Found or not.
        PrintClientCard(Client);
    else
        cout << "Client Not Found!" << endl;
}

void MarkClientForDelete(string AccountNumber, vector<stClient> &vClients)
{
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
            C.MarkForDelete = true;
    }
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
    stClient Client;
    char Delete = 'n';

    if (FindCLientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "Do you want to delete this Client ? [y/n] ? ";
        cin >> Delete;
        if (toupper(Delete) == 'Y')
        {
            MarkClientForDelete(AccountNumber, vClients);

            SaveClientsDataToFile(ClientsFileName, vClients);

            // refreach Data.
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "\nClient Deleted successfully." << endl;
            return true;
        }
    }
    else
    {
        cout << "Client Not Found!" << endl;
    }
    return false;
}

bool UpdateClientInfoByAccountNubmer(string AccountNumber, vector<stClient> &vClients)
{
    stClient Client;
    char Delete = 'n';

    if (FindCLientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "Do you want to Update this Client ? [y/n] ? ";
        cin >> Delete;
        if (toupper(Delete) == 'Y')
        {
            for (stClient &C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChanchClientRecord(AccountNumber);
                    break;
                }
            }

            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\nClient Updated successfully." << endl;
            return true;
        }
    }
    else
    {
        cout << "Client Not Found!" << endl;
    }
    return false;
}

void ShowAddClientsScreen()
{
    PrintLineByChar(40);
    cout << "         Add Client Screen" << endl;
    PrintLineByChar(40);

    AddNewClients();
}

void ShowDeleteClientScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintLineByChar(40);
    cout << "         Delete Client Screen" << endl;
    PrintLineByChar(40);

    DeleteClientByAccountNumber(ReadAccountNumber(), vClients);
}

void ShowUpdateClientInfoScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    PrintLineByChar(40);
    cout << "         Update Client Screen" << endl;
    PrintLineByChar(40);

    UpdateClientInfoByAccountNubmer(ReadAccountNumber(), vClients);
}

void ShowFindClientScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    PrintLineByChar(40);
    cout << "         Find Client Screen" << endl;
    PrintLineByChar(40);

    FindClientScreen(vClients);
}

enum enMainMenueOption
{
    eShowClientsList = 1,
    eShowAddNewClient = 2,
    eShowDeleteClient = 3,
    eShowUpdateClientInfo = 4,
    eShowFindClient = 5,
    eExit = 6
};

void GoBackToMainMenue()
{
    cout << "\nPress any key to go to Main Menue.";
    system("pause>0");
    ShowMainMenueScreen();
}

void PerformMainMenueOption(enMainMenueOption choice)
{
    system("cls");

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    switch (choice)
    {
    case enMainMenueOption::eShowClientsList:
    {
        ShowClientListScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowAddNewClient:
    {
        ShowAddClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowDeleteClient:
    {
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowUpdateClientInfo:
    {
        ShowUpdateClientInfoScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eShowFindClient:
    {
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOption::eExit:
    {
        cout<<"======================"<<endl;
        cout<<"     Good Bye :-)" << endl;
        cout<<"======================"<<endl;
        break;
    }
    default:
    {
        cout << "Invalid Choice" << endl;
        GoBackToMainMenue();
        break;
    }
    }
}

enMainMenueOption ReadMainMenueOption()
{
    short Choice;
    cout << "\nChoose What do you want to do? [1 to 6]?";
    cin >> Choice;
    return (enMainMenueOption)Choice;
}

void ShowMainMenueScreen()
{
    short WidthLine = 50;

    system("cls");
    PrintLineByChar(WidthLine, '=');
    cout << "                Main Menue Screen" << endl;
    PrintLineByChar(WidthLine, '=');
    cout << "        [1] Show Clients List." << endl;
    cout << "        [2] Add New Client." << endl;
    cout << "        [3] Delete Client." << endl;
    cout << "        [4] Update Client Info." << endl;
    cout << "        [5] Find Client." << endl;
    cout << "        [6] eExit" << endl;
    PrintLineByChar(WidthLine, '=');
    PerformMainMenueOption(ReadMainMenueOption());
}

int main()
{
    ShowMainMenueScreen();
}