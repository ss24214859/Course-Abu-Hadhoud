
You can define a readonly property by only implementing the get method.  
  
Look at the following example.
```c#

using System;


class clsEmployee
{

    //ID Property 
    public int ID
    {
        get;
        set;   
    }

    //Name Property Declaration
    public string Name
    {
        get;
        set;
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

  
  
Look at the above example. There are no implementations in the get and set methods. And also you don't need to create private fields. So Auto implemented properties are helpful, when you don't think you need any validation, computation or any implementation.