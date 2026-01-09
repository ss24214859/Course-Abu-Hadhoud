using ContactsBusinessLayer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ContactsWinFrm
{
    public partial class frmListContacts : Form
    {
        public frmListContacts()
        {
            InitializeComponent();
        }
        private void _RefreshContactsList()
        {
            dgvAllContacts.DataSource = clsContact.GetAllContacts();
        }
        private void AddEditContact_Click(object sender, EventArgs e)
        {
            frmAddEditContact frmAddEditContact = new frmAddEditContact(-1) ;
           frmAddEditContact.ShowDialog();

            _RefreshContactsList();
        }

        private void frmListContacts_Load(object sender, EventArgs e)
        {
            _RefreshContactsList();
        }
        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmAddEditContact addEditContact = new frmAddEditContact((int) dgvAllContacts.CurrentRow.Cells["ContactID"].Value);
            addEditContact.ShowDialog();

            _RefreshContactsList();
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure you Want to Delete ContactID["+ dgvAllContacts.CurrentRow.Cells[0].Value +"]" , "Confirm Delete" , MessageBoxButtons.OKCancel) == DialogResult.OK)
            {
                if (clsContact.Delete((int)dgvAllContacts.CurrentRow.Cells["ContactID"].Value))
                {
                    MessageBox.Show("Contact Deleted Successfully");
                    _RefreshContactsList();
                }
                else
                    MessageBox.Show("Contact is not Deleted");
            }
            
        }

        private void dgvAllContacts_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dgvAllContacts_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
