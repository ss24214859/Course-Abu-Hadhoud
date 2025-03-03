#include <iostream>
#include <string>
using namespace std;

string ReadString(string massage)
{
    string String;
    cout<<massage;
    cin.ignore(1,'\n');
    getline (cin,String);
    return String;
}

int NumberOfWordsInString(string String)
{
    int words=1;
    for(int i=0;i<String.length();i++)
    {
        if(String.at(i)==' ')
        words++;
    }
    return words;
}

string ReverseString(string S1)
{
    string ReversedS ="";
    
    for(int i=S1.length()-1; i>=0;i--)
    {
        ReversedS.push_back(S1.at(i));
    }
    return ReversedS;
}
void countNumberOfWordsInString(string &S1)
{
    S1=ReadString("enter a String ? ");
    cout<<"Number Of Words : ";
    cout<<NumberOfWordsInString(S1)<<endl;
    
}

string UppercaseString(string S1)
{
    string Uppercase="";
    for(int i=0;i<S1.length();i++)
    {
        Uppercase.push_back((char)toupper(S1.at(i) ));
        
    }
    return Uppercase;
}

string LowercaseString(string S1)
{
    string Lowercase="";
    for(int i=0;i<S1.length();i++)
    {
        Lowercase.push_back((char)tolower(S1.at(i) ));
        
    }
    return Lowercase;
}

void Process(short choice)
{
    string S1,S2;
    switch (choice)
    {
    
    case 1 :
    S1=ReadString("Enter Frist String : ");
    
    cout<<"Enter second String : ";
    getline(cin,S2);
    
    cout<<"Concatenated : "<<S1.append(S2)<<endl;
    break;
    
    case 2 :
    S1=ReadString("Enter the Main String : ");
    cout<<"Enter the Substring to Find : ";
    getline(cin,S2);
    
    cout<<"Substring found at Position : "<<S1.find(S2)<<endl;
    break;
    
    case 3 :
    S1=ReadString("Enter a Stirng : ");
    cout<<"Reversed String : "<<ReverseString(S1)<<endl;
    break;
    
    case 4 :
    S1=ReadString("Enter a Stirng : ");
    cout<<"Uppercase String : "<<UppercaseString(S1)<<endl;
    break;
    
    case 5 :
    S1=ReadString("Enter a Stirng : ");
    cout<<"Lowercase string : "<<LowercaseString(S1)<<endl;
    break;
    
    case 6 :
    countNumberOfWordsInString(S1);    
    break ;
    
    default :
    cout<<"Goodbye :-) "<<endl;
        
    }
        
}

void StartScreen()
{
cout<<"\n--- String Manipulation Application ---\n"
<<"1. Concatenate Two Strings\n"
<<"2. Find a Substring in a String\n"
<<"3. Reverse a String\n"
<<"4. Convert String to Uppercase\n"
<<"5. Convert String to Lowercase\n"
<<"6. Count the Number of Words in a String\n"
<<"7. Exit"<<endl;
}

void StringManipulationApplication()
{
    short choice=0;
    while(choice!=7)
    {
        StartScreen();
        cout<<"enter Your Choice ? ";
        cin>>choice;
        Process(choice);
        
    };
}

        
int main()
{
    StringManipulationApplication();
}