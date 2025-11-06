namespace WindowsFormsApp1
{
    partial class frmMonthCalandar
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
            this.monthCalendar1 = new System.Windows.Forms.MonthCalendar();
            this.btnSelectedRang = new System.Windows.Forms.Button();
            this.btnEndDate = new System.Windows.Forms.Button();
            this.btnStartDate = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // monthCalendar1
            // 
            this.monthCalendar1.Location = new System.Drawing.Point(195, 60);
            this.monthCalendar1.Name = "monthCalendar1";
            this.monthCalendar1.TabIndex = 0;
            // 
            // btnSelectedRang
            // 
            this.btnSelectedRang.Location = new System.Drawing.Point(124, 315);
            this.btnSelectedRang.Name = "btnSelectedRang";
            this.btnSelectedRang.Size = new System.Drawing.Size(155, 45);
            this.btnSelectedRang.TabIndex = 1;
            this.btnSelectedRang.Text = "selected Rang";
            this.btnSelectedRang.UseVisualStyleBackColor = true;
            this.btnSelectedRang.Click += new System.EventHandler(this.btnSelectedRang_Click);
            // 
            // btnEndDate
            // 
            this.btnEndDate.Location = new System.Drawing.Point(479, 315);
            this.btnEndDate.Name = "btnEndDate";
            this.btnEndDate.Size = new System.Drawing.Size(157, 45);
            this.btnEndDate.TabIndex = 2;
            this.btnEndDate.Text = "End Date";
            this.btnEndDate.UseVisualStyleBackColor = true;
            this.btnEndDate.Click += new System.EventHandler(this.btnEndDate_Click);
            // 
            // btnStartDate
            // 
            this.btnStartDate.Location = new System.Drawing.Point(301, 315);
            this.btnStartDate.Name = "btnStartDate";
            this.btnStartDate.Size = new System.Drawing.Size(155, 45);
            this.btnStartDate.TabIndex = 3;
            this.btnStartDate.Text = "Start Date";
            this.btnStartDate.UseVisualStyleBackColor = true;
            this.btnStartDate.Click += new System.EventHandler(this.btnStartDate_Click);
            // 
            // frmMonthCalandar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnStartDate);
            this.Controls.Add(this.btnEndDate);
            this.Controls.Add(this.btnSelectedRang);
            this.Controls.Add(this.monthCalendar1);
            this.Name = "frmMonthCalandar";
            this.Text = "MonthCalandar";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.MonthCalendar monthCalendar1;
        private System.Windows.Forms.Button btnSelectedRang;
        private System.Windows.Forms.Button btnEndDate;
        private System.Windows.Forms.Button btnStartDate;
    }
}