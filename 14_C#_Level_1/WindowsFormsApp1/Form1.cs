using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private bool IsCopy = false;
        private string temp = "";
        private void button2_Click(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
            IsCopy = true;
        }

        private void button2_MouseEnter(object sender, EventArgs e)
        {
            temp = textBox2.Text;
            textBox2.Text = textBox1.Text;
        }

        private void button2_MouseLeave(object sender, EventArgs e)
        {
            if (!IsCopy)
                textBox2.Text = temp;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            IsCopy = false;
        }
    }
}
