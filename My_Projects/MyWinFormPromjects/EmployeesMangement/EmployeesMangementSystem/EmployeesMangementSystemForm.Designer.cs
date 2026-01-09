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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(EmployeesMangementSystemForm));
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
            this.pnldvgEmployeesContainer = new System.Windows.Forms.Panel();
            this.dgvEmployeesList = new System.Windows.Forms.DataGridView();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.editEmployeeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteEmployeeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label5 = new System.Windows.Forms.Label();
            this.lbTotalEmployees = new System.Windows.Forms.Label();
            this.btnAddEmployee = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
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
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // flpSidebar
            // 
            this.flpSidebar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.flpSidebar.Controls.Add(this.panel2);
            this.flpSidebar.Controls.Add(this.panel3);
            this.flpSidebar.Controls.Add(this.btnAttendance);
            this.flpSidebar.Controls.Add(this.btnStatistics);
            this.flpSidebar.Dock = System.Windows.Forms.DockStyle.Left;
            this.flpSidebar.Location = new System.Drawing.Point(0, 87);
            this.flpSidebar.MaximumSize = new System.Drawing.Size(267, 614);
            this.flpSidebar.MinimumSize = new System.Drawing.Size(93, 614);
            this.flpSidebar.Name = "flpSidebar";
            this.flpSidebar.Size = new System.Drawing.Size(267, 614);
            this.flpSidebar.TabIndex = 0;
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.MenuBoutton);
            this.panel2.Location = new System.Drawing.Point(3, 3);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(288, 79);
            this.panel2.TabIndex = 0;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("MS Reference Sans Serif", 13.8F);
            this.label2.ForeColor = System.Drawing.SystemColors.Control;
            this.label2.Location = new System.Drawing.Point(87, 27);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 24);
            this.label2.TabIndex = 2;
            this.label2.Text = "Menu";
            // 
            // MenuBoutton
            // 
            this.MenuBoutton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.MenuBoutton.Image = global::EmployeesMangementSystem.Properties.Resources.menu;
            this.MenuBoutton.Location = new System.Drawing.Point(20, 16);
            this.MenuBoutton.Name = "MenuBoutton";
            this.MenuBoutton.Size = new System.Drawing.Size(53, 43);
            this.MenuBoutton.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.MenuBoutton.TabIndex = 0;
            this.MenuBoutton.TabStop = false;
            this.MenuBoutton.Click += new System.EventHandler(this.MenuBoutton_Click);
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.Transparent;
            this.panel3.Controls.Add(this.btnEmployees);
            this.panel3.Location = new System.Drawing.Point(3, 88);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(287, 106);
            this.panel3.TabIndex = 1;
            // 
            // btnEmployees
            // 
            this.btnEmployees.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnEmployees.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnEmployees.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnEmployees.FlatAppearance.BorderSize = 0;
            this.btnEmployees.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnEmployees.Font = new System.Drawing.Font("MS Reference Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnEmployees.ForeColor = System.Drawing.SystemColors.Control;
            this.btnEmployees.Image = ((System.Drawing.Image)(resources.GetObject("btnEmployees.Image")));
            this.btnEmployees.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnEmployees.Location = new System.Drawing.Point(-3, 3);
            this.btnEmployees.Name = "btnEmployees";
            this.btnEmployees.Padding = new System.Windows.Forms.Padding(30, 0, 0, 0);
            this.btnEmployees.Size = new System.Drawing.Size(342, 91);
            this.btnEmployees.TabIndex = 2;
            this.btnEmployees.Text = "        Employees";
            this.btnEmployees.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnEmployees.UseVisualStyleBackColor = false;
            this.btnEmployees.Click += new System.EventHandler(this.btnEmployees_Click);
            // 
            // btnAttendance
            // 
            this.btnAttendance.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnAttendance.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnAttendance.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnAttendance.FlatAppearance.BorderSize = 0;
            this.btnAttendance.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnAttendance.Font = new System.Drawing.Font("MS Reference Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAttendance.ForeColor = System.Drawing.SystemColors.Control;
            this.btnAttendance.Image = global::EmployeesMangementSystem.Properties.Resources.attendant_list;
            this.btnAttendance.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnAttendance.Location = new System.Drawing.Point(3, 200);
            this.btnAttendance.Name = "btnAttendance";
            this.btnAttendance.Padding = new System.Windows.Forms.Padding(30, 0, 0, 0);
            this.btnAttendance.Size = new System.Drawing.Size(342, 91);
            this.btnAttendance.TabIndex = 3;
            this.btnAttendance.Text = "        Attendance";
            this.btnAttendance.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnAttendance.UseVisualStyleBackColor = false;
            this.btnAttendance.Click += new System.EventHandler(this.btnAttendance_Click);
            // 
            // btnStatistics
            // 
            this.btnStatistics.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnStatistics.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.btnStatistics.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(120)))), ((int)(((byte)(215)))));
            this.btnStatistics.FlatAppearance.BorderSize = 0;
            this.btnStatistics.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnStatistics.Font = new System.Drawing.Font("MS Reference Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStatistics.ForeColor = System.Drawing.SystemColors.Control;
            this.btnStatistics.Image = global::EmployeesMangementSystem.Properties.Resources.description;
            this.btnStatistics.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnStatistics.Location = new System.Drawing.Point(3, 297);
            this.btnStatistics.Name = "btnStatistics";
            this.btnStatistics.Padding = new System.Windows.Forms.Padding(30, 0, 0, 0);
            this.btnStatistics.Size = new System.Drawing.Size(342, 91);
            this.btnStatistics.TabIndex = 4;
            this.btnStatistics.Text = "        Statistics";
            this.btnStatistics.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnStatistics.UseVisualStyleBackColor = false;
            this.btnStatistics.Click += new System.EventHandler(this.btnStatistics_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.HotTrack;
            this.panel1.Controls.Add(this.panel4);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1291, 87);
            this.panel1.TabIndex = 1;
            // 
            // panel4
            // 
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
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("MS Reference Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.Control;
            this.label4.Location = new System.Drawing.Point(930, 24);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(84, 24);
            this.label4.TabIndex = 3;
            this.label4.Text = "Search:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("MS Reference Sans Serif", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.label1.Location = new System.Drawing.Point(70, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(501, 34);
            this.label1.TabIndex = 0;
            this.label1.Text = "Employees Mangagement System";
            // 
            // SidebarTimer
            // 
            this.SidebarTimer.Interval = 15;
            this.SidebarTimer.Tick += new System.EventHandler(this.SidebarTimer_Tick);
            // 
            // pnlEmployeeScreen
            // 
            this.pnlEmployeeScreen.BackColor = System.Drawing.Color.White;
            this.pnlEmployeeScreen.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlEmployeeScreen.Controls.Add(this.pnldvgEmployeesContainer);
            this.pnlEmployeeScreen.Controls.Add(this.label5);
            this.pnlEmployeeScreen.Controls.Add(this.lbTotalEmployees);
            this.pnlEmployeeScreen.Controls.Add(this.btnAddEmployee);
            this.pnlEmployeeScreen.Controls.Add(this.label3);
            this.pnlEmployeeScreen.Controls.Add(this.pictureBox1);
            this.pnlEmployeeScreen.Location = new System.Drawing.Point(308, 117);
            this.pnlEmployeeScreen.MaximumSize = new System.Drawing.Size(1126, 561);
            this.pnlEmployeeScreen.MinimumSize = new System.Drawing.Size(952, 561);
            this.pnlEmployeeScreen.Name = "pnlEmployeeScreen";
            this.pnlEmployeeScreen.Size = new System.Drawing.Size(952, 561);
            this.pnlEmployeeScreen.TabIndex = 2;
            this.pnlEmployeeScreen.Paint += new System.Windows.Forms.PaintEventHandler(this.pnlEmployeeScreen_Paint);
            // 
            // pnldvgEmployeesContainer
            // 
            this.pnldvgEmployeesContainer.Controls.Add(this.dgvEmployeesList);
            this.pnldvgEmployeesContainer.Location = new System.Drawing.Point(11, 150);
            this.pnldvgEmployeesContainer.Name = "pnldvgEmployeesContainer";
            this.pnldvgEmployeesContainer.Size = new System.Drawing.Size(926, 283);
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
            this.dgvEmployeesList.Size = new System.Drawing.Size(926, 283);
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
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("MS Reference Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.Black;
            this.label5.Location = new System.Drawing.Point(12, 436);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(152, 20);
            this.label5.TabIndex = 9;
            this.label5.Text = "Total Employees:";
            // 
            // lbTotalEmployees
            // 
            this.lbTotalEmployees.AutoSize = true;
            this.lbTotalEmployees.BackColor = System.Drawing.Color.Transparent;
            this.lbTotalEmployees.Font = new System.Drawing.Font("MS Reference Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbTotalEmployees.ForeColor = System.Drawing.Color.Black;
            this.lbTotalEmployees.Location = new System.Drawing.Point(160, 438);
            this.lbTotalEmployees.Name = "lbTotalEmployees";
            this.lbTotalEmployees.Size = new System.Drawing.Size(39, 20);
            this.lbTotalEmployees.TabIndex = 10;
            this.lbTotalEmployees.Text = "565";
            // 
            // btnAddEmployee
            // 
            this.btnAddEmployee.BackColor = System.Drawing.SystemColors.HotTrack;
            this.btnAddEmployee.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnAddEmployee.Font = new System.Drawing.Font("MS Reference Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAddEmployee.Location = new System.Drawing.Point(18, 76);
            this.btnAddEmployee.Name = "btnAddEmployee";
            this.btnAddEmployee.Size = new System.Drawing.Size(195, 61);
            this.btnAddEmployee.TabIndex = 5;
            this.btnAddEmployee.Text = "Add Employee";
            this.btnAddEmployee.UseVisualStyleBackColor = false;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("MS Reference Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.label3.Location = new System.Drawing.Point(14, 23);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(124, 20);
            this.label3.TabIndex = 3;
            this.label3.Text = "Employee List";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::EmployeesMangementSystem.Properties.Resources.Line_PNG_Free_Image;
            this.pictureBox1.Location = new System.Drawing.Point(-18, 32);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(976, 50);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            // 
            // EmployeesMangementSystemForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.WhiteSmoke;
            this.ClientSize = new System.Drawing.Size(1291, 701);
            this.Controls.Add(this.pnlEmployeeScreen);
            this.Controls.Add(this.flpSidebar);
            this.Controls.Add(this.panel1);
            this.DoubleBuffered = true;
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.SystemColors.Control;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "EmployeesMangementSystemForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Tag = "";
            this.Text = "EmployeesMangementSystem";
            this.Load += new System.EventHandler(this.Form1_Load);
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
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
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
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button btnAddEmployee;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label lbTotalEmployees;
        public System.Windows.Forms.Panel pnlEmployeeScreen;
        private System.Windows.Forms.Panel pnldvgEmployeesContainer;
        private System.Windows.Forms.DataGridView dgvEmployeesList;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem editEmployeeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteEmployeeToolStripMenuItem;
    }
}

