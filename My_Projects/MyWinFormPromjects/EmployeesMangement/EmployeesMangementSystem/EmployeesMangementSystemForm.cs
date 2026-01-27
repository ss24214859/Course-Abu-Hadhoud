using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EmployeesBusinessLayer;

namespace EmployeesMangementSystem
{
    public partial class EmployeesMangementSystemForm : System.Windows.Forms.Form
    {
        bool SidebarExpand = true;

        //enum enMenuOptions { Employees = 0, Attendance = 1, Statistics = 2 };
        //enMenuOptions _CurrentMenuOption = enMenuOptions.Employees;

        DataTable dtEmployees = new DataTable(); // All Employees Data
        DataView dvEmployees = new DataView();   // Filtered Employees Data

        DataTable _dtAttendanceStatus  = new DataTable(); // All Attendance Status Data
        DataTable dtMarkAttendance  = new DataTable(); // All Mark Attendance Data

        public EmployeesMangementSystemForm()
        {
            InitializeComponent();
            UIOptimizer.EnableDoubleBuffering(this);
            this.ResizeRedraw = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _dtAttendanceStatus = clsAttendanceStatus.GetAllStatus();
            LoadEmployeesScreen();
            SetEmployeeMenuStayle();
            SetAttendanceMenuStayle();


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

        private void SidebarTimer_Tick(object sender, EventArgs e)
        {


            // SET Minimum or Maximum size Of the Sidebar
            int TargetSidebarWidth = (SidebarExpand) ? /* Collapse */  flpSidebar.MinimumSize.Width : /* Expand */ flpSidebar.MaximumSize.Width;


            //Set Target Size of Sidebar.
            int diff = TargetSidebarWidth - flpSidebar.Width;
            int Sidebardelta = diff / 6;

            if (Sidebardelta == 0)
                Sidebardelta = (diff < 0) ? 1 : -1;

            //Apply width change
            flpSidebar.SuspendLayout();
            flpSidebar.Width += Sidebardelta;  //Ease
            flpSidebar.ResumeLayout(false);

            if ((Sidebardelta < 0 && flpSidebar.Width <= TargetSidebarWidth) ||
                (Sidebardelta > 0 && flpSidebar.Width >= TargetSidebarWidth))
            {
                flpSidebar.Width = TargetSidebarWidth;
                ////pnlEmployeeScreen.Width = TargetEmployeeScreenWidth;

                SidebarExpand = !SidebarExpand;
                SidebarTimer.Stop();

                // Ensure final layout is clean
                this.PerformLayout();
                this.Invalidate();
            }
        }

        private void MenuBoutton_Click(object sender, EventArgs e)
        {
            //set timer interval to lowest to make it smoother.
            if (!SidebarTimer.Enabled)
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
            dtEmployees = clsEmployee.GetAllEmployees();
            dvEmployees = new DataView(dtEmployees);
            dgvEmployeesList.DataSource = dvEmployees;
        }



        void _AddStatusCheckBox()
        {
            if (!dgvMarkAttendance.Columns.Contains("Status"))
            {

                // Create Combo Box Column
                DataGridViewComboBoxColumn combo = new DataGridViewComboBoxColumn();

                combo.HeaderText = "Status";
                combo.Name = "Status";
                //combo.DataPropertyName = "StatusID";

                combo.DataSource = _dtAttendanceStatus;

                combo.DisplayMember = "Name";
                combo.ValueMember = "StatusID";
                combo.ValueType = typeof(int);
                combo.ReadOnly = false;



                // Add Combo Box Column to DataGridView
                dgvMarkAttendance.Columns.Add(combo);
            }

            // Bind Values to Combo Box Column From StatusID Column
            foreach (DataGridViewRow row in dgvMarkAttendance.Rows)
            {

                if (row.Cells["StatusID"].Value != null)
                {
                    row.Cells["status"].Value = row.Cells["StatusID"].Value;
                }
            }

        }
        private void _RefreachMarkAttendance()
        {
            if (dgvMarkAttendance.IsCurrentCellInEditMode)
                return; 
           
            dtMarkAttendance = clsAttendanceReports.GetAttendanceByDateForAttendancList(dtpHireDate.Value);
         

            dgvMarkAttendance.DataSource = dtMarkAttendance;

            //Make all Columns ReadOnly = true
            foreach(DataGridViewColumn col in dgvMarkAttendance.Columns)
            {
                col.ReadOnly = true;
            }

            // Add and Fill Status Combo Box Column
            _AddStatusCheckBox();


            // Handle Data Error Event
            dgvMarkAttendance.DataError += (s, e) =>
            {
                MessageBox.Show(e.Exception.Message);
            };

            //Hide StatusID Column
            if (dgvMarkAttendance.Columns.Contains("StatusID"))
            dgvMarkAttendance.Columns["StatusID"].Visible=false;

        }
        
        private void SetEmployeeMenuStayle()
        {
            DataGridViewModrenStayle(dgvEmployeesList);

            dgvEmployeesList.Columns["Salary"].DefaultCellStyle.Format = "C0";
            dgvEmployeesList.Columns["HireDate"].DefaultCellStyle.Format = "yyyy-MM-dd";
        }

        private void SetAttendanceMenuStayle()
        {
             DataGridViewModrenStayle(dgvMarkAttendance);
            
        }

        private void LoadEmployeesScreen()
        {
            pnlEmployeeScreen.BringToFront();
            _RefreachEmployees();
            SetPlaceholder(tbSearch, "Name or ID...");
            UpdateCountOfEmployees(lbTotalEmployees);
        }


        private void LoadAttendanceScreen()
        {
            pnlAttendanceScreen.BringToFront();
            _RefreachMarkAttendance();
            
        }

        private void LoadStatisticsScreen()
        {


        }

       

        void UpdateCountOfEmployees(Label lbCount)
        {
            if (lbCount == null) return;

            lbCount.Text = dvEmployees.Count.ToString();
        }
        private void btnEmployees_Click(object sender, EventArgs e)
        {
            LoadEmployeesScreen();

        }

        private void btnAttendance_Click(object sender, EventArgs e)
        {
            LoadAttendanceScreen();


        }

        private void btnStatistics_Click(object sender, EventArgs e)
        {
            
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
            string search = tbSearch.Text.Trim().Replace("'", "''");

            if (string.IsNullOrWhiteSpace(search) || search == "Name or ID...")
            {
                dvEmployees.RowFilter = "";
                UpdateCountOfEmployees(lbTotalEmployees);
                return;
            }

            dvEmployees.RowFilter = $"Convert(EmployeeID,'System.String') LIKE '%{search}%' " +
                                    $"OR FirstName LIKE '%{search}%' " +
                                    $"OR LastName LIKE '%{search}%' ";
            UpdateCountOfEmployees(lbTotalEmployees);
        }


        private void deleteEmployeeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int EmployeeID = System.Convert.ToInt32(dgvEmployeesList.CurrentRow.Cells[0].Value);

            if (MessageBox.Show("Are you sure you Want to Delete Employee [ " + EmployeeID + " ]", "Confirm Delete", MessageBoxButtons.OKCancel) == DialogResult.OK)
            {
                if (clsEmployee.Delete(EmployeeID))
                {
                    MessageBox.Show("Employee is Deleted Successfully.");
                    _RefreachEmployees();
                }
                else
                    MessageBox.Show("Cannot delete employee because he has related records.");


            }
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        private void btnAddEmployee_Click(object sender, EventArgs e)
        {
            frmAddOrEditEmployee frmAddOrEditEmployee = new frmAddOrEditEmployee(-1);
            frmAddOrEditEmployee.ShowDialog();

            _RefreachEmployees();

        }

        private void editEmployeeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmAddOrEditEmployee frmAddOrEditEmployee = new frmAddOrEditEmployee((int)dgvEmployeesList.CurrentRow.Cells[0].Value);
            frmAddOrEditEmployee.ShowDialog();

            _RefreachEmployees();
        }

        private void pnlAttendanceScreen_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel6_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel8_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void panel11_Paint(object sender, PaintEventArgs e)
        {

        }

        private void flowLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void dtpHireDate_ValueChanged(object sender, EventArgs e)
        {
            _RefreachMarkAttendance();
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

        private void dgvMarkAttendance_DataBindingComplete(object sender, DataGridViewBindingCompleteEventArgs e)
        {
            /*foreach (DataGridViewRow row in dgvMarkAttendance.Rows)
            {
                // بننقل القيمة من العمود المخفي للكومبو بوكس تاني
                if (row.Cells["StatusID"].Value != null)
                {
                    row.Cells["status"].Value = row.Cells["StatusID"].Value;
                }
            }*/
        }

        private void dgvMarkAttendance_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0 && dgvMarkAttendance.Columns[e.ColumnIndex].Name == "Status")
            {
                dgvMarkAttendance.CurrentCell = dgvMarkAttendance[e.ColumnIndex, e.RowIndex];
                dgvMarkAttendance.BeginEdit(true);

                if (dgvMarkAttendance.EditingControl is ComboBox cb)
                {
                    cb.DroppedDown = true;
                }
            }
        }
    }
}
