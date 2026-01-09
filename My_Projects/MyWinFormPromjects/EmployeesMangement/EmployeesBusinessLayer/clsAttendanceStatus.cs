using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.Remoting;
using System.Text;
using System.Threading.Tasks;
using EmployeesDataAccessLayer;

namespace EmployeesBusinessLayer
{
    public class clsAttendanceStatus
    {
        int StatusID {get;set;}
        string Name { get; set; }

        enum enModeSave { AddNew=0 , Update=1 }
        enModeSave ModeSave = enModeSave.AddNew;
        public clsAttendanceStatus()
        {
            StatusID = -1;
            Name = "";

            ModeSave = enModeSave.AddNew;
        }
        
        private bool _AddNewAttendanceStatus()
        {
            StatusID = clsAttendanceStatusData.AddNewStatus(Name);
            return (StatusID != -1);
        }
        private bool _UpdateAttendanceStatus()
        {
            return clsAttendanceStatusData.UpdateAttendanceStatus(StatusID, Name);
        }
        public clsAttendanceStatus(int statusID, string name)
        {
            StatusID = statusID;
            Name = name;

            ModeSave = enModeSave.Update;
        }

        public static clsAttendanceStatus Find(int ID)
        {
            string Name = "";
            if (clsAttendanceStatusData.GetStatusInfoByID(ID, ref Name))
                return new clsAttendanceStatus(ID, Name);
            else
                return null;
        }

        public static DataTable GetAllStatus()
        {
            return clsAttendanceStatusData.GetAllStatus();
        }

        public static bool IsStatusExist(int statusID)
        {
            return clsAttendanceStatusData.IsStatusExistByID(statusID);
        }

        public bool Save()
        {
            switch(ModeSave)
            {
                case enModeSave.AddNew:
                    if(_AddNewAttendanceStatus())
                    {
                        ModeSave = enModeSave.Update;
                        return true;
                    }
                    else 
                        return false;
                case enModeSave.Update:
                    return _UpdateAttendanceStatus();
            }
            return false;
        }
    }
}
