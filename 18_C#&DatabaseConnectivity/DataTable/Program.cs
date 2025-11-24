using System;
using System.Data;
using System.Linq;
using System.Reflection;

namespace DataTableExample
{
    public class Program
    {

        public static void PrintFilterOfEmployiesData(DataTable Employees , string FilterText)
        {
            Double TotalSalaries = 0;
            Double AverageSalaries = 0;
            Double MinSalaries = 0;
            Double MaxSalaries = 0;


            TotalSalaries = Convert.ToDouble(Employees.Compute("SUM(Salary)", FilterText));
            AverageSalaries = Convert.ToDouble(Employees.Compute("AVG(Salary)", FilterText));
            MinSalaries = Convert.ToDouble(Employees.Compute("Min(Salary)", FilterText));
            MaxSalaries = Convert.ToDouble(Employees.Compute("Max(Salary)", FilterText));

            DataRow[] ResultRows = Employees.Select(FilterText);
            int ResultCount = ResultRows.Count();


            foreach (DataRow row in ResultRows)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", row["ID"].ToString().PadRight(5), row["Name"].ToString().PadRight(10), row["Country"].ToString().PadRight(10), row["Salary"].ToString().PadRight(10), row["DateOfBirth"].ToString().PadRight(15));
            }

            Console.WriteLine("Count Of Result = " + ResultCount);
            Console.WriteLine("Total Employees Salaries = " + TotalSalaries);
            Console.WriteLine("Average Employees Salaries = " + AverageSalaries);
            Console.WriteLine("Min Employees Salaries = " + MinSalaries);
            Console.WriteLine("Max Employees Salaries = " + MaxSalaries);

        }

        public static void PrintEmployeesDataTable(DataTable Employees , string Sort="")
        {
            if(Sort!="")
            {
                Employees.DefaultView.Sort = Sort;
                Employees = Employees.DefaultView.ToTable();
            }

            foreach (DataRow row in Employees.Rows)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", row["ID"].ToString().PadRight(5), row["Name"].ToString().PadRight(10), row["Country"].ToString().PadRight(10), row["Salary"].ToString().PadRight(10), row["DateOfBirth"].ToString().PadRight(15));
            }
        }

        public static void DeleteEmployeesByCondtion(ref DataTable  Employees ,string Condition)
        {
            DataRow[] dataRows = Employees.Select(Condition);

            foreach(DataRow Row in dataRows)
            {
                Row.Delete();
            }
        }
        static void Main(string[] args)
        {
            //-1

            DataTable Employees = new DataTable();
            // Add Columns

            DataColumn dataColumn = new DataColumn();
            dataColumn.ColumnName = "ID";
            dataColumn.DataType = typeof(int);
            dataColumn.AutoIncrement = true;
            dataColumn.AutoIncrementSeed = 1;
            dataColumn.AutoIncrementStep = 1;

            dataColumn.Caption = "Employee ID";
            dataColumn.ReadOnly = true;
            dataColumn.Unique = true;
           
            //Employees.Columns.Add("ID", typeof(int));
            Employees.Columns.Add(dataColumn);
            Employees.Columns.Add("Name", typeof(string));
            Employees.Columns.Add("Country", typeof(string));
            Employees.Columns.Add("Salary", typeof(Double));
            Employees.Columns.Add("DateOfBirth", typeof(DateTime));

            DataColumn[] PrimaryKeyColumns = new DataColumn[1];
            PrimaryKeyColumns[0] = Employees.Columns["ID"];

            Employees.PrimaryKey = PrimaryKeyColumns;

            // Add Rows
            Employees.Rows.Add(null,"Mohamed","Egypt","22000","1092-5-9");
            Employees.Rows.Add(null,"Ahmad","Jordan","12500","2002-5-9");
            Employees.Rows.Add(null, "Hamo", "Egypt", "16600", "2004-9-30");
            Employees.Rows.Add(null, "Nagi", "Jordan", "18600", "2004-9-30");
            Employees.Rows.Add(null, "Ali", "USA", "22000", "2004-9-30");

            /* -2
            int EmployeesCount = 0;
            Double TotalSalaries = 0;
            Double AverageSalaries = 0;
            Double MinSalaries = 0;
            Double MaxSalaries = 0;


            EmployeesCount = Employees.Rows.Count;

            TotalSalaries = Convert.ToDouble(Employees.Compute("SUM(Salary)", string.Empty));
            AverageSalaries = Convert.ToDouble(Employees.Compute("AVG(Salary)",string.Empty));
            MinSalaries = Convert.ToDouble(Employees.Compute("Min(Salary)", string.Empty));
            MaxSalaries = Convert.ToDouble(Employees.Compute("Max(Salary)", string.Empty));

           
            
            Console.WriteLine("Count Of Employees = " + EmployeesCount);
            Console.WriteLine("Total Employees Salaries = " + TotalSalaries);
            Console.WriteLine("Average Employees Salaries = " + AverageSalaries);
            Console.WriteLine("Min Employees Salaries = " + MinSalaries);
            Console.WriteLine("Max Employees Salaries = " + MaxSalaries); 
            */
            
            
            Console.WriteLine("\nEmployees List\n");

            PrintEmployeesDataTable(Employees);





            // -3
            /*Console.WriteLine("\n\n\nFilter \"Jordan\" Employees\n");

            PrintFilterOfEmployiesData(Employees, "Country = 'Jordan'");



            Console.WriteLine("\n\n\nFilter \"Jordan Or Egypt\" Employees\n");

            PrintFilterOfEmployiesData(Employees, "Country in ('Jordan','Egypt') ");



            Console.WriteLine("\n\n\nFilter \"With ID = 1\" \n");

            PrintFilterOfEmployiesData(Employees, " ID=1 ");*/





            /* -4
            Console.WriteLine("\nEmployees List Sorted By ID Desc\n");

            PrintEmployeesDataTable(Employees,"ID Desc");

            Console.WriteLine("\nEmployees List Sorted By Name Asc\n");

            PrintEmployeesDataTable(Employees, "Name Asc");
            */


            // -5
            /*
            DeleteEmployeesByCondtion(ref Employees, "ID = 4");

            Console.WriteLine("\nEmployees List After Delete \n");
            PrintEmployeesDataTable(Employees);
            */

            // -6
            /*
            DataRow[] dataRows = Employees.Select("ID = 4");
            foreach(Var Row in dataRows)
            {
                Row["Name"] = "Am Kash Kash";
                Row["Salary"] = (Double)58500;
            }

            Console.WriteLine("\nEmployees List After Update ID = 4 Record \n");
            PrintEmployeesDataTable(Employees);
            */
            // 7- 

            Employees.Clear();
            Console.WriteLine("\nEmployees List After Clear \n");
            PrintEmployeesDataTable(Employees);
        }
    }
}
