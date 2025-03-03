#include<iostream>
#include<limits>
#include<string>
#include<vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName="ClientsDat.txt";

struct stClientData
{
    string AccountNumber;
    string PINcode;
    string Name;
    string  Phone;
    double AccountBalance;
    bool MarkForDelete=false;
};

vector<string> SplitStringInVector(string S1,string delimiter)
{
    vector<string> vStrWords;
    short pos=0;
    string Word;
    
    while((pos=S1.find(delimiter))!= string::npos)
    {
        Word=S1.substr(0,pos);
        
        if(Word!="")
        vStrWords.push_back(Word);
        
        S1.erase(0,pos+delimiter.length());
    }
    if(S1!="")
        vStrWords.push_back(S1);
        
    return vStrWords;    
}


double ReadPositiveNumber(string massge)
{
    double num=0;
    do
    {
        cout<<massge;
        cin>>num;
    }while(num<0);
    return num;
}

string ReadString(string Massage)
{
    string Input="";
    cout<<Massage;
    getline(cin,Input);
    return Input;
}

string ReadAccountNumber(string Massage)
{
    string Input="";
    cout<<Massage;
    cin>>Input;
    return Input;
}

stClientData ReadNewClient()
{
    stClientData ClientData;
    cout<<"Enter Account Number : ";
    getline(cin>>ws,ClientData.AccountNumber);
    cout<<"Enter PIN Code : ";
    getline(cin,ClientData.PINcode);
    cout<<"Enter Name : ";
    getline(cin,ClientData.Name);
    cout<<"Enter Phone  : ";
    getline(cin,ClientData.Phone);
    cout<<"Enter Account Balance : ";
    cin>>ClientData.AccountBalance;

    return ClientData;
}

string ConvertRecordToLine(stClientData ClientData,string Saperator="#//#")
{
    string ClientDataStr="";
    
    ClientDataStr+=ClientData.AccountNumber+Saperator;
    ClientDataStr+=ClientData.PINcode+Saperator;
    ClientDataStr+=ClientData.Name+Saperator;
    ClientDataStr+=ClientData.Phone+Saperator;
    ClientDataStr+=to_string(ClientData.AccountBalance);
    
    return ClientDataStr;
}

stClientData ConvertLineToRecord(string LineRecord,string Saperator="#//#")
{
    stClientData ClientData;
    vector<string> vClientRecord=SplitStringInVector(LineRecord,Saperator);

    ClientData.AccountNumber=vClientRecord[0];
    ClientData.PINcode=vClientRecord[1];
    ClientData.Name=vClientRecord[2];
    ClientData.Phone=vClientRecord[3];
    ClientData.AccountBalance=stod(vClientRecord[4]);
    

    return ClientData;
}

void PrintClientData(stClientData ClientData)
{
    cout<<"Account Number  : "<<ClientData.AccountNumber<<endl;
    cout<<"PIN Code        : "<<ClientData.PINcode<<endl;
    cout<<"Name            : "<<ClientData.Name<<endl;
    cout<<"Phone           : "<<ClientData.Phone<<endl;
    cout<<"Account Balance : "<<ClientData.AccountBalance<<endl;
}

vector<stClientData> LoadClientsDataFromFile(string FileName)
{
    vector<stClientData> vFileData;
    fstream File;
    File.open(FileName,ios::in);
    
    if(File.is_open())
    {
        stClientData CLient;
        string Line;
        while(getline(File,Line))
        {
            CLient=ConvertLineToRecord(Line,"#//#");
            vFileData.push_back(CLient);
        }
        File.close();
    }
    else
    cout<<"\nField to Open File :-("<<endl;
    
    
    return vFileData;
}

void PrintContantFromFile(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName,ios::in);
    
    if(MyFile.is_open())
    {
        string Line;
        while(getline(MyFile,Line))
        {
            cout<<Line<<endl;
        }
        MyFile.close();
    }
    
}

vector<stClientData> SaveClientsDataToFile(string FileName , vector<stClientData> vClientsData)
{
    fstream File;
    File.open(FileName, ios::out);
    if(File.is_open())
    {
        string line="";
        for(stClientData& Client : vClientsData)
        {
            if(Client.MarkForDelete==false)
            line=ConvertRecordToLine(Client);
            File<<line<<endl;
        }
        File.close();
    }
    return vClientsData;
}


void PrintVector(vector<string> vect)
{
    for(string& line : vect)
    {
        cout<<line<<endl;
    }
}


void AddDataLineToFile(string FileName ,string DataLine )
{
    fstream File;
    File.open(FileName,ios::out | ios:: app);
    if( File.is_open() )
    {
        File<<DataLine<<endl;
        File.close();
    }
}


void AddClient()
{
    stClientData Client=ReadNewClient();
    
    AddDataLineToFile(ClientsFileName,ConvertRecordToLine(Client));
}

void AddClients()
{

    char AddMore='y';
        
    while( tolower(AddMore)=='y' ) 
    {
        system("cls");
        cout<<"Add Client :\n"<<endl;
        AddClient();
        cout<<"Client Added Successfully , do you want to Add More Clients ?";
        cin>>AddMore;
    }
}

void PrintLine(int width,char ch='_')
{
    cout<<"\n";
    for(int i=0;i<width;i++)
    cout<<ch;
    
    cout<<"\n";
}

void PrintRecordInList(stClientData ClientData)
{
    cout<<"| "<<setw(15)<<ClientData.AccountNumber
        <<" | "<<setw(10)<<ClientData.PINcode
        <<" | "<<setw(20)<<left<<ClientData.Name
        <<" | "<<setw(15)<<left<<ClientData.Phone
        <<" | "<<setw(10)<<left<<ClientData.AccountBalance;
}

void PrintClientsDataInList(vector<stClientData> vClientsData)
{
    for(stClientData& Client : vClientsData)
    {
        PrintRecordInList(Client);
        cout<<endl;
    }
}



void PrintClientList(vector<stClientData> vClientsData)
{
    cout<<"The Following Are The client details :"<<endl;
    cout<<setw(40)<<("Client List (" + vClientsData.size() + ") Client(s)." );
    PrintLine(80);
    cout<<"\n| "<<"Account Number " //15
        <<" | "<< "PIN Code  "     //10
        <<" | "<<setw(20)<<left<<"Client Name"
        <<" | "<<setw(15)<<left<<"Phone"
        <<" | "<<setw(10)<<left<<"Balance";
        
    PrintLine(80);
    PrintClientsDataInList(vClientsData);
    PrintLine(80);
    
}


bool FindClientByAccountNumber(string AccountNumber,vector<stClientData> vClientsData ,stClientData& Client)
{
    for(stClientData& c : vClientsData)
    {
        if(c.AccountNumber == AccountNumber)
        {
            Client=c;
            return true;
        }
    }
    return false;
}

bool MarkClintForDeleteByAccountNumber(string AccountNumber,vector<stClientData>& ClientsData)
{
    for(stClientData& C : ClientsData)
    {
        if(C.AccountNumber==AccountNumber)
        {
            C.MarkForDelete=true;
            return true;
        }
    }
    return false;
}
bool DeleteClintByAccountNumber(string AccountNumber,vector<stClientData>& ClientsData)
{
    stClientData Client;
    char Delete='n';
    if(FindClientByAccountNumber(AccountNumber,ClientsData,Client))
    {
        PrintClientData(Client);
        
        cout<<"do you want to delete it ?[y,n]? ";
        cin>>Delete;
        
        if(toupper(Delete)=='Y')
        {
            MarkClintForDeleteByAccountNumber(AccountNumber,ClientsData);
        
            SaveClientsDataToFile(ClientsFileName,ClientsData);
        
            ClientsData=LoadClientsDataFromFile(ClientsFileName);
            
            cout<<"Client Deleted Successfully. "<<endl;
            
            return true;
        }
    }
    else
    {
        cout<<"Client With Account Number ("<<AccountNumber<<") Not Found!"<<endl;
        return false;
    }

}

int main()
{
    
    //AddClients();

   // PrintContantFromFile(ClientsFileName);
    
    vector<stClientData> ClientsData=LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber=ReadAccountNumber("\nEnter Account Number ? ");
    
    DeleteClintByAccountNumber(AccountNumber, ClientsData);
    
    PrintContantFromFile(ClientsFileName);
    
    //PrintClientList(vClientsData);
}