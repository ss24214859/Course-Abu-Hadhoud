using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EmployeesDataAccessLayer;


namespace EmployeesBusinessLayer
{
    public class clsAttendance
    {
        int AttendanceID { get; set; }
        int EmployeeID { get; set; }
        int StatusID {get;set;}
        DateTime DayDate {get;set;}

        enum enModeSave { Addnew=0 , Update=1}
        enModeSave ModeSave = enModeSave.Addnew;

        public clsAttendance()
        {
            AttendanceID = -1; EmployeeID = -1; StatusID = -1; DayDate = DateTime.Now;
            ModeSave = enModeSave.Addnew;
        }
        private bool _AddNewAttendance()
        {
            AttendanceID = clsAttendanceData.AddNewAttendance(EmployeeID,StatusID,DayDate);
            return (AttendanceID != -1);
        }
        private bool _UpdateAttendance()
        {
            return clsAttendanceData.UpdateAttendance(AttendanceID, EmployeeID,StatusID, DayDate);
        }
        public clsAttendance(int attendanceID, int employeeID, int statusID, DateTime dayDate)
        {
            AttendanceID = attendanceID;
            EmployeeID = employeeID;
            StatusID = statusID;
            DayDate = dayDate;

            ModeSave = enModeSave.Update;

        }

        static public DataTable GetAllAttendance()
        {
            return clsAttendanceData.GetAllAttendanceDays();
        }
        static public DataTable GetAttendanceByDayDate(DateTime DayDate)
        {
            return clsAttendanceData.GetAllAttendanceByDayDate(DayDate);
        }
        
        static clsAttendance Find(int AttendanceID)
        {
            int EmployeeID = -1;
            int StatusID = -1;
            DateTime DayDate = DateTime.Now;
            if (clsAttendanceData.GetAttendanceInfoByID(AttendanceID, ref EmployeeID, ref StatusID, ref DayDate))
                return new clsAttendance(AttendanceID, EmployeeID, StatusID, DayDate);
            else
                return null; 
        }

        static public bool IsAttendanceExist(int AttendanceID)
        {
            return clsAttendanceData.IsAttendanceExistByID(AttendanceID);
        }

        static public bool Delete(int AttendanceID)
        {
            return clsAttendance.Delete(AttendanceID);
        }

        public bool Save()
        {
            switch (ModeSave)
            {
                case enModeSave.Addnew:
                    if(_AddNewAttendance())
                    {
                        ModeSave = enModeSave.Update;
                        return true;
                    }
                    else
                    return false;

                case enModeSave.Update:
                    return _UpdateAttendance();
            }
            return false;
        }
    }
}
