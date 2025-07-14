#include <iostream>
#include "clsInputValidateTemplet.h"
using namespace std;    

int main() {
    // Example usage of clsInputValidate
    string AccountNumber = clsInputValidate<string>::ReadString("Please Enter Client Account Number : ");
    cout << "Account Number: " << AccountNumber << endl;

    int age = clsInputValidate<int>::ReadNumber("Please enter your age: ");
    cout << "Your age is: " << age << endl;

    return 0;
}