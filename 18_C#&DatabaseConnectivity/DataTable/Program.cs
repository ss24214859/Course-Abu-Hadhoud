using System;
using System.Data;
using System.Linq;
using System.Reflection;

namespace DataTableExample
{
    public class Program
    {
        static void Main(string[] args)
        {
            DataTable Employees = new DataTable();
            // Add Columns
            Employees.Columns.Add("ID", typeof(int));
            Employees.Columns.Add("Name", typeof(string));
            Employees.Columns.Add("Country", typeof(string));
            Employees.Columns.Add("Salary", typeof(string));
            Employees.Columns.Add("DateOfBirth", typeof(DateTime));

            // Add Rows
            Employees.Rows.Add(1,"Mohamed","Egypt","22000","1092-5-9");
            Employees.Rows.Add(2,"Ahmad","Egypt","12500","2002-5-9");
            Employees.Rows.Add(3, "Hamo", "Egypt", "16600", "2004-9-30");


            Console.WriteLine("\nEmployees List\n");

            foreach (DataRow row in Employees.Rows)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", row["ID"].ToString().PadRight(5), row["Name"].ToString().PadRight(10), row["Country"].ToString().PadRight(10), row["Salary"].ToString().PadRight(10), row["DateOfBirth"].ToString().PadRight(15));
            }

        }
    }
}
