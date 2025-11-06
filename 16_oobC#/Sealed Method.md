

During method overriding, if we don't want an overridden method to be further overridden by another class, we can declare it as a **sealed method**.

We use a `sealed` keyword with an overridden method to create a sealed method. For example,
```c#

using System;


public class Person
{
    public virtual void Greet()
    {
        Console.WriteLine("The person says hello.");
    }
}


public class Employee : Person
{
    public sealed override void Greet()
    {
        Console.WriteLine("The employee greets you.");
    }
}

public class Manager : Employee
{
    //This will produce a compile-time error because the Greet method in Employee is
    //sealed and cannot be overridden.
    //public override void Greet()
    //{
    //    Console.WriteLine("The manager greets you warmly.");
    //}
}


public class Program
{
    public static void Main(string[] args)
    {
        Person person = new Person();
        person.Greet(); // outputs "The person says hello."

        Employee employee = new Employee();
        employee.Greet(); // outputs "The employee greets you."

        Manager manager = new Manager();
        manager.Greet(); // outputs "The employee greets you."

        Console.ReadKey();

    }
}
```

In this example, we have a `Person` base class with a virtual method `Greet`, which can be overridden by derived classes. We then define an `Employee` class that inherits from `Person` and overrides `Greet` with the `sealed` modifier. This means that any class that derives from `Employee` will not be able to override the `Greet` method further.

Finally, we define a `Manager` class that inherits from `Employee` and attempts to override `Greet`, but this will produce a compile-time error because the `Greet` method in `Employee` is sealed and cannot be overridden.

In the `Main` method, we create instances of `Person`, `Employee`, and `Manager` and call their `Greet` methods. The `Person` object outputs "The person says hello.", the `Employee` object outputs "The employee greets you.", and attempting to call the `Greet` method on the `Manager` object will call the inherited Greet method from Employee.