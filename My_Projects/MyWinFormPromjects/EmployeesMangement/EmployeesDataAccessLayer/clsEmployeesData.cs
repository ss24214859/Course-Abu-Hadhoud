using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace EmployeesDataAccessLayer
{
    public class clsEmployeesData
    {
        static public bool GetEmployeeInfoByID(int ID , ref string FirstName,  ref string LastName, ref string Phone, ref double Salary, ref DateTime HireDate)
        {
            bool IsFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = "SELECT * FROM Employees WHERE EmployeeID = @EmployeeID;";
            SqlCommand command = new SqlCommand(Qurey, connection);
            command.Parameters.AddWithValue("@EmployeeID", ID);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();

                if(reader.Read())
                {
                    IsFound = true;
                    FirstName = reader["FirstName"] != DBNull.Value ? (string)reader["FirstName"] : "";
                    LastName = reader["LastName"] != DBNull.Value ? (string)reader["LastName"] : "";
                    Phone = reader["Phone"] != DBNull.Value ? (string)reader["Phone"] : "";
                    Salary = reader["Salary"] != DBNull.Value ? Convert.ToDouble( reader["Salary"] ):-1;
                    HireDate = reader["HireDate"] != DBNull.Value ?(DateTime)reader["HireDate"]: DateTime.Now;

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

        public static int AddNewEmployee(string FirstName,  string LastName,  string Phone,  double? Salary,  DateTime HireDate)
        {
            int EmployeeID = -1;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = @"INSERT INTO Employees([FirstName],[LastName],[Phone],[Salary],[HireDate])
                             VALUES(@FirstName,@LastName,@Phone,@Salary,@HireDate);
                             SELECT SCOPE_IDENTITY();" ;
            SqlCommand command = new SqlCommand(Qurey, connection);
            command.Parameters.AddWithValue("@FirstName", FirstName);
            command.Parameters.AddWithValue("@LastName", LastName);
            command.Parameters.AddWithValue("@Phone", Phone);
            command.Parameters.AddWithValue("@Salary", Salary);
            command.Parameters.AddWithValue("@HireDate", HireDate);

            try
            {
                connection.Open();
                object Result = command.ExecuteScalar();

                if (Result != null && int.TryParse(Result.ToString(),out int InsertedID ))
                {
                    EmployeeID = InsertedID;
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
            return EmployeeID;
        }

        static public bool UpdateEmployee(int ID, string FirstName, string LastName,  string Phone,  double? Salary,  DateTime HireDate)
        {
            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = @"UPDATE Employees set (FirstName = @FirstName,LastName = @LastName,Phone = @Phone,Salary = @Salary,HireDate = @HireDate)
                             WHERE EmployeeID = @EmployeeID;";
            SqlCommand command = new SqlCommand(Qurey, connection);

            command.Parameters.AddWithValue("@EmployeeID", ID);
            command.Parameters.AddWithValue("@FirstName", FirstName);
            command.Parameters.AddWithValue("@LastName", LastName);
            command.Parameters.AddWithValue("@Phone", Phone);
            command.Parameters.AddWithValue("@Salary", Salary);
            command.Parameters.AddWithValue("@HireDate", HireDate);
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

        public static bool DeleteEmployeeByID(int ID)
        {
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Query = @"DELETE Employees WHERE EmployeeID = @EmployeeID";

            SqlCommand cmd = new SqlCommand(Query, Connection);
            cmd.Parameters.AddWithValue("@EmployeeID", ID);

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

        static public DataTable GetAllEmployees ()
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT * FROM Employees;";
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

        static public bool IsEmployeeExistByID(int ID)
        {

            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = "SELECT Found=1 FROM Employees WHERE EmployeeID = @EmployeeID";
            SqlCommand cmd = new SqlCommand(query, Connection);
            cmd.Parameters.AddWithValue("@EmployeeID", ID);


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
                return false;
            }
            finally
            {
                Connection.Close();
            }
            return IsExist;


        }


        static public bool GetEmployeesStatistics(ref double MaximumSalary, ref double MinimumSalary, ref double AverageSalary, ref int TotalEmployees, ref double TotalPayroll)
        {
            bool IsFound = false;

            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);

            string Qurey = "SELECT * FROM StatisticsView";
            SqlCommand command = new SqlCommand(Qurey, connection);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();

                if (reader.Read())
                {
                    IsFound = true;
                    MaximumSalary = reader["MaximumSalary"] != DBNull.Value ? (double)reader["MaximumSalary"] : -1;
                    MinimumSalary = reader["MinimumSalary"] != DBNull.Value ? (double)reader["MinimumSalary"] : -1;
                    AverageSalary = reader["AverageSalary"] != DBNull.Value ? (double)reader["AverageSalary"] : -1;
                    TotalEmployees = reader["TotalEmployees"] != DBNull.Value ? (int)reader["TotalEmployees"] : -1;
                    TotalPayroll = reader["TotalPayroll"] != DBNull.Value ? (double)reader["TotalPayroll"]: -1;


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
    }
}
