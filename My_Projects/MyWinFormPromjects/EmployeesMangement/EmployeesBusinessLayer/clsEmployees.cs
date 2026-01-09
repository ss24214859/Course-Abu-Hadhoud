using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EmployeesDataAccessLayer;

namespace EmployeesBusinessLayer
{
    public class clsEmployees
    {
        public class EmployeesStatistics
        {
            public double MaximumSalary { get; set; }
            public double MinimumSalary { get; set; }
            public double AverageSalary{ get; set; }
            public int TotalEmployees {  get; set; }
            public double TotalPayroll { get; set; }
        }

        enum enSaveMode {AddNew = 0 , Update = 1 };
        enSaveMode SaveMode = enSaveMode.AddNew;
        public int ID {get;set;}
        public string FirstName{get;set;}
        public string LastName {get;set;}
        public string Phone{get;set;}
        public double Salary{get;set;}
        public DateTime HireDate { get; set; }

        public clsEmployees()
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
        public clsEmployees(int id, string  firstName, string lastName, string phone , double salary, DateTime hireDate)
        {
            ID = id;
            FirstName = firstName;
            LastName = lastName;
            Phone = phone;
            Salary = salary;
            HireDate = hireDate;

            SaveMode = enSaveMode.Update;
        }

        public static clsEmployees Find(int ID)
        {
            string FirstName = "";
            string LastName = "";
            string Phone = "";
            double Salary = -1;
            DateTime HireDate = DateTime.Now;
            if (clsEmployeesData.GetEmployeeInfoByID(ID, ref FirstName, ref LastName, ref Phone, ref Salary, ref HireDate))
                return new clsEmployees(ID, FirstName, LastName, Phone, Salary, HireDate);
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

        public static EmployeesStatistics GetEmployeesStatistics()
        {
            EmployeesStatistics employeesStatistics = new EmployeesStatistics();
            double MaximumSalary = -1;
            double MinimumSalary = -1;
            double AverageSalary = -1;
            int TotalEmployees = -1;
            double TotalPayroll = -1;

            
            clsEmployeesData.GetEmployeesStatistics(ref MaximumSalary,ref MinimumSalary,ref AverageSalary,ref TotalEmployees,ref TotalPayroll);
        
            employeesStatistics.MaximumSalary = MaximumSalary;
            employeesStatistics.MinimumSalary = MinimumSalary;
            employeesStatistics.AverageSalary = AverageSalary;
            employeesStatistics.TotalEmployees = TotalEmployees;
            employeesStatistics.TotalPayroll = TotalPayroll;

            var Result = employeesStatistics;

            return Result;
        
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
