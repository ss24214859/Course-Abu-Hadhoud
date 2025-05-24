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

class clsEmployee : public clsPerson
{
private:
    float _Salary;
    string _Title, _Department;

public:
    clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
        : clsPerson(ID, FirstName, LastName, Email, Phone)
    {
        _Title = Title;
        _Department = Department;
        _Salary = Salary;
    }

    void setSalary(int Salary)
    {
        _Salary = Salary;
    }
    float Salary()
    {
        return _Salary;
    }

    void setTitle(string Title)
    {
        _Title = Title;
    }
    string Title()
    {
        return _Title;
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
        cout << "ID         : " << ID() << endl;
        cout << "First Name : " << FirstName() << endl;
        cout << "Last Name  : " << LastName() << endl;
        cout << "Full Name  : " << FullName() << endl;
        cout << "Email      : " << Email() << endl;
        cout << "Phone      : " << Phone() << endl;
        cout << "Title      : " << _Title << endl;
        cout << "Department : " << _Department << endl;
        cout << "Salary     : " << _Salary << endl;
        cout << "______________________" << endl;
    }
};

int main()
{
    clsEmployee Employee1(3027, "Hamo", "Shaaban", "ss1224515@gmail.com", "01244963562", "Joker", "Operations", 7400);
    Employee1.Print();
    Employee1.SendEmail("hi", "How Are You Now");
    Employee1.SendSMS("How Are you");
}