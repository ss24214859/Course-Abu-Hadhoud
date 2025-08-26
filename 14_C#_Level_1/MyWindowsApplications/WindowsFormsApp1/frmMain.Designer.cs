namespace WindowsFormsApp1
{
    partial class frmMain
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
            this.btnChoicePhoto = new System.Windows.Forms.Button();
            this.btnMaskedTextBox = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnChoicePhoto
            // 
            this.btnChoicePhoto.Location = new System.Drawing.Point(105, 93);
            this.btnChoicePhoto.Name = "btnChoicePhoto";
            this.btnChoicePhoto.Size = new System.Drawing.Size(100, 75);
            this.btnChoicePhoto.TabIndex = 0;
            this.btnChoicePhoto.Text = "Choice Photo";
            this.btnChoicePhoto.UseVisualStyleBackColor = true;
            this.btnChoicePhoto.Click += new System.EventHandler(this.btnChoicePhoto_Click);
            // 
            // btnMaskedTextBox
            // 
            this.btnMaskedTextBox.Location = new System.Drawing.Point(404, 90);
            this.btnMaskedTextBox.Name = "btnMaskedTextBox";
            this.btnMaskedTextBox.Size = new System.Drawing.Size(153, 80);
            this.btnMaskedTextBox.TabIndex = 1;
            this.btnMaskedTextBox.Text = "Masked Text Box";
            this.btnMaskedTextBox.UseVisualStyleBackColor = true;
            this.btnMaskedTextBox.Click += new System.EventHandler(this.btnMaskedTextBox_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(438, 235);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(100, 75);
            this.button1.TabIndex = 2;
            this.button1.Text = "Choice Photo 2";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnMaskedTextBox);
            this.Controls.Add(this.btnChoicePhoto);
            this.Name = "frmMain";
            this.Text = "Main";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnChoicePhoto;
        private System.Windows.Forms.Button btnMaskedTextBox;
        private System.Windows.Forms.Button button1;
    }
}