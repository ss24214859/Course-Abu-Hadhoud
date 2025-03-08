#include <iostream>
using namespace std;

string ReadString(string massge)
{
    string Str;
    cout<<massge;
    cin>>Str;
    return Str;

}


string EncryptText(string text,int EncryptionKey)
{
    for(int i=0;i<=text.length();i++)
    {
        text[i]= char(int (text[i])+EncryptionKey);
    }
    return text;
}

string DecryptText(string text,int EncryptionKey)
{
    for(int i=0;i<=text.length();i++)
    {
        text[i]= char(int (text[i])-EncryptionKey);
    }
    return text;
}

int main()
{
    int Encryptionkey=8;
    string text=ReadString("enter Text ?\n");
    string TextAfterEncryption=EncryptText(text,Encryptionkey);
    string TextAfterDecryption=DecryptText(TextAfterEncryption,Encryptionkey);

    cout<<endl<<"Text Befor Encryption : "<<text<<endl;
    cout<<"Text After Encryption : "<<TextAfterEncryption<<endl;
    cout<<"Text After Decryption : "<<TextAfterDecryption<<endl;

}