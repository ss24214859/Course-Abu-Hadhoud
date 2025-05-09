#include <iostream>
using namespace std;

class clsPerson
{
public:
    string FirstName;
    string LastName;
    string FullName = FirstName + " " + LastName;

    string FullNameFunc()
    {
        return FirstName + " " + LastName;
    }
};

int main()
{
    clsPerson Person1;
    Person1.FirstName = "Hamo";
    Person1.LastName = "Shaaban";
    cout << Person1.FullName;
    cout << Person1.FullNameFunc();
}