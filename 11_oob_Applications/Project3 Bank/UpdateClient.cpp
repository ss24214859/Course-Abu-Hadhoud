#include <iostream>
#include "clsBankClient.h"
#include "../../MyClasss/clsInputValidate.h"
#include "../../MyClasss/clsString.h"
using namespace std;

void ReadClient(clsBankClient &Client)
{
    Client.setFirstName(clsInputValidate::ReadString("Enter First Name : "));
    Client.setLastName(clsInputValidate::ReadString("Enter Last Name : "));
    Client.setEmail(clsInputValidate::ReadString("Enter Email : "));
    Client.setPhone(clsInputValidate::ReadString("Enter Phone : "));
    Client.SetPINCode(clsInputValidate::ReadString("Enter PIN Code : "));
    Client.SetAccountBalance(clsInputValidate::ReadDblNumber("Enter Account Balance : "));
}

void UpdateClient()
{
    string AccountNumber = clsInputValidate::ReadString("Please Enter Client Account Number : ");
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        AccountNumber = clsInputValidate::ReadString("Account number Not exists, please enter another one : ");
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    ReadClient(Client);

    clsBankClient::enSaveResult SaveResult;

    SaveResult = Client.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResult::SvFaildEmptyObject:
        cout << "Save Faild Empty Object :-( " << endl;
        break;

    case clsBankClient::enSaveResult::SvSucceeded:
        cout << "Account update successfully :-) " << endl;
        Client.Print();
        break;
    }
}

int main()
{
    UpdateClient();
}
