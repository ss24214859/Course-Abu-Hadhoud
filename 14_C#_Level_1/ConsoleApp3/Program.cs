using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyFirstLibraryClass;

namespace ConsoleApp3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //clsMyMath myMath = new clsMyMath();
            //Console.WriteLine(myMath.Sum(3, 3));
            //Console.WriteLine(myMath.Sum(3, 3,7));
            
            for (int i = 0; i < 10; i++)
            {

               Guid guid = Guid.NewGuid();
               Console.WriteLine(guid);
            }
        }
    }
}
