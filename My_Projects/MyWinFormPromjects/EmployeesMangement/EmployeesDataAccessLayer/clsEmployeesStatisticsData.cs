using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeesDataAccessLayer
{
    public  class clsEmployeesStatisticsData
    {


        static public int GetEmployeesCountByYear(int Year)
        {
           
            int TotalEmployees=-1;
            SqlConnection connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string Qurey = $@"SELECT count(1) HiredEmployeeCount FROM Employees
                              WHERE Year(HireDate) = @Year ";
            SqlCommand command = new SqlCommand(Qurey, connection);
            command.Parameters.AddWithValue("@Year", Year);

            try
            {
                connection.Open();
                object Result = command.ExecuteScalar();

                if (Result != null)
                    TotalEmployees = Convert.ToInt32(Result);

            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message);
                
            }
            finally
            {
                connection.Close();
            }
            return TotalEmployees;
        }

        static public DataTable GetRecentHiresLast3Employees()
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = @"Select top 3 (FirstName + ' ' + LastName)as Name , HireDate,Salary From Employees
                             order by HireDate desc";
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

        static public bool GetEmployeesSalaryStatistics(ref double MaximumSalary, ref double MinimumSalary, ref double AverageSalary, ref double TotalEmployees, ref double TotalPayroll)
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
                    MaximumSalary = reader["MaximumSalary"] != DBNull.Value ? Convert.ToDouble(reader["MaximumSalary"]) : -1;
                    MinimumSalary = reader["MinimumSalary"] != DBNull.Value ? Convert.ToDouble(reader["MinimumSalary"]) : -1;
                    AverageSalary = reader["AverageSalary"] != DBNull.Value ? Convert.ToDouble(reader["AverageSalary"]) : -1;
                    TotalEmployees = reader["TotalEmployees"] != DBNull.Value ? Convert.ToDouble(reader["TotalEmployees"]) : -1;
                    TotalPayroll = reader["TotalPayroll"] != DBNull.Value ? Convert.ToDouble(reader["TotalPayroll"]) : -1;

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
