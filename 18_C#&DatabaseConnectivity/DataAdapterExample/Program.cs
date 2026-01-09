using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAdapterExample
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string ConnectionStirng = "Server =.; Database = HR_Database;User Id=sa;Password=123456;";

            //Create a new DataSet
            DataSet dataSet = new DataSet();

            //Create a new DataAdapter
            string Query = "SELECT * FROM Employees";
            SqlDataAdapter DataAdapter = new SqlDataAdapter(Query,ConnectionStirng);

            // Open the Connection 
            SqlConnection connection = new SqlConnection(ConnectionStirng);

            connection.Open();
                //Set the SelectedCommand of the DataAdapter to the Connection.
            DataAdapter.SelectCommand.Connection= connection;

                //Fill the DataSet With data From the data source
            DataAdapter.Fill(dataSet, "Employees");

            connection.Close();

            DataTable dtEmployees = dataSet.Tables["Employees"];

            foreach (DataRow row in dtEmployees.Rows)
            {
                    //Print Data with All Columns
                /* for (int i = 0;i<dtEmployees.Columns.Count;i++)
                  {
                      Console.Write(row[i].ToString()+"  ");
                  }
                  Console.WriteLine();
                */

                Console.WriteLine("Customer ID : {0} , Name : {1} , LastName : {2} ", row["ID"], row["FirstName"], row["LastName"]);
            }
            // Make Changes To The DataSet (Add, Modify, Or Delete Rows)
            //
            //
            //
            //

            //Update the Data Source with the Changes Made to the DataSet

            connection.Open();
            //Set the UpdateCommand of the DataAdapter to the Connection 
            DataAdapter.UpdateCommand.Connection= connection;

            //Update the Data Source with the Changes
            DataAdapter.Update(dataSet, "Employees");

            connection.Close();

        }
    }
}
