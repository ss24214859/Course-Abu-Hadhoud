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
            this.btnCountYourAge = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.btnLinkLable = new System.Windows.Forms.Button();
            this.btnCheckedListBox = new System.Windows.Forms.Button();
            this.btnMonthCalandar = new System.Windows.Forms.Button();
            this.btnTreeView = new System.Windows.Forms.Button();
            this.btnListView = new System.Windows.Forms.Button();
            this.btnTabControl = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnChoicePhoto
            // 
            this.btnChoicePhoto.Location = new System.Drawing.Point(44, 17);
            this.btnChoicePhoto.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnChoicePhoto.Name = "btnChoicePhoto";
            this.btnChoicePhoto.Size = new System.Drawing.Size(100, 75);
            this.btnChoicePhoto.TabIndex = 0;
            this.btnChoicePhoto.Text = "Choice Photo";
            this.btnChoicePhoto.UseVisualStyleBackColor = true;
            this.btnChoicePhoto.Click += new System.EventHandler(this.btnChoicePhoto_Click);
            // 
            // btnCountYourAge
            // 
            this.btnCountYourAge.Location = new System.Drawing.Point(447, 14);
            this.btnCountYourAge.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnCountYourAge.Name = "btnCountYourAge";
            this.btnCountYourAge.Size = new System.Drawing.Size(153, 80);
            this.btnCountYourAge.TabIndex = 1;
            this.btnCountYourAge.Text = "Count your Age";
            this.btnCountYourAge.UseVisualStyleBackColor = true;
            this.btnCountYourAge.Click += new System.EventHandler(this.btnMaskedTextBox_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(44, 98);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(100, 75);
            this.button1.TabIndex = 2;
            this.button1.Text = "Choice Photo 2";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnLinkLable
            // 
            this.btnLinkLable.Location = new System.Drawing.Point(195, 17);
            this.btnLinkLable.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnLinkLable.Name = "btnLinkLable";
            this.btnLinkLable.Size = new System.Drawing.Size(100, 75);
            this.btnLinkLable.TabIndex = 3;
            this.btnLinkLable.Text = "Link Lable";
            this.btnLinkLable.UseVisualStyleBackColor = true;
            this.btnLinkLable.Click += new System.EventHandler(this.btnLinkLable_Click);
            // 
            // btnCheckedListBox
            // 
            this.btnCheckedListBox.Location = new System.Drawing.Point(187, 98);
            this.btnCheckedListBox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnCheckedListBox.Name = "btnCheckedListBox";
            this.btnCheckedListBox.Size = new System.Drawing.Size(205, 75);
            this.btnCheckedListBox.TabIndex = 4;
            this.btnCheckedListBox.Text = "CheckedListBox";
            this.btnCheckedListBox.UseVisualStyleBackColor = true;
            this.btnCheckedListBox.Click += new System.EventHandler(this.btnCheckedListBox_Click);
            // 
            // btnMonthCalandar
            // 
            this.btnMonthCalandar.Location = new System.Drawing.Point(447, 100);
            this.btnMonthCalandar.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnMonthCalandar.Name = "btnMonthCalandar";
            this.btnMonthCalandar.Size = new System.Drawing.Size(153, 80);
            this.btnMonthCalandar.TabIndex = 5;
            this.btnMonthCalandar.Text = "MonthCalandar";
            this.btnMonthCalandar.UseVisualStyleBackColor = true;
            this.btnMonthCalandar.Click += new System.EventHandler(this.btnMonthCalandar_Click);
            // 
            // btnTreeView
            // 
            this.btnTreeView.Location = new System.Drawing.Point(44, 242);
            this.btnTreeView.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnTreeView.Name = "btnTreeView";
            this.btnTreeView.Size = new System.Drawing.Size(153, 80);
            this.btnTreeView.TabIndex = 6;
            this.btnTreeView.Text = "Tree View";
            this.btnTreeView.UseVisualStyleBackColor = true;
            this.btnTreeView.Click += new System.EventHandler(this.btnTimer_Click);
            // 
            // btnListView
            // 
            this.btnListView.Location = new System.Drawing.Point(296, 249);
            this.btnListView.Name = "btnListView";
            this.btnListView.Size = new System.Drawing.Size(177, 66);
            this.btnListView.TabIndex = 7;
            this.btnListView.Text = "List View &&  Error Provider";
            this.btnListView.UseVisualStyleBackColor = true;
            this.btnListView.Click += new System.EventHandler(this.btnListView_Click);
            // 
            // btnTabControl
            // 
            this.btnTabControl.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnTabControl.Location = new System.Drawing.Point(510, 242);
            this.btnTabControl.Name = "btnTabControl";
            this.btnTabControl.Size = new System.Drawing.Size(222, 85);
            this.btnTabControl.TabIndex = 8;
            this.btnTabControl.Text = "Dialog Controls In Tab";
            this.btnTabControl.UseVisualStyleBackColor = true;
            this.btnTabControl.Click += new System.EventHandler(this.btnTabControl_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnTabControl);
            this.Controls.Add(this.btnListView);
            this.Controls.Add(this.btnTreeView);
            this.Controls.Add(this.btnMonthCalandar);
            this.Controls.Add(this.btnCheckedListBox);
            this.Controls.Add(this.btnLinkLable);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnCountYourAge);
            this.Controls.Add(this.btnChoicePhoto);
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "frmMain";
            this.Text = "Main";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnChoicePhoto;
        private System.Windows.Forms.Button btnCountYourAge;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button btnLinkLable;
        private System.Windows.Forms.Button btnCheckedListBox;
        private System.Windows.Forms.Button btnMonthCalandar;
        private System.Windows.Forms.Button btnTreeView;
        private System.Windows.Forms.Button btnListView;
        private System.Windows.Forms.Button btnTabControl;
    }
}