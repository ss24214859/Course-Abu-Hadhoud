using System.Windows.Forms;

namespace EmployeesMangementSystem
{
    partial class EmployeesMangementSystemForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.Panel panel15;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(EmployeesMangementSystemForm));
            this.panel16 = new System.Windows.Forms.Panel();
            this.label14 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.flpSidebar = new System.Windows.Forms.FlowLayoutPanel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.MenuBoutton = new System.Windows.Forms.PictureBox();
            this.panel3 = new System.Windows.Forms.Panel();
            this.btnEmployees = new System.Windows.Forms.Button();
            this.btnAttendance = new System.Windows.Forms.Button();
            this.btnStatistics = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel4 = new System.Windows.Forms.Panel();
            this.tbSearch = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SidebarTimer = new System.Windows.Forms.Timer(this.components);
            this.pnlEmployeeScreen = new System.Windows.Forms.Panel();
            this.panel5 = new System.Windows.Forms.Panel();
            this.label3 = new System.Windows.Forms.Label();
            this.pnldvgEmployeesContainer = new System.Windows.Forms.Panel();
            this.dgvEmployeesList = new System.Windows.Forms.DataGridView();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.editEmployeeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteEmployeeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label5 = new System.Windows.Forms.Label();
            this.lbTotalEmployees = new System.Windows.Forms.Label();
            this.btnAddEmployee = new System.Windows.Forms.Button();
            this.pnlAttendanceScreen = new System.Windows.Forms.Panel();
            this.panel9 = new System.Windows.Forms.Panel();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.panel17 = new System.Windows.Forms.Panel();
            this.panel18 = new System.Windows.Forms.Panel();
            this.label16 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.panel12 = new System.Windows.Forms.Panel();
            this.panel11 = new System.Windows.Forms.Panel();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.panel13 = new System.Windows.Forms.Panel();
            this.panel14 = new System.Windows.Forms.Panel();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.dtpHireDate = new System.Windows.Forms.DateTimePicker();
            this.label9 = new System.Windows.Forms.Label();
            this.btnSaveAttendance = new System.Windows.Forms.Button();
            this.panel10 = new System.Windows.Forms.Panel();
            this.label8 = new System.Windows.Forms.Label();
            this.btnLoadAttendance = new System.Windows.Forms.Button();
            this.panel6 = new System.Windows.Forms.Panel();
            this.label7 = new System.Windows.Forms.Label();
            this.panel8 = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.panel7 = new System.Windows.Forms.Panel();
            this.dgvMarkAttendance = new System.Windows.Forms.DataGridView();
            panel15 = new System.Windows.Forms.Panel();
            panel15.SuspendLayout();
            this.panel16.SuspendLayout();
            this.flpSidebar.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.MenuBoutton)).BeginInit();
            this.panel3.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel4.SuspendLayout();
            this.pnlEmployeeScreen.SuspendLayout();
            this.pnldvgEmployeesContainer.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvEmployeesList)).BeginInit();
            this.contextMenuStrip1.SuspendLayout();
            this.pnlAttendanceScreen.SuspendLayout();
            this.panel9.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.panel17.SuspendLayout();
            this.panel18.SuspendLayout();
            this.panel12.SuspendLayout();
            this.panel11.SuspendLayout();
            this.panel13.SuspendLayout();
            this.panel14.SuspendLayout();
            this.panel6.SuspendLayout();
            this.panel7.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvMarkAttendance)).BeginInit();
            this.SuspendLayout();
            // 
            // panel15
            // 
            panel15.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(239)))), ((int)(((byte)(108)))), ((int)(((byte)(0)))));
            panel15.Controls.Add(this.panel16);
            panel15.Dock = System.Windows.Forms.DockStyle.Fill;
            panel15.Enabled = false;
            panel15.Location = new System.Drawing.Point(502, 10);
            panel15.Margin = new System.Windows.Forms.Padding(10);
            panel15.Name = "panel15";
            panel15.Size = new System.Drawing.Size(226, 96);
            panel15.TabIndex = 42;
            panel15.UseWaitCursor = true;
            // 
            // panel16
            // 
            this.panel16.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel16.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(243)))), ((int)(((byte)(224)))));
            this.panel16.Controls.Add(this.label14);
            this.panel16.Controls.Add(this.label15);
            this.panel16.ForeColor = System.Drawing.SystemColors.Control;
            this.panel16.Location = new System.Drawing.Point(1, 1);
            this.panel16.Name = "panel16";
            this.panel16.Size = new System.Drawing.Size(224, 94);
            this.panel16.TabIndex = 0;
            this.panel16.UseWaitCursor = true;
            // 
            // label14
            // 
            this.label14.AutoEllipsis = true;
            this.label14.BackColor = System.Drawing.Color.Transparent;
            this.label14.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.label14.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label14.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(239)))), ((int)(((byte)(108)))), ((int)(((byte)(0)))));
            this.label14.Location = new System.Drawing.Point(0, 51);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(224, 43);
            this.label14.TabIndex = 17;
            this.label14.Text = "0";
            this.label14.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.label14.UseWaitCursor = true;
            // 
            // label15
            // 
            this.label15.AutoEllipsis = true;
            this.label15.BackColor = System.Drawing.Color.Transparent;
            this.label15.Dock = System.Windows.Forms.DockStyle.Top;
            this.label15.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label15.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(239)))), ((int)(((byte)(108)))), ((int)(((byte)(0)))));
            this.label15.Location = new System.Drawing.Point(0, 0);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(224, 45);
            this.label15.TabIndex = 16;
            this.label15.Text = "Late";
            this.label15.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.label15.UseWaitCursor = true;
            // 
            // flpSidebar
            // 
            this.flpSidebar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.flpSidebar.Controls.Add(this.panel2);
            this.flpSidebar.Controls.Add(this.panel3);
            this.flpSidebar.Controls.Add(this.btnAttendance);
            this.flpSidebar.Controls.Add(this.btnStatistics);
            this.flpSidebar.Dock = System.Windows.Forms.DockStyle.Left;
            this.flpSidebar.Location = new System.Drawing.Point(0, 81);
            this.flpSidebar.MaximumSize = new System.Drawing.Size(267, 0);
            this.flpSidebar.MinimumSize = new System.Drawing.Size(93, 0);
            this.flpSidebar.Name = "flpSidebar";
            this.flpSidebar.Size = new System.Drawing.Size(267, 627);
            this.flpSidebar.TabIndex = 0;
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.MenuBoutton);
            this.panel2.Cursor = System.Windows.Forms.Cursors.Default;
            this.panel2.Location = new System.Drawing.Point(3, 3);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(288, 79);
            this.panel2.TabIndex = 0;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.Control;
            this.label2.Location = new System.Drawing.Point(98, 27);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(62, 25);
            this.label2.TabIndex = 2;
            this.label2.Text = "Menu";
            // 
            // MenuBoutton
            // 
            this.MenuBoutton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.MenuBoutton.Image = global::EmployeesMangementSystem.Properties.Resources.menu;
            this.MenuBoutton.Location = new System.Drawing.Point(20, 16);
            this.MenuBoutton.Name = "MenuBoutton";
            this.MenuBoutton.Size = new System.Drawing.Size(61, 43);
            this.MenuBoutton.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.MenuBoutton.TabIndex = 0;
            this.MenuBoutton.TabStop = false;
            this.MenuBoutton.Click += new System.EventHandler(this.MenuBoutton_Click);
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.panel3.Controls.Add(this.btnEmployees);
            this.panel3.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.panel3.Location = new System.Drawing.Point(3, 88);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(287, 79);
            this.panel3.TabIndex = 1;
            // 
            // btnEmployees
            // 
            this.btnEmployees.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.btnEmployees.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnEmployees.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnEmployees.FlatAppearance.BorderSize = 0;
            this.btnEmployees.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnEmployees.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnEmployees.ForeColor = System.Drawing.SystemColors.Control;
            this.btnEmployees.Image = ((System.Drawing.Image)(resources.GetObject("btnEmployees.Image")));
            this.btnEmployees.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnEmployees.Location = new System.Drawing.Point(-3, 3);
            this.btnEmployees.Name = "btnEmployees";
            this.btnEmployees.Padding = new System.Windows.Forms.Padding(30, 0, 0, 0);
            this.btnEmployees.Size = new System.Drawing.Size(342, 91);
            this.btnEmployees.TabIndex = 2;
            this.btnEmployees.Text = "            Employees";
            this.btnEmployees.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnEmployees.UseVisualStyleBackColor = false;
            this.btnEmployees.Click += new System.EventHandler(this.btnEmployees_Click);
            // 
            // btnAttendance
            // 
            this.btnAttendance.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.btnAttendance.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnAttendance.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnAttendance.FlatAppearance.BorderSize = 0;
            this.btnAttendance.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnAttendance.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAttendance.ForeColor = System.Drawing.SystemColors.Control;
            this.btnAttendance.Image = global::EmployeesMangementSystem.Properties.Resources.attendant_list;
            this.btnAttendance.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnAttendance.Location = new System.Drawing.Point(3, 173);
            this.btnAttendance.Name = "btnAttendance";
            this.btnAttendance.Padding = new System.Windows.Forms.Padding(30, 0, 0, 0);
            this.btnAttendance.Size = new System.Drawing.Size(342, 79);
            this.btnAttendance.TabIndex = 3;
            this.btnAttendance.Text = "            Attendance";
            this.btnAttendance.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnAttendance.UseVisualStyleBackColor = false;
            this.btnAttendance.Click += new System.EventHandler(this.btnAttendance_Click);
            // 
            // btnStatistics
            // 
            this.btnStatistics.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.btnStatistics.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnStatistics.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnStatistics.FlatAppearance.BorderSize = 0;
            this.btnStatistics.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnStatistics.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStatistics.ForeColor = System.Drawing.SystemColors.Control;
            this.btnStatistics.Image = global::EmployeesMangementSystem.Properties.Resources.description;
            this.btnStatistics.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnStatistics.Location = new System.Drawing.Point(3, 258);
            this.btnStatistics.Name = "btnStatistics";
            this.btnStatistics.Padding = new System.Windows.Forms.Padding(30, 0, 0, 0);
            this.btnStatistics.Size = new System.Drawing.Size(342, 79);
            this.btnStatistics.TabIndex = 4;
            this.btnStatistics.Text = "            Statistics";
            this.btnStatistics.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnStatistics.UseVisualStyleBackColor = false;
            this.btnStatistics.Click += new System.EventHandler(this.btnStatistics_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.panel1.Controls.Add(this.panel4);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1291, 81);
            this.panel1.TabIndex = 1;
            // 
            // panel4
            // 
            this.panel4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.panel4.BackColor = System.Drawing.Color.WhiteSmoke;
            this.panel4.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.panel4.Controls.Add(this.tbSearch);
            this.panel4.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.panel4.Location = new System.Drawing.Point(1020, 20);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(226, 34);
            this.panel4.TabIndex = 2;
            // 
            // tbSearch
            // 
            this.tbSearch.AccessibleDescription = "";
            this.tbSearch.AccessibleName = "";
            this.tbSearch.BackColor = System.Drawing.Color.WhiteSmoke;
            this.tbSearch.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.tbSearch.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbSearch.ForeColor = System.Drawing.SystemColors.AppWorkspace;
            this.tbSearch.Location = new System.Drawing.Point(9, 7);
            this.tbSearch.Name = "tbSearch";
            this.tbSearch.Size = new System.Drawing.Size(208, 17);
            this.tbSearch.TabIndex = 0;
            this.tbSearch.Tag = "";
            this.tbSearch.TextChanged += new System.EventHandler(this.tbSearch_TextChanged);
            // 
            // label4
            // 
            this.label4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.Control;
            this.label4.Location = new System.Drawing.Point(930, 24);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(74, 25);
            this.label4.TabIndex = 3;
            this.label4.Text = "Search:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label1.Location = new System.Drawing.Point(70, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(480, 40);
            this.label1.TabIndex = 0;
            this.label1.Text = "Employees Mangagement System";
            // 
            // SidebarTimer
            // 
            this.SidebarTimer.Interval = 5;
            this.SidebarTimer.Tick += new System.EventHandler(this.SidebarTimer_Tick);
            // 
            // pnlEmployeeScreen
            // 
            this.pnlEmployeeScreen.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(248)))), ((int)(((byte)(249)))), ((int)(((byte)(250)))));
            this.pnlEmployeeScreen.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlEmployeeScreen.Controls.Add(this.panel5);
            this.pnlEmployeeScreen.Controls.Add(this.label3);
            this.pnlEmployeeScreen.Controls.Add(this.pnldvgEmployeesContainer);
            this.pnlEmployeeScreen.Controls.Add(this.label5);
            this.pnlEmployeeScreen.Controls.Add(this.lbTotalEmployees);
            this.pnlEmployeeScreen.Controls.Add(this.btnAddEmployee);
            this.pnlEmployeeScreen.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlEmployeeScreen.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.pnlEmployeeScreen.Location = new System.Drawing.Point(267, 81);
            this.pnlEmployeeScreen.Name = "pnlEmployeeScreen";
            this.pnlEmployeeScreen.Size = new System.Drawing.Size(1024, 627);
            this.pnlEmployeeScreen.TabIndex = 2;
            this.pnlEmployeeScreen.Paint += new System.Windows.Forms.PaintEventHandler(this.pnlEmployeeScreen_Paint);
            // 
            // panel5
            // 
            this.panel5.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel5.BackColor = System.Drawing.Color.Gray;
            this.panel5.Location = new System.Drawing.Point(14, 59);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(1000, 1);
            this.panel5.TabIndex = 13;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.label3.Location = new System.Drawing.Point(14, 23);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(130, 25);
            this.label3.TabIndex = 3;
            this.label3.Text = "Employee List";
            // 
            // pnldvgEmployeesContainer
            // 
            this.pnldvgEmployeesContainer.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pnldvgEmployeesContainer.Controls.Add(this.dgvEmployeesList);
            this.pnldvgEmployeesContainer.Location = new System.Drawing.Point(11, 150);
            this.pnldvgEmployeesContainer.Name = "pnldvgEmployeesContainer";
            this.pnldvgEmployeesContainer.Size = new System.Drawing.Size(998, 416);
            this.pnldvgEmployeesContainer.TabIndex = 11;
            // 
            // dgvEmployeesList
            // 
            this.dgvEmployeesList.AllowUserToAddRows = false;
            this.dgvEmployeesList.AllowUserToDeleteRows = false;
            this.dgvEmployeesList.AllowUserToResizeRows = false;
            this.dgvEmployeesList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvEmployeesList.ContextMenuStrip = this.contextMenuStrip1;
            this.dgvEmployeesList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dgvEmployeesList.Location = new System.Drawing.Point(0, 0);
            this.dgvEmployeesList.MultiSelect = false;
            this.dgvEmployeesList.Name = "dgvEmployeesList";
            this.dgvEmployeesList.ReadOnly = true;
            this.dgvEmployeesList.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvEmployeesList.Size = new System.Drawing.Size(998, 416);
            this.dgvEmployeesList.TabIndex = 0;
            this.dgvEmployeesList.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvEmployeesList_CellContentClick_1);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.editEmployeeToolStripMenuItem,
            this.deleteEmployeeToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(126, 56);
            this.contextMenuStrip1.Opening += new System.ComponentModel.CancelEventHandler(this.contextMenuStrip1_Opening);
            // 
            // editEmployeeToolStripMenuItem
            // 
            this.editEmployeeToolStripMenuItem.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.editEmployeeToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.editEmployeeToolStripMenuItem.Image = global::EmployeesMangementSystem.Properties.Resources.user_avatar;
            this.editEmployeeToolStripMenuItem.ImageTransparentColor = System.Drawing.Color.White;
            this.editEmployeeToolStripMenuItem.Name = "editEmployeeToolStripMenuItem";
            this.editEmployeeToolStripMenuItem.Size = new System.Drawing.Size(125, 26);
            this.editEmployeeToolStripMenuItem.Text = "Edit";
            this.editEmployeeToolStripMenuItem.Click += new System.EventHandler(this.editEmployeeToolStripMenuItem_Click);
            // 
            // deleteEmployeeToolStripMenuItem
            // 
            this.deleteEmployeeToolStripMenuItem.BackColor = System.Drawing.Color.RosyBrown;
            this.deleteEmployeeToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.deleteEmployeeToolStripMenuItem.Image = global::EmployeesMangementSystem.Properties.Resources.remove;
            this.deleteEmployeeToolStripMenuItem.Name = "deleteEmployeeToolStripMenuItem";
            this.deleteEmployeeToolStripMenuItem.Size = new System.Drawing.Size(125, 26);
            this.deleteEmployeeToolStripMenuItem.Text = "Delete ";
            this.deleteEmployeeToolStripMenuItem.Click += new System.EventHandler(this.deleteEmployeeToolStripMenuItem_Click);
            // 
            // label5
            // 
            this.label5.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("MS Reference Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.Black;
            this.label5.Location = new System.Drawing.Point(15, 572);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(152, 20);
            this.label5.TabIndex = 9;
            this.label5.Text = "Total Employees:";
            // 
            // lbTotalEmployees
            // 
            this.lbTotalEmployees.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.lbTotalEmployees.AutoSize = true;
            this.lbTotalEmployees.BackColor = System.Drawing.Color.Transparent;
            this.lbTotalEmployees.Font = new System.Drawing.Font("MS Reference Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbTotalEmployees.ForeColor = System.Drawing.Color.Black;
            this.lbTotalEmployees.Location = new System.Drawing.Point(163, 574);
            this.lbTotalEmployees.Name = "lbTotalEmployees";
            this.lbTotalEmployees.Size = new System.Drawing.Size(39, 20);
            this.lbTotalEmployees.TabIndex = 10;
            this.lbTotalEmployees.Text = "565";
            // 
            // btnAddEmployee
            // 
            this.btnAddEmployee.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.btnAddEmployee.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnAddEmployee.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAddEmployee.Location = new System.Drawing.Point(18, 76);
            this.btnAddEmployee.Name = "btnAddEmployee";
            this.btnAddEmployee.Size = new System.Drawing.Size(195, 61);
            this.btnAddEmployee.TabIndex = 5;
            this.btnAddEmployee.Text = "Add Employee";
            this.btnAddEmployee.UseVisualStyleBackColor = false;
            this.btnAddEmployee.Click += new System.EventHandler(this.btnAddEmployee_Click);
            // 
            // pnlAttendanceScreen
            // 
            this.pnlAttendanceScreen.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(248)))), ((int)(((byte)(249)))), ((int)(((byte)(250)))));
            this.pnlAttendanceScreen.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlAttendanceScreen.Controls.Add(this.panel9);
            this.pnlAttendanceScreen.Controls.Add(this.panel6);
            this.pnlAttendanceScreen.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlAttendanceScreen.Font = new System.Drawing.Font("Segoe UI Semibold", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.pnlAttendanceScreen.Location = new System.Drawing.Point(267, 81);
            this.pnlAttendanceScreen.Name = "pnlAttendanceScreen";
            this.pnlAttendanceScreen.Size = new System.Drawing.Size(1024, 627);
            this.pnlAttendanceScreen.TabIndex = 12;
            this.pnlAttendanceScreen.UseWaitCursor = true;
            this.pnlAttendanceScreen.Paint += new System.Windows.Forms.PaintEventHandler(this.pnlAttendanceScreen_Paint);
            // 
            // panel9
            // 
            this.panel9.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel9.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel9.Controls.Add(this.tableLayoutPanel1);
            this.panel9.Controls.Add(this.dtpHireDate);
            this.panel9.Controls.Add(this.label9);
            this.panel9.Controls.Add(this.btnSaveAttendance);
            this.panel9.Controls.Add(this.panel10);
            this.panel9.Controls.Add(this.label8);
            this.panel9.Controls.Add(this.btnLoadAttendance);
            this.panel9.Location = new System.Drawing.Point(19, 16);
            this.panel9.Name = "panel9";
            this.panel9.Size = new System.Drawing.Size(986, 219);
            this.panel9.TabIndex = 13;
            this.panel9.UseWaitCursor = true;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 4;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.Controls.Add(this.panel17, 3, 0);
            this.tableLayoutPanel1.Controls.Add(this.panel12, 0, 0);
            this.tableLayoutPanel1.Controls.Add(panel15, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this.panel13, 1, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 101);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(984, 116);
            this.tableLayoutPanel1.TabIndex = 39;
            this.tableLayoutPanel1.UseWaitCursor = true;
            // 
            // panel17
            // 
            this.panel17.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(21)))), ((int)(((byte)(101)))), ((int)(((byte)(192)))));
            this.panel17.Controls.Add(this.panel18);
            this.panel17.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel17.Location = new System.Drawing.Point(748, 10);
            this.panel17.Margin = new System.Windows.Forms.Padding(10);
            this.panel17.Name = "panel17";
            this.panel17.Size = new System.Drawing.Size(226, 96);
            this.panel17.TabIndex = 43;
            this.panel17.UseWaitCursor = true;
            // 
            // panel18
            // 
            this.panel18.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel18.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(227)))), ((int)(((byte)(242)))), ((int)(((byte)(253)))));
            this.panel18.Controls.Add(this.label16);
            this.panel18.Controls.Add(this.label17);
            this.panel18.ForeColor = System.Drawing.SystemColors.Control;
            this.panel18.Location = new System.Drawing.Point(1, 1);
            this.panel18.Name = "panel18";
            this.panel18.Size = new System.Drawing.Size(224, 94);
            this.panel18.TabIndex = 0;
            this.panel18.UseWaitCursor = true;
            // 
            // label16
            // 
            this.label16.AutoEllipsis = true;
            this.label16.BackColor = System.Drawing.Color.Transparent;
            this.label16.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.label16.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label16.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(21)))), ((int)(((byte)(101)))), ((int)(((byte)(192)))));
            this.label16.Location = new System.Drawing.Point(0, 51);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(224, 43);
            this.label16.TabIndex = 17;
            this.label16.Text = "0";
            this.label16.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.label16.UseWaitCursor = true;
            // 
            // label17
            // 
            this.label17.AutoEllipsis = true;
            this.label17.BackColor = System.Drawing.Color.Transparent;
            this.label17.Dock = System.Windows.Forms.DockStyle.Top;
            this.label17.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label17.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(21)))), ((int)(((byte)(101)))), ((int)(((byte)(192)))));
            this.label17.Location = new System.Drawing.Point(0, 0);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(224, 45);
            this.label17.TabIndex = 16;
            this.label17.Text = "Leave";
            this.label17.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.label17.UseWaitCursor = true;
            // 
            // panel12
            // 
            this.panel12.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(125)))), ((int)(((byte)(50)))));
            this.panel12.Controls.Add(this.panel11);
            this.panel12.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel12.Location = new System.Drawing.Point(10, 10);
            this.panel12.Margin = new System.Windows.Forms.Padding(10);
            this.panel12.Name = "panel12";
            this.panel12.Size = new System.Drawing.Size(226, 96);
            this.panel12.TabIndex = 40;
            this.panel12.UseWaitCursor = true;
            // 
            // panel11
            // 
            this.panel11.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel11.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(232)))), ((int)(((byte)(245)))), ((int)(((byte)(233)))));
            this.panel11.Controls.Add(this.label11);
            this.panel11.Controls.Add(this.label10);
            this.panel11.ForeColor = System.Drawing.SystemColors.Control;
            this.panel11.Location = new System.Drawing.Point(1, 1);
            this.panel11.Name = "panel11";
            this.panel11.Size = new System.Drawing.Size(224, 94);
            this.panel11.TabIndex = 0;
            this.panel11.UseWaitCursor = true;
            this.panel11.Paint += new System.Windows.Forms.PaintEventHandler(this.panel11_Paint);
            // 
            // label11
            // 
            this.label11.BackColor = System.Drawing.Color.Transparent;
            this.label11.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.label11.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(125)))), ((int)(((byte)(50)))));
            this.label11.Location = new System.Drawing.Point(0, 51);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(224, 43);
            this.label11.TabIndex = 17;
            this.label11.Text = "0";
            this.label11.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.label11.UseWaitCursor = true;
            // 
            // label10
            // 
            this.label10.BackColor = System.Drawing.Color.Transparent;
            this.label10.Dock = System.Windows.Forms.DockStyle.Top;
            this.label10.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(125)))), ((int)(((byte)(50)))));
            this.label10.Location = new System.Drawing.Point(0, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(224, 45);
            this.label10.TabIndex = 16;
            this.label10.Text = "Present";
            this.label10.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.label10.UseWaitCursor = true;
            this.label10.Click += new System.EventHandler(this.label10_Click);
            // 
            // panel13
            // 
            this.panel13.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(198)))), ((int)(((byte)(40)))), ((int)(((byte)(40)))));
            this.panel13.Controls.Add(this.panel14);
            this.panel13.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel13.Location = new System.Drawing.Point(256, 10);
            this.panel13.Margin = new System.Windows.Forms.Padding(10);
            this.panel13.Name = "panel13";
            this.panel13.Size = new System.Drawing.Size(226, 96);
            this.panel13.TabIndex = 44;
            this.panel13.UseWaitCursor = true;
            // 
            // panel14
            // 
            this.panel14.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel14.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(235)))), ((int)(((byte)(238)))));
            this.panel14.Controls.Add(this.label12);
            this.panel14.Controls.Add(this.label13);
            this.panel14.ForeColor = System.Drawing.SystemColors.Control;
            this.panel14.Location = new System.Drawing.Point(1, 1);
            this.panel14.Name = "panel14";
            this.panel14.Size = new System.Drawing.Size(224, 94);
            this.panel14.TabIndex = 0;
            this.panel14.UseWaitCursor = true;
            // 
            // label12
            // 
            this.label12.AutoEllipsis = true;
            this.label12.BackColor = System.Drawing.Color.Transparent;
            this.label12.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.label12.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(198)))), ((int)(((byte)(40)))), ((int)(((byte)(40)))));
            this.label12.Location = new System.Drawing.Point(0, 51);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(224, 43);
            this.label12.TabIndex = 17;
            this.label12.Text = "0";
            this.label12.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.label12.UseWaitCursor = true;
            // 
            // label13
            // 
            this.label13.AutoEllipsis = true;
            this.label13.BackColor = System.Drawing.Color.Transparent;
            this.label13.Dock = System.Windows.Forms.DockStyle.Top;
            this.label13.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(198)))), ((int)(((byte)(40)))), ((int)(((byte)(40)))));
            this.label13.Location = new System.Drawing.Point(0, 0);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(224, 45);
            this.label13.TabIndex = 16;
            this.label13.Text = "Absent";
            this.label13.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.label13.UseWaitCursor = true;
            // 
            // dtpHireDate
            // 
            this.dtpHireDate.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dtpHireDate.Location = new System.Drawing.Point(71, 56);
            this.dtpHireDate.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.dtpHireDate.Name = "dtpHireDate";
            this.dtpHireDate.Size = new System.Drawing.Size(191, 29);
            this.dtpHireDate.TabIndex = 37;
            this.dtpHireDate.UseWaitCursor = true;
            this.dtpHireDate.ValueChanged += new System.EventHandler(this.dtpHireDate_ValueChanged);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.Color.Transparent;
            this.label9.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.label9.Location = new System.Drawing.Point(19, 58);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(54, 21);
            this.label9.TabIndex = 38;
            this.label9.Text = "Date :";
            this.label9.UseWaitCursor = true;
            // 
            // btnSaveAttendance
            // 
            this.btnSaveAttendance.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(16)))), ((int)(((byte)(103)))), ((int)(((byte)(16)))));
            this.btnSaveAttendance.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSaveAttendance.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSaveAttendance.Location = new System.Drawing.Point(473, 50);
            this.btnSaveAttendance.Name = "btnSaveAttendance";
            this.btnSaveAttendance.Size = new System.Drawing.Size(173, 45);
            this.btnSaveAttendance.TabIndex = 17;
            this.btnSaveAttendance.Text = "Save Attendance";
            this.btnSaveAttendance.UseVisualStyleBackColor = false;
            this.btnSaveAttendance.UseWaitCursor = true;
            // 
            // panel10
            // 
            this.panel10.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel10.BackColor = System.Drawing.Color.Gray;
            this.panel10.Location = new System.Drawing.Point(20, 42);
            this.panel10.Name = "panel10";
            this.panel10.Size = new System.Drawing.Size(945, 1);
            this.panel10.TabIndex = 16;
            this.panel10.UseWaitCursor = true;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.Transparent;
            this.label8.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.label8.Location = new System.Drawing.Point(15, 8);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(155, 25);
            this.label8.TabIndex = 15;
            this.label8.Text = "Daily Attendance";
            this.label8.UseWaitCursor = true;
            // 
            // btnLoadAttendance
            // 
            this.btnLoadAttendance.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.btnLoadAttendance.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnLoadAttendance.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLoadAttendance.Location = new System.Drawing.Point(282, 50);
            this.btnLoadAttendance.Name = "btnLoadAttendance";
            this.btnLoadAttendance.Size = new System.Drawing.Size(173, 45);
            this.btnLoadAttendance.TabIndex = 5;
            this.btnLoadAttendance.Text = "Load Attendance";
            this.btnLoadAttendance.UseVisualStyleBackColor = false;
            this.btnLoadAttendance.UseWaitCursor = true;
            // 
            // panel6
            // 
            this.panel6.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel6.BackColor = System.Drawing.Color.White;
            this.panel6.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel6.Controls.Add(this.label7);
            this.panel6.Controls.Add(this.panel8);
            this.panel6.Controls.Add(this.label6);
            this.panel6.Controls.Add(this.panel7);
            this.panel6.Location = new System.Drawing.Point(19, 257);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(987, 357);
            this.panel6.TabIndex = 11;
            this.panel6.UseWaitCursor = true;
            this.panel6.Paint += new System.Windows.Forms.PaintEventHandler(this.panel6_Paint);
            // 
            // label7
            // 
            this.label7.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.Font = new System.Drawing.Font("MS Reference Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.Color.Black;
            this.label7.Location = new System.Drawing.Point(18, 320);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(152, 20);
            this.label7.TabIndex = 15;
            this.label7.Text = "Total Employees:";
            this.label7.UseWaitCursor = true;
            // 
            // panel8
            // 
            this.panel8.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel8.BackColor = System.Drawing.Color.Gray;
            this.panel8.Location = new System.Drawing.Point(19, 45);
            this.panel8.Name = "panel8";
            this.panel8.Size = new System.Drawing.Size(947, 1);
            this.panel8.TabIndex = 14;
            this.panel8.UseWaitCursor = true;
            this.panel8.Paint += new System.Windows.Forms.PaintEventHandler(this.panel8_Paint);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(62)))), ((int)(((byte)(80)))));
            this.label6.Location = new System.Drawing.Point(14, 11);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(156, 25);
            this.label6.TabIndex = 13;
            this.label6.Text = "Mark Attendance";
            this.label6.UseWaitCursor = true;
            // 
            // panel7
            // 
            this.panel7.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel7.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel7.Controls.Add(this.dgvMarkAttendance);
            this.panel7.Location = new System.Drawing.Point(19, 58);
            this.panel7.Name = "panel7";
            this.panel7.Size = new System.Drawing.Size(947, 254);
            this.panel7.TabIndex = 12;
            this.panel7.UseWaitCursor = true;
            // 
            // dgvMarkAttendance
            // 
            this.dgvMarkAttendance.AllowUserToAddRows = false;
            this.dgvMarkAttendance.AllowUserToDeleteRows = false;
            this.dgvMarkAttendance.AllowUserToResizeRows = false;
            this.dgvMarkAttendance.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.dgvMarkAttendance.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvMarkAttendance.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dgvMarkAttendance.EditMode = System.Windows.Forms.DataGridViewEditMode.EditOnEnter;
            this.dgvMarkAttendance.Location = new System.Drawing.Point(0, 0);
            this.dgvMarkAttendance.MultiSelect = false;
            this.dgvMarkAttendance.Name = "dgvMarkAttendance";
            this.dgvMarkAttendance.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect;
            this.dgvMarkAttendance.Size = new System.Drawing.Size(945, 252);
            this.dgvMarkAttendance.TabIndex = 0;
            this.dgvMarkAttendance.UseWaitCursor = true;
            this.dgvMarkAttendance.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvMarkAttendance_CellClick);
            this.dgvMarkAttendance.DataBindingComplete += new System.Windows.Forms.DataGridViewBindingCompleteEventHandler(this.dgvMarkAttendance_DataBindingComplete);
            // 
            // EmployeesMangementSystemForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.WhiteSmoke;
            this.ClientSize = new System.Drawing.Size(1291, 708);
            this.Controls.Add(this.pnlAttendanceScreen);
            this.Controls.Add(this.pnlEmployeeScreen);
            this.Controls.Add(this.flpSidebar);
            this.Controls.Add(this.panel1);
            this.DoubleBuffered = true;
            this.Font = new System.Drawing.Font("Segoe UI", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.SystemColors.Control;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "EmployeesMangementSystemForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Tag = "";
            this.Text = "EmployeesMangementSystem";
            this.Load += new System.EventHandler(this.Form1_Load);
            panel15.ResumeLayout(false);
            this.panel16.ResumeLayout(false);
            this.flpSidebar.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.MenuBoutton)).EndInit();
            this.panel3.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.pnlEmployeeScreen.ResumeLayout(false);
            this.pnlEmployeeScreen.PerformLayout();
            this.pnldvgEmployeesContainer.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvEmployeesList)).EndInit();
            this.contextMenuStrip1.ResumeLayout(false);
            this.pnlAttendanceScreen.ResumeLayout(false);
            this.panel9.ResumeLayout(false);
            this.panel9.PerformLayout();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.panel17.ResumeLayout(false);
            this.panel18.ResumeLayout(false);
            this.panel12.ResumeLayout(false);
            this.panel11.ResumeLayout(false);
            this.panel13.ResumeLayout(false);
            this.panel14.ResumeLayout(false);
            this.panel6.ResumeLayout(false);
            this.panel6.PerformLayout();
            this.panel7.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvMarkAttendance)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.FlowLayoutPanel flpSidebar;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Button btnEmployees;
        private System.Windows.Forms.Button btnAttendance;
        private System.Windows.Forms.Button btnStatistics;
        private System.Windows.Forms.PictureBox MenuBoutton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Timer SidebarTimer;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.TextBox tbSearch;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnAddEmployee;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label lbTotalEmployees;
        public System.Windows.Forms.Panel pnlEmployeeScreen;
        private System.Windows.Forms.Panel pnldvgEmployeesContainer;
        private System.Windows.Forms.DataGridView dgvEmployeesList;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem editEmployeeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteEmployeeToolStripMenuItem;
        public System.Windows.Forms.Panel pnlAttendanceScreen;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.Button btnLoadAttendance;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.Panel panel7;
        private System.Windows.Forms.DataGridView dgvMarkAttendance;
        private System.Windows.Forms.Panel panel8;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Panel panel9;
        private System.Windows.Forms.Panel panel10;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button btnSaveAttendance;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.DateTimePicker dtpHireDate;
        private System.Windows.Forms.Panel panel11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Panel panel12;
        private System.Windows.Forms.Panel panel16;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Panel panel17;
        private System.Windows.Forms.Panel panel18;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Panel panel14;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Panel panel13;
    }
}

