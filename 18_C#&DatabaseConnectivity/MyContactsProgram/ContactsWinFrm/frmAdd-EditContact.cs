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
using System.IO;
using ContactsWinFrm.Properties;

namespace ContactsWinFrm
{
    public partial class frmAddEditContact : Form
    {
        public enum enMode { AddNew = 0, Update = 1 };
        private enMode _Mode;
        int _ID { get; set; }
        clsContact _Contact = new clsContact();
        public frmAddEditContact(int id)
        {
            
            InitializeComponent();
            _ID = id;
            _Mode = (_ID != -1) ? enMode.Update : enMode.AddNew;

        }

         void _FillCountriesCheckBox()
        {
                DataTable dtCountries = clsCountry.GetAllCountries();
                foreach(DataRow Row in dtCountries.Rows)
                {
                    cbCountry.Items.Add(Row["CountryName"]);
                }
        }

        private void frmAddEditContact_Load(object sender, EventArgs e)
        {
            _FillCountriesCheckBox();
            cbCountry.SelectedIndex = 0;

            if(_Mode == enMode.AddNew)
            {
                lblMode.Text = "Add New Contact";
                pictureBox1.Image = Resources.no_image_icon_23479;
                return;
            }
            _Contact = clsContact.Find(_ID);

            if(_Contact == null)
            {
                MessageBox.Show($"This Form will be closed Beccause no Contact with ID = {_ID}");
                this.Close();
                return ;

            }

            lblMode.Text = $"Edit Contact ID = {_ID}";
            lbContactID.Text =$"{_ID}";

            tbFirstName.Text = _Contact.FirstName;
            tbLastName.Text = _Contact.LastName;
            tbEmail.Text = _Contact.Email;
            tbPhone.Text = _Contact.Phone;
            tbAddress.Text = _Contact.Address;
            dtpDateOfBirth.Value = _Contact.DateOfBirth;

            cbCountry.SelectedIndex = cbCountry.FindString(clsCountry.Find(_Contact.CountryID).Name);

            
            bool IsPhotoexist = File.Exists(_Contact.ImagePath); //to Check if Path is right

            if (!IsPhotoexist && _Contact.ImagePath != "") // if  Image Path not Found
            {
                pictureBox1.Image = Resources.Image_Not_Found;
            }
            else if (_Contact.ImagePath == null || _Contact.ImagePath == "") //if Contact not Have Image path
            {
                pictureBox1.Image = Resources.no_image_icon_23479;
            }
            else  // Contact Have right Image Path
            {
                pictureBox1.Load(_Contact.ImagePath);
            }

            lblRemove.Visible = (_Contact.ImagePath != "" || _Contact.ImagePath == null);
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void clsCountryBindingSource_CurrentChanged(object sender, EventArgs e)
        {

        }

        private void lblRemove_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            pictureBox1.ImageLocation = null;
            pictureBox1.Image = Resources.no_image_icon_23479;
            lblRemove.Visible = false;
        }

        private void lblSetImage_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            openFileDialog1.Filter = "Image Files|*.png; *.jpg;*.jpeg;*.gif; *.bmp";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.RestoreDirectory = true;
            if(openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string SelectedFilePath = openFileDialog1.FileName;
                pictureBox1.Load(SelectedFilePath);
                lblRemove.Visible= true;

            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            _Contact.FirstName= tbFirstName.Text;
            _Contact.LastName= tbLastName.Text;
            _Contact.Email= tbEmail.Text;
            _Contact.Phone= tbPhone.Text;
            _Contact.DateOfBirth = dtpDateOfBirth.Value;
            _Contact.CountryID = clsCountry.Find(cbCountry.Text).ID;
            _Contact.Address = tbAddress.Text;
            _Contact.ImagePath = (pictureBox1.ImageLocation != null) ? pictureBox1.ImageLocation : "";

            if(_Contact.Save())
            {
                MessageBox.Show("Data Saved Successfully");
                _Mode = enMode.Update;
                _ID = _Contact.ID;
                lblMode.Text = $"Edit Contact ID = {_ID}";
                lbContactID.Text = _ID.ToString();
            }
            else
            {
                MessageBox.Show("Faild to Save Data");
            }
            return;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
