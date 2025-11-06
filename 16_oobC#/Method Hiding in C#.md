
As we already know about polymorphism and method overriding in C#. C# also provides a concept to hide the methods of the base class from derived class, this concept is known as Method Hiding. It is also known as **Method Shadowing**. In method hiding, you can hide the implementation of the methods of a base class from the derived class using the _new_ keyword. Or in other words, in method hiding, you can redefine the method of the base class in the derived class by using the _new_ keyword.

  
```c#

using System;


public class MyBaseClass
{
    public virtual void MyMethod()
    {
        Console.WriteLine("Base class implementation");
    }


    public virtual void MyOtherMethod()
    {
        Console.WriteLine("Base class implementation of MyOtherMethod");
    }
}


public class MyDerivedClass : MyBaseClass
{
    public override void MyMethod()
    {
        Console.WriteLine("Derived class implementation using override");
    }


    public new void MyOtherMethod()
    {
        Console.WriteLine("Derived class implementation of MyOtherMethod using new");
    }
}


class Program
{
    static void Main(string[] args)
    {
        MyBaseClass myBaseObj = new MyBaseClass();
        Console.WriteLine("\nBase Object:\n");
        myBaseObj.MyMethod(); // Output: "Base class implementation"
        myBaseObj.MyOtherMethod(); // Output: "Base class implementation of MyOtherMethod"


        MyDerivedClass myDerivedObj = new MyDerivedClass();
        Console.WriteLine("\nDerived Object:\n");
        myDerivedObj.MyMethod(); // Output: "Derived class implementation using override"
        myDerivedObj.MyOtherMethod(); // Output: "Derived class implementation of MyOtherMethod using new"


        MyBaseClass myDerivedObjAsBase = myDerivedObj;
        Console.WriteLine("\nAfter Castring:\n");
        myDerivedObjAsBase.MyMethod(); // Output: "Derived class implementation using override"
        myDerivedObjAsBase.MyOtherMethod(); // Output: "Base class implementation of MyOtherMethod"
    
        Console.ReadKey();
    }
}

  
```

In the `Main` method, we create an instance of the base class and call its `MyMethod` and `MyOtherMethod` methods, which output "Base class implementation" and "Base class implementation of MyOtherMethod", respectively.

We then create an instance of the derived class and call its `MyMethod` and `MyOtherMethod` methods, which output "Derived class implementation using override" and "Derived class implementation of MyOtherMethod using new", respectively.

We also cast the derived class instance to the base class type and call its `MyMethod` and `MyOtherMethod` methods, which output "Derived class implementation using override" and "Base class implementation of MyOtherMethod", respectively. This is because we have overridden `MyMethod` in the derived class but only hidden `MyOtherMethod`, so calling it on an instance of the base class type will invoke the implementation in the base class.