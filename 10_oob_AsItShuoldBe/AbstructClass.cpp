#include <iostream>
using namespace std;

// Abstruct Class / Interface / Contract
class clsMobile
{
    // Pure virtual Functions
    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string PhoneNumber, string Text) = 0;
    virtual void TakePicture() = 0;
};

class clsMyPhone : public clsMobile
{
    string _Name;

public:
    clsMyPhone(string Name)
    {
        _Name = Name;
    }

    void Dial(string PhoneNumber)
    {
    }

    void SendSMS(string PhoneNumber, string Text)
    {
    }
    void TakePicture()
    {
    }

    void Print()
    {
        cout << "Name : " << _Name << endl;
    }
};

int main()
{
    clsMyPhone MyPhone("Redmi");
    MyPhone.Print();
}