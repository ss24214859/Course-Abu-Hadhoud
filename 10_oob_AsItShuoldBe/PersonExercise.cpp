#include <iostream>
using namespace std;

class clsPerson
{
private:
    int _ID;
    string _FirstName, _LastName, _Email, _Phone;

public:
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    int ID()
    {
        return _ID;
    }

    void setFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string FirstName()
    {
        return _FirstName;
    }
    void setLastName(string LastName)
    {
        _LastName = LastName;
    }
    string LastName()
    {
        return _LastName;
    }

    void setEmail(string Email)
    {
        _Email = Email;
    }
    string Email()
    {
        return _Email;
    }
    void setPhone(string Phone)
    {
        _Phone = Phone;
    }
    string Phone()
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "Info:"
             << endl;
        cout << "______________________" << endl;
        cout << "ID         : " << _ID << endl;
        cout << "First Name : " << _FirstName << endl;
        cout << "Last Name  : " << _LastName << endl;
        cout << "Full Name  : " << FullName() << endl;
        cout << "Email      : " << _Email << endl;
        cout << "Phone      : " << _Phone << endl;
        cout << "______________________" << endl;
    }

    void SendEmail(string Subject, string Body)
    {
        cout << "The Following Massage sent Successfully to Email : " << _Email << endl;
        cout << "Subject : " << Subject << endl;
        cout << "Body : " << Body << endl
             << endl;
    }
    void SendSMS(string TextMassage)
    {
        cout << "The Following SMS sent Successfully to Phone : " << _Phone << endl;
        cout << TextMassage << endl;
    }
};

int main()
{
    clsPerson Person1(15, "Mohamed", "Shaaban", "ss888595gmail.co", "0123556453");
    Person1.Print();
    Person1.SendEmail("hi", "How Are You Now");
    Person1.SendSMS("How Are you");
}