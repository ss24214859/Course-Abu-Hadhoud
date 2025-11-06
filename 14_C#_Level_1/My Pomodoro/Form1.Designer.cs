namespace My_Pomodoro
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.tmTimer = new System.Windows.Forms.Timer(this.components);
            this.lblTimer = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.notifyIcon1 = new System.Windows.Forms.NotifyIcon(this.components);
            this.btnPomodoro = new System.Windows.Forms.Button();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.setTimeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.Min10 = new System.Windows.Forms.ToolStripMenuItem();
            this.Min15 = new System.Windows.Forms.ToolStripMenuItem();
            this.Min20 = new System.Windows.Forms.ToolStripMenuItem();
            this.Min25 = new System.Windows.Forms.ToolStripMenuItem();
            this.Min30 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.minToolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.minToolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.minToolStripMenuItem5 = new System.Windows.Forms.ToolStripMenuItem();
            this.minToolStripMenuItem6 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.restToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.setColorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.restColorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnShortBreak = new System.Windows.Forms.Button();
            this.btnLongBreak = new System.Windows.Forms.Button();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.BackgroundImage = global::My_Pomodoro.Properties.Resources.empty_circle_clock_w;
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.pictureBox1.InitialImage = null;
            this.pictureBox1.Location = new System.Drawing.Point(149, 115);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(500, 369);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // tmTimer
            // 
            this.tmTimer.Interval = 1000;
            this.tmTimer.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // lblTimer
            // 
            this.lblTimer.BackColor = System.Drawing.Color.Transparent;
            this.lblTimer.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.lblTimer.Font = new System.Drawing.Font("Microsoft Sans Serif", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTimer.Location = new System.Drawing.Point(334, 264);
            this.lblTimer.Name = "lblTimer";
            this.lblTimer.Size = new System.Drawing.Size(151, 44);
            this.lblTimer.TabIndex = 1;
            this.lblTimer.Text = "00:00";
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.Black;
            this.btnStart.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnStart.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnStart.Font = new System.Drawing.Font("Microsoft JhengHei", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStart.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btnStart.Location = new System.Drawing.Point(183, 510);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(143, 53);
            this.btnStart.TabIndex = 2;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnStop
            // 
            this.btnStop.BackColor = System.Drawing.Color.Black;
            this.btnStop.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnStop.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnStop.Font = new System.Drawing.Font("Microsoft JhengHei", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStop.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btnStop.Location = new System.Drawing.Point(492, 510);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(143, 53);
            this.btnStop.TabIndex = 3;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = false;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnReset
            // 
            this.btnReset.BackColor = System.Drawing.Color.Black;
            this.btnReset.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnReset.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnReset.Font = new System.Drawing.Font("Microsoft JhengHei", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnReset.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btnReset.Location = new System.Drawing.Point(363, 491);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(92, 53);
            this.btnReset.TabIndex = 4;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = false;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // notifyIcon1
            // 
            this.notifyIcon1.BalloonTipText = "Time out ";
            this.notifyIcon1.BalloonTipTitle = "My Pomodoro";
            this.notifyIcon1.Icon = ((System.Drawing.Icon)(resources.GetObject("notifyIcon1.Icon")));
            this.notifyIcon1.Text = "My Pomodoro";
            this.notifyIcon1.Visible = true;
            // 
            // btnPomodoro
            // 
            this.btnPomodoro.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.btnPomodoro.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnPomodoro.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnPomodoro.FlatAppearance.BorderSize = 6;
            this.btnPomodoro.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnPomodoro.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnPomodoro.Font = new System.Drawing.Font("Microsoft JhengHei", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPomodoro.ForeColor = System.Drawing.Color.Transparent;
            this.btnPomodoro.Location = new System.Drawing.Point(170, 37);
            this.btnPomodoro.Name = "btnPomodoro";
            this.btnPomodoro.Size = new System.Drawing.Size(143, 53);
            this.btnPomodoro.TabIndex = 5;
            this.btnPomodoro.Text = "Pomodoro";
            this.btnPomodoro.UseVisualStyleBackColor = false;
            this.btnPomodoro.Click += new System.EventHandler(this.ChangeMode);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.setTimeToolStripMenuItem,
            this.restToolStripMenuItem,
            this.toolStripSeparator1,
            this.setColorToolStripMenuItem,
            this.restColorToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(181, 128);
            this.contextMenuStrip1.Opening += new System.ComponentModel.CancelEventHandler(this.contextMenuStrip1_Opening);
            // 
            // setTimeToolStripMenuItem
            // 
            this.setTimeToolStripMenuItem.BackColor = System.Drawing.Color.Black;
            this.setTimeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Min10,
            this.Min15,
            this.Min20,
            this.Min25,
            this.Min30,
            this.toolStripMenuItem1,
            this.minToolStripMenuItem3,
            this.minToolStripMenuItem4,
            this.minToolStripMenuItem5,
            this.minToolStripMenuItem6,
            this.toolStripMenuItem2,
            this.toolStripMenuItem3});
            this.setTimeToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.setTimeToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.setTimeToolStripMenuItem.Name = "setTimeToolStripMenuItem";
            this.setTimeToolStripMenuItem.Size = new System.Drawing.Size(180, 24);
            this.setTimeToolStripMenuItem.Text = "Set Time";
            // 
            // Min10
            // 
            this.Min10.Name = "Min10";
            this.Min10.Size = new System.Drawing.Size(180, 24);
            this.Min10.Tag = "10";
            this.Min10.Text = "10 Min";
            this.Min10.Click += new System.EventHandler(this.SetTime);
            // 
            // Min15
            // 
            this.Min15.Name = "Min15";
            this.Min15.Size = new System.Drawing.Size(180, 24);
            this.Min15.Tag = "15";
            this.Min15.Text = "15 Min";
            this.Min15.Click += new System.EventHandler(this.SetTime);
            // 
            // Min20
            // 
            this.Min20.Name = "Min20";
            this.Min20.Size = new System.Drawing.Size(180, 24);
            this.Min20.Tag = "20";
            this.Min20.Text = "20 Min";
            this.Min20.Click += new System.EventHandler(this.SetTime);
            // 
            // Min25
            // 
            this.Min25.Name = "Min25";
            this.Min25.Size = new System.Drawing.Size(180, 24);
            this.Min25.Tag = "25";
            this.Min25.Text = "25 Min";
            this.Min25.Click += new System.EventHandler(this.SetTime);
            // 
            // Min30
            // 
            this.Min30.Name = "Min30";
            this.Min30.Size = new System.Drawing.Size(180, 24);
            this.Min30.Tag = "30";
            this.Min30.Text = "30 Min";
            this.Min30.Click += new System.EventHandler(this.SetTime);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(180, 24);
            this.toolStripMenuItem1.Tag = "35";
            this.toolStripMenuItem1.Text = "35 Min";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.SetTime);
            // 
            // minToolStripMenuItem3
            // 
            this.minToolStripMenuItem3.Name = "minToolStripMenuItem3";
            this.minToolStripMenuItem3.Size = new System.Drawing.Size(180, 24);
            this.minToolStripMenuItem3.Tag = "40";
            this.minToolStripMenuItem3.Text = "40 Min";
            this.minToolStripMenuItem3.Click += new System.EventHandler(this.SetTime);
            // 
            // minToolStripMenuItem4
            // 
            this.minToolStripMenuItem4.Name = "minToolStripMenuItem4";
            this.minToolStripMenuItem4.Size = new System.Drawing.Size(180, 24);
            this.minToolStripMenuItem4.Tag = "45";
            this.minToolStripMenuItem4.Text = "45 Min";
            this.minToolStripMenuItem4.Click += new System.EventHandler(this.SetTime);
            // 
            // minToolStripMenuItem5
            // 
            this.minToolStripMenuItem5.Name = "minToolStripMenuItem5";
            this.minToolStripMenuItem5.Size = new System.Drawing.Size(180, 24);
            this.minToolStripMenuItem5.Tag = "50";
            this.minToolStripMenuItem5.Text = "50 Min";
            this.minToolStripMenuItem5.Click += new System.EventHandler(this.SetTime);
            // 
            // minToolStripMenuItem6
            // 
            this.minToolStripMenuItem6.Name = "minToolStripMenuItem6";
            this.minToolStripMenuItem6.Size = new System.Drawing.Size(180, 24);
            this.minToolStripMenuItem6.Tag = "60";
            this.minToolStripMenuItem6.Text = "60 Min";
            this.minToolStripMenuItem6.Click += new System.EventHandler(this.SetTime);
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(180, 24);
            this.toolStripMenuItem2.Tag = "70";
            this.toolStripMenuItem2.Text = "70 Min";
            this.toolStripMenuItem2.Click += new System.EventHandler(this.SetTime);
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size(180, 24);
            this.toolStripMenuItem3.Tag = "80";
            this.toolStripMenuItem3.Text = "80 Min";
            this.toolStripMenuItem3.Click += new System.EventHandler(this.SetTime);
            // 
            // restToolStripMenuItem
            // 
            this.restToolStripMenuItem.BackColor = System.Drawing.Color.Black;
            this.restToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.restToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.restToolStripMenuItem.Name = "restToolStripMenuItem";
            this.restToolStripMenuItem.Size = new System.Drawing.Size(180, 24);
            this.restToolStripMenuItem.Text = "RestTime";
            this.restToolStripMenuItem.Click += new System.EventHandler(this.restToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.BackColor = System.Drawing.Color.Black;
            this.toolStripSeparator1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(177, 6);
            // 
            // setColorToolStripMenuItem
            // 
            this.setColorToolStripMenuItem.BackColor = System.Drawing.Color.Black;
            this.setColorToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.setColorToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.setColorToolStripMenuItem.Name = "setColorToolStripMenuItem";
            this.setColorToolStripMenuItem.Size = new System.Drawing.Size(180, 24);
            this.setColorToolStripMenuItem.Text = "Set Color";
            this.setColorToolStripMenuItem.Click += new System.EventHandler(this.setColorToolStripMenuItem_Click);
            // 
            // restColorToolStripMenuItem
            // 
            this.restColorToolStripMenuItem.BackColor = System.Drawing.Color.Black;
            this.restColorToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.restColorToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.restColorToolStripMenuItem.Name = "restColorToolStripMenuItem";
            this.restColorToolStripMenuItem.Size = new System.Drawing.Size(180, 24);
            this.restColorToolStripMenuItem.Text = "Rest Color";
            this.restColorToolStripMenuItem.Click += new System.EventHandler(this.restColorToolStripMenuItem_Click);
            // 
            // btnShortBreak
            // 
            this.btnShortBreak.BackColor = System.Drawing.Color.LightSkyBlue;
            this.btnShortBreak.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnShortBreak.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnShortBreak.FlatAppearance.BorderSize = 6;
            this.btnShortBreak.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnShortBreak.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnShortBreak.Font = new System.Drawing.Font("Microsoft JhengHei", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShortBreak.ForeColor = System.Drawing.Color.Transparent;
            this.btnShortBreak.Location = new System.Drawing.Point(338, 37);
            this.btnShortBreak.Name = "btnShortBreak";
            this.btnShortBreak.Size = new System.Drawing.Size(148, 53);
            this.btnShortBreak.TabIndex = 6;
            this.btnShortBreak.Text = "Short Break";
            this.btnShortBreak.UseVisualStyleBackColor = false;
            this.btnShortBreak.Click += new System.EventHandler(this.ChangeMode);
            // 
            // btnLongBreak
            // 
            this.btnLongBreak.BackColor = System.Drawing.Color.DeepSkyBlue;
            this.btnLongBreak.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnLongBreak.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnLongBreak.FlatAppearance.BorderSize = 6;
            this.btnLongBreak.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnLongBreak.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnLongBreak.Font = new System.Drawing.Font("Microsoft JhengHei", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLongBreak.ForeColor = System.Drawing.Color.Transparent;
            this.btnLongBreak.Location = new System.Drawing.Point(514, 37);
            this.btnLongBreak.Name = "btnLongBreak";
            this.btnLongBreak.Size = new System.Drawing.Size(136, 53);
            this.btnLongBreak.TabIndex = 7;
            this.btnLongBreak.Text = "Long Break";
            this.btnLongBreak.UseVisualStyleBackColor = false;
            this.btnLongBreak.Click += new System.EventHandler(this.ChangeMode);
            // 
            // progressBar1
            // 
            this.progressBar1.BackColor = System.Drawing.Color.MintCream;
            this.progressBar1.ForeColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.progressBar1.Location = new System.Drawing.Point(325, 318);
            this.progressBar1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(146, 30);
            this.progressBar1.TabIndex = 8;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.ClientSize = new System.Drawing.Size(808, 600);
            this.ContextMenuStrip = this.contextMenuStrip1;
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.btnLongBreak);
            this.Controls.Add(this.btnShortBreak);
            this.Controls.Add(this.btnPomodoro);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.lblTimer);
            this.Controls.Add(this.pictureBox1);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Timer tmTimer;
        private System.Windows.Forms.Label lblTimer;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.NotifyIcon notifyIcon1;
        private System.Windows.Forms.Button btnPomodoro;
        private System.Windows.Forms.Button btnShortBreak;
        private System.Windows.Forms.Button btnLongBreak;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem setTimeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem setColorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem restToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem restColorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem Min10;
        private System.Windows.Forms.ToolStripMenuItem Min15;
        private System.Windows.Forms.ToolStripMenuItem Min20;
        private System.Windows.Forms.ToolStripMenuItem Min25;
        private System.Windows.Forms.ToolStripMenuItem Min30;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem minToolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem minToolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem minToolStripMenuItem5;
        private System.Windows.Forms.ToolStripMenuItem minToolStripMenuItem6;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem3;
    }
}

