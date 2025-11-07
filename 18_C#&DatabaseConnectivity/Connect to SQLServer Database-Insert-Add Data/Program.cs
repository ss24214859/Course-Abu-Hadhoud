using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Net.Configuration;
using System.Text;
using System.Threading.Tasks;

namespace Connect_to_SQLServer_Database_Insert_Add_Data
{
    internal class Program
    {
        static string ConnectionString = "Server=.;Database=ContactsDB;User ID=sa;Password=123456;";
        public struct stContact
        {
            public int ContactID { get; set; }
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public string Email { get; set; }
            public string Phone { get; set; }
            public string Address { get; set; }
            public int CountryID { get; set; }
        }

        static void AddNewContact(stContact Contact)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string Query = "INSERT INTO Contacts([FirstName],[LastName],[Email],[Phone] ,[Address],[CountryID]) VALUES(@FirstName, @LastName,@Email,@Phone,@Address,@CountryID)";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@FirstName", Contact.FirstName);
            cmd.Parameters.AddWithValue("@LastName",Contact.LastName);
            cmd.Parameters.AddWithValue("@Email",Contact.Email);
            cmd.Parameters.AddWithValue("@Phone", Contact.Phone);
            cmd.Parameters.AddWithValue("@Address",Contact.Address);
            cmd.Parameters.AddWithValue("@CountryID",Contact.CountryID);

            try
            {
                Connection.Open();
                int RowsAffected = cmd.ExecuteNonQuery();
                if(RowsAffected > 0)
                {
                    Console.WriteLine("Record Inserted Successfully");
                }
                else
                {
                    Console.WriteLine("Record Insertion Failed");
                }
                Connection.Close();
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            
        }

        static int AddNewContactAndGetID(stContact Contact)
        {

            int InsertedID = 0;

            SqlConnection Connection = new SqlConnection(ConnectionString);
            string Query = "INSERT INTO Contacts([FirstName],[LastName],[Email],[Phone] ,[Address],[CountryID])" +
                " VALUES(@FirstName, @LastName,@Email,@Phone,@Address,@CountryID);" +
                "SELECT SCOPE_IDENTITY();";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@FirstName", Contact.FirstName);
            cmd.Parameters.AddWithValue("@LastName", Contact.LastName);
            cmd.Parameters.AddWithValue("@Email", Contact.Email);
            cmd.Parameters.AddWithValue("@Phone", Contact.Phone);
            cmd.Parameters.AddWithValue("@Address", Contact.Address);
            cmd.Parameters.AddWithValue("@CountryID", Contact.CountryID);

            try
            {
                Connection.Open();
                object Result = cmd.ExecuteScalar();
                if (Result !=null && int.TryParse(Result.ToString(),out int insertedID))
                {
                    InsertedID = insertedID;
                    Console.WriteLine($"Newly Inserted ID:{insertedID}");
                }
                else
                {
                    Console.WriteLine("Failed To Retrieve the Inserted ID.");
                }
                
                Connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            return InsertedID;
        }
        static void Main(string[] args)
        {
            stContact contact = new stContact();
            contact.FirstName = "jane";
            contact.LastName = "shhaaaa";
            contact.Email = "janjon@hgg.com";
            contact.Phone = "0855554565";
            contact.Address = "jht 335f";
            contact.CountryID = 2;

            Console.WriteLine("ID : " + AddNewContactAndGetID(contact));

        }
    }
}
