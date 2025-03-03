#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

string ReadString(string Massage)
{
    string Input="";
    cout<<Massage;
    getline(cin,Input);
    return Input;
}

void PrintFirstLetterOfEachWordInString(string Str)
{
    cout<<"Characters of Word : "<<endl;
    bool InWord=false;
    
    for(int i=0; i<Str.length();i++)
    {
        if(Str[i]!=' '&&!InWord)
        {
                cout<<Str[i]<<endl;
                InWord=true;
        }
        
        if(Str[i]==' ')
        InWord=false;
    }
}
/*                   Mytoupper() 

bool IsUppercase(char ch)   
{
    return int(ch)>=65&&int(ch)<=90;
}

char Mytoupper(char ch)
{
    if(!IsUppercase(ch))
        return char(int(ch)-32);
    else
        return ch;
}*/


void UppercaseFirstLetterOfEachWordInString(string &S1)
{
     bool InWord=false;
     
    
    for(int i=0; i<S1.length();i++)
    {
        if(S1[i]!=' '&&!InWord)
        {
            S1[i]=toupper(S1[i]);
            InWord=true;
        }
        InWord=S1[i]!=' ';
    }
}

int main()
{
    //PrintFirstLetterOfEachWordInString(ReadString("Enter String ? \n"));
   
    string S1=ReadString("Enter String ? ");
    UppercaseFirstLetterOfEachWordInString(S1);
    cout<<"String After Conversation : "<<endl;
    cout<<S1<<endl;
    
    return 0;
}