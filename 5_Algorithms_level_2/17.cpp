#include <iostream>
#include <string>
using namespace std;

string ReadString(string massge)
{
    string Str;
    cout<<massge;
    cin>>Str;
    return Str;

}

bool gess3LatterPassword(string Password)
{ 
    cout<<endl;
    int counter=0;
    string word="";
    for(int a=65; a<=90;a++)
    {
        for(int b=65;b<=90;b++)
        {
            for(int c=65;c<=90;c++)
            {
                counter++;
                word+=char(a);
                word+=char(b);
                word+=char(c);

                cout<<"Trail("<<counter<<"):";
                cout<<word<<endl;
                if(word == Password)
                {
                    cout<<"Password is "<<word<<endl;
                    cout<<"Found After "<<counter<<" Trial(s)";
                    return true;
                }  
                word="";
                
            }
        } 
    }
    return false;
}

int main()
{
    string password=ReadString("Enter Password ?\n");
    gess3LatterPassword(password);
}