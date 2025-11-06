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
    public partial class frmListView : Form
    {
        public frmListView()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        bool AddNewItemInListView(string ID, string Name)
        {
            if (string.IsNullOrEmpty(ID) || string.IsNullOrEmpty(Name))
                return false;

            ListViewItem Item = new ListViewItem(ID);

            if (rbMale.Checked)
                Item.ImageIndex = 0;
            else
                Item.ImageIndex = 1;

            Item.SubItems.Add(Name);
            listView1.Items.Add(Item);
            textID.Focus();

            return true;
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            AddNewItemInListView(textID.Text, textName.Text);
            textID.Text="";
            textName.Text="";
        }

        private void btnFillRandom_Click(object sender, EventArgs e)
        {
            int ItemsCount = listView1.Items.Count;
            for (int i = ItemsCount; i<10+ItemsCount; i++)
            {
                if(i%2 ==0)
                    rbMale.Checked= true;
                else
                    rbFemale.Checked= true;

                    AddNewItemInListView("" + (i + 1), "Person" + (i + 1));
            }
            rbMale.Checked = true;
                
        }

        private void btnRemove_Click(object sender, EventArgs e)
        {
            if (listView1.Items.Count > 0 && listView1.SelectedItems.Count > 0)
            {
                foreach(ListViewItem item in listView1.SelectedItems)
                {
                    item.Remove();
                }
            }
               
        }

        private void rbDetails_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.Details;
        }

        private void listView1_DoubleClick(object sender, EventArgs e)
        {
            MessageBox.Show(listView1.SelectedItems[0].Text);
        }

        private void rbSmallIcon_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.SmallIcon ;
        }

        private void rbLargeIcon_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.LargeIcon ;
        }

        private void rbList_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View= View.List ;
        }

        private void rbTile_CheckedChanged(object sender, EventArgs e)
        {
            listView1.View = View.Tile;
        }

        void ErrorProviderIsNullOrEmpty(TextBox textBox,CancelEventArgs e,string ErrorMessage)
        {
            
            if (string.IsNullOrEmpty(textBox.Text ))
            {
                e.Cancel = true;
                textBox.Focus();
                errorProvider1.SetError(textBox, ErrorMessage);
            }
            else
            {
                e.Cancel = false;
                errorProvider1.SetError(textBox, "");
            }
        }
        private void textID_Validating(object sender, CancelEventArgs e)
        {
            ErrorProviderIsNullOrEmpty((TextBox)sender, e, "ID Should Have a Value");
        }

        private void textName_Validating(object sender, CancelEventArgs e)
        {
            ErrorProviderIsNullOrEmpty((TextBox)sender, e, "Name Should Have a Value");
        }
    }
}
