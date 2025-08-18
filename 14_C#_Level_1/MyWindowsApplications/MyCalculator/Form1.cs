using System;
using System.CodeDom;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyCalculator
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Calculator = new ClsCalculator();
        }

        public ClsCalculator Calculator;
        public string ScreenDefulteValue = "0";








        

        private void Result_Click(object sender, EventArgs e)
        { 
            short index =(short) Screen.Text.IndexOf(Calculator.Operator);
            if (index == -1||index==Screen.Text.Length-1) // if Operator is set not found set
                return;

            Calculator.Num2 = Convert.ToSingle(Screen.Text.Substring(index+1));
            Screen.Text = "";
            Screen.Text += Calculator.Result();

        }
        private void Add_Click(object sender, EventArgs e)
        {
            if (Screen.Text != "")
            {
                if (Calculator.Operator == 'n')
                {
                    Calculator.Num1 = Convert.ToSingle(Screen.Text);
                    Calculator.Operator = '+';
                    Screen.Text += Calculator.Operator;
                }
                else if (Calculator.Operator != '+')
                {
                    Screen.Text = Screen.Text.Replace(Calculator.Operator, '+');
                    Calculator.Operator = '+';
                }
            }
        }
        
        private void Sub_Click(object sender, EventArgs e)
        {
            if (Screen.Text != "")
            {
                if (Calculator.Operator == 'n')
                {
                    Calculator.Num1 = Convert.ToSingle(Screen.Text);
                    Calculator.Operator = '-';
                    Screen.Text += Calculator.Operator;
                }
                else if (Calculator.Operator != '-')
                {
                    Screen.Text = Screen.Text.Replace(Calculator.Operator, '-');
                    Calculator.Operator = '-';
                }
            }
        }

        private void Divison_Click(object sender, EventArgs e)
        {
            if(Screen.Text!="")
            {
                if (Calculator.Operator == 'n')
                {
                    Calculator.Num1 = Convert.ToSingle(Screen.Text);
                    Calculator.Operator = '÷';
                    Screen.Text += Calculator.Operator;
                }
                else if (Calculator.Operator != '÷')
                {
                    Screen.Text = Screen.Text.Replace(Calculator.Operator, '÷');
                    Calculator.Operator = '÷';
                }
            }
        }

        private void Multiplication_Click(object sender, EventArgs e)
        {
            if (Screen.Text != "")
            {
                if (Calculator.Operator == 'n')
                {
                    Calculator.Num1 = Convert.ToSingle(Screen.Text);
                    Calculator.Operator = 'x';
                    Screen.Text += Calculator.Operator;
                }
                else if (Calculator.Operator != 'x')
                {
                    Screen.Text = Screen.Text.Replace(Calculator.Operator, 'x');
                    Calculator.Operator = 'x';
                }
            }
        }

        private void Clear_Click(object sender, EventArgs e)
        {
            Calculator.Clear();
            Screen.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Screen.Text += 1;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Screen.Text += 2;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Screen.Text += 3;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Screen.Text += 4;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Screen.Text += 5;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Screen.Text += 6;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Screen.Text += 7;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Screen.Text += 8;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Screen.Text += 9;
        }

        private void zero_Click(object sender, EventArgs e)
        {
            Screen.Text += 0;
        }

        private void Back_Click_1(object sender, EventArgs e)
        {
            int ScreenTextLength = Screen.Text.Length;
            if (ScreenTextLength == 0)
                return;
            else
            {
                switch(Screen.Text[ScreenTextLength-1])
                {
                    case '-':
                    case '+':
                    case 'x':
                    case '÷':
                        Calculator.Operator = 'n';
                        break;
                    default:
                        break;
                }
                Screen.Text = Screen.Text.Remove(ScreenTextLength-1);
            }

        }

        private void Dote_Click(object sender, EventArgs e)
        {
            Screen.Text += '.';
        }

        private void plusOrMinusToggle_Click(object sender, EventArgs e)
        {
            if (Screen.Text == "")
                return;
            if (Screen.Text[0] != '-')
                Screen.Text=Screen.Text.Insert(0, "-");
            else
                Screen.Text =Screen.Text.Substring(1);
        }
    }
    public class ClsCalculator
    {
        float _Num1 = 0;
        float _Num2 = 0;
        char _Operator = 'n';
        
        public ClsCalculator()
        {
            _Num1 = 0;
            _Num2 = 0;
            _Operator = 'n';
        }
        public float Num1
        {
            get { return _Num1; }
            set { _Num1 = value; }
        }
        public float Num2
        {
            get { return _Num2; }
            set { _Num2 = value; }
        }
        public char Operator
        {
            get { return _Operator; }
            set { _Operator = value; }
        }
        public float Result()
        {
            return SempleCalculator(_Num1, _Num2, _Operator);
        }

        public static float SempleCalculator(float num1, float num2, char op)
        {
            switch (op)
            {
                case '+': return num1 + num2;
                case '-': return num1 - num2;
                case '÷': return num1 / num2;
                case 'x': return num1 * num2;
            }
            return 0;
        }

        public void Clear()
        {
            _Num1 = 0;
            _Num2 = 0;
            _Operator = 'n';
        }
    }

}

    