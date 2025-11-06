
In C#, an interface is similar to abstract class. However, unlike abstract classes, all methods of an interface are fully abstract (method without body).

An `interface` is a completely "**abstract class**", which can only contain abstract methods and properties (with empty bodies).

We use the `interface` keyword to create an interface. For example,
```C#

public interface IPerson
{
    string FirstName { get; set; }
    string LastName { get; set; }
    void Introduce();
    void Print();
    string To_String();
}

```
Here,

- IPerson is the name of the interface.
- By convention, interface starts with I so that we can identify it just by seeing its name.
- We cannot use access modifiers inside an interface.
- All members of an interface are public by default.
- An interface doesn't allow fields.
- Like **abstract classes**, interfaces **cannot** be used to create objects.
- Interface methods do not have a body - the body is provided by the "implement" class.
- Interfaces can contain properties and methods, but not fields/variables
- Interface members are by default `abstract` and `public`
- An interface cannot contain a constructor (as it cannot be used to create objects)

  

---

## Implementing an Interface

We cannot create objects of an interface. To use an interface, other classes must implement it. Same as in C# Inheritance, we use `:` symbol to implement an interface. For example,
```C#

using System;

public interface IPerson
{
    string FirstName { get; set; }
    string LastName { get; set; }

    void Introduce();
    void Print();

    string To_String();
}


public abstract class Person : IPerson
{
    public string FirstName { get; set; }
    public string LastName { get; set; }


    public abstract void Introduce();

    public void SayGoodbye()
    {
        Console.WriteLine("Goodbye!");
    }

    public void Print()
    {
        Console.WriteLine("Hi I'm the print method");
    }

    public string To_String()
    {
        return "Hi this is the complete string....";
    }


    public void SedEmail()
    {
        Console.WriteLine("Email Sent :-)");
    }

}


public class Employee : Person
{
    public int EmployeeId { get; set; }

    public override void Introduce()
    {
        Console.WriteLine($"Hi, my name is {FirstName} {LastName}, and my employee ID is {EmployeeId}.");
    }
}

public class Program
{
    public static void Main()
    {
        //You cannot create an object of an Interface, you can only Implement it.
       // IPerson Person1 = new IPerson();

        Employee employee = new Employee();
        employee.FirstName = "Mohammed";
        employee.LastName = "Abu-Hadhoud";
        employee.EmployeeId = 123;
        employee.Introduce(); // Output: "Hi, my name is John Doe, and my employee ID is 123."
        employee.SayGoodbye(); // Output: "Goodbye!"
        employee.Print();
        employee.SedEmail();
        Console.ReadKey();
    }
}

```
  

**Note**: We must provide the implementation of all the methods of interface inside the class that implements it.