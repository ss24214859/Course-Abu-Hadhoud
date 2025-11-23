using System;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ContactsBusinessLayer;

namespace ContactsConsolApp_PresentationLayer
{
    internal class Program
    {

        public static void PrintContact(clsContact contact)
        {
            if (contact != null)
            {
                Console.WriteLine($"ID :{contact.ID}");
                Console.WriteLine($"FirstName :{contact.FirstName}");
                Console.WriteLine($"LastName : {contact.LastName}");
                Console.WriteLine($"Email :{contact.Email}");
                Console.WriteLine($"Address :{contact.Address}");
                Console.WriteLine($"DateOfBirth :{contact.DateOfBirth}");
                Console.WriteLine($"CountryID :{contact.CountryID}");
                Console.WriteLine($"ImagePath :{contact.ImagePath}");
            }
        }
        static void testFindContactByID(int ID)
        {
            clsContact Contact =  clsContact.Find(ID);
            if (Contact != null)
                PrintContact(Contact);
            else
                Console.WriteLine($"Contact[{ID}] Not Found!");
            

        }

        static void testAddNewContact()
        {
            clsContact Contact = new clsContact();
            Contact.ID = 5;
            Contact.FirstName = "Hamo";
            Contact.LastName = "Shaaban";
            Contact.Email = "shjhjh@gamil.com";
            Contact.Phone = "02012";
            Contact.Address = "llj 555";
            Contact.DateOfBirth = new DateTime(2004, 4, 6, 1, 30, 5);
            Contact.CountryID = 1;


            if (Contact.Save())
            {
                Console.WriteLine($"Contact Added Successfully :-) with ID = {Contact.ID}");
            }
            else
            {
                Console.WriteLine(" Failed !  To Add Contact :-(");
            }
        }


        static void testUpdateContact()
        {
            clsContact Contact = clsContact.Find(24);
        Contact.FirstName= "hi";
            Contact.LastName = "kjdjkldjflkdndl";
            Contact.Email = "dd@hh.com";
            Contact.Phone = "dddddd";
            Contact.Address = "llj ddd";
            Contact.DateOfBirth= new DateTime(2063,4,6,1,30,5);
            Contact.CountryID = 2;
            
            
            if(Contact.Save())
            {
                Console.WriteLine($"Contact Updated Successfully :-)");
                Console.WriteLine();
                PrintContact(Contact);
            }
            else
            {
                Console.WriteLine(" Failed! To Update Contact :-(");
            }
        }

        static void testDeleteContact(int ID)
        {
            if(clsContact.Delete(ID))
            {
                Console.WriteLine("Contact Deleted Successfully :-)");
            }
            else
            {
                Console.WriteLine("Failed! To Delete Contact :-(");
            }

        }

        static void testGetAllContacts()
        {
            DataTable dataTable = clsContact.GetAllContacts();
            Console.WriteLine("Contacts Data:\n");

            foreach(DataRow row in dataTable.Rows)
            {
                Console.WriteLine($"{row["ContactID"]} , {row["FirstName"]} , {row["LastName"]}");
            }
        }

        static void testContactExist(int ID)
        {
            if (clsContact.IsContactExist(ID))
                Console.WriteLine("Contact is Exist :-)");
            else
                Console.WriteLine($"Contact[{ID}] Not Found!");


        }


        public static void PrintCountry(clsCountry Country)
        {
            if (Country != null)
            {
                Console.WriteLine($"Country ID  : {Country.ID}");
                Console.WriteLine($"Country Name: {Country.Name}");
                
            }
        }
        static void testFindCountryByName(string Name)
        {
            clsCountry Country = clsCountry.Find(Name);
            if (Country != null)
                PrintCountry(Country);
            else
                Console.WriteLine($"Country[{Country.ID}] Not Found!");


        }

        static void testFindCountryByName(int ID)
        {
            clsCountry Country = clsCountry.Find(ID);
            if (Country != null)
                PrintCountry(Country);
            else
                Console.WriteLine($"Country[{Country.ID}] Not Found!");


        }

        static void testCountryExist(string Name)
        {
            if (clsCountry.IsExist(Name))
                Console.WriteLine("Country is Exist :-)");
            else
                Console.WriteLine($"Country[{Name}] Not Found!");


        }



        static void testAddNewCountry()
        {
            clsCountry Country = new clsCountry();
            Country.Name = "Hamo";
            Country.Code = "1";
            Country.PhoneCode = "1";  

           


            if (Country.Save())
            {
                Console.WriteLine($"Country Added Successfully :-) with ID = {Country.ID}");
            }
            else
            {
                Console.WriteLine(" Failed !  To Add Country :-(");
            }
        }


        static void testUpdateCountry(int ID)
        {
            clsCountry Country = clsCountry.Find(ID);
            Country.Name = "Germany";
           


            if (Country.Save())
            {
                Console.WriteLine($"Country Updated Successfully :-)");
                Console.WriteLine();
                PrintCountry(Country);
            }
            else
            {
                Console.WriteLine(" Failed! To Update Country :-(");
            }
        }

        static void testDeleteCountry(int ID)
        {
            if (clsCountry.Delete(ID))
            {
                Console.WriteLine("Country Deleted Successfully :-)");
            }
            else
            {
                Console.WriteLine("Failed! To Delete Country :-(");
            }

        }

        static void testGetAllCountries()
        {
            DataTable dataTable = clsCountry.GetAllCountries();
            Console.WriteLine("Countries Data:\n");

            foreach (DataRow row in dataTable.Rows)
            {
                Console.WriteLine($"{row["CountryID"]} , {row["CountryName"]} , {row["Code"]} ");
            }
        }

        static void Main(string[] args)
        {
            //testFindContactByID(5);
            //testContactExist(1);

            //testAddNewContact();
            //testUpdateContact();
            //testDeleteContact(26);
            //testGetAllContacts();

            //testFindCountryByName("Canada");
            //testFindCountryByName(5);
            //testCountryExist("Australia");
            //testAddNewCountry();
            //testUpdateCountry(5);
            //testDeleteCountry(7);
            testGetAllCountries();


        }
    }
}
