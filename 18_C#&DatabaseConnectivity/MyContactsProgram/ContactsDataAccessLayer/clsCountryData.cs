using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace ContactsDataAccessLayer
{
    public class clsCountryData
    {

        static public bool GetCountryByName(ref int CountryID, string CountryName,ref string Code,ref string PhoneCode)
        {
            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "Select * From Countries WHERE CountryName = @CountryName";
            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@CountryName", CountryName);

            bool IsFound;
            try
            {
                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    CountryID = (int)reader["CountryID"];
                    Code = (reader["Code"] != DBNull.Value)? (string)reader["Code"] : "";
                    PhoneCode = (reader["PhoneCode"] != DBNull.Value) ? (string)reader["PhoneCode"] : "";
                    IsFound = true;
                }
                else
                    IsFound = false;

                reader.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                IsFound = false;
            }
            finally
            {
                conn.Close();
            }

            return IsFound;
        }


        static public bool GetCountryByID( int CountryID, ref string CountryName ,ref string Code,ref string PhoneCode)
        {
            SqlConnection conn = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "Select * From Countries WHERE CountryID = @CountryID";
            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.Parameters.AddWithValue("@CountryID", CountryID);

            bool IsFound;
            try
            {
                conn.Open();
                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    CountryName = (string)reader["CountryName"];
                    Code = (reader["Code"] != DBNull.Value) ? (string)reader["Code"] : "";
                    PhoneCode = (reader["PhoneCode"] != DBNull.Value) ? (string)reader["PhoneCode"] : "";
                    IsFound = true;
                }
                else
                    IsFound = false;

                reader.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                IsFound = false;
            }
            finally
            {
                conn.Close();
            }

            return IsFound;
        }



        static public bool IsCountryExistByName(string Name)
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT Found=1 FROM Countries WHERE CountryName = @CountryName";
            SqlCommand cmd = new SqlCommand(query, Connection);
            cmd.Parameters.AddWithValue("@CountryName", Name);


            bool IsExist = false;

            try
            {

                Connection.Open();

                //SqlDataReader R = cmd.ExecuteReader();
                //if(R.HasRows)
                //    IsExist=true;


                object Result = cmd.ExecuteScalar();
                if (Result != null)
                    IsExist = true;

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Connection.Close();
            }
            return IsExist;
        }

        public static bool UpdateCountry(int CountryID, string CountryName , string Code, string PhoneCode)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"UPDATE [dbo].[Countries]
                             SET CountryName = @CountryName,
                                 Code = @Code,
                                 PhoneCode = @PhoneCode
                             WHERE  CountryID = @CountryID ;";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@CountryID", CountryID);
            cmd.Parameters.AddWithValue("@CountryName", CountryName);
            cmd.Parameters.AddWithValue("@Code", Code);
            cmd.Parameters.AddWithValue("@PhoneCode",PhoneCode);

            int RowsAffected = 0;

            try
            {
                Connection.Open();
                RowsAffected = cmd.ExecuteNonQuery();

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                Connection.Close();
            }
            return (RowsAffected > 0);
        }


        public static int AddNewCountry(string CountryName, string Code, string PhoneCode)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"INSERT INTO Countries([CountryName],[Code],[PhoneCode])
                            VALUES(@CountryName,@Code,@PhoneCode);
                            SELECT SCOPE_IDENTITY();";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@CountryName", CountryName);
            cmd.Parameters.AddWithValue("@Code", Code);
            cmd.Parameters.AddWithValue("@PhoneCode", PhoneCode);



            int CountryID = -1;
            try
            {
                Connection.Open();
                object Result = cmd.ExecuteScalar();
                if (Result != null && int.TryParse(Result.ToString(), out int InsertedID))
                {
                    CountryID = InsertedID;
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
            return CountryID;
        }

        public static bool DeleteCountryByID(int ID)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"DELETE Countries WHERE CountryID = @CountryID";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@CountryID", ID);

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

        static public DataTable GetAllCountries()
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT * FROM Countries";
            SqlCommand cmd = new SqlCommand(query, Connection);
            try
            {
                Connection.Open();
                SqlDataReader Reader = cmd.ExecuteReader();

                if (Reader.HasRows)
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

        
    }
}
