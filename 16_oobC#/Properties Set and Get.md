

Properties provide a flexible mechanism to read, write, validate or compute a private field. You can also use public fields in properties, but if we use a public field in a property then anybody can access our field in a program. A property makes our field secure, and we can change our rule (property) in one location, and it is easy to use anywhere.  
  
Look at the following example.

```c#
using System;

class clsEmployee
{
    // Private fields
    private int _ID;
    private string _Name = string.Empty;


    //ID Property Declaration
    public int ID
    {
        //Get is use for Reading field
        get
        {
            return _ID;
        }

        //Set is use for writing field
        set
        {
            _ID = value;
        }
    }

    //Name Property Declaration

    public string Name
    {
        //Get is use for Reading field
        get
        {
            return _Name;
        }

        //Set is use for writing field
        set
        {
            _Name = value;
        }

    }

    static void Main(string[] args)
    {

        //Create an object of Employee class.

        clsEmployee Employee1 = new clsEmployee();

        Employee1.ID = 7;
        Employee1.Name = "Mohammed Abu-Hadhoud";

        Console.WriteLine("Employee Id:={0}", Employee1.ID);
        Console.WriteLine("Employee Name:={0}", Employee1.Name);
        Console.ReadLine();


    }

}
```

  

In the preceding example, we have the following two private fields:

1. _ID (int) 
2. _Name (string)

And we have two properties, Id and Name. When a property is created we have the two methods Get and Set. Get is for reading the value and Set is for writing the value for a field.