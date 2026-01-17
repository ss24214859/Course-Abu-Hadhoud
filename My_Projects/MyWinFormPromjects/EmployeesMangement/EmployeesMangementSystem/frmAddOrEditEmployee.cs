using EmployeesBusinessLayer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EmployeesMangementSystem
{
    public partial class frmAddOrEditEmployee : System.Windows.Forms.Form
    {
        enum enMode {Add = 0 , Update = 1 }
        enMode _Mode;
        int _ID { get;set;}   

        clsEmployee _Employee = new clsEmployee();
        public frmAddOrEditEmployee(int ID)
        {
            InitializeComponent();
            _ID = ID;
            _Mode = (_ID == -1) ? enMode.Add : enMode.Update;
        }

        private void frmAddOrEditEmployee_Load(object sender, EventArgs e)
        {
            //  if in Add new Mode  Mode
            if(_Mode == enMode.Add)
            {
                this.Text = "Add New Employee";

                lblMode.Text = "Add New Employee";

                lbEmployeeID.Text = "-1";
                
                return;
            }

            // Fill _Employee Object with data from database
            _Employee = clsEmployee.Find(_ID);

            // if ID not found in database
            if(_Employee == null)
            {
                MessageBox.Show("Employee Not Found", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                this.Close();
                return;
            }

            //if in Edit Mode
            // Fill Form Fields with Employee Data
            this.Text = "Edit Employee Data";

            lblMode.Text = "Edit Employee Data";

            lbEmployeeID.Text = _ID.ToString();
            tbFirstName.Text = _Employee.FirstName;
            tbLastName.Text = _Employee.LastName;
            tbPhone.Text = _Employee.Phone;
            nudSalary.Value = (decimal)_Employee.Salary;
            dtpHireDate.Value = _Employee.HireDate;



        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
            
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            // Fill Employee Object with data from Form Fields
            _Employee.FirstName = tbFirstName.Text;
            _Employee.LastName = tbLastName.Text;
            _Employee.Phone = tbPhone.Text;
            _Employee.Salary = (double)nudSalary.Value;
            _Employee.HireDate = dtpHireDate.Value;

            // Save Employee Data
            if (_Employee.Save())
            {
                MessageBox.Show("Data Saved Successfully", "Save", MessageBoxButtons.OK, MessageBoxIcon.Information);

                
                    //Convert to Update Mode 
                    _Mode = enMode.Update;
                    lblMode.Text = "Edit Employee Data";
                    this.Text = "Edit Employee Data";
                    _ID = _Employee.ID;
                    lbEmployeeID.Text = _ID.ToString();

                

            }
            else
            {
                MessageBox.Show("Failed to Save Employee Data", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
