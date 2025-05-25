// ProgrammingAdivces.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;

class clsPerson
{

    class clsAddress
    {
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;

    public:
        clsAddress(string AddressLine1, string AddressLine2, string City, string Country)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City = City;
            _Country = Country;
        }
        string AddressLine1()
        {
            return _AddressLine1;
        }
        void setAddressLine1(string AddressLine1)
        {
            _AddressLine1 = AddressLine1;
        }
        string AddressLine2()
        {
            return _AddressLine2;
        }
        void setAddressLine2(string AddressLine2)
        {
            _AddressLine2 = AddressLine2;
        }
        string City()
        {
            return _City;
        }
        void setCity(string City)
        {
            _City = City;
        }
        string Country()
        {
            return _Country;
        }
        void setCountry(string Country)
        {
            _Country = Country;
        }

        void Print()
        {
            cout << "\nAddress:\n";
            cout << _AddressLine1 << endl;
            cout << _AddressLine2 << endl;
            cout << _City << endl;
            cout << _Country << endl;
        }
    };
    string _FullName;

public:
    string FullName()
    {
        return _FullName;
    }
    void setFullName(string FullName)
    {
        _FullName = FullName;
    }

    clsAddress Address = clsAddress("", "", "", "");

    clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
    {
        _FullName = FullName;
        Address = clsAddress(AddressLine1, AddressLine2, City, Country);
    }
};

int main()

{

    clsPerson Person1("Mohamed Shaaban", "Alshamhdan street", "Adikhla", "Alex", "Egypt");
    cout << Person1.FullName() << endl;
    Person1.Address.Print();

    system("pause>0");
    return 0;
}