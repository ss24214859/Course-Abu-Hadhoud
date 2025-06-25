#include <iostream>
#include "clsBankClient.h"
#include "../../MyClasss/clsInputValidate.h"
#include "../../MyClasss/clsString.h"
#include "clsUtilClientUI.h"
using namespace std;

void ReadClientInfo(clsBankClient &Client)
{
    Client.setFirstName(clsInputValidate::ReadString("Enter First Name : "));
    Client.setLastName(clsInputValidate::ReadString("Enter Last Name : "));
    Client.setEmail(clsInputValidate::ReadString("Enter Email : "));
    Client.setPhone(clsInputValidate::ReadString("Enter Phone : "));
    Client.SetPINCode(clsInputValidate::ReadString("Enter PIN Code : "));
    Client.SetAccountBalance(clsInputValidate::ReadDblNumber("Enter Account Balance : "));
}

string ReadExistingAccountNumber()
{
    string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number : ");
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        AccountNumber = clsInputValidate::ReadString("Account number Not exists, please enter another one : ");
    }
    return AccountNumber;
}

string ReadNewAccountNumber()
{
    string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number : ");
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        AccountNumber = clsInputValidate::ReadString("Account number is Exists, please enter another one : ");
    }
    return AccountNumber;
}

void DeleteClient()
{
    string AccountNumber = ReadExistingAccountNumber();
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    clsUtilClientUI::Print(Client);
    if (clsInputValidate::ReadYesOrNo("Are you Sure you want delete this Client? y/n ?"))
    {
        if (Client.Delete())
        {
            cout << "Client Delete Successfully :-) " << endl;
            clsUtilClientUI::Print(Client);
        }
        else
            cout << "Faild Client is Not Delete :-( " << endl;
    }
}

int main()
{
    DeleteClient();
}