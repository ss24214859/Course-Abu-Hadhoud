#include <iostream>
using namespace std;

class clsPerson
{

private:
    int _ID;
    string _FirstName;
    string _LastName;

public:
    clsPerson(int ID, string FirstName, string LastName)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
    }

    static void Func1(clsPerson Person)
    {
        Person.Print();
    }

    void Func2()
    {
        Func1(*this);
    }

    void Print()
    {
        cout << "\nInfo:";
        cout << "\n___________________";
        cout << "\nID       : " << _ID;
        cout << "\nFirstName: " << _FirstName;
        cout << "\nLastName : " << _LastName;
        cout << "\n___________________\n";
    }
};

int main()
{

    clsPerson Person1(12, "Hamo", "Shaaban");
    clsPerson Person2(50, "Ali", "hoda");
    Person2.Func2();
}