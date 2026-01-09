using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ContactsDataAccessLayer
{
    public class clsContactData
    {
        public static bool GetContactInfoByID(int ID , ref string FirstName, ref string LastName,
            ref string Email, ref string Phone, ref string Address, ref DateTime DateOfBirth,
            ref int CountryID,ref string ImagePath)
        {
            bool IsFound = false;

            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = "SELECT * FROM Contacts WHERE ContactID = @ContactID";
            SqlCommand cmd = new SqlCommand(Query, conn);
            cmd.Parameters.AddWithValue("@ContactID",ID);

            try
            {
                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                if (reader.Read())
                {
                    //The Record is Found
                    IsFound = true;

                        FirstName =reader["FirstName"]    !=DBNull.Value?   (string)reader["FirstName"]     : "";       
                        LastName = reader["LastName"]     !=DBNull.Value?   (string)reader["LastName"]      : "";  
                        Email =    reader["Email"]        !=DBNull.Value?   (string)reader["Email"]         : "";        
                        Phone =    reader["Phone"]        !=DBNull.Value?   (string)reader["Phone"]         : "";      
                        Address =  reader["Address"]      !=DBNull.Value?   (string)reader["Address"]       : "";
                    DateOfBirth =  reader["DateOfBirth"]  !=DBNull.Value?   (DateTime)reader["DateOfBirth"]  : DateTime.Now;      
                    CountryID =    reader["CountryID"]    !=DBNull.Value?   (int)reader["CountryID"]        : -1;  
                    ImagePath =    reader["ImagePath"]    !=DBNull.Value?   (string)reader["ImagePath"]     : "";  
                }
                else
                {
                    //The Record is not Found
                    IsFound = false;
                }
                reader.Close();
            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message.ToString());
                IsFound = false;
            }
            finally
            {
                conn.Close();
            }
            return IsFound;
        }

        public static int AddNewContact(string FirstName, string LastName,
            string Email, string Phone, string Address, DateTime DateOfBirth,
            int CountryID, string ImagePath)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"INSERT INTO Contacts([FirstName],[LastName],[Email],[Phone] ,[Address],[DateOfBirth],[CountryID],[ImagePath])
                            VALUES(@FirstName, @LastName,@Email,@Phone,@Address,@DateOfBirth,@CountryID,@ImagePath);
                            SELECT SCOPE_IDENTITY();";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@FirstName",FirstName);
            cmd.Parameters.AddWithValue("@LastName", LastName);
            cmd.Parameters.AddWithValue("@Email",Email);
            cmd.Parameters.AddWithValue("@Phone",Phone);
            cmd.Parameters.AddWithValue("@Address", Address);
            cmd.Parameters.AddWithValue("@DateOfBirth", DateOfBirth);
            cmd.Parameters.AddWithValue("@CountryID",CountryID);
            if(ImagePath != "")
                cmd.Parameters.AddWithValue("@ImagePath", ImagePath);
            else
                cmd.Parameters.AddWithValue("@ImagePath", System.DBNull.Value);

            int ContactID = -1;
            try
            {
                Connection.Open();
                object Result = cmd.ExecuteScalar();
                if (Result !=null && int.TryParse(Result.ToString(),out int InsertedID))
                {
                    ContactID = InsertedID;
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Connection.Close();
            }
            return ContactID;
        }

        public static bool UpdateContact(int ContactID,string FirstName, string LastName,
           string Email, string Phone, string Address, DateTime DateOfBirth,
           int CountryID, string ImagePath)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"UPDATE [dbo].[Contacts]
                             SET [FirstName] = @FirstName,	
                                 [LastName] = @LastName,		
                                 [Email] = @Email,			
                                 [Phone] = @Phone,			
                                 [Address] = @Address,		
                                 [DateOfBirth] = @DateOfBirth,
                                 [CountryID] = @CountryID,	
                                 [ImagePath] = @ImagePath
                             WHERE  ContactID = @ContactID ;";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@ContactID", ContactID);
            cmd.Parameters.AddWithValue("@FirstName", FirstName);
            cmd.Parameters.AddWithValue("@LastName", LastName);
            cmd.Parameters.AddWithValue("@Email", Email);
            cmd.Parameters.AddWithValue("@Phone", Phone);
            cmd.Parameters.AddWithValue("@Address", Address);
            cmd.Parameters.AddWithValue("@DateOfBirth", DateOfBirth);
            cmd.Parameters.AddWithValue("@CountryID", CountryID);
            if (ImagePath != "")
                cmd.Parameters.AddWithValue("@ImagePath", ImagePath);
            else
                cmd.Parameters.AddWithValue("@ImagePath", System.DBNull.Value);
            
            int RowsAffected = 0;

            try
            {
                Connection.Open();
                RowsAffected = cmd.ExecuteNonQuery();

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                return false;
            }
            finally
            {
                Connection.Close();
            }
            return (RowsAffected >0);
        }

        public static bool DeleteContactByID(int ID)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"DELETE Contacts WHERE ContactID = @ContactID";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@ContactID", ID);

            int RowsAffected = 0;

            try
            {
                Connection.Open();
                RowsAffected = cmd.ExecuteNonQuery();

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                return false;
            }
            finally
            {
                Connection.Close();
            }
            return (RowsAffected > 0);
        }

        static public DataTable GetAllContacts()
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT * FROM Contacts";
            SqlCommand cmd= new SqlCommand(query, Connection);
            try
            {
                Connection.Open();
                SqlDataReader Reader = cmd.ExecuteReader();

                if(Reader.HasRows)
                    dt.Load(Reader);

                Reader.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
               
            }
            finally
            {
                Connection.Close();
            }
        
            return dt;
        }

        static public bool IsContactExistByID(int ID)
        {

            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT Found=1 FROM Contacts WHERE ContactID = @ContactID";
            SqlCommand cmd = new SqlCommand(query, Connection);
            cmd.Parameters.AddWithValue("@ContactID", ID);


            bool IsExist = false;

            try
            {
                
                Connection.Open();

                //SqlDataReader R = cmd.ExecuteReader();
                //if(R.HasRows)
                //    IsExist=true;
                

                object Result = cmd.ExecuteScalar();
                if(Result != null)
                    IsExist = true;

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
                return false;
            }
            finally
            {
                Connection.Close();
            }
            return IsExist ;
        }

    }
}
