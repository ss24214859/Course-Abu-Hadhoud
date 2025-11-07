using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sql_Update_Data
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

        static void UpdateContact(int ContactID,stContact Contact)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string Query = @"UPDATE Contacts" +
                        "   SET [FirstName] = @FirstName" +
                        "      ,[LastName] =  @LastName" +
                        "      ,[Email] = @Email" +
                        "      ,[Phone] = @Phone" +
                        "      ,[Address] =@Address" +
                        "      ,[CountryID] = @CountryID " +
                        "   WHERE ContactID = @ContactID  ";


            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@FirstName", Contact.FirstName);
            cmd.Parameters.AddWithValue("@LastName", Contact.LastName);
            cmd.Parameters.AddWithValue("@Email", Contact.Email);
            cmd.Parameters.AddWithValue("@Phone", Contact.Phone);
            cmd.Parameters.AddWithValue("@Address", Contact.Address);
            cmd.Parameters.AddWithValue("@CountryID", Contact.CountryID);
            cmd.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                Connection.Open();
                int RowsAffected = cmd.ExecuteNonQuery();
                if (RowsAffected > 0)
                {
                    Console.WriteLine("Record Updated Successfully");
                }
                else
                {
                    Console.WriteLine("Record Update Failed");
                }
                Connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }

        }

        static void DeleteContact(int ContactID)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string Query = @"DELETE  Contacts
                            Where ContactID = @ContactID";
            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                Connection.Open();
                int RowsAffected = cmd.ExecuteNonQuery();
                if (RowsAffected > 0)
                {
                    Console.WriteLine("Record Deleted Successfully");
                }
                else
                {
                    Console.WriteLine("Record Delete Failed");
                }
                Connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }

        static void Main(string[] args)
        {
            /*stContact contact = new stContact();
            contact.FirstName = "Ahmed";
            contact.LastName = "Ali";
            contact.Email = "Ahm@ali.com";
            contact.Phone = "0125557115";
            contact.Address = "335 stf";
            contact.CountryID = 2;

            UpdateContact(12, contact);*/

            DeleteContact(12);
        }
    }
}
