#include <iostream>
#include <vector>
#include "../MyLiberary/VectorLib.h"
using namespace std;

class clsPerson
{

private:
    int _ID = 2022;
    string _FirstName;
    string _LastName;
    vector<string> _HestoryOfFirstName;
    vector<string> _HestoryOfLastName;

public:
    void SetFirstName(string NewFirstName)
    {
        _HestoryOfFirstName.push_back(_FirstName);
        _FirstName = NewFirstName;
    }
    void SetLastName(string NewLastName)
    {
        _HestoryOfLastName.push_back(_LastName);
        _LastName = NewLastName;
    }
    string FirstName()
    {
        return _FirstName;
    }

    string LastName()
    {
        return _LastName;
    }

    int ID()
    {
        return _ID;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }
    void PrintHistoryOfFirstName()
    {
        cout << endl;
        Vector::PrintVector(_HestoryOfFirstName);
    }
    void PrintHistoryOfLastName()
    {
        cout << endl;
        Vector::PrintVector(_HestoryOfLastName);
    }
};

int main()
{
    clsPerson Person1;
    Person1.SetFirstName("Hamo");
    Person1.SetLastName("Shaaban");
    cout << "FullName" << Person1.FullName() << endl;
    cout << "ID" << Person1.ID() << endl;
    Person1.SetFirstName("doha");
    Person1.SetLastName("Kardoushy");
    cout << "FullName" << Person1.FullName() << endl;
    cout << "ID" << Person1.ID() << endl;
    Person1.SetFirstName("Shaimaa");
    Person1.SetLastName("Mamoud");
    cout << "FullName" << Person1.FullName() << endl;
    cout << "ID" << Person1.ID() << endl;
    Person1.SetFirstName("bakhit");
    Person1.SetLastName("Kofta");
    cout << "FullName" << Person1.FullName() << endl;
    cout << "ID" << Person1.ID() << endl;
    Person1.SetFirstName("Zaky");
    Person1.SetLastName("Nader");
    cout << "FullName" << Person1.FullName() << endl;
    cout << "ID" << Person1.ID() << endl;
    Person1.SetFirstName("homus");
    Person1.SetLastName("Ali");
    cout << "FullName" << Person1.FullName() << endl;
    cout << "ID" << Person1.ID() << endl;
    Person1.SetFirstName("homus");
    Person1.SetLastName("Rady");
    cout << "FullName" << Person1.FullName() << endl;
    cout << "ID" << Person1.ID() << endl;

    cout << "History Of First Name Of Person1 : " << endl;
    Person1.PrintHistoryOfFirstName();

    cout << "History Of Last Name Of Person1 : " << endl;
    Person1.PrintHistoryOfLastName();
}