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

    void SetLastName(string NewLastName)
    {
        _LastName = NewLastName;
    }

    string GetLastName()
    {
        return _LastName;
    }
};

int main()
{
    clsPerson Person1;
    Person1.SetFirstName("Hamo");
    Person1.SetLastName("Shaaban");
    cout << "FullName :" << Person1.GetFirstName() << endl;
    cout << "LastName :" << Person1.GetLastName() << endl;
}
