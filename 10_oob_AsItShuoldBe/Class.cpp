#include <iostream>
#include <vector>
#include "../MyLiberary/VectorLib.h"
using namespace std;

class clsPerson
{

private:
    string _FirstName;
    string _LastName;

public:
    void SetFirstName(string NewFirstName)
    {
        _FirstName = NewFirstName;
    }

    string GetFirstName()
    {
        return _FirstName;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    void SetLastName(string NewLastName)
    {
        _LastName = NewLastName;
    }

    string GetLastName()
    {
        return _LastName;
    }

    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;
};

int main()
{
    clsPerson Person1;
    Person1.SetFirstName("Hamo");
    Person1.SetLastName("Shaaban");
    cout << "FullName :" << Person1.GetFirstName() << endl;
    cout << "LastName :" << Person1.GetLastName() << endl;

    // instead of The above, we only write this
    Person1.FirstName = "Hamo";
    Person1.LastName = "Shaaban";
    cout << "FullName :" << Person1.FirstName << endl;
    cout << "LastName :" << Person1.LastName << endl;
}
