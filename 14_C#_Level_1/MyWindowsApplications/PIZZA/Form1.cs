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

        float GetSelectedSizePrice()
        {
            if (rbtnSmall.Checked)
                return Convert.ToSingle(rbtnSmall.Tag);
            else if (rbtnMedium.Checked)
                return Convert.ToSingle(rbtnMedium.Tag);
            else if(rbtnLarg.Checked)
                return Convert.ToSingle(rbtnLarg.Tag);

            return 0;
        }
        float GetSelectedCrustPrice()
        {
            if (rbtnThinCrust.Checked)
                return Convert.ToSingle(rbtnThinCrust.Tag);
            else if (rbtnThickCrust.Checked)
                    return Convert.ToSingle(rbtnThickCrust.Tag);

                return 0;
        }

        float CalculateToppingsPrice()
        {
            float ToppingsPrice=0;
            if (cboxExtraChees.Checked)
                ToppingsPrice += Convert.ToSingle(cboxExtraChees.Tag);

            if(cboxMushrooms.Checked)
                ToppingsPrice += Convert.ToSingle(cboxMushrooms.Tag);

            if (cboxTomatoes.Checked)
                ToppingsPrice += Convert.ToSingle(cboxTomatoes.Tag);

             if (cboxOnion.Checked)
                ToppingsPrice += Convert.ToSingle(cboxOnion.Tag);

             if (cboxOlives.Checked)
                ToppingsPrice += Convert.ToSingle(cboxOlives.Tag);

             if (cboxGreenPeppers.Checked)
                ToppingsPrice += Convert.ToSingle(cboxGreenPeppers.Tag);


            return ToppingsPrice;
        }

        float CalculateTotalPrice()
        {
            return GetSelectedCrustPrice() + GetSelectedSizePrice() + CalculateToppingsPrice();
        }

        void UpdateTotalPrice()
        {
            labTotalPriceNum.Text= '$'+ CalculateTotalPrice().ToString();
        }

         void UpdateSize()
        {
            UpdateTotalPrice();
            if (rbtnSmall.Checked)
                labSizeOp.Text = "Small";
            else if (rbtnMedium.Checked)
                labSizeOp.Text = "Meduim";
            else if (rbtnLarg.Checked)
                labSizeOp.Text = "Larg";
        }

        void UpdateCrustType()
        {
            UpdateTotalPrice();
            if (rbtnThinCrust.Checked)
                labCrustTypeOp.Text = "Thin Crust";
            else if (rbtnThickCrust.Checked)
                labCrustTypeOp.Text = "Thick Crust";
        }

        public void ChangePrice(int Num,char Opration)
        {
            return;
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
            UpdateToppings();
        }

        private void cboxOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void cboxGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void rbtnSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();    
        }

        private void rbtnMedium_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize(); 
        }

        private void rbtnLarg_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbtnThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();
            
        }


        private void rbtnThickCrust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();
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


        public void UpdateToppings()
        {
            UpdateTotalPrice();

            string strToppings = "";
            int count = 0;
            foreach(Control crtl in gboToppings.Controls)
            {
                if(crtl is CheckBox checBox)
                {
                    if(checBox.Checked)
                    {
                        strToppings +=", " + checBox.Text;
                        count++;
                        if (count == 3)
                            strToppings += "\n";
                    }
                }
            }
            if (strToppings == "")
                labToppingsOp.Text = "No Toppings";
            else
                
                labToppingsOp.Text = strToppings.Substring(2);

        }
        private void cboxExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();

        }

        private void cboxMushrooms_CheckedChanged(object sender, EventArgs e)
        {

            UpdateToppings();
        }

        private void cboxTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
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

        private void gboxSize_Enter(object sender, EventArgs e)
        {

        }
    }
}
