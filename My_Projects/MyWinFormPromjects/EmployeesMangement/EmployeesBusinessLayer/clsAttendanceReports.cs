using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EmployeesDataAccessLayer;

namespace EmployeesBusinessLayer
{
    public class clsAttendanceReports
    {
        static public DataTable GetAttendanceByDateForAttendancList(DateTime DayDate)
        {
            return clsAttendanceReportsDAL.GetAttendanceByDateForAttendancList(DayDate);
        }
    }
}
