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
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void btnChoicePhoto_Click(object sender, EventArgs e)
        {
            Form form = new frmChoicePhoto();
            form.ShowDialog();
           
        }

        private void btnMaskedTextBox_Click(object sender, EventArgs e)
        {
            Form form = new frmMaskedTextBox();
            form.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form form = new frmChoicePhoto2();
            form.ShowDialog();
        }
    }
}
