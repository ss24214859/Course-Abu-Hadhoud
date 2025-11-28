using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace dataView
{
    internal class Program
    {
        static void Main(string[] args)
        {

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
            Employees.Rows.Add(null, "Mohamed", "Egypt", "22000", "1092-5-9");
            Employees.Rows.Add(null, "Ahmad", "Jordan", "12500", "2002-5-9");
            Employees.Rows.Add(null, "Hamo", "Egypt", "16600", "2004-9-30");
            Employees.Rows.Add(null, "Nagi", "Jordan", "18600", "2004-9-30");
            Employees.Rows.Add(null, "Ali", "USA", "22000", "2004-9-30");

            Console.WriteLine("Employees List : ");
            foreach (DataRow row in Employees.Rows)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", row["ID"].ToString().PadRight(5), row["Name"].ToString().PadRight(10), row["Country"].ToString().PadRight(10), row["Salary"].ToString().PadRight(10), row["DateOfBirth"].ToString().PadRight(15));
            }

            DataView dvEmployess = Employees.DefaultView;

            Console.WriteLine("Employees List From DataView: ");
            for(int i=0; i<dvEmployess.Count; i++)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", dvEmployess[i][0].ToString().PadRight(5), dvEmployess[i][1].ToString().PadRight(10), dvEmployess[i][2].ToString().PadRight(10), dvEmployess[i][3].ToString().PadRight(10), dvEmployess[i][4].ToString().PadRight(15));
            }

            // -2
            // Now Filter
            //


            /*dvEmployess.RowFilter = "Country in ('Egypt','Jordan')";

            Console.WriteLine("Employees List From DataView after Filtering \" Jordan Or Egypt \": ");
            for (int i = 0; i < dvEmployess.Count; i++)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", dvEmployess[i][0].ToString().PadRight(5), dvEmployess[i][1].ToString().PadRight(10), dvEmployess[i][2].ToString().PadRight(10), dvEmployess[i][3].ToString().PadRight(10), dvEmployess[i][4].ToString().PadRight(15));
            }*/


            //-3
            //Now Sort By Name Asc
            //

            dvEmployess.Sort = "Name Asc";

            Console.WriteLine("Employees List From DataView after Sorting By \" Name Asc \": ");
            for (int i = 0; i < dvEmployess.Count; i++)
            {
                Console.WriteLine("ID : {0} , Name: {1} , Country: {2} , Salary: {3} ,  Date Of Birth: {4} ", dvEmployess[i][0].ToString().PadRight(5), dvEmployess[i][1].ToString().PadRight(10), dvEmployess[i][2].ToString().PadRight(10), dvEmployess[i][3].ToString().PadRight(10), dvEmployess[i][4].ToString().PadRight(15));
            }

        }
    }
}
