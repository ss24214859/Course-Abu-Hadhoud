using System;
using System.Net.Cache;
using System.Xml.Linq;

public class clsEmployee : clsPerson 
{
    public clsEmployee(int ID ,string FirstName,string LastName,short Age,float salary,string departmentName) : base(ID,FirstName,LastName,Age) 
    {
        Salary = salary;
        DepartmentName = departmentName;
    }
   public float Salary { get; set; }
    public string DepartmentName { get; set; }

    public void IncreaseSalaryBy(float Amount)
    {
        Salary += Amount;
    }
    public sealed override void  Print()
    {
        // use Class only (if it null) than Exit form Function to avoid Mistakes
        if (this == null)
            return;

        base.Print();
        Console.WriteLine("Department Name : " + this.DepartmentName);
        Console.WriteLine("Salary : " + this.Salary);


    }
};

public class clsDoctor : clsEmployee
{
    public string Specialty { get; set; }
    public clsDoctor(int ID, string FirstName, string LastName, short Age, float salary, string departmentName, string specialty) : base(ID, FirstName, LastName,Age, salary, departmentName)
    {
        Specialty = specialty;
    }

    public void Heal()
    {
        Console.WriteLine($"Doctor {FullName} with ID {ID}, salary {Salary:C}, and specialty {Specialty} is healing a patient.");
    }

    public new void Print()
    {
        if (this == null) return;
        base.Print();
        Console.WriteLine("Specialty : " + Specialty);
    }
};

internal class Program
{ 
    public static void Main(string[] args)
    {
        
        //

        clsEmployee Emp1 = new clsEmployee(10,"Hamo","Shaaban",25,5000,"it");
        Emp1.Print();
        Emp1.IncreaseSalaryBy(1000);
        Console.WriteLine("\nAfter Increase Salary By 1000\n------------------------------");
        Emp1.Print();
        Console.WriteLine("-------------------------------");
        //Upcasting
        clsPerson P1 =Emp1;
        

        P1.Print();
        Console.WriteLine("-------------------------------");

        //Downcasting
        clsEmployee emp2 = (clsEmployee)P1;
        Emp1.Print();
        Console.WriteLine("-------------------------------");
        Console.WriteLine("Print Doctor");
        Console.WriteLine("-------------------------------");
        clsDoctor Doc1 =new clsDoctor(10, "Hamo", "Shaaban", 25, 5000, "it", "Cardiology") ;
       
        Doc1.Print();
        Console.WriteLine("-------------------------------");
        Console.WriteLine("Hell Function");
        Console.WriteLine("-------------------------------");
        Doc1.Heal();


        Console.ReadKey();
    }
}
