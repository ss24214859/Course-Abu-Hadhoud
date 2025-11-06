
In multilevel inheritance, a derived class inherits from a base and then the same derived class acts as a base class for another class.  

![](https://uploads.teachablecdn.com/attachments/rXg4LApQ2C9MakNZjcet_csharp-multilevel-inheritance.png)  

## Example:
```C#

using System;

public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public void Introduce()
    {
        Console.WriteLine($"Hi, my name is {Name} and I'm {Age} years old.");
    }
}

public class Employee : Person
{
    public int EmployeeId { get; set; }
    public decimal Salary { get; set; }

    public void Work()
    {
        Console.WriteLine($"Employee with ID {EmployeeId} and salary {Salary:C} is working.");
    }
}


public class Doctor : Employee
{
    public string Specialty { get; set; }


    public void Heal()
    {
        Console.WriteLine($"Doctor {Name} with ID {EmployeeId}, salary {Salary:C}, and specialty {Specialty} is healing a patient.");
    }
}


class Program
{
    static void Main(string[] args)
    {
        Doctor doctor = new Doctor();
        doctor.Name = "John";
        doctor.Age = 35;
        doctor.EmployeeId = 123;
        doctor.Salary = 100000.00M;
        doctor.Specialty = "Cardiology";
        doctor.Introduce(); // Output: "Hi, my name is John and I'm 35 years old."
        doctor.Work(); // Output: "Employee with ID 123 and salary $100,000 is working."
        doctor.Heal(); // Output: "Doctor John with ID 123, salary $100,000, and specialty Cardiology is healing a patient."


        Console.ReadKey();
    }
}

```

In this example, we have a Person class that has Name and Age properties, as well as an Introduce method. The Employee class inherits from Person and has an additional EmployeeId and Salary property and a Work method. The Doctor class inherits from Employee and has an additional Specialty property and a Heal method.  

In the Main method, we create a new Doctor object and set its properties. Since Doctor inherits from Employee, which in turn inherits from Person, it has access to all of the properties and methods defined in those classes.