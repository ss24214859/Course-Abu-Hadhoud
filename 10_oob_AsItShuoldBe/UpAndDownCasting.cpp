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

    clsPerson() {}

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

    virtual void Print()
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

    clsEmployee() {}

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

class clsDeveloper : public clsEmployee
{
private:
    string _MainProgrammingLanguage;

public:
    clsDeveloper(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary, string MainProgrammingLanguage)
        : clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    clsDeveloper() {}

    string MainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
    }
    void setMainProgrammingLanguage(string MainProgrammingLanguage)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }

    void Print()
    {
        cout << "Info:"
             << endl;
        cout << "______________________" << endl;
        cout << "ID                       : " << ID() << endl;
        cout << "First Name               : " << FirstName() << endl;
        cout << "Last Name                : " << LastName() << endl;
        cout << "Full Name                : " << FullName() << endl;
        cout << "Email                    : " << Email() << endl;
        cout << "Phone                    : " << Phone() << endl;
        cout << "Title                    : " << Title() << endl;
        cout << "Department               : " << Department() << endl;
        cout << "Salary                   : " << Salary() << endl;
        cout << "Main Programing Language : " << _MainProgrammingLanguage << endl;
        cout << "______________________" << endl;
    }
};

int main()
{

    // UPCasting is work.

    clsDeveloper Developer1(3027, "Hamo", "Shaaban", "ss1224515@gmail.com", "01244963562", "Programming", "Full Stack", 26000, "C++");
    clsEmployee *Employee1 = &Developer1;
    Employee1->Print();

    clsEmployee Employee2;
    clsPerson *Person1 = &Developer1;

    Person1->Print(); // in UpCasting Overriding is not work if Print()isn't virtual Function

    // DownCasting Is not Work
}