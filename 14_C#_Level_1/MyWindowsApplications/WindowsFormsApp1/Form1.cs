using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApp1.Properties;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        void UpadateRbOption(object sender)
        {
            RadioButton rbSelected = (RadioButton)sender;
            if(rbSelected.Checked)
            {
                switch (rbSelected.Name)
                {
                    case  "rbBoy":
                        pictureBox1.Image = Resources.Boy;
                        break;
                    case "rbGirl":
                        pictureBox1.Image = Resources.Girl;
                        break;
                    case "rbPen":
                        pictureBox1.Image = Resources.Pen;
                        break;
                    case "rbBook":
                        pictureBox1.Image = Resources.Book;
                        break;
                }
                lbTitle.Text = rbSelected.Tag.ToString();
            }
           
        }
        private void rbBoy_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Boy;
            

            lbTitle.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void rbGirl_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Girl;
            lbTitle.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void rbPen_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Pen;
            lbTitle.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void rbBook_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Book;
            lbTitle.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            rbBoy.Checked = true;
        }
    }
}
