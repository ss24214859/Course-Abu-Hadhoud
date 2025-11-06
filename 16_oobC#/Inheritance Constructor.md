```C#
using System;

 public class clsPerson
{

    public int ID { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }

    public Int16 Age { get; set; }

    public string Username { get; set; }

    public string Password { get; set; }

    public string FullName
    {
        get
        {
            return FirstName + " " + LastName;
        }
    }


    // To don't Create new Empty Object.
    public clsPerson(int iD, string Firstname,string Lastname, Int16 age)
    {
        ID = iD;
        FirstName = Firstname;
        LastName = Lastname;
        Age = age;
    }



    static public void Print(clsPerson Person)
    {
        // use Class only (if it null) than Exit form Function to avoid Mistakes
        if (Person == null)
            return;

        Console.WriteLine(Person.ID.ToString());
        Console.WriteLine(Person.FullName.ToString());
        Console.WriteLine(Person.Age.ToString());

    }
};


public class clsEmployee : clsPerson 
{
    public clsEmployee(int ID ,string FirstName,string LastName,short Age,float salary,string departmentName) : base(ID,FirstName,LastName,Age) 
    {
        Salary = salary;
        DepartmentName = departmentName;
    }
   public float Salary { get; set; }
    public string DepartmentName { get; set; }

    public void IncreaseSalaryBy(float Amount)
    {
        Salary += Amount;
    }
    static public void Print(clsEmployee Employee)
    {
        // use Class only (if it null) than Exit form Function to avoid Mistakes
        if (Employee == null)
            return;

        Console.WriteLine("ID : " + Employee.ID.ToString());
        Console.WriteLine("Full Name : " + Employee.FullName.ToString());
        Console.WriteLine("Age : " + Employee.Age.ToString());
        Console.WriteLine("Department Name : " + Employee.DepartmentName);
        Console.WriteLine("Salary : " + Employee.Salary);


    }
};

internal class Program
{ 
    public static void Main(string[] args)
    {
        clsEmployee Emp1 = new clsEmployee(10,"Hamo","Shaaban",25,5000,"it");
        clsEmployee.Print(Emp1);
        Emp1.IncreaseSalaryBy(1000);
        Console.WriteLine("\nAfter Increase Salary By 1000\n------------------------------");
        clsEmployee.Print(Emp1);


        Console.ReadKey();
    }
}

```