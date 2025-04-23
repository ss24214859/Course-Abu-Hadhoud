#include <iostream>
#include "StringLip.h"
using namespace std;

int main()
{
    string Str1 = "Mohamed Shaaban Khalaf Abrahim Mohamed ";
    cout << Str1 << endl;
    Str1 = String::ReplaceWordInString(Str1, "Mohamed", "reda");
    cout << Str1 << endl;
}