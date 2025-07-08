#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "../../MyClasss/clsUtil.h"
#include "../../MyClasss/clsInputValidate.h"
#include "clsUtilClientUI.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{


public:
    static void ShowTransferScreen()
    {
        cout<<"First: Account Number To Transfer From.  "<<endl;    
        clsBankClient ClientFrom=clsBankClient::Find(clsUtilClientUI::ReadExistingAccountNumber());
        clsUtilClientUI::PrintMiniCard(ClientFrom);
         cout<<"Secondly: Account Number To Transfer To. "<<endl;    
        clsBankClient ClientTo=clsBankClient::Find(clsUtilClientUI::ReadExistingAccountNumber());
        clsUtilClientUI::PrintMiniCard(ClientTo);

        double Amount=clsInputValidate::ReadDblNumberBetween(0,ClientFrom.AccountBalance(),"Enter Transfer Amount ? ","Amount Exceeds The available Balance, Enter another Amount ?");
        if (clsInputValidate::ReadYesOrNo("Are you sure you want to perform this transction ?"))
        {
            if(ClientFrom.Transfer(ClientTo,Amount))
            {
                cout<<"\nTransfer done Successfully.\n";
                clsUtilClientUI::PrintMiniCard(ClientFrom);
                clsUtilClientUI::PrintMiniCard(ClientTo);
                
                ClientFrom.SaveInTransferLog(ClientTo,Amount);
            }
            else 
            cout<<"Transfer Faild, Amount Exceeds The available Balance"<<endl;

        }


    }
};