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

class clsAddress
{
private:
    string _AddressLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

public:
    clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
    {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;
    }

    void setAddressLine1(string AddressLine1)
    {
        _AddressLine1 = AddressLine1;
    }
    string AddressLine1()
    {
        return _AddressLine1;
    }

    void setAddressLine2(string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }
    string AddressLine2()
    {
        return _AddressLine2;
    }

    void setPOBox(string POBox)
    {
        _POBox = POBox;
    }
    string POBox()
    {
        return _POBox;
    }

    void setZipCode(string ZipCode)
    {
        _ZipCode = ZipCode;
    }
    string ZipCode()
    {
        return _ZipCode;
    }

    void Print()
    {
        cout << "Address Line 1 : " << _AddressLine1 << endl;
        cout << "Address Line 2 : " << _AddressLine2 << endl;
        cout << "PO Box         : " << _POBox << endl;
        cout << "Zip Code       : " << _ZipCode << endl;
    }
};

int main()
{
    clsAddress Address1("ALdikhla Alex", "Al Shamhadan", "ha898", "001545");
    clsAddress Address2 = Address1;
    Address1.Print();
    Address2.Print();

    system("pause>0");
}
