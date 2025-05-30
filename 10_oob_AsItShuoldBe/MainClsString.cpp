#include <iostream>
#include "../MyClasss/clsString.h"
using namespace std;

int main()
{
    clsString S1;
    string FullName;
    S1.Read("Enter String ? ");
    S1.Encrypt(5);
    cout << S1.Value() << endl;
    S1.Decrypt(5);
    cout << "After Decrypt : " << S1.Value() << endl;
}