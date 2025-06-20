#include <iostream>
#include "clsBankClient.h"
#include "../../MyClasss/clsInputValidate.h"
#include "../../MyClasss/clsString.h"
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

string ReadAccountNumberInUse()
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

void AddNewClient()
{
    string AccountNumber = ReadNewAccountNumber();
    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
    ReadClientInfo(NewClient);
    clsBankClient::enSaveResult SaveResult = NewClient.Save();
    switch (SaveResult)
    {
    case clsBankClient::enSaveResult::SvSucceeded:
        cout << "Account Added Successfully :-) " << endl;
        NewClient.Print();
        break;
    case clsBankClient::enSaveResult::svFaildAccountisExist:
        cout << "Save Faild BeCause Account Number is Already Used :-( " << endl;
        break;
    case clsBankClient::enSaveResult::SvFaildEmptyObject:
        cout << "Save Faild BeCuase Client Is Empty :-( " << endl;
        break;
    }
}

int main()
{
    AddNewClient();
}