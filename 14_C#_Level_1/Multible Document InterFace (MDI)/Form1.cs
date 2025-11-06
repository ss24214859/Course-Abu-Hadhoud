using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Multible_Document_InterFace__MDI_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        
        private void btnForm2_Click(object sender, EventArgs e)
        {
            Form frm2 = new Form2();
            frm2.MdiParent = this;
            frm2.Show();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripComboBox1_Click(object sender, EventArgs e)
        {

        }

        private void greenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BackColor = Color.Green;
        }

        private void yellowToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BackColor = Color.Yellow;
        }

        private void redToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BackColor = Color.Red;
        }

        private void blueToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BackColor = Color.Blue;
        }

        private void witeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BackColor = Color.White;
        }

        private void blackToolStripMenuItem_Click(object sender, EventArgs e)
        {
            BackColor = Color.Black;
        }

        private void toolStripMenuItem2_Click(object sender, EventArgs e)
        {

        }

        private void changeBackImageToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }
    }
}
