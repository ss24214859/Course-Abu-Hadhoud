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
        cout << "Hi Im Constructors." << endl
             << endl;
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

    ~clsAddress()
    {
        cout << "hi Im Desturctor" << endl;
    }
};

class clsA
{
public:
    static int counter;
    clsA()
    {
        counter++;
    }
    static int Func1()
    {
        return 10;
    }

    int Func2()
    {
        return 30;
    }
};
int clsA::counter = 0;
int main()
{
    clsA A1, A2;
    cout << A1.Func1() << endl;
    cout << A2.Func2() << endl;
    cout << A1.counter << endl;
    system("pause>0");
}
