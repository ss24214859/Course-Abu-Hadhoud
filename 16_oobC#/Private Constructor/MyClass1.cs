using System;



public  abstract partial class clsPerson
{

    public int ID { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }

    public Int16 Age { get; set; }

    public string Username { get; set; }

    public string Password { get; set; }

    public string FullName
    {
        get
        {
            return FirstName + " " + LastName;
        }
    }


    // To don't Create new Empty Object.
    public clsPerson(int iD, string Firstname, string Lastname, Int16 age)
    {
        ID = iD;
        FirstName = Firstname;
        LastName = Lastname;
        Age = age;
    }
    
};
