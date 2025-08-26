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
    public partial class frmChoicePhoto2 : Form
    {
        public frmChoicePhoto2()
        {
            InitializeComponent();
        }

        private void frmChoicePhoto2_Load(object sender, EventArgs e)
        {
            cboChoicePhoto.SelectedIndex = 0;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //switch(cboChoicePhoto.SelectedIndex)
            //{
            //    case 0:
            //        lbTitle.Text = "Book";
            //        pictureBox1.Image = Resources.Book;
            //        break;
            //    case 1:
            //        lbTitle.Text = "Boy";
            //        pictureBox1.Image = Resources.Boy;
            //        break;
            //    case 2:
            //        lbTitle.Text = "Girl";
            //        pictureBox1.Image = Resources.Girl;
            //        break;
            //    case 3:
            //        lbTitle.Text = "Pen";
            //        pictureBox1.Image = Resources.Pen;
            //        break;
            //}

            //this is the shortcut Slution.
            string ActiveChoice = cboChoicePhoto.Text;
            lbTitle.Text = ActiveChoice;
            pictureBox1.Image =(Image )Resources.ResourceManager.GetObject(ActiveChoice);

        }

        private void btnDone_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
