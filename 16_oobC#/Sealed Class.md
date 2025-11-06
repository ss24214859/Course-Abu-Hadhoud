

In C#, when we don't want a class to be inherited by another class, we can declare the class as **a sealed class**.

## Why Sealed Class?

We use sealed classes to prevent inheritance. As we cannot inherit from a sealed class, the methods in the sealed class cannot be manipulated from other classes.

It helps to prevent security issues. For example,
```c#

    using System;

    sealed  class clsA
    {


    }

    // trying to inherit sealed class
    // Error Code
    class clsB : clsA
    {


    }

    class Program
    {
        static void Main(string[] args)
        {

            // create an object of B class
            clsB B1 = new clsB();

            Console.ReadKey();
        }
    }
    
```

As class A cannot be inherited, class B cannot override and manipulate the methods of class A.

In the above example, we have created a sealed class A. Here, we are trying to derive B class from the A class.

Since a sealed class cannot be inherited, the program generates the following error:

error CS0509: 'B': cannot derive from sealed type 'Al'