using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Authentication;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace My_Pomodoro
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        struct stSetColor
        {
            public Color Pomodoro
            , ShortBreak
            , LongBreak;
        }
        public struct stTimerSet
        {
            public int Pomodoro
            , ShortBreak
            , LongBreak;
        }
        enum enStatus
        {
            Pomodoro = 20,
            ShortBreak = 5,
            LongBreak = 15
        }

        enStatus TimerStatus;
        stSetColor OriginalColor;
        stTimerSet OriginalTime;
        public stTimerSet timerSet;
        
        TimeSpan Timer;
       
        private void Form1_Load(object sender, EventArgs e)
        {
            OriginalColor = new stSetColor { Pomodoro = btnPomodoro.BackColor,ShortBreak = btnShortBreak.BackColor,LongBreak = btnLongBreak.BackColor };
            OriginalTime = new stTimerSet { Pomodoro = 20, ShortBreak = 5, LongBreak = 15 };
            timerSet = OriginalTime;
            ChangeTimeInTimer(btnPomodoro); 
        }

        void NextMode()
        {
            if (TimerStatus == enStatus.Pomodoro)
            {
                TimerStatus = enStatus.ShortBreak;
                ChangeTimeInTimer(btnShortBreak);
                notifyIcon1.BalloonTipText = "Time Out, It's Time for a Break. ";
                notifyIcon1.ShowBalloonTip(1000);
            }
            else if(TimerStatus == enStatus.ShortBreak || TimerStatus == enStatus.LongBreak )
            {
                ChangeTimeInTimer(btnPomodoro);
                notifyIcon1.BalloonTipText = "Break Is Over,Please Get Back To Work. ";
                notifyIcon1.ShowBalloonTip(1000);
            }
                

            
        }
        private void timer_Tick(object sender, EventArgs e)
        {
            if (Timer == new TimeSpan(0, 0, 0))
            {
                NextMode();
               
                return;
            }
            Timer -= new TimeSpan(0, 0, 1);
            lblTimer.Text = Timer.ToString(@"h\:mm\:ss");

            //Update ProgressBar
            progressBar1.Value++;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            tmTimer.Enabled = true;
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            tmTimer.Enabled=false;
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            ChangeTimeInTimer(btnPomodoro);
        }
            
        public void ChangeTimeInTimer(Button button)
        {
            int TimeSet =0;
            if(button.Text== "Pomodoro")
            { 
                TimeSet = timerSet.Pomodoro;
                TimerStatus = enStatus.Pomodoro;
            }
               
            else if(button.Text== "Short Break")
            {
                TimeSet = timerSet.ShortBreak;
                TimerStatus = enStatus.ShortBreak;
            }
            else if(button.Text=="Long Break")
            {
                TimeSet = timerSet.LongBreak;
                TimerStatus = enStatus.LongBreak;
            }

            tmTimer.Enabled = false;

            if(TimeSet<59)
                Timer = new TimeSpan(0, TimeSet, 0);

            else if(TimeSet>=60 && TimeSet<120)
                Timer = new TimeSpan(1, TimeSet-60, 0);


            this.BackColor = button.BackColor;

            lblTimer.Text = Timer.ToString(@"h\:mm\:ss");

            //Set ProgressBar
            progressBar1.Maximum = (TimeSet * 60);
            progressBar1.Value = 0;

        }

        private void ChangeMode(object sender, EventArgs e)
        {
            ChangeTimeInTimer((Button)sender);
        }

 


        private void setColorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                if (TimerStatus == enStatus.Pomodoro)
                {
                    btnPomodoro.BackColor = colorDialog1.Color;
                    ChangeTimeInTimer(btnPomodoro);
                }

                else if (TimerStatus == enStatus.ShortBreak)
                {
                    btnShortBreak.BackColor = colorDialog1.Color;
                    ChangeTimeInTimer(btnShortBreak);
                }

                else if (TimerStatus == enStatus.LongBreak)
                {
                    btnLongBreak.BackColor = colorDialog1.Color;
                    ChangeTimeInTimer(btnLongBreak);
                }
            }
            
               
        }

        private void SetTime(object sender, EventArgs e)
        {
            ToolStripMenuItem button = ((ToolStripMenuItem)sender);
            int Min = Convert.ToInt32(button.Tag);
            if (TimerStatus == enStatus.Pomodoro)
            {
                timerSet.Pomodoro = Min;
                ChangeTimeInTimer(btnPomodoro);
            }

            else if (TimerStatus == enStatus.ShortBreak)
            {
                timerSet.ShortBreak = Min;
                ChangeTimeInTimer(btnShortBreak);
            }

            else if (TimerStatus == enStatus.LongBreak)
            {
                timerSet.LongBreak = Min;
                ChangeTimeInTimer(btnLongBreak);
            }
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }

        private void restToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //timerSet = new TimerSet { Pomodoro = 20, ShortBreak = 5, LongBreak = 15 };
            if (TimerStatus == enStatus.Pomodoro)
            {
                timerSet.Pomodoro = OriginalTime.Pomodoro;
                ChangeTimeInTimer(btnPomodoro);
            }

            else if (TimerStatus == enStatus.ShortBreak)
            {
                timerSet.ShortBreak = OriginalTime.ShortBreak;
                ChangeTimeInTimer(btnShortBreak);
            }

            else if (TimerStatus == enStatus.LongBreak)
            {
                timerSet.LongBreak = OriginalTime.LongBreak;
                ChangeTimeInTimer(btnLongBreak);
            }
        }

        private void restColorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (TimerStatus == enStatus.Pomodoro)
            {
                btnPomodoro.BackColor=OriginalColor.Pomodoro;
                ChangeTimeInTimer(btnPomodoro);
            }

            else if (TimerStatus == enStatus.ShortBreak)
            {
                btnShortBreak.BackColor = OriginalColor.ShortBreak;
                ChangeTimeInTimer(btnShortBreak);
            }

            else if (TimerStatus == enStatus.LongBreak)
            {
                btnLongBreak.BackColor = OriginalColor.LongBreak;
                ChangeTimeInTimer(btnLongBreak);
            }
        }
    }
}
