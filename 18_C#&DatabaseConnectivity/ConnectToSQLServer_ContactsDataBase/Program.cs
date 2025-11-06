using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

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

        static void Main(string[] args)
        {
            //PrintAllContacts();
            //PrintAllContactsWithFirstName("Jane");
            PrintAllContactsWithFirstNameAndCountryID("Jane",1);
        }
    }
}
