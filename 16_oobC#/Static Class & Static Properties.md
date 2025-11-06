# Static Class

A static class is basically the same as a non-static class, but there is one difference: a static class cannot be instantiated. In other words, you cannot use the new operator to create a variable of the class type.

# Static Properties

A **static property** is similar to a static method. It uses the composite name to be accessed. Static properties use the same get and set tokens as instance properties. They are useful for abstracting global data in programs.  
  
Look at the following example.
```C#

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
}

class Program
{
    static void Main()
    {
        //
        // Read the static properties.
        //
        Console.WriteLine(Settings.DayNumber);
        Console.WriteLine(Settings.DayName);
        //
        // Change the value of the static bool property.
        //
        Settings.ProjectPath = @"C:\MyProjects\";
        Console.WriteLine(Settings.ProjectPath);
        Console.ReadKey();

    }
}
```

  

**Note:** there is no need to have an object from the class to access static properties.