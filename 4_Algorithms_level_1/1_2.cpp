#include <iostream>
#include <string>
using namespace std;

void PrintName(string Name)           //problem 1
{
    cout<<"\nyour Name is: "<<Name <<endl;
}

string ReadName()                     //problem 2
{
    string name;
    cout<<"enter your Name?";
    getline(cin,name);
    return name;
}

int main()
{
    PrintName(ReadName());
}

