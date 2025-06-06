#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

struct stClientData
{
    string AccountNumber;
    string PINcode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitStringInVector(string S1, string delimiter)
{
    vector<string> vStrWords;
    short pos = 0;
    string Word;

    while ((pos = S1.find(delimiter)) != std::string::npos)
    {
        Word = S1.substr(0, pos);

        if (Word != "")
            vStrWords.push_back(Word);

        S1.erase(0, pos + delimiter.length());
    }
    if (S1 != "")
        vStrWords.push_back(S1);

    return vStrWords;
}

double ReadPositiveNumber(string massge)
{
    double num = 0;
    do
    {
        cout << massge;
        cin >> num;
    } while (num < 0);
    return num;
}

string ReadString(string Massage)
{
    string Input = "";
    cout << Massage;
    getline(cin, Input);
    return Input;
}

stClientData ReadNewClient()
{
    stClientData ClientData;
    cout << "Enter Account Number : ";
    getline(cin, ClientData.AccountNumber);
    cout << "Enter PIN Code : ";
    getline(cin, ClientData.PINcode);
    cout << "Enter Name : ";
    getline(cin, ClientData.Name);
    cout << "Enter Phone  : ";
    getline(cin, ClientData.Phone);
    cout << "Enter Account Balance : ";
    cin >> ClientData.AccountBalance;

    return ClientData;
}

string ConvertRecordToLine(stClientData ClientData, string Saperator = "#//#")
{
    string ClientDataStr = "";

    ClientDataStr += ClientData.AccountNumber + Saperator;
    ClientDataStr += ClientData.PINcode + Saperator;
    ClientDataStr += ClientData.Name + Saperator;
    ClientDataStr += ClientData.Phone + Saperator;
    ClientDataStr += (to_string(ClientData.AccountBalance));

    return ClientDataStr;
}

stClientData ExtructClientRecord(string LineRecord, string Saperator)
{
    stClientData ClientData;
    vector<string> vClientRecord = SplitStringInVector(LineRecord, Saperator);

    ClientData.AccountNumber = vClientRecord[0];
    ClientData.PINcode = vClientRecord[1];
    ClientData.Name = vClientRecord[2];
    ClientData.Phone = vClientRecord[3];
    ClientData.AccountBalance = stod(vClientRecord[4]);

    return ClientData;
}

void PrintClientData(stClientData ClientData)
{
    cout << "Account Number  : " << ClientData.AccountNumber << endl;
    cout << "PIN Code        : " << ClientData.PINcode << endl;
    cout << "Name            : " << ClientData.Name << endl;
    cout << "Phone           : " << ClientData.Phone << endl;
    cout << "Account Balance : " << ClientData.AccountBalance << endl;
}
int main()
{

    string LineRecord = "jf2565#//#1234#//#mohamed SHaaban Khalaf#//#01245465374#//#5000.540000";
    string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud #//#079999#//#5270.500000";
    stClientData ClientData = ExtructClientRecord(LineRecord, "#//#");

    PrintClientData(ClientData);
    return 0;
}