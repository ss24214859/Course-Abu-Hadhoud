

If the same method is present in both the base class and the derived class, the method in the derived class overrides the method in the base class. This is called method overriding in C#. For example,
```c#

using System;
public  class clsA
{
  public virtual void  Print()
    {
        Console.WriteLine("Hi, I'm the print method from the base class A");
    }
}

public class clsB : clsA
{
    public  override void  Print() 
    
    {
        Console.WriteLine("Hi, I'm the print method from the derived class B");
        base.Print();           
     }
}


 internal class Program
    {
        static void Main(string[] args)
        {
       
        //Create an object of Empoyee
        clsB ObjB= new clsB();

        ObjB.Print();

        Console.ReadKey();
        }
    }

```
  

**Output**

Hi, I'm the print method from the derived class B
Hi, I'm the print method from the base class A

In the above example, the print() method is present in both the base class and derived class.

When we call print() using the B object,
```C#
 ObjB.Print();
```
the Print inside B is called. This is because the Print method inside B overrides the Print method inside A.

Notice, we have used `virtual` and override with methods of the base class and derived class respectively. Here,

- `virtual` - allows the method to be overridden by the derived class
- `override` - indicates the method is overriding the method from the base class

  

## base Keyword in C# Inheritance

In the previous example, we saw that the method in the derived class overrides the method in the base class.

**However, what if we want to call the method of the base class as well?**

In that case, we use the `base` keyword to call the method of the base class from the derived class.
```c#

    public  override void  Print() 
    
    {
        Console.WriteLine("Hi, I'm the print method from the derived class B");
        base.Print();           
     }

  

`base` keyword is used to call the Print method in the base class.

        base.Print();
        
```
