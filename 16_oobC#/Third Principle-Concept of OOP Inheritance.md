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
        clsEmployee Emp1 = new clsEmployee();

        Emp1.ID = 10;
        Emp1.FirstName = "Hamo";
        Emp1.LastName = "Shaaban";
        Emp1.Age = 25;
        Emp1.DepartmentName = "it";
        Emp1.Salary = 5000;
        clsEmployee.Print(Emp1);
        Emp1.IncreaseSalaryBy(1000);
        Console.WriteLine("\nAfter Increase Salary By 1000\n------------------------------");
        clsEmployee.Print(Emp1);


        Console.ReadKey();
    }
}
```


# C# Inheritance

In C#, inheritance allows us to create a new class from an existing class. It is a key feature of Object-Oriented Programming (OOP).

In C#, it is possible to inherit fields and methods from one class to another. We group the "inheritance concept" into two categories:

- **Derived Class** (child) - the class that inherits from another class
- **Base Class** (parent) - the class being inherited from

To inherit from a class, use the `:` symbol.

The class from which a new class is created is known as the base class (parent or superclass or base class ). And, the new class is called derived class (child or subclass or derived class)

The derived class inherits the fields and methods of the base class. This helps with the code reusability in C#.

  

## How to perform inheritance in C#?

In C#, we use the `:` symbol to perform inheritance. For example,
```C#

class clsPerson{  
  // fields and methods
} 

// Employee Class Inherits Person
class clsEmployee: Person
{
  // fields and methods of Person are inherited no need to rewrite them
  // fields and methods of Employee
}

```
Here, we are inheriting the derived class Employee from the base class Person. The Employee class can now access the fields and methods of Person class.

  

### Example: C# Inheritance
```C#

using System;

public class clsPerson
{
    //properties
    public int ID { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string Title { get; set; }

    //read only property
    public string FullName
    {
        //Get is use for Reading field
        get
        {
            return FirstName + ' ' + LastName;
        }
    }
}


public class clsEmployee : clsPerson
    {


    public float Salary { get; set; }
    public string DepartmentName { get; set; }


    public void IncreaseSalaryBy(float Amount)
    {
        Salary += Amount;
    }


}


    internal class Program
    {
        static void Main(string[] args)
        {
       
        //Create an object of Empoyee
        clsEmployee Employee1 = new clsEmployee();

        //the following inherited from base class person
        Employee1.ID = 10;
        Employee1.Title = "Mr.";
        Employee1.FirstName = "Mohammed";
        Employee1.LastName = "Abu-Hadhoud";
       
        //the following are from derived class Employee
        Employee1.DepartmentName = "IT";
        Employee1.Salary = 5000;
       
        Console.WriteLine("Accessing Object 1 (Employee1):\n");
        Console.WriteLine("ID := {0}", Employee1.ID);
        Console.WriteLine("Title := {0}", Employee1.Title);
        Console.WriteLine("Full Name := {0}" , Employee1.FullName);
        Console.WriteLine("Department Name := {0}", Employee1.DepartmentName);
        Console.WriteLine("Salary := {0}", Employee1.Salary);

        Employee1.IncreaseSalaryBy(100);
        Console.WriteLine("Salary after increase := {0}", Employee1.Salary);
        Console.ReadKey();
    }
    }

**Output**

Accessing Object 1 (Employee1):

ID := 10
Title := Mr.
Full Name := Mohammed Abu-Hadhoud
Department Name := IT
Salary := 5000
Salary after increase := 5100

In the above example, we have derived a subclass Employee from the superclass Person. Notice the statements,

        Employee1.ID = 10;
        Employee1.Title = "Mr.";
        Employee1.FirstName = "Mohammed";
        Employee1.LastName = "Abu-Hadhoud";

```
Here, all properties and methods came from Person Class via inheritance.

Also, we can access them all inside the employee class.

![](https://uploads.teachablecdn.com/attachments/8xNv8KuqRDSwaHhPPeWH_1.jpg)  

---

## is-a relationship

In C#, inheritance is an is-a relationship. We use inheritance only if there is an is-a relationship between two classes. For example,

- **Employee** is a **Person**

We can derive **Employee** from **Person** class.

## What can you inherit?

you can only inherit the public and protected members, private members are not inherited.