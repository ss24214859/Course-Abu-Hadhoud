using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeesDataAccessLayer
{
    public class clsAttendanceReportsDAL
    {
        static public DataTable GetAttendanceByDateForAttendancList(DateTime DayDate)
        {
            DataTable dt = new DataTable();
            SqlConnection Connection = new SqlConnection(clsDataAccessSettings.ConnectionString);
            string query = @"SELECT       E.EmployeeID, E.FirstName, E.Phone, IsNull(A.StatusID, CAST(1 AS INT) ) As StatusID
                             FROM   Employees E
                             				Left JOIN Attendance A
                                             ON A.EmployeeID = E.EmployeeID
                             	  And DayDate >= @DayDate
                             	  And  DayDate < DATEADD(day,1,@DayDate)	
                             
                             where  HireDate <= @DayDate ;";

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

}
}
