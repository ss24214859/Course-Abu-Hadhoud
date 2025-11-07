using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Dynamic;

namespace ConnectToSQLServer_ContactsDataBase
{ 
    internal class Program
    {
        static string ConnectionString = "Server=.;Database=ContactsDB;User ID=sa;Password=123456;";


        static void PrintAllContacts()
        { 
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string query = "Select * From Contacts";
            SqlCommand Command = new SqlCommand(query, Connection);

            try
            {
                Connection.Open();
                SqlDataReader Reader = Command.ExecuteReader();
                while (Reader.Read())
                {
                    int ContactID = (int)Reader["ContactID"];
                    string FirstName = (string)Reader["FirstName"];
                    string LastName = (string)Reader["LastName"];
                    string Email = (string)Reader["Email"];
                    string Phone = (string)Reader["Phone"];
                    string Address = (string)Reader["Address"];
                    int CountryID = (int)Reader["CountryID"];

                    Console.WriteLine($"Contact ID: {ContactID}");
                    Console.WriteLine($"First Name: {FirstName}");
                    Console.WriteLine($"Last Name: {LastName}");
                    Console.WriteLine($"Email: {Email}");
                    Console.WriteLine($"Phone: {Phone}");
                    Console.WriteLine($"Address: {Address}");
                    Console.WriteLine($"CountryID: {CountryID}");
                    Console.WriteLine();
                }

                Reader.Close();
                Connection.Close();
            }
            catch (Exception ex) 
            {
                Console.WriteLine("Error: " + ex.ToString()); 
            }
        }

       
        static void PrintAllContactsWithFirstName(string FirstName)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string query = "SELECT * FROM Contacts WHERE FirstName = @FirstName ";
            SqlCommand Command = new SqlCommand(query, Connection);
            Command.Parameters.AddWithValue("@FirstName", FirstName);

            try
            {
                Connection.Open();
                SqlDataReader Reader = Command.ExecuteReader();
                while (Reader.Read())
                {
                    int ContactID = (int)Reader["ContactID"];
                    string firstName = (string)Reader["FirstName"];
                    string LastName = (string)Reader["LastName"];
                    string Email = (string)Reader["Email"];
                    string Phone = (string)Reader["Phone"];
                    string Address = (string)Reader["Address"];
                    int CountryID = (int)Reader["CountryID"];

                    Console.WriteLine($"Contact ID: {ContactID}");
                    Console.WriteLine($"First Name: {firstName}");
                    Console.WriteLine($"Last Name: {LastName}");
                    Console.WriteLine($"Email: {Email}");
                    Console.WriteLine($"Phone: {Phone}");
                    Console.WriteLine($"Address: {Address}");
                    Console.WriteLine($"CountryID: {CountryID}");
                    Console.WriteLine();
                }

                Reader.Close();
                Connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
        }

        static void PrintAllContactsWithFirstNameAndCountryID(string FirstName,int CountryID)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string query = "SELECT * FROM Contacts WHERE FirstName = @FirstName And CountryID = @CountryID ";
            SqlCommand Command = new SqlCommand(query, Connection);
            Command.Parameters.AddWithValue("@FirstName", FirstName);
            Command.Parameters.AddWithValue("@CountryID", CountryID);

            try
            {
                Connection.Open();
                SqlDataReader Reader = Command.ExecuteReader();
                while (Reader.Read())
                {
                    int ContactID = (int)Reader["ContactID"];
                    string firstName = (string)Reader["FirstName"];
                    string LastName = (string)Reader["LastName"];
                    string Email = (string)Reader["Email"];
                    string Phone = (string)Reader["Phone"];
                    string Address = (string)Reader["Address"];
                    int countryID = (int)Reader["CountryID"];

                    Console.WriteLine($"Contact ID: {ContactID}");
                    Console.WriteLine($"First Name: {firstName}");
                    Console.WriteLine($"Last Name: {LastName}");
                    Console.WriteLine($"Email: {Email}");
                    Console.WriteLine($"Phone: {Phone}");
                    Console.WriteLine($"Address: {Address}");
                    Console.WriteLine($"CountryID: {countryID}");
                    Console.WriteLine();
                }

                Reader.Close();
                Connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
        }


        static void PrintAllContactsStartsWith(string StartsWith)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string query = "SELECT * FROM Contacts WHERE FirstName LIKE '' + @StartsWith + '%'";
            SqlCommand Command = new SqlCommand(query, Connection);
            Command.Parameters.AddWithValue("@StartsWith", StartsWith);
            

            try
            {
                Connection.Open();
                SqlDataReader Reader = Command.ExecuteReader();
                while (Reader.Read())
                {
                    int ContactID = (int)Reader["ContactID"];
                    string firstName = (string)Reader["FirstName"];
                    string LastName = (string)Reader["LastName"];
                    string Email = (string)Reader["Email"];
                    string Phone = (string)Reader["Phone"];
                    string Address = (string)Reader["Address"];
                    int countryID = (int)Reader["CountryID"];

                    Console.WriteLine($"Contact ID: {ContactID}");
                    Console.WriteLine($"First Name: {firstName}");
                    Console.WriteLine($"Last Name: {LastName}");
                    Console.WriteLine($"Email: {Email}");
                    Console.WriteLine($"Phone: {Phone}");
                    Console.WriteLine($"Address: {Address}");
                    Console.WriteLine($"CountryID: {countryID}");
                    Console.WriteLine();
                }

                Reader.Close();
                Connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
        }


        static void PrintAllContactsEndsWith(string EndsWith)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string query = "SELECT * FROM Contacts WHERE FirstName LIKE '%' + @EndsWith +'' ";
            SqlCommand Command = new SqlCommand(query, Connection);
            Command.Parameters.AddWithValue("@EndsWith", EndsWith);


            try
            {
                Connection.Open();
                SqlDataReader Reader = Command.ExecuteReader();
                while (Reader.Read())
                {
                    int ContactID = (int)Reader["ContactID"];
                    string firstName = (string)Reader["FirstName"];
                    string LastName = (string)Reader["LastName"];
                    string Email = (string)Reader["Email"];
                    string Phone = (string)Reader["Phone"];
                    string Address = (string)Reader["Address"];
                    int countryID = (int)Reader["CountryID"];

                    Console.WriteLine($"Contact ID: {ContactID}");
                    Console.WriteLine($"First Name: {firstName}");
                    Console.WriteLine($"Last Name: {LastName}");
                    Console.WriteLine($"Email: {Email}");
                    Console.WriteLine($"Phone: {Phone}");
                    Console.WriteLine($"Address: {Address}");
                    Console.WriteLine($"CountryID: {countryID}");
                    Console.WriteLine();
                }

                Reader.Close();
                Connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
        }




        static void PrintAllContactsContains(string Contains)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string query = "SELECT * FROM Contacts WHERE FirstName LIKE '%' + @Contains +'%' ";
            SqlCommand Command = new SqlCommand(query, Connection);
            Command.Parameters.AddWithValue("@Contains", Contains);


            try
            {
                Connection.Open();
                SqlDataReader Reader = Command.ExecuteReader();
                while (Reader.Read())
                {
                    int ContactID = (int)Reader["ContactID"];
                    string firstName = (string)Reader["FirstName"];
                    string LastName = (string)Reader["LastName"];
                    string Email = (string)Reader["Email"];
                    string Phone = (string)Reader["Phone"];
                    string Address = (string)Reader["Address"];
                    int countryID = (int)Reader["CountryID"];

                    Console.WriteLine($"Contact ID: {ContactID}");
                    Console.WriteLine($"First Name: {firstName}");
                    Console.WriteLine($"Last Name: {LastName}");
                    Console.WriteLine($"Email: {Email}");
                    Console.WriteLine($"Phone: {Phone}");
                    Console.WriteLine($"Address: {Address}");
                    Console.WriteLine($"CountryID: {countryID}");
                    Console.WriteLine();
                }

                Reader.Close();
                Connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
        }

        static string GetFirstNameByID(int ContactID)
        {
            string FirstName="";

            SqlConnection connection = new SqlConnection(ConnectionString);
            string Query = "SELECT FirstName FROM Contacts WHERE ContactID = @ContactID";
            SqlCommand cmd = new SqlCommand(Query, connection);
            cmd.Parameters.AddWithValue("@ContactID",ContactID);

            try
            {
                connection.Open();
                object result = cmd.ExecuteScalar();

                if (result != null)
                {
                    FirstName = result.ToString();
                }
                else
                {
                    FirstName = "";
                }
                connection.Close();
            }
            catch (Exception ex)
            { 
                Console.WriteLine(ex.ToString());
            }

            return FirstName;
        }


        public struct stContact
        {
            public int ContactID { get; set; }
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public string Email {  get; set; }
            public string Phone { get; set; }
            public string Address { get; set; }
            public int CountryID { get; set; }
        }


        static bool FindContactByID(int ContactID,ref stContact Contact)
        {
            bool IsFound = false;

            SqlConnection connection = new SqlConnection(ConnectionString);
            string Query = "SELECT * FROM Contacts WHERE ContactID = @ContactID";
            SqlCommand cmd = new SqlCommand(Query, connection);
            cmd.Parameters.AddWithValue("@ContactID", ContactID);
            try
            {
                connection.Open();
                SqlDataReader Reader = cmd.ExecuteReader();
                    if (Reader.Read())
                    {
                    // the Record is Found.
                        Contact.ContactID = (int)Reader["ContactID"];
                        Contact.FirstName = (string)Reader["FirstName"];
                        Contact.LastName = (string)Reader["LastName"];
                        Contact.Email = (string)Reader["Email"];
                        Contact.Phone = (string)Reader["Phone"];
                        Contact.Address = (string)Reader["Address"];
                        Contact.CountryID = (int)Reader["CountryID"];
                        IsFound = true;
                    }
                    else
                    {
                    //the Record is Not Found.
                        IsFound = false;
                    }

                Reader.Close();
                connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.ToString());
            }
            return IsFound;
        }

        static void PrintContact(stContact Contact)
        {
            Console.WriteLine( "Contact ID : " + Contact.ContactID);
            Console.WriteLine($"Name       : {Contact.FirstName} {Contact.LastName}");
            Console.WriteLine( "Email      : " + Contact.Email);
            Console.WriteLine( "Phone      : " + Contact.Phone);
            Console.WriteLine( "Address    : " + Contact.Address);
            Console.WriteLine( "Country ID : " + Contact.CountryID);
            Console.WriteLine();
        }
        static void Main(string[] args)
        {
            // -- Lesson 1
            //PrintAllContacts();


            // -- Parameterized Query 
            /*
            PrintAllContactsWithFirstName("Jane");
            PrintAllContactsWithFirstNameAndCountryID("Jane",1);
            */

            // -- Parameterized Query With "Like"
            /*
            Console.WriteLine("------------Contacts Starts With 'j' ");
            PrintAllContactsStartsWith("j");

            Console.WriteLine("------------Contacts Ends With 'ne' ");
            PrintAllContactsEndsWith("ne");

            Console.WriteLine("------------Contacts Contains With 'ae' ");
            PrintAllContactsContains("ae");
            */

            //Console.WriteLine(GetFirstNameByID(5));

            stContact Contact = new stContact();

            if(FindContactByID(4,ref Contact))
            {
                PrintContact(Contact);
            }
            else
            {
                Console.WriteLine("Not Found");
            }
        }
    }
}
