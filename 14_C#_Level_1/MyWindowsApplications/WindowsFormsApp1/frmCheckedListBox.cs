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
    public partial class frmCheckedListBox : Form
    {
        public frmCheckedListBox()
        {
            InitializeComponent();
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btnAddItem_Click(object sender, EventArgs e)
        {
            for(int i = 0; i<5;i++)
            {
                checkedListBox1.Items.Add("Item" + (i+1));
            }
            
        }

        private void btnShowSlectedItems_Click(object sender, EventArgs e)
        {
            for(int i=0; i<checkedListBox1.CheckedItems.Count;i++)
            {
                MessageBox.Show(checkedListBox1.CheckedItems[i].ToString());
            }
        }

        private void btnCheckAllItems_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBox1.Items.Count; i++)
            {
                checkedListBox1.SetItemChecked(i,true);
            }
        }

        private void btnUnCheckAllItems_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBox1.Items.Count;i++)
            {
                checkedListBox1.SetItemChecked(i, false);
            }
        }

        private void btnRemoveItem_Click(object sender, EventArgs e)
        {

            int ItemsCount = checkedListBox1.Items.Count;
            if(ItemsCount > 0)
            {
                checkedListBox1.Items.RemoveAt(ItemsCount-1);
            }
        }

        private void btnRemoveAllItems_Click(object sender, EventArgs e)
        {
            checkedListBox1.Items.Clear();
        }
    }
}
