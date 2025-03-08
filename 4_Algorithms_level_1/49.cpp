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
        }
    }while(PinCode != "1234");
    
}


int main()
{
    float Balance=7500;
    if(Login())
    {
        system("color 2F");  //green screen
        cout<<"\nyour Balance is "<<Balance<<endl;
    }
}