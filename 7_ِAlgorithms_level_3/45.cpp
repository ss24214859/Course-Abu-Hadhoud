#include<iostream>
#include<limits>
#include<string>
#include<vector>
#include <C:\CoursesMohamedAbuHadoud\MyLiberary\MyLib.h>
using namespace std;

struct stClientData
{
    string AccountNumber;
    string PINcode;
    string Name;
    string  Phone;
    double AccountBalance;
};

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

stClientData ReadNewClient()
{
    stClientData ClientData;
    cout<<"Enter Account Number : ";
    getline(cin,ClientData.AccountNumber);
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
    ClientDataStr+=(to_string(ClientData.AccountBalance));
    
    return ClientDataStr;
}

int main()
{
    stClientData ClientData=ReadNewClient();

    string ClientDataLine=ConvertRecordToLine(ClientData);
    
    cout<<ClientDataLine<<endl;
         
    return 0;
}