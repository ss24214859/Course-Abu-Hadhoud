#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

string ReadString(string Massage)
{
    string Input="";
    cout<<Massage;
    getline(cin,Input);
    return Input;
}

char ReadChar(string Massage)
{
    char Input;
    cout<<Massage;
    cin>>Input;
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

string InvertLetterCase(string S1)
{
    for(int i=0; i<S1.length();i++)
    {
            S1[i]=InvertCase(S1[i]);
    }
    return S1;
    
}

int SmallLettersCount(string S1)
{
    int small=0;
    for(int i=0;i<S1.length();i++)
        small=islower(S1[i])? small+1:small;
    return small;
}

int CapitalLettersCount(string S1)
{
    int Capital=0;
    for(int i=0;i<S1.length();i++)
        Capital=isupper(S1[i])? Capital+1:Capital;
    return Capital;
}

int CharacterCount(string S1,char ch,bool MatchCase=true)
{
    int counter=0;
    if(MatchCase)
    {
        for(int i=0;i<S1.length();i++)
            counter= (S1[i]==ch)? counter+1: counter;
        return counter;
    }else
    {
       for(int i=0;i<S1.length();i++)
            counter= (tolower(S1[i])==tolower(ch))? counter+1: counter;
       return counter; 
    }
}

bool isvowel(char ch)
{
    ch=tolower(ch);
    return (ch=='a'||ch=='i'||ch=='e'||ch=='o'||ch=='u');
}

int VowelCount(string S1)
{
   int counter=0;
   for(int i=0;i<S1.length();i++)
      counter= (isvowel(S1[i]))? counter+1: counter;
      
   return counter;
   
}

void PrintVowelLetters(string S1)
{
    for(int i=0;i<S1.length();i++)
    {
        if(isvowel(S1[i]))
        cout<<S1[i]<<"\t";
    }
}

int WordsCounter(string S1)
{
    int counter=0;
    
    string delimiter=" ";
    short pos=0;
    string Word;
    
    while((pos=S1.find(delimiter))!=std::string::npos)
    {
        Word=S1.substr(0,pos);
        
        if(Word!="")
        counter++;
        
        S1.erase(0,pos+delimiter.length());
    }
    if(S1!="")
        counter++;
        
    return counter;    
}


void PrintEatchWordInString(string S1)
{
    string delimiter=" ";
    short pos=0;
    string Word;
    
    while((pos=S1.find(delimiter))!=std::string::npos)
    {
        Word=S1.substr(0,pos);
        
        if(Word!="")
        cout<<Word<<endl;
        
        S1.erase(0,pos+delimiter.length());
    }
    if(S1!="")
        cout<<S1<<endl;
        
}

vector<string> SplitEachWordInString(string S1)
{
    vector<string> vStrWords;
    string delimiter=" ";
    short pos=0;
    string Word;
    
    while((pos=S1.find(delimiter))!=std::string::npos)
    {
        Word=S1.substr(0,pos);
        
        if(Word!="")
        vStrWords.push_back(Word);
        
        S1.erase(0,pos+delimiter.length());
    }
    if(S1!="")
        vStrWords.push_back(S1);
        
    return vStrWords;    
}


void PrintVector(vector<string> Vec)
{
    for(string &str : Vec)
    {
        cout<<str<<endl;
    }
}

int main()
{
    /*char ch;
    cout<<"Please Enter a Character ? ";
    cin>>ch; in the 
    cout<<"\nCharacter after inverting case"<<endl;
    cout<<InvertCase(ch);*/
    vector<string> vStrWords;
    
    string S1=ReadString("Enter String ? ");
    /*char Ch1=ReadChar("Enter a character ?");
    cout<<"\nletter \'"<<Ch1<<"\' Count : "<<CharacterCount(S1,Ch1)<<endl;
    cout<<"\nletter \'"<<Ch1<<"\' Or \'"<<InvertCase(Ch1)<<"\' Count : "<<CharacterCount(S1,Ch1,0)<<endl;
    cout<<"\nString Length : "<<S1.length()<<endl;
    cout<<"Capital letters count : "<<CapitalLettersCount(S1)<<endl;
    cout<<"Small letters count : "<<SmallLettersCount(S1)<<endl;*/
    
    
    vStrWords=SplitEachWordInString(S1);
    
    cout<<"Your String Words Are : "<<endl;
    PrintVector(vStrWords);
    
  cout <<"\nTokens = "<<vStrWords.size()<<endl;
    
    /*char ch=ReadChar("Please Enter a Character ? ");
    if(isvowel(ch))
    cout<<"Yes : Letter \'"<<ch<<"\' is vowel."<<endl;
    else
    cout<<"NO : Letter \'"<<ch<<"\' is Not vowel."<<endl;*/
    
    return 0;
}