

  

In C#, upcasting and downcasting refer to converting an object reference to a base class or derived class reference, respectively.

Upcasting is a safe operation because a derived class is always a specialization of the base class, but downcasting can be dangerous because a base class may not have all the members of a derived class. Here is an example to illustrate upcasting and downcasting:

  

**Example:**
```c#

using System;

public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public void Greet()
    {
        Console.WriteLine($"Hi, my name is {Name} and I am {Age} years old.");
    }
}

public class Employee : Person
{
    public string Company { get; set; }
    public decimal Salary { get; set; }


    public void Work()
    {
        Console.WriteLine($"I work at {Company} and earn {Salary:C} per year.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Upcasting
        Employee employee = new Employee { Name = "John", Age = 30, Company = "Acme Inc.", Salary = 50000 };
        Person person = employee;
        person.Greet(); // Output: "Hi, my name is John and I am 30 years old."

        // Downcasting
        Person person2 = new Employee { Name = "Jane", Age = 25, Company = "XYZ Corp.", Salary = 60000 };
        Employee employee2 = (Employee)person2;
        employee2.Work(); // Output: "I work at XYZ Corp. and earn $60,000.00 per year."

        // Invalid downcasting - throws InvalidCastException at runtime
      //  Person person3 = new Person { Name = "Bob", Age = 40 };
       // Employee employee3 = (Employee)person3; // Runtime exception: InvalidCastException

        Console.ReadKey();
    }
}

```
  

In this example, we have a `Person` class and an `Employee` class that inherits from `Person`. The `Person` class has a `Name` and `Age` property, as well as a `Greet` method that prints a greeting to the console. The `Employee` class has an additional `Company` and `Salary` property, as well as a `Work` method that prints information about the employee's job to the console.

In the `Main` method, we first create a new `Employee` object and assign it to a variable of type `Person`, which is an example of upcasting. We then call the `Greet` method on the `Person` variable, which outputs "Hi, my name is John and I am 30 years old." This is possible because the `Employee` class inherits from `Person`, so it can be safely upcast to `Person`.

Next, we create a new `Employee` object and assign it to a `Person` variable, which is another example of upcasting. We then downcast the `Person` variable to an `Employee` variable using an explicit cast with the `(Employee)` syntax. We can then call the `Work` method on the `Employee` variable, which outputs "I work at XYZ Corp. and earn $60,000.00 per year." This is possible because the `Person` variable actually refers to an `Employee` object, which has the `Work` method.

Finally, we attempt to downcast a `Person` object to an `Employee` object, which is an example of invalid downcasting because the `Person` object is not actually an `Employee` object. This will throw an `InvalidCastException` at runtime.  

**Note:**

- Up Casting is converting derived object to it's base object.
- Down Casting is Converting Base object to Derived object
- Upcasting is a safe operation because a derived class is always a specialization of the base class
- Downcasting can be dangerous because a base class may not have all the members of a derived class.