
C# supports two types of class methods: static and nonstatic. Any normal method is a nonstatic method. 

A static method in C# is a method that keeps only one copy of the method at the Type level, not the object level. The last updated value of the method is shared among all objects of that Type. That means all class instances share the exact copy of the method and its data.   
Look at the following example.

![](https://uploads.teachablecdn.com/attachments/VQv8oD48THyr26BHRqlk_1.JPG)


```C#

using System;

    class clsA
    {
        public int x1;
        //x2 is shared for all object because it's on the class level
        public static int x2;


        public int Method1 ()
        {
            //not static methods can always access the static members
            return x1 + x2;
        }

        public static int Method2()
        {
            //static methods cannot access non-static memebers because there is no object
            //static methods are called at the class level.
            //return clsA.x1 + x2;
            return  x2;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            //Create an object of Employee class.
            clsA objA1 = new clsA();
            clsA objA2 = new clsA();


            objA1.x1 = 7;
            objA2.x1 = 10;
            //x2 is shared for all object because it's on the class level, you can access it 
            //using the class name.
            clsA.x2 = 100;


            Console.WriteLine("objA1.x1:={0}", objA1.x1);
            Console.WriteLine("objA2.x1:={0}", objA2.x1);
            Console.WriteLine("objA1.method1 results:={0}", objA1.Method1());
            Console.WriteLine("objA2.method1 results:={0}", objA2.Method1());


            //Method 2 cannot be accessed through object, only through the class itself.
            //  Console.WriteLine(objA1.Method2());
            Console.WriteLine("static method2 results:={0}",clsA.Method2());

            Console.WriteLine("static x2:={0}", clsA.x2);
            Console.ReadLine();
        }
    }

  

```
**x2** is also a static Field that is saved on the class level.

**Note:** remember that all static methods and properties are shared for all objects because they are saved at the class level not at the object level.