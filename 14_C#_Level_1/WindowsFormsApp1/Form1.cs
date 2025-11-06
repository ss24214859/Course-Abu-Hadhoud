using System;
using System.Windows.Forms;
using MyFirstLibraryClass;

namespace WindowsFormsApp1
{
    public class clsperson : clsMyMath
    {
        int i = 0;

    }
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            clsperson MyMath1 = new clsperson();
            MessageBox.Show(MyMath1.Sum(25, 9, 8).ToString());
        }
    }
}
