
In C#, destructor (finalizer) is used to destroy objects of class when the scope of an object ends. It has the same name as the class and starts with a tilde `~`. For example,
```c#

class Test {
  ...
  //destructor
  ~Test() {
    ...
  }
}
```

Here, `~Test()` is the destructor.  

---

### Example: Working of C# Destructor
```C#

using System;

    class clsPerson
    {

        public clsPerson()
        {
            Console.WriteLine("Constructor called.");
        }

        // destructor
        ~clsPerson()
        {
            Console.WriteLine("Destructor called.");
        }

        public static void Main(string[] args)
        {
            //creates object of Person
            clsPerson p1 = new clsPerson();
            Console.ReadKey();
        }
    }
}

```
In the above example, we have created a destructor `~clsPerson` inside the `clsPerson` class.  

When we create an object of the `clsPerson` class, the constructor is called. After the scope of the object ends, object p1 is no longer needed. So, the destructor is called implicitly which destroys object p1.

## Features of Destructors

There are some important features of the C# destructor. They are as follows:

- We can only have one destructor in a class.
- A destructor cannot have access modifiers, parameters, or return types.
- A destructor is called implicitly by the Garbage collector of the .NET Framework.
- We cannot overload or inherit destructors.
- We cannot define destructors in structs.