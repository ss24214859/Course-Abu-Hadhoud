

In C#, we cannot create objects of an abstract class. We use the `abstract` keyword to create an abstract class.

The `abstract` keyword is used for classes and methods:

- **Abstract class:** is a restricted class that cannot be used to create objects (to access it, it must be inherited from another class).
- **Abstract method:** can only be used in an abstract class, and it does not have a body. The body is provided by the derived class (inherited from).

An abstract class can have both abstract and regular methods:  

## Example:
```C#

using System;

public abstract class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }

    public abstract void Introduce();

    public void SayGoodbye()
    {
        Console.WriteLine("Goodbye!");
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
        //You cannot create an object of an abstract class, you can only inherit it.
      //  Person Person1= new Person();

        Employee employee = new Employee();
        employee.FirstName = "Mohammed";
        employee.LastName = "Abu-Hadhoud";
        employee.EmployeeId = 123;
        employee.Introduce(); // Output: "Hi, my name is John Doe, and my employee ID is 123."
        employee.SayGoodbye(); // Output: "Goodbye!"

        Console.ReadKey();
    }
}

```
  

In this example, the abstract class `Person` has two properties `FirstName` and `LastName`, an abstract method `Introduce()`, and a non-abstract method `SayGoodbye()`. The `Introduce()` method is marked as `abstract`, which means it does not have an implementation in the `Person` class and must be implemented by any derived class that inherits from `Person`. The `SayGoodbye()` method is not marked as `abstract`, which means it has an implementation in the `Person` class and can be inherited by derived classes.

The `Employee` class is derived from `Person` and provides an implementation for the `Introduce()` method. It also has an additional property `EmployeeId`. We can create instances of the `Employee` class and call its methods, including the inherited `SayGoodbye()` method