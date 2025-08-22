using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tic_Tac_Toe.Properties;

namespace Tic_Tac_Toe
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lbTurn.Text = "Player 1";
            lbWinner.Text = "In Progress";
            panel1.Enabled = true;
            foreach (Control crtl in panel1.Controls)
            {
                if (crtl is PictureBox pictureBox)
                {
                    pictureBox.BackgroundImage = Resources.question_mark;
                    pictureBox.Tag = '?';
                }
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Color White = Color.FromArgb(255, 255, 255, 255);
            Pen Pen = new Pen(White);
            Pen.Width = 10;

            Pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            Pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(Pen, 450, 130, 450, 430);
            e.Graphics.DrawLine(Pen, 580, 130, 580, 430);
            e.Graphics.DrawLine(Pen, 331, 224, 697,224);
            e.Graphics.DrawLine(Pen, 331, 330, 697, 330);




        }

        void ChangePhoto(object sender)
        {

            if (Convert.ToChar(((PictureBox)sender).Tag) == '?')
            {
                if (lbTurn.Text == "Player 1")
                {
                    ((PictureBox)sender).BackgroundImage = Resources.X;
                    ((PictureBox)sender).Tag = 'X';
                }
                else if (lbTurn.Text == "Player 2")
                {
                    ((PictureBox)sender).BackgroundImage = Resources.O;
                    ((PictureBox)sender).Tag = 'O';
                }
            }
            else
            {
                MessageBox.Show("Wrong Choice", "Wrong", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }         
        }

        void GameOver()
        {
            if(lbWinner.Text !="In Progress")
            {
                MessageBox.Show("Game Over","Game Over",MessageBoxButtons.OK,MessageBoxIcon.Information);
                panel1.Enabled = false;
            }
        }

        bool ChackWinner()
        {
            char choic='1';
            if (lbTurn.Text == "Player 1")
                choic = 'X';
            else if (lbTurn.Text == "Player 2")
                choic = 'O';

            char p1 = Convert.ToChar(picb1.Tag);
            char p2 = Convert.ToChar(picb2.Tag);
            char p3 = Convert.ToChar(picb3.Tag);
            char p4 = Convert.ToChar(picb4.Tag);
            char p5 = Convert.ToChar(picb5.Tag);
            char p6 = Convert.ToChar(picb6.Tag);
            char p7 = Convert.ToChar(picb7.Tag);
            char p8 = Convert.ToChar(picb8.Tag);
            char p9 = Convert.ToChar(picb9.Tag);

            bool Probability1 = (p1 == choic) && (p2 == choic) && (p3 == choic);
            bool Probability2 = (p4 == choic) && (p5 == choic) && (p6 == choic);
            bool Probability3 = (p7 == choic) && (p8 == choic) && (p9 == choic);
            bool Probability4 = (p1 == choic) && (p4 == choic) && (p7 == choic);
            bool Probability5 = (p2 == choic) && (p5 == choic) && (p8 == choic);
            bool Probability6 = (p3 == choic) && (p6 == choic) && (p9 == choic);
            bool Probability7 = (p1 == choic) && (p5 == choic) && (p9 == choic);
            bool Probability8 = (p3 == choic) && (p5 == choic) && (p7 == choic);



            if (Probability1|| Probability2 || Probability3 || Probability4 ||
               Probability5 || Probability6 || Probability7 || Probability7 || Probability8)
            {
                lbWinner.Text = lbTurn.Text;
                return true;
            }
            return false;

               
        }

        void ChackDraw()
        {
            int counter = 0;
            foreach(Control crtl in panel1.Controls)
            {
                if(crtl is PictureBox picBox)
                {
                    if (Convert.ToChar(picBox.Tag) != '?')
                        counter++;
                }
            }
            if (counter == 9)
            {
                lbWinner.Text = "Draw";
                GameOver();
            }
        }
        void NextTurn()
        {
            if (lbTurn.Text == "Player 1")
                lbTurn.Text = "Player 2";
            else if (lbTurn.Text == "Player 2")
                lbTurn.Text = "Player 1";
        }

        void UpdateTurn(object sender)
        {
            ChangePhoto(sender);

            if (ChackWinner())
            {
                GameOver();
            }
            else
                ChackDraw();

            NextTurn();
        }
        private void picb1_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
            
        }

        private void picb2_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
        }

        private void picb3_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
        }

        private void picb4_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
        }

        private void picb5_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
        }

        private void picb6_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
        }

        private void picb7_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
        }

        private void picb8_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
        }

        private void picb9_Click(object sender, EventArgs e)
        {
            UpdateTurn(sender);
        }

        private void btRestartGame_Click(object sender, EventArgs e)
        {
            lbTurn.Text = "Player 1";
            lbWinner.Text = "In Progress";
            panel1.Enabled = true;
            foreach (Control crtl in panel1.Controls)
            {
                if(crtl is PictureBox pictureBox)
                {
                    pictureBox.BackgroundImage = Resources.question_mark;
                    pictureBox.Tag = '?';
                }
            }

        }


       
    }
}
