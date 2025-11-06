using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestPrametraizedQuery
{ 
    internal class Program
    {
        static string ConnectionString = "Server=.;Database=DB2;User ID=sa;Password=123456;";

        static public void PrintAllStudentwithName(string Name)
        {
            SqlConnection Connection = new SqlConnection(ConnectionString);
            string Query = $"SELECT * FROM Students WHERE Name = @Name";
            SqlCommand Commend = new SqlCommand(Query,Connection) ;
            Commend.Parameters.AddWithValue("@Name", Name);

            try
            {
                Connection.Open();
                SqlDataReader Reader = Commend.ExecuteReader();

                while (Reader.Read())
                {
                    int id = (int)Reader["ID"];
                    string name = (string)Reader["Name"];
                    string phone = (string)Reader["Phone"];
                    DateTime date = (DateTime)Reader["BirthDate"];

                    Console.WriteLine("ID        : "+id);
                    Console.WriteLine("Name      : "+name);
                    Console.WriteLine("Phone     : "+phone);
                    Console.WriteLine("BirthDate : " + date);
                    Console.WriteLine();

                    
                }

                Connection.Close(); 
                Reader.Close();

            }
            catch (Exception Ex)
            {
                Console.WriteLine(Ex.ToString());
            }

        }
        static void Main(string[] args)
        {
            //'; UPDATE Students SET Phone = '6666666656' WHERE Name = 'Ahmed
            PrintAllStudentwithName("Ahmed");
        }
    }
}
