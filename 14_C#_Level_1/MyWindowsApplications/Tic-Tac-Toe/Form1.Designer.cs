namespace Tic_Tac_Toe
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.lbTitle = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.picb2 = new System.Windows.Forms.PictureBox();
            this.picb4 = new System.Windows.Forms.PictureBox();
            this.picb5 = new System.Windows.Forms.PictureBox();
            this.picb6 = new System.Windows.Forms.PictureBox();
            this.picb1 = new System.Windows.Forms.PictureBox();
            this.picb3 = new System.Windows.Forms.PictureBox();
            this.picb7 = new System.Windows.Forms.PictureBox();
            this.picb8 = new System.Windows.Forms.PictureBox();
            this.picb9 = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lbWinner = new System.Windows.Forms.Label();
            this.lbTurn = new System.Windows.Forms.Label();
            this.btRestartGame = new System.Windows.Forms.Button();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.panel1 = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb9)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // lbTitle
            // 
            resources.ApplyResources(this.lbTitle, "lbTitle");
            this.lbTitle.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbTitle.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.lbTitle.Name = "lbTitle";
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.K4fTj4SWRHCoJT03mBYl_Telegram_Logos__6_;
            resources.ApplyResources(this.pictureBox1, "pictureBox1");
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.TabStop = false;
            // 
            // picb2
            // 
            resources.ApplyResources(this.picb2, "picb2");
            this.picb2.Name = "picb2";
            this.picb2.TabStop = false;
            this.picb2.Click += new System.EventHandler(this.picb2_Click);
            // 
            // picb4
            // 
            resources.ApplyResources(this.picb4, "picb4");
            this.picb4.Name = "picb4";
            this.picb4.TabStop = false;
            this.picb4.Click += new System.EventHandler(this.picb4_Click);
            // 
            // picb5
            // 
            resources.ApplyResources(this.picb5, "picb5");
            this.picb5.Name = "picb5";
            this.picb5.TabStop = false;
            this.picb5.Click += new System.EventHandler(this.picb5_Click);
            // 
            // picb6
            // 
            resources.ApplyResources(this.picb6, "picb6");
            this.picb6.Name = "picb6";
            this.picb6.TabStop = false;
            this.picb6.Click += new System.EventHandler(this.picb6_Click);
            // 
            // picb1
            // 
            resources.ApplyResources(this.picb1, "picb1");
            this.picb1.Name = "picb1";
            this.picb1.TabStop = false;
            this.picb1.Click += new System.EventHandler(this.picb1_Click);
            // 
            // picb3
            // 
            resources.ApplyResources(this.picb3, "picb3");
            this.picb3.Name = "picb3";
            this.picb3.TabStop = false;
            this.picb3.Click += new System.EventHandler(this.picb3_Click);
            // 
            // picb7
            // 
            resources.ApplyResources(this.picb7, "picb7");
            this.picb7.Name = "picb7";
            this.picb7.TabStop = false;
            this.picb7.Click += new System.EventHandler(this.picb7_Click);
            // 
            // picb8
            // 
            resources.ApplyResources(this.picb8, "picb8");
            this.picb8.Name = "picb8";
            this.picb8.TabStop = false;
            this.picb8.Click += new System.EventHandler(this.picb8_Click);
            // 
            // picb9
            // 
            resources.ApplyResources(this.picb9, "picb9");
            this.picb9.Name = "picb9";
            this.picb9.TabStop = false;
            this.picb9.Click += new System.EventHandler(this.picb9_Click);
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label1.ForeColor = System.Drawing.Color.Yellow;
            this.label1.Name = "label1";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label2.ForeColor = System.Drawing.Color.Yellow;
            this.label2.Name = "label2";
            // 
            // lbWinner
            // 
            resources.ApplyResources(this.lbWinner, "lbWinner");
            this.lbWinner.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbWinner.ForeColor = System.Drawing.Color.Lime;
            this.lbWinner.Name = "lbWinner";
            // 
            // lbTurn
            // 
            resources.ApplyResources(this.lbTurn, "lbTurn");
            this.lbTurn.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.lbTurn.ForeColor = System.Drawing.Color.White;
            this.lbTurn.Name = "lbTurn";
            // 
            // btRestartGame
            // 
            this.btRestartGame.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            resources.ApplyResources(this.btRestartGame, "btRestartGame");
            this.btRestartGame.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.btRestartGame.Name = "btRestartGame";
            this.btRestartGame.UseVisualStyleBackColor = false;
            this.btRestartGame.Click += new System.EventHandler(this.btRestartGame_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.picb9);
            this.panel1.Controls.Add(this.picb8);
            this.panel1.Controls.Add(this.picb7);
            this.panel1.Controls.Add(this.picb3);
            this.panel1.Controls.Add(this.picb1);
            this.panel1.Controls.Add(this.picb6);
            this.panel1.Controls.Add(this.picb5);
            this.panel1.Controls.Add(this.picb4);
            this.panel1.Controls.Add(this.picb2);
            resources.ApplyResources(this.panel1, "panel1");
            this.panel1.Name = "panel1";
            // 
            // Form1
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.btRestartGame);
            this.Controls.Add(this.lbTurn);
            this.Controls.Add(this.lbWinner);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.lbTitle);
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picb9)).EndInit();
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbTitle;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox picb2;
        private System.Windows.Forms.PictureBox picb4;
        private System.Windows.Forms.PictureBox picb5;
        private System.Windows.Forms.PictureBox picb6;
        private System.Windows.Forms.PictureBox picb1;
        private System.Windows.Forms.PictureBox picb3;
        private System.Windows.Forms.PictureBox picb7;
        private System.Windows.Forms.PictureBox picb8;
        private System.Windows.Forms.PictureBox picb9;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lbWinner;
        private System.Windows.Forms.Label lbTurn;
        private System.Windows.Forms.Button btRestartGame;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Panel panel1;
    }
}

