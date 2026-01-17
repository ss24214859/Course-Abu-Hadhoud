using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeesDataAccessLayer
{
    public class clsAttendanceData
    {
        
        static public bool GetAttendanceInfoByID(int AttendanceID, ref int EmployeeID, ref int StatusID, ref DateTime DayDate)
        {
            bool IsFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = "SELECT * FROM Attendance WHERE AttendanceID = @AttendanceID;";
            SqlCommand command = new SqlCommand(Qurey, connection);
            command.Parameters.AddWithValue("@AttendanceID", AttendanceID);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();

                if (reader.Read())
                {
                    IsFound = true;
                    EmployeeID = reader["EmployeeID"] != DBNull.Value ? (int)reader["EmployeeID"] : -1;
                    StatusID = reader["StatusID"] != DBNull.Value ? (int)reader["StatusID"] : -1;
                    DayDate = reader["DateDay"] != DBNull.Value ? (DateTime)reader["DateDay"] : DateTime.Now;

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

        public static int AddNewAttendance(int EmployeeID,int StatusID, DateTime DayDate)
        {
            int AttendanceID = -1;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = @"INSERT INTO Attendance([EmployeeID],[StatusID],[DayDate])
                             VALUES(@EmployeeID,@StatusID,@DayDate);
                             SELECT SCOPE_IDENTITY();";
            SqlCommand command = new SqlCommand(Qurey, connection);
            command.Parameters.AddWithValue("@EmployeeID", EmployeeID);
            command.Parameters.AddWithValue("@StatusID", StatusID);
            command.Parameters.AddWithValue("@DayDate", DayDate);

            try
            {
                connection.Open();
                object Result = command.ExecuteScalar();

                if (Result != null && int.TryParse(Result.ToString(), out int InsertedID))
                {
                    AttendanceID = InsertedID;
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
            return AttendanceID;
        }

        static public bool UpdateAttendance(int AttendanceID, int EmployeeID, int StatusID, DateTime DayDate)
        {
            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = @"UPDATE Attendance set (EmployeeID = @EmployeeID,StatusID = @StatusID,DayDate = @DayDate)
                             WHERE AttendanceID = @AttendanceID;";
            SqlCommand command = new SqlCommand(Qurey, connection);

            command.Parameters.AddWithValue("@AttendanceID", AttendanceID);
            command.Parameters.AddWithValue("@EmployeeID", EmployeeID);
            command.Parameters.AddWithValue("@StatusID", StatusID);
            command.Parameters.AddWithValue("@DayDate", DayDate);
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

        public static bool DeleteAttendanceByID(int ID)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"DELETE Attendance WHERE AttendanceID = @AttendanceID";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@AttendanceID", ID);

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

        static public DataTable GetAllAttendanceByDayDate(DateTime DayDate)
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT * FROM Attendance WHERE DayDate = @DayDate;";
            SqlCommand cmd = new SqlCommand(query, Connection);
            cmd.Parameters.AddWithValue("@DayDate", DayDate);

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

        static public DataTable GetAllAttendanceDays()
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT * FROM Attendance;";
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

        static public bool IsAttendanceExistByID(int ID)
        {

            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT Found=1 FROM Attendance WHERE AttendanceID = @AttendanceID";
            SqlCommand cmd = new SqlCommand(query, Connection);
            cmd.Parameters.AddWithValue("@AttendanceID", ID);


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

