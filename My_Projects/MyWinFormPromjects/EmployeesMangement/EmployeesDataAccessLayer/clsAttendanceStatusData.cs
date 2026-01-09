using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeesDataAccessLayer
{
    public class clsAttendanceStatusData
    {
        static public bool GetStatusInfoByID(int StatusID, ref string Name)
        {
            bool IsFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = "SELECT * FROM AttendanceStatus WHERE AttendanceStatusID = @AttendanceStatusID;";
            SqlCommand command = new SqlCommand(Qurey, connection);
            command.Parameters.AddWithValue("@AttendanceStatusID", StatusID);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();

                if (reader.Read())
                {
                    IsFound = true;
                    Name = reader["Name"] != DBNull.Value ? (string)reader["Name"] : "";

                }
                else
                {
                    IsFound = false;
                }

                reader.Close();
            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message);
                IsFound = false;
            }
            finally
            {
                connection.Close();
            }
            return IsFound;
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
