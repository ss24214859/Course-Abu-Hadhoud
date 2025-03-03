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
.
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


string UppercaseFirstLetterOfEachWordInString(string S1)
{
     bool IsFirstLetter=true;
     
    
    for(int i=0; i<S1.length();i++)
    {
        if(S1[i]!=' '&&IsFirstLetter)
        {
            S1[i]=tolower(S1[i]);
        }
        IsFirstLetter=(S1[i]==' ')? true : false;
    }
    return S1;
}

string LowerAllString(string S1)
{
    for(int i=0; i<S1.length();i++)
    {
            S1[i]=tolower(S1[i]);
    }
    return S1;
}

string UpperAllString(string S1)
{
    for(int i=0; i<S1.length();i++)
    {
            S1[i]=toupper(S1[i]);
    }
    return S1;
}


char InvertCase(char ch)
{

    return islower(ch)? toupper(ch) : tolower(ch);

}

int main()
{
    char ch;
    cout<<"Please Enter a Character ? ";
    cin>>ch;
    cout<<"\nCharacter after inverting case"<<endl;
    cout<<InvertCase(ch);
    
    return 0;
}