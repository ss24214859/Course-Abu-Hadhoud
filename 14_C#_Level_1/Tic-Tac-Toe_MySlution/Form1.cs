using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tic_Tac_Toe_MySlution
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Color white = Color.FromArgb(255, 255, 255, 255);
            Pen whitePen = new Pen(white);
            whitePen.Width = 15;
            //whitePen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dash;
            whitePen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            whitePen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            //draw Horizental lines
            e.Graphics.DrawLine(whitePen, 100, 325, 550, 325);
            e.Graphics.DrawLine(whitePen, 100, 475, 550, 475);
            
            //draw Vertical lines
            e.Graphics.DrawLine(whitePen, 250, 175, 250, 600);
            e.Graphics.DrawLine(whitePen, 400, 175, 400, 600);
        }

        private void button10_MouseEnter(object sender, EventArgs e)
        {

        }

        private void button11_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void lblTurn_Click(object sender, EventArgs e)
        {

        }

        private void btn4_Click(object sender, EventArgs e)
        {

        }
    }
}
