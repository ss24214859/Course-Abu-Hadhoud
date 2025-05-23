#include <iostream>
using namespace std;

class clsEmployee
{
private:
    int _ID, _Salary;
    string _FirstName, _LastName, _Title, _Email, _Phone, _Department;

public:
    clsEmployee(int ID, int Salary, string FirstName, string LastName, string Title, string Email, string Phone, string Department)
    {
        _ID = ID;
        _Salary = Salary;
        _FirstName = FirstName;
        _LastName = LastName;
        _Title = Title;
        _Email = Email;
        _Phone = Phone;
        _Department = Department;
    }

    int ID()
    {
        return _ID;
    }

    void setSalary(int Salary)
    {
        _Salary = Salary;
    }
    int Salary()
    {
        return _Salary;
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

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void setTitle(string Title)
    {
        _Title = Title;
    }
    string Title()
    {
        return _Title;
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

    void setDepartment(string Department)
    {
        _Department = Department;
    }
    string Department()
    {
        return _Department;
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
        cout << "Title       : " << _Title << endl;
        cout << "Email      : " << _Email << endl;
        cout << "Phone      : " << _Phone << endl;
        cout << "Salary      : " << _Salary << endl;
        cout << "Department  : " << _Department << endl;
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
    clsEmployee Employee1(15, 7400, "Mohamed", "Shaaban", "Jokar", "ss888595gmail.co", "0123556453", "Operations");
    Employee1.Print();
    Employee1.SendEmail("hi", "How Are You Now");
    Employee1.SendSMS("How Are you");
}