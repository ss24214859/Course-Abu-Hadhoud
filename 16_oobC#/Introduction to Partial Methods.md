

A partial class may contain a partial method. One part of the class contains the signature of the method. An optional implementation may be defined in the same part or another part. If the implementation is not supplied, then the method and all calls are removed at compile time.

### Example 2:
```c#

// File: Person.cs
public partial class Person
{
    public int Age { get; set; }

    partial void PrintAge();

    public void Birthday()
    {
        Age++;
        PrintAge();
    }
}
```

```C#
// File: PersonPrinting.cs
public partial class Person
{
    partial void PrintAge()
    {
        Console.WriteLine("Current age: {0}", Age);
    }
}
```

```C#
// File: Program.cs
class Program
{
    static void Main()
    {
        //the code of Person Class is seperated in 2 files Person1.cs and PersonPrinting.cs
        Person person1 = new Person();
        person1.Age = 25;
        person1.Birthday(); // Output: "Current age: 26"
    }
}

  
```

In this example, the `Person` class declares a partial method `PrintAge`, which prints the current age of the person. The `Birthday` method of the `Person` class calls the `PrintAge` partial method after incrementing the person's age. if the PrintAge is implemented it will be called , if not implemented the compiler will ignore it.

The `PersonPrinting.cs` file provides an implementation of the partial method, which writes the current age to the console.

When the `Main` method in `Program.cs` creates an instance of `Person` and calls its `Birthday` method  

---

### Things to remember about Partial Method

- `partial` keyword.
- return type `void`.
- implicitly `private`.
- and cannot be `virtual`.[](https://www.programiz.com/csharp-programming/nested-class)

  

Partial methods are a feature in C# that allow you to declare a method in one part of a partial class, but provide its implementation in another part of the same class. Partial methods are optional, and you can use them when you want to allow other parts of your code to optionally provide an implementation for a specific method.

Here are some scenarios where you might use partial methods:

1. Code generation: When you are generating code using a tool or framework, you can use partial methods to generate the method signature in one file and provide its implementation in another file. This allows you to separate the generated code from the manually written code and makes it easier to maintain.
2. Performance optimization: You can use partial methods to write code that can be optimized by different compilers or environments. For example, you can write a partial method that uses platform-specific code to achieve better performance on a particular platform.
3. Framework design: You can use partial methods to provide a hook for external developers to customize the behavior of your framework. For example, you might provide a partial method that is called at a specific point in your framework's execution and allow external developers to provide their own implementation of the method.
4. Code organization: You can use partial methods to organize your code by splitting a large method into smaller parts, each with its own file. This can make it easier to navigate and understand your codebase.

It's important to note that partial methods can only be defined in a partial class or partial struct, and their return type must be void. Also, partial methods cannot be accessed outside of the partial class or struct where they are defined, so they can't be used to implement a public API.