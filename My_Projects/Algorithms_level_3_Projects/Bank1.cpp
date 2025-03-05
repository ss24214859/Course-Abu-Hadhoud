#include<iostream>
#include<limits>
#include<string>
#include<vector>
#include <fstream>
#include <iomanip>
#include <C:\Users\ss242\Documents\repos\MyLiberary\MyLib.h>
using namespace std;

const string ClientsFileName="Clients.txt";

struct stClient
{
    string AccountNumber;
    string PINcode;
    string Name;
    string  Phone;
    double AccountBalance;
    bool MarkForDelete=false;
};

void PrintLineByChar(int width,char ch='_')
{
    
    for(int i=0;i<width;i++)
    cout<<ch;
    
    cout<<"\n";
}

void MainMenueScreen()
{
    short WidthLine=50;
    
    system("cls");
    PrintLineByChar(WidthLine,'-');
    PrintLineByChar(WidthLine,'-');
    cout<<"                Main Menue Screen"<<endl;
    PrintLineByChar(WidthLine,'-');
    PrintLineByChar(WidthLine,'-');
    cout<<"        [1] Show Clients List."<<endl;
    cout<<"        [2] Add New Client."<<endl;
    cout<<"        [3] Delete Client."<<endl;
    cout<<"        [4] Update Client Info."<<endl;
    cout<<"        [5] Find Client."<<endl;
    cout<<"        [6] Exit"<<endl;
    PrintLineByChar(WidthLine,'-');
    PrintLineByChar(WidthLine,'-');
    
}

vector<string> SpletStringInVector(string S1,string Delimeter)
{
    vector<string> vStrWords;
    short pos=0;
    string Word;

    while((pos=S1.find(Delimeter)) != string::npos)
    {
        Word=S1.substr(0,pos);

        if(Word != "")
        vStrWords.push_back(Word);

        S1.erase(0,pos+Delimeter.length());
    }
    if(S1 != "")
    vStrWords.push_back(S1);

    return vStrWords;

}

stClient ConvertLineToRecord(string Line,string Delimeter="/##/")
{
    vector<string> ClientData=SpletStringInVector(Line,Delimeter);  //to split the line of client data into vector

    stClient Client;
    Client.AccountNumber=ClientData[0];
    Client.PINcode=ClientData[1];
    Client.Name=ClientData[2];
    Client.Phone=ClientData[3];
    Client.AccountBalance=stod(ClientData[4]);
    Client.MarkForDelete=false;

    return Client;
}
 
string ConvertRecordToLine(stClient Client, string Delimeter="/##/")
{
 
    string Line="";
    
    Line+=Client.AccountNumber+Delimeter;
    Line+=Client.PINcode+Delimeter;
    Line+=Client.Name+Delimeter;
    Line+=Client.Phone+Delimeter;
    Line+=to_string(Client.AccountBalance);
    
    return Line;
    
}

vector<stClient> LoadClientsData(string FileName)
{
    vector<stClient> vClients;
    
    fstream File;
    File.open(FileName,ios::in);
    if(File.is_open())
    {
        string Line;
        stClient Client;
        while(getline(File,Line))
        {
            Client=ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        
        File.close();
    }
    return vClients;
        
}


void PrintRecordInList(stClient Client)
{
    cout<<"| "<<setw(15)<<left<<Client.AccountNumber
        <<"| "<<setw(10)<<left<<Client.PINcode
        <<"| "<<setw(22)<<left<<Client.Name
        <<"| "<<setw(20)<<left<<Client.Phone
        <<"| "<<setw(8)<<left<<Client.AccountBalance<<"|";

}

void PrintClientsDataInList(vector<stClient> vClients)
{
        for(stClient C : vClients)
        {
            PrintRecordInList(C);
            cout<<endl;
        }
}

void PrintClientList(vector<stClient> vClients)
{
    string length=" Balance ";
    cout<<setw(40)<<"Client List (" << vClients.size() << ") Clients(s)."<<endl;
    string Title ="| Account Number | PIN Code  | Client Name           | Phone Number        | Balance |";
    PrintLineByChar(Title.length());
    cout<<endl<<Title<<endl;
    PrintLineByChar(Title.length());
    PrintClientsDataInList(vClients);
    PrintLineByChar(Title.length());
}

stClient ReadClient()
{
    cout<<"Add Clients:\n"<<endl;
    stClient Client;
    cout<<"Enter Account Number ?";
    getline(cin>>ws,Client.AccountNumber);
    cout<<"Enter PIN Code ?";
    getline(cin,Client.PINcode);
    cout<<"Enter Name ?";
    getline(cin,Client.Name);
    cout<<"Enter Phone ?";
    getline(cin,Client.Phone);
    cout<<"Enter Account Balance ?";
    cin>>Client.AccountBalance;

    return Client;
}

void AddClientToFile(string FileName,stClient Client)
{
    fstream file;
    file.open(FileName,ios::app | ios::out);
    if(file.is_open())
    {
        file<<ConvertRecordToLine(Client)<<endl;
        file.close();
    }
}

void AddClients()
{
    do
    {
        AddClientToFile(ClientsFileName,ReadClient());
    } while (IO::ReadYesOrNo("Do you want to add more Client ? [y/n] ? "));
}

void DoChoice(short choice)
{
    system("cls");
    
    vector<stClient> vClients=LoadClientsData(ClientsFileName);
    
    switch (choice)
    {
        case 1: 
        {
            PrintClientList(vClients);
            break;
        }
        case 2:
        {
            PrintLineByChar(35);
            cout<<setw(10)<<"Add New Client"<<endl;
            PrintLineByChar(35);
            AddClients();
            break;
        }
        case 3:
        {
            cout<<"Delete Client"<<endl;
            break;
        }
        case 4:
        {
            cout<<"Update Client Info"<<endl;
            break;
        }
        case 5:
        {
            cout<<"Find Client"<<endl;
            break;
        }
        default:
        {
            if(choice != 6)
            cout<<"Invalid Choice"<<endl;

            break;
        }
    }
   
}

void StartProgram()
{
    short Choice=0;
    while( Choice != 6 )
    {
        MainMenueScreen();
        cout<<"Choose What do you want to do? [1 to 6]?";
        cin>>Choice;
        DoChoice(Choice);
        cout<<"\n";
        if(Choice != 6)
        system("pause");
        
    }
}

    
int main()
{

    StartProgram();

}