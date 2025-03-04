#include<iostream>
#include<limits>
#include<string>
#include<vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName="Clients";

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
    cout<<setw((WidthLine/2)+8)<<"Main Menue Screen"<<endl;
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

    while(pos=S1.find(Delimeter) != string::npos)
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
    cout<<"| "<<setw(15)<<Client.AccountNumber
        <<"| "<<setw(10)<<Client.PINcode
        <<"| "<<setw(23)<<Client.Name
        <<"| "<<setw(21)<<Client.Phone
        <<"| "<<setw(10)<<Client.AccountBalance;

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
    cout<<Title<<endl;
    PrintLineByChar(Title.length());
    PrintClientsDataInList(vClients);
    PrintLineByChar(Title.length());
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
            cout<<"Add New Client"<<endl;
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