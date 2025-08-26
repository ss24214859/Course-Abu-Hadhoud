using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class frmMaskedTextBox : Form
    {
        public frmMaskedTextBox()
        {
            InitializeComponent();
        }

        private void frmMaskedTextBox_Load(object sender, EventArgs e)
        {

        }

        string CheckAgeFormDate(string strDate)
        {
            DateTime UserDate;
            var IsValidDate= DateTime.TryParse(strDate, out UserDate);
            if(!IsValidDate)
            {
                return "this Is Not Valid Date :-(";
            }

            DateTime AgeDate = DateTime.Now;
            int Year= AgeDate.Year - UserDate.Year;
            if (AgeDate.Month < UserDate.Month || (AgeDate.Month == UserDate.Month && AgeDate.Day < UserDate.Day))
                --Year;
            
            int Month= AgeDate.Month-UserDate.Month;

            if(Month < 0)
                Month+=12;

            int Day= AgeDate.Day-UserDate.Day;
            if (Day < 0)
                Month--;
                Day+=30;
           
            string Age = $"{Year} Year, {Month} Month,{Day} Day.";
            return Age;
        }
        private void btnCheckDate_Click(object sender, EventArgs e)
        {
            lblAge.Text=CheckAgeFormDate(maskedTextBox1.Text);
        }
    }
}
