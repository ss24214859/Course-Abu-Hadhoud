namespace WindowsFormsApp1
{
    partial class frmTabControl
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
            this.label1 = new System.Windows.Forms.Label();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.fontDialog1 = new System.Windows.Forms.FontDialog();
            this.tabPassword = new System.Windows.Forms.TabPage();
            this.label5 = new System.Windows.Forms.Label();
            this.textPassword = new System.Windows.Forms.TextBox();
            this.tabAccount = new System.Windows.Forms.TabPage();
            this.label4 = new System.Windows.Forms.Label();
            this.textAccount = new System.Windows.Forms.TextBox();
            this.tabFontScreen = new System.Windows.Forms.TabPage();
            this.button5 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.btnNext = new System.Windows.Forms.Button();
            this.tabColorScreen = new System.Windows.Forms.TabPage();
            this.btnChoiceColor = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabResult = new System.Windows.Forms.TabPage();
            this.label6 = new System.Windows.Forms.Label();
            this.btnBack = new System.Windows.Forms.Button();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.btnSaveFile = new System.Windows.Forms.Button();
            this.btnOpenFile = new System.Windows.Forms.Button();
            this.btnMultiOpenFile = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.btnBrowsingFolder = new System.Windows.Forms.Button();
            this.folderBrowserDialog1 = new System.Windows.Forms.FolderBrowserDialog();
            this.tabPassword.SuspendLayout();
            this.tabAccount.SuspendLayout();
            this.tabFontScreen.SuspendLayout();
            this.tabColorScreen.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabResult.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Mongolian Baiti", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(0)))), ((int)(((byte)(64)))));
            this.label1.Location = new System.Drawing.Point(429, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(253, 85);
            this.label1.TabIndex = 4;
            this.label1.Text = "Log In";
            // 
            // tabPassword
            // 
            this.tabPassword.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.tabPassword.Controls.Add(this.label5);
            this.tabPassword.Controls.Add(this.textPassword);
            this.tabPassword.ForeColor = System.Drawing.Color.Black;
            this.tabPassword.Location = new System.Drawing.Point(4, 25);
            this.tabPassword.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tabPassword.Name = "tabPassword";
            this.tabPassword.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tabPassword.Size = new System.Drawing.Size(948, 361);
            this.tabPassword.TabIndex = 3;
            this.tabPassword.Text = "Password";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Mongolian Baiti", 36F);
            this.label5.ForeColor = System.Drawing.Color.Black;
            this.label5.Location = new System.Drawing.Point(280, 66);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(402, 64);
            this.label5.TabIndex = 13;
            this.label5.Text = "Enter Password";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // textPassword
            // 
            this.textPassword.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textPassword.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.textPassword.Location = new System.Drawing.Point(320, 170);
            this.textPassword.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textPassword.Name = "textPassword";
            this.textPassword.Size = new System.Drawing.Size(339, 38);
            this.textPassword.TabIndex = 12;
            this.textPassword.TextChanged += new System.EventHandler(this.textPassword_TextChanged);
            // 
            // tabAccount
            // 
            this.tabAccount.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.tabAccount.Controls.Add(this.label4);
            this.tabAccount.Controls.Add(this.textAccount);
            this.tabAccount.ForeColor = System.Drawing.Color.Black;
            this.tabAccount.Location = new System.Drawing.Point(4, 25);
            this.tabAccount.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tabAccount.Name = "tabAccount";
            this.tabAccount.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tabAccount.Size = new System.Drawing.Size(948, 361);
            this.tabAccount.TabIndex = 2;
            this.tabAccount.Text = "Account";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Mongolian Baiti", 36F);
            this.label4.Location = new System.Drawing.Point(220, 55);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(515, 64);
            this.label4.TabIndex = 10;
            this.label4.Text = "Enter Your Account";
            // 
            // textAccount
            // 
            this.textAccount.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textAccount.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.textAccount.Location = new System.Drawing.Point(317, 158);
            this.textAccount.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textAccount.Name = "textAccount";
            this.textAccount.Size = new System.Drawing.Size(339, 38);
            this.textAccount.TabIndex = 9;
            this.textAccount.TextChanged += new System.EventHandler(this.textAccount_TextChanged);
            // 
            // tabFontScreen
            // 
            this.tabFontScreen.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.tabFontScreen.Controls.Add(this.button5);
            this.tabFontScreen.Controls.Add(this.label3);
            this.tabFontScreen.ForeColor = System.Drawing.Color.Black;
            this.tabFontScreen.Location = new System.Drawing.Point(4, 25);
            this.tabFontScreen.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabFontScreen.Name = "tabFontScreen";
            this.tabFontScreen.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabFontScreen.Size = new System.Drawing.Size(948, 361);
            this.tabFontScreen.TabIndex = 1;
            this.tabFontScreen.Text = "Font Screen";
            this.tabFontScreen.Click += new System.EventHandler(this.tabPage2_Click);
            // 
            // button5
            // 
            this.button5.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.button5.Font = new System.Drawing.Font("Leelawadee UI", 19.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.Location = new System.Drawing.Point(351, 160);
            this.button5.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(248, 81);
            this.button5.TabIndex = 10;
            this.button5.Text = "Choice Font";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Mongolian Baiti", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(245, 57);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(462, 64);
            this.label3.TabIndex = 7;
            this.label3.Text = "Enter Screen Font";
            // 
            // btnNext
            // 
            this.btnNext.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnNext.Font = new System.Drawing.Font("Leelawadee UI", 19.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnNext.Location = new System.Drawing.Point(837, 548);
            this.btnNext.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnNext.Name = "btnNext";
            this.btnNext.Size = new System.Drawing.Size(197, 63);
            this.btnNext.TabIndex = 5;
            this.btnNext.Text = "Next";
            this.btnNext.UseVisualStyleBackColor = true;
            this.btnNext.Click += new System.EventHandler(this.btnNext_Click);
            // 
            // tabColorScreen
            // 
            this.tabColorScreen.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.tabColorScreen.Controls.Add(this.btnChoiceColor);
            this.tabColorScreen.Controls.Add(this.label2);
            this.tabColorScreen.ForeColor = System.Drawing.Color.Black;
            this.tabColorScreen.Location = new System.Drawing.Point(4, 25);
            this.tabColorScreen.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabColorScreen.Name = "tabColorScreen";
            this.tabColorScreen.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabColorScreen.Size = new System.Drawing.Size(948, 361);
            this.tabColorScreen.TabIndex = 0;
            this.tabColorScreen.Text = "Color Screen";
            this.tabColorScreen.Click += new System.EventHandler(this.tabPage1_Click_1);
            // 
            // btnChoiceColor
            // 
            this.btnChoiceColor.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnChoiceColor.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnChoiceColor.Font = new System.Drawing.Font("Leelawadee UI", 19.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnChoiceColor.Location = new System.Drawing.Point(361, 158);
            this.btnChoiceColor.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnChoiceColor.Name = "btnChoiceColor";
            this.btnChoiceColor.Size = new System.Drawing.Size(248, 81);
            this.btnChoiceColor.TabIndex = 5;
            this.btnChoiceColor.Text = "Choice Color";
            this.btnChoiceColor.UseVisualStyleBackColor = true;
            this.btnChoiceColor.Click += new System.EventHandler(this.btnChoiceColor_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Mongolian Baiti", 36F);
            this.label2.Location = new System.Drawing.Point(237, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(489, 64);
            this.label2.TabIndex = 4;
            this.label2.Text = "Enter Screen Color";
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabColorScreen);
            this.tabControl1.Controls.Add(this.tabFontScreen);
            this.tabControl1.Controls.Add(this.tabAccount);
            this.tabControl1.Controls.Add(this.tabPassword);
            this.tabControl1.Controls.Add(this.tabResult);
            this.tabControl1.Location = new System.Drawing.Point(79, 122);
            this.tabControl1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(956, 390);
            this.tabControl1.TabIndex = 0;
            this.tabControl1.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // tabResult
            // 
            this.tabResult.BackColor = System.Drawing.Color.Red;
            this.tabResult.Controls.Add(this.label6);
            this.tabResult.ForeColor = System.Drawing.Color.Black;
            this.tabResult.Location = new System.Drawing.Point(4, 25);
            this.tabResult.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tabResult.Name = "tabResult";
            this.tabResult.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tabResult.Size = new System.Drawing.Size(948, 361);
            this.tabResult.TabIndex = 4;
            this.tabResult.Text = "Result";
            this.tabResult.Click += new System.EventHandler(this.Result_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Mongolian Baiti", 36F);
            this.label6.ForeColor = System.Drawing.Color.Black;
            this.label6.Location = new System.Drawing.Point(281, 135);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(402, 64);
            this.label6.TabIndex = 13;
            this.label6.Text = "Enter Password";
            // 
            // btnBack
            // 
            this.btnBack.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnBack.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnBack.Font = new System.Drawing.Font("Leelawadee UI", 19.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnBack.Location = new System.Drawing.Point(79, 558);
            this.btnBack.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnBack.Name = "btnBack";
            this.btnBack.Size = new System.Drawing.Size(197, 63);
            this.btnBack.TabIndex = 12;
            this.btnBack.Text = "Back";
            this.btnBack.UseVisualStyleBackColor = true;
            this.btnBack.Click += new System.EventHandler(this.btnBack_Click);
            // 
            // btnSaveFile
            // 
            this.btnSaveFile.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnSaveFile.Font = new System.Drawing.Font("Leelawadee UI", 19.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSaveFile.Location = new System.Drawing.Point(589, 537);
            this.btnSaveFile.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnSaveFile.Name = "btnSaveFile";
            this.btnSaveFile.Size = new System.Drawing.Size(197, 63);
            this.btnSaveFile.TabIndex = 13;
            this.btnSaveFile.Text = "Save File";
            this.btnSaveFile.UseVisualStyleBackColor = true;
            this.btnSaveFile.Click += new System.EventHandler(this.btnSaveFile_Click);
            // 
            // btnOpenFile
            // 
            this.btnOpenFile.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnOpenFile.Font = new System.Drawing.Font("Leelawadee UI", 19.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnOpenFile.Location = new System.Drawing.Point(316, 610);
            this.btnOpenFile.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnOpenFile.Name = "btnOpenFile";
            this.btnOpenFile.Size = new System.Drawing.Size(219, 63);
            this.btnOpenFile.TabIndex = 14;
            this.btnOpenFile.Text = "Open File";
            this.btnOpenFile.UseVisualStyleBackColor = true;
            this.btnOpenFile.Click += new System.EventHandler(this.btnOpenFile_Click);
            // 
            // btnMultiOpenFile
            // 
            this.btnMultiOpenFile.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnMultiOpenFile.Font = new System.Drawing.Font("Leelawadee UI", 18F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMultiOpenFile.Location = new System.Drawing.Point(543, 610);
            this.btnMultiOpenFile.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnMultiOpenFile.Name = "btnMultiOpenFile";
            this.btnMultiOpenFile.Size = new System.Drawing.Size(243, 63);
            this.btnMultiOpenFile.TabIndex = 15;
            this.btnMultiOpenFile.Text = "Multi Open File";
            this.btnMultiOpenFile.UseVisualStyleBackColor = true;
            this.btnMultiOpenFile.Click += new System.EventHandler(this.btnMultiOpenFile_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // btnBrowsingFolder
            // 
            this.btnBrowsingFolder.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnBrowsingFolder.Font = new System.Drawing.Font("Leelawadee UI", 16.2F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnBrowsingFolder.Location = new System.Drawing.Point(316, 533);
            this.btnBrowsingFolder.Margin = new System.Windows.Forms.Padding(4);
            this.btnBrowsingFolder.Name = "btnBrowsingFolder";
            this.btnBrowsingFolder.Size = new System.Drawing.Size(230, 74);
            this.btnBrowsingFolder.TabIndex = 16;
            this.btnBrowsingFolder.Text = "Browsing Folder";
            this.btnBrowsingFolder.UseVisualStyleBackColor = true;
            this.btnBrowsingFolder.Click += new System.EventHandler(this.btnBrowsingFolder_Click);
            // 
            // frmTabControl
            // 
            this.AcceptButton = this.btnNext;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1145, 713);
            this.Controls.Add(this.btnBrowsingFolder);
            this.Controls.Add(this.btnMultiOpenFile);
            this.Controls.Add(this.btnOpenFile);
            this.Controls.Add(this.btnSaveFile);
            this.Controls.Add(this.btnBack);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.btnNext);
            this.ForeColor = System.Drawing.Color.Black;
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "frmTabControl";
            this.Text = "TabControl";
            this.Load += new System.EventHandler(this.frmTabControl_Load);
            this.tabPassword.ResumeLayout(false);
            this.tabPassword.PerformLayout();
            this.tabAccount.ResumeLayout(false);
            this.tabAccount.PerformLayout();
            this.tabFontScreen.ResumeLayout(false);
            this.tabFontScreen.PerformLayout();
            this.tabColorScreen.ResumeLayout(false);
            this.tabColorScreen.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabResult.ResumeLayout(false);
            this.tabResult.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.FontDialog fontDialog1;
        private System.Windows.Forms.TabPage tabPassword;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textPassword;
        private System.Windows.Forms.TabPage tabAccount;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textAccount;
        private System.Windows.Forms.TabPage tabFontScreen;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnNext;
        private System.Windows.Forms.TabPage tabColorScreen;
        private System.Windows.Forms.Button btnChoiceColor;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabResult;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btnBack;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Button btnSaveFile;
        private System.Windows.Forms.Button btnOpenFile;
        private System.Windows.Forms.Button btnMultiOpenFile;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button btnBrowsingFolder;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog1;
    }
}