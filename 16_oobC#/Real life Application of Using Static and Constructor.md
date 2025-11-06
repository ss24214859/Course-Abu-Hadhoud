

```C#
using System;

class clsPerson
{

    private int ID { get; set; }
    string Name { get; set; }

    public Int16 Age { get; set; }

    public string Username { get; set; }

    public string Password { get; set; }


    // To don't Create new Empty Object.
    public clsPerson(int iD, string name, Int16 age)
    {
        ID = iD;
        Name = name;
        Age = age;
    }

    public  static clsPerson Find (int id)
    {
        if (id == 10)
            return new clsPerson(10, "Hamo", 16);
        else
            return null;
    }

    public static clsPerson Find(string userName ,string password)
    {
        if (userName == "Hamo" && password == "0002")
            return new clsPerson(8, "Shaaban", 19);
        else 
            return null;
    }

    static public void Print(clsPerson Person)
    {
        // use Class only (if it null) than Exit form Function to avoid Mistakes.
        if (Person == null)
            return;

		
        Console.WriteLine(Person.ID.ToString());
        Console.WriteLine(Person.Name.ToString());
        Console.WriteLine(Person.Age.ToString());
        
        //or this is the same.
        /* if(Person !=null)
        {
	        Console.WriteLine(Person.ID.ToString());
	        Console.WriteLine(Person.Name.ToString());
	        Console.WriteLine(Person.Age.ToString());
        }
        */

    }

}
internal class Program
{ 
    public static void Main(string[] args)
    {
        //find for an object in clsPerson
        clsPerson p1 = clsPerson.Find(10);
        clsPerson p2 = clsPerson.Find("Hamo","0002");

        
        clsPerson.Print(p1);
        clsPerson.Print(p2);

        Console.ReadKey();
    }
}

```