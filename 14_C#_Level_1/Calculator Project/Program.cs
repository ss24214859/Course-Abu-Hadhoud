using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator_Project
{
    class clsCalculator
    {
        private string _OPName="";
        private double _tempNumber=0;  // To Print it in Final Result such as ( (Add , subtract , etc..) num(tempNum) to num(Result) )
        private double _Result=0;

        public void Add(double Value)
        {
            _tempNumber = Value;
            _OPName = "Adding";
            _Result += Value;
        }

        public void Subtract(double Value)
        {
            _tempNumber = Value;
            _OPName = "Subtracting";
            _Result -= Value;
        }

        public void Divide(double Value)
        {
            if (Value == 0)
                Value = 1;

            _tempNumber = Value;
            _OPName = "Dividing";
            _Result /= Value;
        }

        public void Multiply(double Value)
        {
            _tempNumber = Value;
            _OPName = "Multiplying";
            _Result *= Value;
        }
        public void Clear()
        {
            _tempNumber = 0;
            _OPName = "Clear";
            _Result = 0;
        }

        public void PrintResult()
        {
            Console.WriteLine("Result After {0} {1} is : {2}", _OPName, _tempNumber, _Result);
        }

        public clsCalculator(double DefaultNumber )
        {
            _Result = DefaultNumber;
        }

    }
    internal class Program
    {
        static void Main(string[] args)
        {
            clsCalculator Calculator = new clsCalculator(Convert.ToDouble( Console.ReadLine()));
            //Calculator.Clear();
            Calculator.PrintResult();

            Calculator.Add(10);
            Calculator.PrintResult();

            Calculator.Add(100);
            Calculator.PrintResult();

            Calculator.Subtract(20);
            Calculator.PrintResult();

            Calculator.Divide(0);
            Calculator.PrintResult();

            Calculator.Divide(2);
            Calculator.PrintResult();

            Calculator.Multiply(3);
            Calculator.PrintResult();

            Calculator.Clear();
            Calculator.PrintResult();

        }
    }
}
