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

        private void btnLinkLable_Click(object sender, EventArgs e)
        {
            Form form = new frmLinkLabel();
            form.ShowDialog();
        }

        private void btnCheckedListBox_Click(object sender, EventArgs e)
        {
            Form form = new frmCheckedListBox();
            form.ShowDialog();
        }

        private void btnMonthCalandar_Click(object sender, EventArgs e)
        {
            Form frm = new frmMonthCalandar();
            frm.ShowDialog();
        }

        private void btnTimer_Click(object sender, EventArgs e)
        {
            Form frm = new frmTreeView();
            frm.ShowDialog();
        }

        private void btnListView_Click(object sender, EventArgs e)
        {
            Form frm = new frmListView();
            frm.ShowDialog();
        }

        private void btnTabControl_Click(object sender, EventArgs e)
        {
            Form frm = new frmTabControl();
            frm.ShowDialog();
        }
    }
}
