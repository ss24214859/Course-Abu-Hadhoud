using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dataset
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DataTable Employees = new DataTable();
            // Add Columns
            Employees.TableName = "Employees";

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
            Employees.Rows.Add(null, "Mohamed", "Egypt", "22000", "1092-5-9");
            Employees.Rows.Add(null, "Ahmad", "Jordan", "12500", "2002-5-9");
            Employees.Rows.Add(null, "Hamo", "Egypt", "16600", "2004-9-30");
            Employees.Rows.Add(null, "Nagi", "Jordan", "18600", "2004-9-30");
            Employees.Rows.Add(null, "Ali", "USA", "22000", "2004-9-30");

            Console.WriteLine("Employees List : \n");
            foreach (DataRow row in Employees.Rows)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", row["ID"].ToString().PadRight(5), row["Name"].ToString().PadRight(10), row["Country"].ToString().PadRight(10), row["Salary"].ToString().PadRight(10), row["DateOfBirth"].ToString().PadRight(15));
            } 

            DataTable Department = new DataTable("Department");

            DataColumn ColmID =  new DataColumn();

            ColmID.ColumnName = "ID";
            ColmID.DataType = typeof(int);
            ColmID.AutoIncrement = true;
            ColmID.AutoIncrementSeed = 1;
            ColmID.AutoIncrementStep = 1;
            
            ColmID.Caption = "Department ID";
            ColmID.ReadOnly = true;
            ColmID.Unique = true;

            Department.Columns.Add(ColmID);
            Department.Columns.Add("Name",typeof(string));

            Department.Rows.Add(null,"IT");
            Department.Rows.Add(null,"Markting");
            Department.Rows.Add(null,"HR");
                                
            Console.WriteLine("\n\n\nDepartment List: \n");
            foreach(DataRow row in Department.Rows)
            {
                Console.WriteLine("ID: {0} |  Name: {1}", row["ID"], row["Name"]);
            }


            DataSet dataSet = new DataSet();
            dataSet.Tables.Add(Employees);
            dataSet.Tables.Add(Department);


            Console.WriteLine("\n\n\nEmployees List From DataSet: \n");
            foreach (DataRow row in dataSet.Tables["Employees"].Rows)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", row["ID"].ToString().PadRight(5), row["Name"].ToString().PadRight(10), row["Country"].ToString().PadRight(10), row["Salary"].ToString().PadRight(10), row["DateOfBirth"].ToString().PadRight(15));
            }
            Console.WriteLine("\n\n\nDepartment List From DataSet: \n");
            foreach (DataRow row in dataSet.Tables["Department"].Rows)
            {
                Console.WriteLine("ID: {0} |  Name: {1}", row["ID"], row["Name"]);
            }

        }
    }
}
