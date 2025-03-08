#include <iostream>
#include <string>
using namespace std;

void PrintAllWordsFromAAAtoZZZ()
{
    
    cout<<endl;
    string word=" ";
    for(int a=65; a<=90;a++)
    {
        for(int b=65;b<=90;b++)
        {
            for(int c=65;c<=90;c++)
            {
                word=(char)a+(char)b+(char)c;

                cout<<word<<endl;
            }
        } 
    }

}


int main()
{
    PrintAllWordsFromAAAtoZZZ();
}