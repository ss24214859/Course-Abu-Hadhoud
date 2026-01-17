using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace EmployeesDataAccessLayer
{
    public class clsAttendanceStatusData
    {
        static public bool GetStatusInfoByID(int StatusID, ref string Name)
        {
            bool IsFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = "SELECT Name FROM AttendanceStatus WHERE AttendanceStatusID = @AttendanceStatusID;";
            SqlCommand command = new SqlCommand(Qurey, connection);
            command.Parameters.AddWithValue("@StatusID", StatusID);

            try
            {
                connection.Open();
                Object   Result = command.ExecuteReader();

                if (Result!= DBNull.Value && Result != null)
                {
                    IsFound = true;
                    Name = (string)Result;

                }
  
                
            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message);
                // Logger.Log(ex);
                throw;
            }
            finally
            {
                connection.Close();
            }
            return IsFound;
        }

        static public bool GetStatusInfoByName(string Name, ref int StatusID)
        {

            using (SqlConnection connection =
                   new SqlConnection(clsDataAccessSettings.ConnectionString))
            {
                string query = @"SELECT StatusID
                         FROM AttendanceStatus
                         WHERE Name = @Name";

                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    command.Parameters.Add("@Name", SqlDbType.NVarChar, 50).Value = Name;

                    try
                    {
                        connection.Open();
                        object result = command.ExecuteScalar();

                        if (result != null && result != DBNull.Value)
                        {
                            StatusID = Convert.ToInt32(result);
                            return true;
                        }
                    }
                    catch (Exception ex)
                    {
                        // Logger.Log(ex);
                        throw; 
                    }
                }
            }
            return false;
        }

        public static int AddNewStatus(string Name)
        {
            int StatusID = -1;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = @"INSERT INTO AttendanceStatus([Name])
                             VALUES(@Name);
                             SELECT SCOPE_IDENTITY();";
            SqlCommand command = new SqlCommand(Qurey, connection);
            command.Parameters.AddWithValue("@Name", Name);


            try
            {
                connection.Open();
                object Result = command.ExecuteScalar();

                if (Result != null && int.TryParse(Result.ToString(), out int InsertedID))
                {
                    StatusID = InsertedID;
                }

            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }
            return StatusID;
        }

        static public bool UpdateAttendanceStatus(int StatusID, string Name)
        {
            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = @"UPDATE AttendanceStatus set (Name = @Name)
                             WHERE StatusID = @StatusID;";
            SqlCommand command = new SqlCommand(Qurey, connection);

            command.Parameters.AddWithValue("@Name", Name);
            command.Parameters.AddWithValue("@StatusID", StatusID);

            int RowsAffected = 0;
            try
            {
                connection.Open();
                RowsAffected = command.ExecuteNonQuery();

            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }
            return (RowsAffected > 0);
        }

        public static bool DeleteStatusByID(int ID)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"DELETE AttendanceStatus WHERE StatusID = @StatusID";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@StatusID", ID);

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

        static public DataTable GetAllStatus()
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT * FROM AttendanceStatus;";
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

        static public bool IsStatusExistByID(int ID)
        {

            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT Found=1 FROM AttendanceStatus WHERE StatusID = @StatusID";
            SqlCommand cmd = new SqlCommand(query, Connection);
            cmd.Parameters.AddWithValue("@StatusID", ID);


            bool IsExist = false;

            try
            {

                Connection.Open();

                object Result = cmd.ExecuteScalar();
                if (Result != null)
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
            return IsExist;


        }
    }
}
