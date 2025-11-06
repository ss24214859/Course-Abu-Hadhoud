

In C#, we can also make our constructor static. We use the `static` keyword to create a static constructor. For example,
```c#

using System;
static class Settings
{
    public static int DayNumber
    {
        get
        {
            return DateTime.Today.Day;
        }
    }


    public static string DayName
    {
        get
        {
            return DateTime.Today.DayOfWeek.ToString();
        }
    }


    public static string ProjectPath
    {
        get;
        set;
    }
    //this is a static constructor will be called once during the program
    static Settings()
    {
        ProjectPath = @"C:\MyProjects\";
    }
}

class Program
{
    static void Main()
    {

        // You cannot create an object here because class is static
        // Settings Obj1 = new Settings();

        //
        // Read the static properties.
        //
        Console.WriteLine(Settings.DayNumber);
        Console.WriteLine(Settings.DayName);
        //
        // Change the value of the static bool property.
        //
        
        Console.WriteLine(Settings.ProjectPath);

        Console.ReadKey();

    }
}

```
In the above example, we have created a static constructor.

We cannot call a static constructor directly. However, the static constructor gets called automatically.

The static constructor is called only once during the execution of the program. That's why when we call the constructor again, only the regular constructor is called.

**Note**: We can have only one static constructor in a class. **It cannot have any parameters or access modifiers**.