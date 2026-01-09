using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EmployeesBusinessLayer;

namespace EmployeesMangementSystem
{
    public partial class EmployeesMangementSystemForm : System.Windows.Forms.Form
    {
        bool SidebarExpand = true;

        enum enMenuOptions { Employees=0,Attendance =1, Statistics  =2};
        enMenuOptions CurrentMenuOption = enMenuOptions.Employees;
        DataTable dtEmployees = new DataTable();
        DataView dvEmployees = new DataView();
        public EmployeesMangementSystemForm()
        {
            InitializeComponent();
            this.DoubleBuffered = true;
            this.ResizeRedraw = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
            LoadEmployeesScreen();
            SetEmployeeMenuStayle();

            
        }

        
        private void SetPlaceholder(TextBox txt, string placeholder)
        {
            txt.Text = placeholder;
            txt.ForeColor = Color.Gray;

            txt.GotFocus += (sender, e) =>
            {
                if (txt.Text == placeholder)
                {
                    txt.Text = "";
                    txt.ForeColor = Color.Black;
                }
            };

            txt.LostFocus += (s, e) =>
            {
                if (string.IsNullOrWhiteSpace(txt.Text))
                {
                    txt.Text = placeholder;
                    txt.ForeColor = Color.Gray;
                }
            };
        }

        private void ExpandOrReduceEmployeeScreenToTarget(int TargetWidth)
        {
            int CurrentWidth = pnlEmployeeScreen.Width;
            int delta = (TargetWidth - CurrentWidth)/6;

            if (delta == 0)
                delta = (TargetWidth > CurrentWidth) ? 1 : -1;

            pnlEmployeeScreen.SuspendLayout();
            pnldvgEmployeesContainer.SuspendLayout();

            pnlEmployeeScreen.Width += delta; //Update Size.
            pictureBox1.Width += delta; //Update Line Of Panal.
            pnldvgEmployeesContainer.Width += delta; //  Upadate Data Graid View.
            pnlEmployeeScreen.Location = new Point(pnlEmployeeScreen.Location.X - delta, pnlEmployeeScreen.Location.Y); //Update location in the end to Ignore nose in Animation.
            pnldvgEmployeesContainer.ResumeLayout();
            pnlEmployeeScreen.ResumeLayout();

        }
        private void SidebarTimer_Tick(object sender, EventArgs e)
        {
            int TargetSidebarWidth = 0;
            int TargetEmployeeScreenWidth = 0;

            // SET Minimum or Maximum size Of the Sidebar
            if (SidebarExpand)
            {
                // Collapse
                TargetSidebarWidth = flpSidebar.MinimumSize.Width;
                TargetEmployeeScreenWidth = pnlEmployeeScreen.MaximumSize.Width;
            }
            else
            {
                //Expand
                TargetSidebarWidth = flpSidebar.MaximumSize.Width;
                TargetEmployeeScreenWidth = pnlEmployeeScreen.MinimumSize.Width;
            }
            //Set Target Size of Sidebar.
            int Sidebardelta = (TargetSidebarWidth - flpSidebar.Width) / 6;

            if (Sidebardelta == 0)
                Sidebardelta = (TargetSidebarWidth < flpSidebar.Width) ? 1 : -1;

            flpSidebar.Width += Sidebardelta;  //Ease

            //Set Target Size of Employees Screen.
            ExpandOrReduceEmployeeScreenToTarget(TargetEmployeeScreenWidth);

            if ((Sidebardelta < 0 && flpSidebar.Width <= TargetSidebarWidth) || (Sidebardelta > 0 && flpSidebar.Width >= TargetSidebarWidth))
            {
                flpSidebar.Width = TargetSidebarWidth;
                pnlEmployeeScreen.Width = TargetEmployeeScreenWidth;

                SidebarExpand = !SidebarExpand;
                SidebarTimer.Stop();
            }
        }

        private void MenuBoutton_Click(object sender, EventArgs e)
        {
            //set timer interval to lowest to make it smoother.
            if(!SidebarTimer.Enabled)
            SidebarTimer.Start();
        }
        private void DataGridViewModrenStayle(DataGridView dgvModrenStayle)
        {
            // عام
            dgvModrenStayle.Dock = DockStyle.Fill;
            dgvModrenStayle.BackgroundColor = Color.White;
            dgvModrenStayle.BorderStyle = BorderStyle.FixedSingle;

            // الأعمدة
            dgvModrenStayle.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvModrenStayle.ColumnHeadersHeight = 60;
            dgvModrenStayle.ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle.Single;

            // هيدر الأعمدة
            dgvModrenStayle.EnableHeadersVisualStyles = false;
            dgvModrenStayle.ColumnHeadersDefaultCellStyle.BackColor = Color.FromArgb(245, 245, 245);
            dgvModrenStayle.ColumnHeadersDefaultCellStyle.ForeColor = Color.Black;
            dgvModrenStayle.ColumnHeadersDefaultCellStyle.Font =
                new Font("Segoe UI", 12, FontStyle.Bold);

            // الصفوفdgvModrenStayle
            dgvModrenStayle.DefaultCellStyle.Font =
                new Font("Segoe UI", 10, FontStyle.Regular);
            dgvModrenStayle.DefaultCellStyle.ForeColor = Color.Black;
            dgvModrenStayle.DefaultCellStyle.BackColor = Color.White;
            dgvModrenStayle.DefaultCellStyle.SelectionBackColor = Color.FromArgb(224, 240, 255);
            dgvModrenStayle.DefaultCellStyle.SelectionForeColor = Color.Black;

            // صفوف متبادلة
            dgvModrenStayle.AlternatingRowsDefaultCellStyle.BackColor =
                Color.FromArgb(250, 250, 250);

            // الشبكة
            dgvModrenStayle.GridColor = Color.FromArgb(220, 220, 220);
        }
        private void _RefreachEmployees()
        {
            dtEmployees = clsEmployees.GetAllEmployees();
            dvEmployees = new DataView(dtEmployees);
            dgvEmployeesList.DataSource = dvEmployees;
        }

        private void SetEmployeeMenuStayle()
        {
            DataGridViewModrenStayle(dgvEmployeesList);

            dgvEmployeesList.Columns["Salary"].DefaultCellStyle.Format = "C0";
            dgvEmployeesList.Columns["HireDate"].DefaultCellStyle.Format = "yyyy-MM-dd";

        }

        private void LoadEmployeesScreen()
        {
            _RefreachEmployees();
            

            SetPlaceholder(tbSearch, "Name or ID...");
            pnlEmployeeScreen.Visible = true;
            pnlEmployeeScreen.Enabled = true;

            UpdateCountOfEmployees(lbTotalEmployees);
        }

        private void CloseCurrentMenuOptionScreen(enMenuOptions SelectedMenuOption)
        {
            if(SelectedMenuOption == CurrentMenuOption)
                return;

            switch (CurrentMenuOption)
            {
                case enMenuOptions.Employees :
                    pnlEmployeeScreen.Visible = false;
                    pnlEmployeeScreen.Enabled = false;
                    break;
            }
            
            CurrentMenuOption = SelectedMenuOption;

        }

        void UpdateCountOfEmployees(Label lbCount)
        {
            if (lbCount == null) return;

            lbCount.Text = dvEmployees.Count.ToString();
        }
        private void btnEmployees_Click(object sender, EventArgs e)
        {
            CloseCurrentMenuOptionScreen(enMenuOptions.Employees);
            LoadEmployeesScreen();
            
        }

        private void btnAttendance_Click(object sender, EventArgs e)
        {
            CloseCurrentMenuOptionScreen(enMenuOptions.Attendance);
        }

        private void btnStatistics_Click(object sender, EventArgs e)
        {
            CloseCurrentMenuOptionScreen(enMenuOptions.Statistics);
        }
        
        private void pnlEmployeeScreen_Paint(object sender, PaintEventArgs e)
        {

        }

        private void dgvEmployeesList_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dgvEmployeesList_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }
        
        private void tbSearch_TextChanged(object sender, EventArgs e)
        {
            string search = tbSearch.Text.Trim().Replace("'","''");

            if (string.IsNullOrWhiteSpace(search)|| search == "Name or ID...")
            {
                dvEmployees.RowFilter = "";
                UpdateCountOfEmployees(lbTotalEmployees);

                return;
            }
            
                dvEmployees.RowFilter = $"Convert(EmployeeID,'System.String') LIKE '%{search}%' "+
                                        $"OR FirstName LIKE '%{search}%' " +
                                        $"OR LastName LIKE '%{search}%' " ;
            UpdateCountOfEmployees(lbTotalEmployees);
        }


        private void deleteEmployeeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int EmployeeID = System.Convert.ToInt32(dgvEmployeesList.CurrentRow.Cells[0].Value);

            if (MessageBox.Show("Are you sure you Want to Delete Employee [ " + EmployeeID + " ]", "Confirm Delete", MessageBoxButtons.OKCancel) == DialogResult.OK)
            {
                if (clsEmployees.Delete(EmployeeID))
                {
                    MessageBox.Show("Employee is Deleted Successfully.");
                    _RefreachEmployees();
                }
                else
                    MessageBox.Show("Cannot delete employee because he has related records.");


            }
        }
    }
}
