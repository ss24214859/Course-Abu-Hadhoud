#include <iostream>
using namespace std;

string ReadPinCode()
{
string PinCode;
cout<<"enter PIN Code? ";
cin>>PinCode;
return PinCode;
}

bool Login()
{
    string PinCode;
    int i=1;
    do{
        PinCode=ReadPinCode();

        if(PinCode=="1234")
        {
            return true;
        }
        else
        {
        system("color 4F");    //Red screen
        cout<<"Wrong Numbe Try Againe\n"<<endl;
        i++;
        }
    
    }while(i<=3 & PinCode != "1234" );
    
    return false;
}


int main()
{
    float Balance=7500;
    if(Login())
    {
        system("color 2F");  //green screen
        cout<<"\nyour Balance is "<<Balance<<endl;
    }
    else
    {
        cout<<"your Card is Locked call the bank for help";
    }
    
}