namespace MyCalculator
{
    partial class Form1
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
            this.Screen = new System.Windows.Forms.MaskedTextBox();
            this.Result = new System.Windows.Forms.Button();
            this.zero = new System.Windows.Forms.Button();
            this.Dote = new System.Windows.Forms.Button();
            this.plusOrMinusToggle = new System.Windows.Forms.Button();
            this.Add = new System.Windows.Forms.Button();
            this.Sub = new System.Windows.Forms.Button();
            this.Back = new System.Windows.Forms.Button();
            this.Multiplication = new System.Windows.Forms.Button();
            this.Divison = new System.Windows.Forms.Button();
            this.Clear = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Screen
            // 
            this.Screen.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.Screen.BackColor = System.Drawing.Color.Silver;
            this.Screen.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Screen.Font = new System.Drawing.Font("Microsoft Sans Serif", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Screen.Location = new System.Drawing.Point(16, 23);
            this.Screen.Margin = new System.Windows.Forms.Padding(3, 3, 3, 5);
            this.Screen.Name = "Screen";
            this.Screen.ReadOnly = true;
            this.Screen.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Screen.Size = new System.Drawing.Size(500, 98);
            this.Screen.TabIndex = 0;
            this.Screen.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // Result
            // 
            this.Result.BackColor = System.Drawing.Color.Yellow;
            this.Result.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.Result.FlatAppearance.BorderSize = 4;
            this.Result.FlatAppearance.CheckedBackColor = System.Drawing.Color.Yellow;
            this.Result.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DarkGoldenrod;
            this.Result.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Result.Font = new System.Drawing.Font("Microsoft Sans Serif", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Result.Location = new System.Drawing.Point(412, 400);
            this.Result.Name = "Result";
            this.Result.Size = new System.Drawing.Size(98, 110);
            this.Result.TabIndex = 1;
            this.Result.Text = "=";
            this.Result.UseVisualStyleBackColor = false;
            this.Result.Click += new System.EventHandler(this.Result_Click);
            // 
            // zero
            // 
            this.zero.Font = new System.Drawing.Font("Microsoft Sans Serif", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.zero.Location = new System.Drawing.Point(126, 440);
            this.zero.Name = "zero";
            this.zero.Size = new System.Drawing.Size(148, 70);
            this.zero.TabIndex = 2;
            this.zero.Text = "0";
            this.zero.UseVisualStyleBackColor = true;
            this.zero.Click += new System.EventHandler(this.zero_Click);
            // 
            // Dote
            // 
            this.Dote.Font = new System.Drawing.Font("Microsoft Sans Serif", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Dote.Location = new System.Drawing.Point(291, 439);
            this.Dote.Name = "Dote";
            this.Dote.Size = new System.Drawing.Size(104, 69);
            this.Dote.TabIndex = 3;
            this.Dote.Text = ".";
            this.Dote.UseVisualStyleBackColor = true;
            this.Dote.Click += new System.EventHandler(this.Dote_Click);
            // 
            // plusOrMinusToggle
            // 
            this.plusOrMinusToggle.Font = new System.Drawing.Font("Microsoft Sans Serif", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.plusOrMinusToggle.Location = new System.Drawing.Point(5, 439);
            this.plusOrMinusToggle.Name = "plusOrMinusToggle";
            this.plusOrMinusToggle.Size = new System.Drawing.Size(104, 69);
            this.plusOrMinusToggle.TabIndex = 4;
            this.plusOrMinusToggle.Text = "+/-";
            this.plusOrMinusToggle.UseVisualStyleBackColor = true;
            this.plusOrMinusToggle.Click += new System.EventHandler(this.plusOrMinusToggle_Click);
            // 
            // Add
            // 
            this.Add.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.Add.BackColor = System.Drawing.Color.Yellow;
            this.Add.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.Add.FlatAppearance.BorderSize = 4;
            this.Add.FlatAppearance.CheckedBackColor = System.Drawing.Color.Yellow;
            this.Add.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DarkGoldenrod;
            this.Add.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Add.Font = new System.Drawing.Font("Microsoft Sans Serif", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Add.Location = new System.Drawing.Point(415, 301);
            this.Add.Name = "Add";
            this.Add.Size = new System.Drawing.Size(97, 80);
            this.Add.TabIndex = 5;
            this.Add.Text = "+";
            this.Add.UseVisualStyleBackColor = false;
            this.Add.Click += new System.EventHandler(this.Add_Click);
            // 
            // Sub
            // 
            this.Sub.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.Sub.BackColor = System.Drawing.Color.Yellow;
            this.Sub.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.Sub.FlatAppearance.BorderSize = 4;
            this.Sub.FlatAppearance.CheckedBackColor = System.Drawing.Color.Yellow;
            this.Sub.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DarkGoldenrod;
            this.Sub.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Sub.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Sub.Location = new System.Drawing.Point(415, 226);
            this.Sub.Name = "Sub";
            this.Sub.Size = new System.Drawing.Size(97, 56);
            this.Sub.TabIndex = 6;
            this.Sub.Text = "-";
            this.Sub.UseVisualStyleBackColor = false;
            this.Sub.Click += new System.EventHandler(this.Sub_Click);
            // 
            // Back
            // 
            this.Back.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Back.Location = new System.Drawing.Point(415, 151);
            this.Back.Name = "Back";
            this.Back.Size = new System.Drawing.Size(97, 56);
            this.Back.TabIndex = 7;
            this.Back.Text = "B";
            this.Back.UseVisualStyleBackColor = true;
            this.Back.Click += new System.EventHandler(this.Back_Click_1);
            // 
            // Multiplication
            // 
            this.Multiplication.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.Multiplication.BackColor = System.Drawing.Color.Yellow;
            this.Multiplication.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.Multiplication.FlatAppearance.BorderSize = 4;
            this.Multiplication.FlatAppearance.CheckedBackColor = System.Drawing.Color.Yellow;
            this.Multiplication.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DarkGoldenrod;
            this.Multiplication.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Multiplication.Font = new System.Drawing.Font("Microsoft Tai Le", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Multiplication.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.Multiplication.Location = new System.Drawing.Point(165, 151);
            this.Multiplication.Name = "Multiplication";
            this.Multiplication.Size = new System.Drawing.Size(97, 56);
            this.Multiplication.TabIndex = 8;
            this.Multiplication.Text = "x";
            this.Multiplication.UseVisualStyleBackColor = false;
            this.Multiplication.Click += new System.EventHandler(this.Multiplication_Click);
            // 
            // Divison
            // 
            this.Divison.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.Divison.BackColor = System.Drawing.Color.Yellow;
            this.Divison.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.Divison.FlatAppearance.BorderSize = 4;
            this.Divison.FlatAppearance.CheckedBackColor = System.Drawing.Color.Yellow;
            this.Divison.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DarkGoldenrod;
            this.Divison.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Divison.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Divison.Location = new System.Drawing.Point(290, 151);
            this.Divison.Name = "Divison";
            this.Divison.Size = new System.Drawing.Size(97, 56);
            this.Divison.TabIndex = 9;
            this.Divison.Text = "÷";
            this.Divison.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.Divison.UseVisualStyleBackColor = false;
            this.Divison.Click += new System.EventHandler(this.Divison_Click);
            // 
            // Clear
            // 
            this.Clear.BackColor = System.Drawing.Color.White;
            this.Clear.BackgroundImage = global::MyCalculator.Properties.Resources.files;
            this.Clear.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.Clear.FlatAppearance.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.Clear.FlatAppearance.BorderSize = 4;
            this.Clear.FlatAppearance.CheckedBackColor = System.Drawing.Color.Yellow;
            this.Clear.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DarkGoldenrod;
            this.Clear.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.Clear.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Clear.Location = new System.Drawing.Point(12, 151);
            this.Clear.Name = "Clear";
            this.Clear.Size = new System.Drawing.Size(125, 56);
            this.Clear.TabIndex = 10;
            this.Clear.Text = "CE";
            this.Clear.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.Clear.UseVisualStyleBackColor = false;
            this.Clear.Click += new System.EventHandler(this.Clear_Click);
            // 
            // button1
            // 
            this.button1.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button1.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button1.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button1.Location = new System.Drawing.Point(12, 367);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(97, 56);
            this.button1.TabIndex = 11;
            this.button1.Text = "1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button2.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button2.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button2.Location = new System.Drawing.Point(149, 367);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(97, 56);
            this.button2.TabIndex = 12;
            this.button2.Text = "2";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button3.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button3.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button3.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button3.Location = new System.Drawing.Point(286, 367);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(97, 56);
            this.button3.TabIndex = 13;
            this.button3.Text = "3";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button4.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button4.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button4.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button4.Location = new System.Drawing.Point(12, 300);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(97, 56);
            this.button4.TabIndex = 14;
            this.button4.Text = "4";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button5.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button5.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button5.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button5.Location = new System.Drawing.Point(149, 300);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(97, 56);
            this.button5.TabIndex = 15;
            this.button5.Text = "5";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button6.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button6.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button6.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button6.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button6.Location = new System.Drawing.Point(286, 300);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(97, 56);
            this.button6.TabIndex = 16;
            this.button6.Text = "6";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button7
            // 
            this.button7.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button7.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button7.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button7.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button7.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button7.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button7.Location = new System.Drawing.Point(12, 233);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(97, 56);
            this.button7.TabIndex = 17;
            this.button7.Text = "7";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // button8
            // 
            this.button8.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button8.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button8.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button8.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button8.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button8.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button8.Location = new System.Drawing.Point(149, 233);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(97, 56);
            this.button8.TabIndex = 18;
            this.button8.Text = "8";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // button9
            // 
            this.button9.FlatAppearance.CheckedBackColor = System.Drawing.Color.Silver;
            this.button9.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.button9.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.button9.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button9.Font = new System.Drawing.Font("Microsoft Tai Le", 25.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button9.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button9.Location = new System.Drawing.Point(286, 233);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(97, 56);
            this.button9.TabIndex = 19;
            this.button9.Text = "9";
            this.button9.UseVisualStyleBackColor = true;
            this.button9.Click += new System.EventHandler(this.button9_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(530, 519);
            this.Controls.Add(this.button9);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button7);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Clear);
            this.Controls.Add(this.Divison);
            this.Controls.Add(this.Multiplication);
            this.Controls.Add(this.Back);
            this.Controls.Add(this.Sub);
            this.Controls.Add(this.Add);
            this.Controls.Add(this.plusOrMinusToggle);
            this.Controls.Add(this.Dote);
            this.Controls.Add(this.zero);
            this.Controls.Add(this.Result);
            this.Controls.Add(this.Screen);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MaskedTextBox Screen;
        private System.Windows.Forms.Button Result;
        private System.Windows.Forms.Button zero;
        private System.Windows.Forms.Button Dote;
        private System.Windows.Forms.Button plusOrMinusToggle;
        private System.Windows.Forms.Button Add;
        private System.Windows.Forms.Button Sub;
        private System.Windows.Forms.Button Back;
        private System.Windows.Forms.Button Multiplication;
        private System.Windows.Forms.Button Divison;
        private System.Windows.Forms.Button Clear;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button9;
    }
}

