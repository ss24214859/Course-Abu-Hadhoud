namespace WindowsFormsApp1
{
    partial class frmCheckedListBox
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
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            this.btnAddItem = new System.Windows.Forms.Button();
            this.btnShowSlectedItems = new System.Windows.Forms.Button();
            this.btnCheckAllItems = new System.Windows.Forms.Button();
            this.btnUnCheckAllItems = new System.Windows.Forms.Button();
            this.btnRemoveItem = new System.Windows.Forms.Button();
            this.btnRemoveAllItems = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Location = new System.Drawing.Point(282, 40);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.Size = new System.Drawing.Size(267, 191);
            this.checkedListBox1.TabIndex = 0;
            this.checkedListBox1.SelectedIndexChanged += new System.EventHandler(this.checkedListBox1_SelectedIndexChanged);
            // 
            // btnAddItem
            // 
            this.btnAddItem.Location = new System.Drawing.Point(117, 276);
            this.btnAddItem.Name = "btnAddItem";
            this.btnAddItem.Size = new System.Drawing.Size(121, 59);
            this.btnAddItem.TabIndex = 1;
            this.btnAddItem.Text = "Add Item";
            this.btnAddItem.UseVisualStyleBackColor = true;
            this.btnAddItem.Click += new System.EventHandler(this.btnAddItem_Click);
            // 
            // btnShowSlectedItems
            // 
            this.btnShowSlectedItems.Location = new System.Drawing.Point(343, 276);
            this.btnShowSlectedItems.Name = "btnShowSlectedItems";
            this.btnShowSlectedItems.Size = new System.Drawing.Size(158, 59);
            this.btnShowSlectedItems.TabIndex = 2;
            this.btnShowSlectedItems.Text = "Show Selected Items";
            this.btnShowSlectedItems.UseVisualStyleBackColor = true;
            this.btnShowSlectedItems.Click += new System.EventHandler(this.btnShowSlectedItems_Click);
            // 
            // btnCheckAllItems
            // 
            this.btnCheckAllItems.Location = new System.Drawing.Point(607, 276);
            this.btnCheckAllItems.Name = "btnCheckAllItems";
            this.btnCheckAllItems.Size = new System.Drawing.Size(158, 62);
            this.btnCheckAllItems.TabIndex = 3;
            this.btnCheckAllItems.Text = "Check All Items";
            this.btnCheckAllItems.UseVisualStyleBackColor = true;
            this.btnCheckAllItems.Click += new System.EventHandler(this.btnCheckAllItems_Click);
            // 
            // btnUnCheckAllItems
            // 
            this.btnUnCheckAllItems.Location = new System.Drawing.Point(607, 356);
            this.btnUnCheckAllItems.Name = "btnUnCheckAllItems";
            this.btnUnCheckAllItems.Size = new System.Drawing.Size(158, 62);
            this.btnUnCheckAllItems.TabIndex = 4;
            this.btnUnCheckAllItems.Text = "UnCheck All Items";
            this.btnUnCheckAllItems.UseVisualStyleBackColor = true;
            this.btnUnCheckAllItems.Click += new System.EventHandler(this.btnUnCheckAllItems_Click);
            // 
            // btnRemoveItem
            // 
            this.btnRemoveItem.Location = new System.Drawing.Point(117, 376);
            this.btnRemoveItem.Name = "btnRemoveItem";
            this.btnRemoveItem.Size = new System.Drawing.Size(121, 62);
            this.btnRemoveItem.TabIndex = 5;
            this.btnRemoveItem.Text = "Remove Item";
            this.btnRemoveItem.UseVisualStyleBackColor = true;
            this.btnRemoveItem.Click += new System.EventHandler(this.btnRemoveItem_Click);
            // 
            // btnRemoveAllItems
            // 
            this.btnRemoveAllItems.Location = new System.Drawing.Point(343, 376);
            this.btnRemoveAllItems.Name = "btnRemoveAllItems";
            this.btnRemoveAllItems.Size = new System.Drawing.Size(121, 62);
            this.btnRemoveAllItems.TabIndex = 6;
            this.btnRemoveAllItems.Text = "Remove All Items";
            this.btnRemoveAllItems.UseVisualStyleBackColor = true;
            this.btnRemoveAllItems.Click += new System.EventHandler(this.btnRemoveAllItems_Click);
            // 
            // frmCheckedListBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnRemoveAllItems);
            this.Controls.Add(this.btnRemoveItem);
            this.Controls.Add(this.btnUnCheckAllItems);
            this.Controls.Add(this.btnCheckAllItems);
            this.Controls.Add(this.btnShowSlectedItems);
            this.Controls.Add(this.btnAddItem);
            this.Controls.Add(this.checkedListBox1);
            this.Name = "frmCheckedListBox";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.CheckedListBox checkedListBox1;
        private System.Windows.Forms.Button btnAddItem;
        private System.Windows.Forms.Button btnShowSlectedItems;
        private System.Windows.Forms.Button btnCheckAllItems;
        private System.Windows.Forms.Button btnUnCheckAllItems;
        private System.Windows.Forms.Button btnRemoveItem;
        private System.Windows.Forms.Button btnRemoveAllItems;
    }
}