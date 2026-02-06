using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EmployeesDataAccessLayer;

namespace EmployeesBusinessLayer
{
    public class clsEmployee
    {
        

        enum enSaveMode {AddNew = 0 , Update = 1 };
        enSaveMode SaveMode = enSaveMode.AddNew;
        public int ID {get;set;}
        public string FirstName{get;set;}
        public string LastName {get;set;}
        public string Phone{get;set;}
        public double Salary{get;set;}
        public DateTime HireDate { get; set; }

        public clsEmployee()
        {
            ID = -1;
            FirstName = "";
            LastName = "";
            Phone = "";
            Salary = -1;
            HireDate = DateTime.Now;

            SaveMode = enSaveMode.AddNew;
        }


        private bool _AddNewEmployee()
        {
            ID = clsEmployeesData.AddNewEmployee(this.FirstName,this. LastName,this. Phone,this. Salary,this. HireDate);
            return (ID != -1);
        }
        private bool _UpadateEmployee()
        {
            return clsEmployeesData.UpdateEmployee(this.ID, this.FirstName, this.LastName, this.Phone, this.Salary, this.HireDate);
        }
        public clsEmployee(int id, string  firstName, string lastName, string phone , double salary, DateTime hireDate)
        {
            ID = id;
            FirstName = firstName;
            LastName = lastName;
            Phone = phone;
            Salary = salary;
            HireDate = hireDate;

            SaveMode = enSaveMode.Update;
        }

        public static clsEmployee Find(int ID)
        {
            string FirstName = "";
            string LastName = "";
            string Phone = "";
            double Salary = -1;
            DateTime HireDate = DateTime.Now;
            if (clsEmployeesData.GetEmployeeInfoByID(ID, ref FirstName, ref LastName, ref Phone, ref Salary, ref HireDate))
                return new clsEmployee(ID, FirstName, LastName, Phone, Salary, HireDate);
            else
                return null;
        }
        public static bool Delete(int ID)
        {
            return clsEmployeesData.DeleteEmployeeByID(ID);
        }

        public static DataTable GetAllEmployees()
        {
            return clsEmployeesData.GetAllEmployees();

        }

        

        public static bool IsEmployeeExist(int ID)
        {
            return clsEmployeesData.IsEmployeeExistByID(ID);
        }

        public bool Save()
        {
            switch (SaveMode)
            {
                case enSaveMode.AddNew :
                    if (_AddNewEmployee())
                    {
                        SaveMode = enSaveMode.Update;
                        return true;
                    }
                    else
                     return false;
                case enSaveMode.Update :
                    return _UpadateEmployee();          
            }
            return false;
        }
    }
}
