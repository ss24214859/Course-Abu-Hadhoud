using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PIZZA
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        List<string> ToppingsList = new List<string>();

        public void ChangePrice(int Num,char Opration)
        {
            int TotalPrice = 0;
            switch (Opration)
            {
                case '+':
                    TotalPrice = Convert.ToInt32(labTotalPriceNum.Text) + Num;
                    break;
                case '-':
                    TotalPrice = Convert.ToInt32(labTotalPriceNum.Text) - Num;
                    break;
                default:
                    return;
            }
            labTotalPriceNum.Text = Convert.ToString(TotalPrice);
        }
        
        

        private void Form1_Load(object sender, EventArgs e)
        {
            rbtnSmall.Checked = true;
            rbtnThickCrust.Checked = true;
            rbtnEatIn.Checked = true;
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void cboxOnion_CheckedChanged(object sender, EventArgs e)
        {
            if (cboxOnion.Checked)
            {
                ChangeLabToppings("Onion", '+');
                ChangePrice(5, '+');
            }
            else
            {
                ChangeLabToppings("Onion", '-');
                ChangePrice(5, '-');
            }
        }

        private void cboxOlives_CheckedChanged(object sender, EventArgs e)
        {
            if (cboxOlives.Checked)
            {
                ChangeLabToppings("Olives", '+');
                ChangePrice(5, '+');
            }
            else
            {
                ChangeLabToppings("Olives", '-');
                ChangePrice(5, '-');
            }
        }

        private void cboxGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            if (cboxGreenPeppers.Checked)
            {
                ChangeLabToppings("Green Peppers", '+');
                ChangePrice(5, '+');
            }
            else
            {
                ChangeLabToppings("Green Peppers", '-');
                ChangePrice(5, '-');
            }
        }

        private void rbtnSmall_CheckedChanged(object sender, EventArgs e)
        {
            int Price = 20;
            if (rbtnSmall.Checked)
            {
                labSizeOp.Text = "Small";
                ChangePrice(Price, '+');
            }
            else
                ChangePrice(Price, '-');
            
                

                
        }

        private void rbtnMedium_CheckedChanged(object sender, EventArgs e)
        {
            int Price = 30;
            if (rbtnMedium.Checked)
            {
                labSizeOp.Text = "Medium";
                ChangePrice(Price, '+');
            }
            else
                ChangePrice(Price, '-');
        }

        private void rbtnLarg_CheckedChanged(object sender, EventArgs e)
        {
            int Price = 40;
            if (rbtnLarg.Checked)
            {
                labSizeOp.Text = "Larg";
                ChangePrice(Price, '+');
            }
            else
                ChangePrice(Price, '-');
        }

        private void rbtnThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            if(rbtnThinCrust.Checked)
                labCrustTypeOp.Text = "Thin Crust";
            
        }


        private void rbtnThickCrust_CheckedChanged(object sender, EventArgs e)
        {
            if(rbtnThickCrust.Checked)
            {
                labCrustTypeOp.Text = "Thick Crust";
                ChangePrice(10, '+');
            }
            else
                ChangePrice(10, '-');
        }
        private void labTotalPriceNum_Click(object sender, EventArgs e)
        {

        }

        private void rbtnEatIn_CheckedChanged(object sender, EventArgs e)
        {
            if (rbtnEatIn.Checked)
            {
                labWhereToEatOp.Text = "Eat In";
            }
        }

        private void rbtnTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            if(rbtnTakeOut.Checked)
            {
                labWhereToEatOp.Text = "Tack Out";
            }
        }

        public void ChangeLabToppings(string TypeOfToppings, char Operation)
        {
            if (Operation=='+')
            {
                ToppingsList.Add(TypeOfToppings);  
            }
            else if(Operation=='-')
            {
                ToppingsList.Remove(TypeOfToppings);
            }

            if (ToppingsList.Count == 0)
                labToppingsOp.Text = "No Toppings";
            else
            {
                labToppingsOp.Text = "";
                bool FirstWord = true;
                for(int i=0;ToppingsList.Count>i;i++)
                {
                    if (i == 3) labToppingsOp.Text += "\n";
                        
                    if (!FirstWord) labToppingsOp.Text += " , ";
                    
                    labToppingsOp.Text += ToppingsList[i];
                    FirstWord = false; 
                    
                }
            }

        }
        private void cboxExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            if(cboxExtraChees.Checked)
            {
                ChangeLabToppings("Extra Chees", '+');
                ChangePrice(5, '+');
            }
            else
            {
                ChangeLabToppings("Extra Chees",'-');
                ChangePrice(5, '-');
            }
                
        }

        private void cboxMushrooms_CheckedChanged(object sender, EventArgs e)
        {

            if (cboxMushrooms.Checked)
            {
                ChangeLabToppings("Mushrooms", '+');
                ChangePrice(5, '+');
            }
            else
            {
                ChangeLabToppings("Mushrooms", '-');
                ChangePrice(5, '-');
            }
        }

        private void cboxTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            if (cboxTomatoes.Checked)
            {
                ChangeLabToppings("Tomatoes", '+');
                ChangePrice(5, '+');
            }
            else
            {
                ChangeLabToppings("Tomatoes", '-');
                ChangePrice(5, '-');
            }
        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if(MessageBox.Show("Conferm Order","Conferm",MessageBoxButtons.OKCancel,MessageBoxIcon.Question) == DialogResult.OK)
            {
                gboToppings.Enabled    = false;
                gboxSize.Enabled       = false;
                gboxCrustType.Enabled  = false;
                gboxWhereToEat.Enabled = false;
                MessageBox.Show("Your Order is Conferm :-) ");
            }
        }

        private void btnRestForm_Click(object sender, EventArgs e)
        {
            gboToppings.Enabled    = true;
            gboxSize.Enabled       = true;
            gboxCrustType.Enabled  = true;
            gboxWhereToEat.Enabled = true;

            //to Rest All Toppings Check Boxs.
            foreach(Control crtl in gboToppings.Controls) 
            {
                if(crtl is CheckBox checkbox)
                {
                    checkbox.Checked = false;
                }
            }
            rbtnEatIn.Checked = true;
            rbtnSmall.Checked = true;
            rbtnThickCrust.Checked = true;

        }
    }
}
