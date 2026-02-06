using EmployeesDataAccessLayer;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeesBusinessLayer
{
    public class clsEmployeesStatistics
    {
        public double MaximumSalary { get; set; }
        public double MinimumSalary { get; set; }
        public double AverageSalary { get; set; }
        public double TotalEmployees { get; set; }
        public double TotalPayroll { get; set; }

        //public int HiredEmplooyeeCount { get; set; }


        public static clsEmployeesStatistics GetEmployeesStatistics()
        {
            clsEmployeesStatistics employeesStatistics = new clsEmployeesStatistics();
            double maximumSalary = -1;
            double minimumSalary = -1;
            double averageSalary = -1;
            double totalEmployees = -1;
            double totalPayroll = -1;



            if(!clsEmployeesStatisticsData.GetEmployeesSalaryStatistics(ref maximumSalary, ref minimumSalary, ref averageSalary, ref totalEmployees, ref totalPayroll))
                return null;

            employeesStatistics.MaximumSalary = maximumSalary;
            employeesStatistics.MinimumSalary = minimumSalary;
            employeesStatistics.AverageSalary = averageSalary;
            employeesStatistics.TotalEmployees = totalEmployees;
            employeesStatistics.TotalPayroll = totalPayroll;

            var Result = employeesStatistics;

            return employeesStatistics;

        }

        public static int GetEmployeesCountByYear(int Year)
        {
            return clsEmployeesStatisticsData.GetEmployeesCountByYear(Year);
        }

        public static DataTable GetRecentHiresLast3Employees()
        {
            return clsEmployeesStatisticsData.GetRecentHiresLast3Employees();
        }


    }
}
