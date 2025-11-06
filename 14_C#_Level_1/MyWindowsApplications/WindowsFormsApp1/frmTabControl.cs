using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace WindowsFormsApp1
{
    public partial class frmTabControl : Form
    {
        public frmTabControl()
        {
            InitializeComponent();
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {
            
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void tabPage1_Click_1(object sender, EventArgs e)
        {

        }

        private void frmTabControl_Load(object sender, EventArgs e)
        {
            openFileDialog1.InitialDirectory = @"C:\Users\ss242\OneDrive\Documents";
            openFileDialog1.Title = "Open Mohamed's Files";
            openFileDialog1.DefaultExt = "txt";
            openFileDialog1.Filter = "Png Files (*.png)|*.png|Text Files (*.txt)|*.text|All Files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void btnChoiceColor_Click(object sender, EventArgs e)
        {
            if(colorDialog1.ShowDialog() == DialogResult.OK)
            {
                this.BackColor = colorDialog1.Color;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                label1.Font = fontDialog1.Font;
            }
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            
        }

        private void Result_Click(object sender, EventArgs e)
        {

        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            if(tabControl1.SelectedIndex < tabControl1.TabPages.Count-1) 
            tabControl1.SelectTab(tabControl1.SelectedIndex+1);
        }

        private void btnBack_Click(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex > 0)
                tabControl1.SelectTab(tabControl1.SelectedIndex - 1);
        }

        void ChackLogIn()
        {
            if (!string.IsNullOrEmpty(textAccount.Text) && !string.IsNullOrEmpty(textPassword.Text))
            {
                
                if (textAccount.Text == "hamo@gmail.com" && textPassword.Text == "1234")
                {
                    
                    tabResult.BackColor = Color.FromArgb(0, 192, 0);
                    label6.Text = "Log In Successfully";
                }
                else
                {
                    tabResult.BackColor = Color.Red;
                    label6.Text = "Log In Failed ";
                }
                

            }
        }
        private void textPassword_TextChanged(object sender, EventArgs e)
        {
            ChackLogIn();
        }

        private void textAccount_TextChanged(object sender, EventArgs e)
        {
            ChackLogIn();
        }

        private void btnSaveFile_Click(object sender, EventArgs e)
        {
            saveFileDialog1.InitialDirectory = @"C:\User\ss242\Downloads\Downloaded";
            saveFileDialog1.Title = "Save Mohamed's Files";
            saveFileDialog1.DefaultExt = "txt";
            saveFileDialog1.Filter = "Text Files (*.txt) | .text |All File (*.*)|*_)";
            saveFileDialog1.FilterIndex = 1;
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
                MessageBox.Show(saveFileDialog1.FileName);

            
        }

        private void btnOpenFile_Click(object sender, EventArgs e)
        {
            openFileDialog1.Multiselect = false;
            


            if(openFileDialog1.ShowDialog() == DialogResult.OK)
                MessageBox.Show(openFileDialog1.FileName); 
        }

        private void btnMultiOpenFile_Click(object sender, EventArgs e)
        {
            openFileDialog1.Multiselect = true;
            if(openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                foreach(var fileName in openFileDialog1.FileNames )
                {
                    MessageBox.Show(fileName);
                }
            }
        }

        private void btnBrowsingFolder_Click(object sender, EventArgs e)
        {
            folderBrowserDialog1.ShowNewFolderButton= false;

            if (folderBrowserDialog1.ShowDialog() == DialogResult.OK)
                MessageBox.Show(folderBrowserDialog1.SelectedPath);
                
            
        }
    }
}
