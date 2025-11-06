using System;



public  abstract partial class clsPerson
{
    public virtual  void Print()
    {
        // use Class only (if it null) than Exit form Function to avoid Mistakes
        if (this == null)
            return;

        Console.WriteLine("ID : " + this.ID.ToString());
        Console.WriteLine("Full Name : " + this.FullName);
        Console.WriteLine("Age : " + this.Age);

    }
}