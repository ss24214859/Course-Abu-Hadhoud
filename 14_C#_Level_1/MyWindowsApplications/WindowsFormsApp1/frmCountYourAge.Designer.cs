namespace WindowsFormsApp1
{
    partial class frmMaskedTextBox
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
            this.maskedTextBox1 = new System.Windows.Forms.MaskedTextBox();
            this.btnCheckDate = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.lblAge = new System.Windows.Forms.Label();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.lblDateTime = new System.Windows.Forms.Label();
            this.btnShortDate = new System.Windows.Forms.Button();
            this.btnLongDate = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // maskedTextBox1
            // 
            this.maskedTextBox1.BeepOnError = true;
            this.maskedTextBox1.Location = new System.Drawing.Point(181, 98);
            this.maskedTextBox1.Mask = "00 /00 /0000";
            this.maskedTextBox1.Name = "maskedTextBox1";
            this.maskedTextBox1.Size = new System.Drawing.Size(167, 22);
            this.maskedTextBox1.TabIndex = 0;
            this.maskedTextBox1.Text = "00000000";
            this.maskedTextBox1.ValidatingType = typeof(System.DateTime);
            // 
            // btnCheckDate
            // 
            this.btnCheckDate.AutoEllipsis = true;
            this.btnCheckDate.Location = new System.Drawing.Point(181, 149);
            this.btnCheckDate.Name = "btnCheckDate";
            this.btnCheckDate.Size = new System.Drawing.Size(167, 49);
            this.btnCheckDate.TabIndex = 1;
            this.btnCheckDate.Text = "Check Your Age";
            this.btnCheckDate.UseVisualStyleBackColor = true;
            this.btnCheckDate.Click += new System.EventHandler(this.btnCheckDate_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.DarkGreen;
            this.label1.Location = new System.Drawing.Point(199, 39);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(149, 29);
            this.label1.TabIndex = 2;
            this.label1.Text = "Your Age Is :";
            // 
            // lblAge
            // 
            this.lblAge.AutoSize = true;
            this.lblAge.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAge.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.lblAge.Location = new System.Drawing.Point(354, 39);
            this.lblAge.Name = "lblAge";
            this.lblAge.Size = new System.Drawing.Size(61, 29);
            this.lblAge.TabIndex = 3;
            this.lblAge.Text = "------";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.dateTimePicker1.Location = new System.Drawing.Point(452, 149);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(263, 38);
            this.dateTimePicker1.TabIndex = 4;
            this.dateTimePicker1.ValueChanged += new System.EventHandler(this.dateTimePicker1_ValueChanged);
            // 
            // lblDateTime
            // 
            this.lblDateTime.AutoSize = true;
            this.lblDateTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDateTime.Location = new System.Drawing.Point(177, 245);
            this.lblDateTime.Name = "lblDateTime";
            this.lblDateTime.Size = new System.Drawing.Size(110, 28);
            this.lblDateTime.TabIndex = 5;
            this.lblDateTime.Text = "DateTime";
            // 
            // btnShortDate
            // 
            this.btnShortDate.Location = new System.Drawing.Point(399, 257);
            this.btnShortDate.Name = "btnShortDate";
            this.btnShortDate.Size = new System.Drawing.Size(145, 47);
            this.btnShortDate.TabIndex = 6;
            this.btnShortDate.Text = "Short Date";
            this.btnShortDate.UseVisualStyleBackColor = true;
            this.btnShortDate.Click += new System.EventHandler(this.btnShortDate_Click);
            // 
            // btnLongDate
            // 
            this.btnLongDate.Location = new System.Drawing.Point(594, 257);
            this.btnLongDate.Name = "btnLongDate";
            this.btnLongDate.Size = new System.Drawing.Size(145, 47);
            this.btnLongDate.TabIndex = 7;
            this.btnLongDate.Text = "Long Date";
            this.btnLongDate.UseVisualStyleBackColor = true;
            this.btnLongDate.Click += new System.EventHandler(this.btnLongDate_Click);
            // 
            // frmMaskedTextBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoValidate = System.Windows.Forms.AutoValidate.EnableAllowFocusChange;
            this.ClientSize = new System.Drawing.Size(800, 508);
            this.Controls.Add(this.btnLongDate);
            this.Controls.Add(this.btnShortDate);
            this.Controls.Add(this.lblDateTime);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.lblAge);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnCheckDate);
            this.Controls.Add(this.maskedTextBox1);
            this.Name = "frmMaskedTextBox";
            this.Text = "Masked Text Box";
            this.Load += new System.EventHandler(this.frmMaskedTextBox_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MaskedTextBox maskedTextBox1;
        private System.Windows.Forms.Button btnCheckDate;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblAge;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.Label lblDateTime;
        private System.Windows.Forms.Button btnShortDate;
        private System.Windows.Forms.Button btnLongDate;
    }
}