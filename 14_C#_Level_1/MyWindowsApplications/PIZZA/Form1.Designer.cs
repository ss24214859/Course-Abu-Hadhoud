namespace PIZZA
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.rbtnSmall = new System.Windows.Forms.RadioButton();
            this.rbtnMedium = new System.Windows.Forms.RadioButton();
            this.rbtnLarg = new System.Windows.Forms.RadioButton();
            this.gboxSize = new System.Windows.Forms.GroupBox();
            this.gboxCrustType = new System.Windows.Forms.GroupBox();
            this.rbtnThickCrust = new System.Windows.Forms.RadioButton();
            this.rbtnThinCrust = new System.Windows.Forms.RadioButton();
            this.gboxWhereToEat = new System.Windows.Forms.GroupBox();
            this.rbtnTakeOut = new System.Windows.Forms.RadioButton();
            this.rbtnEatIn = new System.Windows.Forms.RadioButton();
            this.cboxExtraChees = new System.Windows.Forms.CheckBox();
            this.cboxMushrooms = new System.Windows.Forms.CheckBox();
            this.cboxTomatoes = new System.Windows.Forms.CheckBox();
            this.cboxOnion = new System.Windows.Forms.CheckBox();
            this.cboxOlives = new System.Windows.Forms.CheckBox();
            this.cboxGreenPeppers = new System.Windows.Forms.CheckBox();
            this.gboToppings = new System.Windows.Forms.GroupBox();
            this.labOrdrerSummary = new System.Windows.Forms.Label();
            this.labSize = new System.Windows.Forms.Label();
            this.labCrustType = new System.Windows.Forms.Label();
            this.labToppings = new System.Windows.Forms.Label();
            this.labWhereToEat = new System.Windows.Forms.Label();
            this.labTotalPrice = new System.Windows.Forms.Label();
            this.labTotalPriceNum = new System.Windows.Forms.Label();
            this.labCrustTypeOp = new System.Windows.Forms.Label();
            this.labToppingsOp = new System.Windows.Forms.Label();
            this.labWhereToEatOp = new System.Windows.Forms.Label();
            this.labSizeOp = new System.Windows.Forms.Label();
            this.btnOrderPizza = new System.Windows.Forms.Button();
            this.btnRestForm = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.gboxSize.SuspendLayout();
            this.gboxCrustType.SuspendLayout();
            this.gboxWhereToEat.SuspendLayout();
            this.gboToppings.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackgroundImage = global::PIZZA.Properties.Resources.صمم_ليا_صوره_لموقع_ب;
            this.pictureBox1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.pictureBox1.Location = new System.Drawing.Point(-5, -1);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(390, 745);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Cursor = System.Windows.Forms.Cursors.Default;
            this.label1.Font = new System.Drawing.Font("Monotype Corsiva", 48F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.label1.Location = new System.Drawing.Point(389, 9);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(451, 79);
            this.label1.TabIndex = 1;
            this.label1.Text = "Make Your Pizza";
            // 
            // rbtnSmall
            // 
            this.rbtnSmall.AutoSize = true;
            this.rbtnSmall.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnSmall.Location = new System.Drawing.Point(33, 19);
            this.rbtnSmall.Name = "rbtnSmall";
            this.rbtnSmall.Size = new System.Drawing.Size(50, 17);
            this.rbtnSmall.TabIndex = 3;
            this.rbtnSmall.Tag = "20";
            this.rbtnSmall.Text = "Small";
            this.rbtnSmall.UseVisualStyleBackColor = true;
            this.rbtnSmall.CheckedChanged += new System.EventHandler(this.rbtnSmall_CheckedChanged);
            // 
            // rbtnMedium
            // 
            this.rbtnMedium.AutoSize = true;
            this.rbtnMedium.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnMedium.Location = new System.Drawing.Point(33, 42);
            this.rbtnMedium.Name = "rbtnMedium";
            this.rbtnMedium.Size = new System.Drawing.Size(62, 17);
            this.rbtnMedium.TabIndex = 4;
            this.rbtnMedium.Tag = "30";
            this.rbtnMedium.Text = "Medium";
            this.rbtnMedium.UseVisualStyleBackColor = true;
            this.rbtnMedium.CheckedChanged += new System.EventHandler(this.rbtnMedium_CheckedChanged);
            // 
            // rbtnLarg
            // 
            this.rbtnLarg.AutoSize = true;
            this.rbtnLarg.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnLarg.Location = new System.Drawing.Point(33, 65);
            this.rbtnLarg.Name = "rbtnLarg";
            this.rbtnLarg.Size = new System.Drawing.Size(46, 17);
            this.rbtnLarg.TabIndex = 5;
            this.rbtnLarg.Tag = "40";
            this.rbtnLarg.Text = "Larg";
            this.rbtnLarg.UseVisualStyleBackColor = true;
            this.rbtnLarg.CheckedChanged += new System.EventHandler(this.rbtnLarg_CheckedChanged);
            // 
            // gboxSize
            // 
            this.gboxSize.BackColor = System.Drawing.Color.Brown;
            this.gboxSize.Controls.Add(this.rbtnLarg);
            this.gboxSize.Controls.Add(this.rbtnMedium);
            this.gboxSize.Controls.Add(this.rbtnSmall);
            this.gboxSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gboxSize.Location = new System.Drawing.Point(417, 109);
            this.gboxSize.Name = "gboxSize";
            this.gboxSize.Size = new System.Drawing.Size(111, 88);
            this.gboxSize.TabIndex = 6;
            this.gboxSize.TabStop = false;
            this.gboxSize.Text = "Size";
            this.gboxSize.Enter += new System.EventHandler(this.gboxSize_Enter);
            // 
            // gboxCrustType
            // 
            this.gboxCrustType.BackColor = System.Drawing.Color.Brown;
            this.gboxCrustType.Controls.Add(this.rbtnThickCrust);
            this.gboxCrustType.Controls.Add(this.rbtnThinCrust);
            this.gboxCrustType.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gboxCrustType.Location = new System.Drawing.Point(414, 218);
            this.gboxCrustType.Name = "gboxCrustType";
            this.gboxCrustType.Size = new System.Drawing.Size(111, 64);
            this.gboxCrustType.TabIndex = 7;
            this.gboxCrustType.TabStop = false;
            this.gboxCrustType.Text = "Crust Type";
            // 
            // rbtnThickCrust
            // 
            this.rbtnThickCrust.AutoSize = true;
            this.rbtnThickCrust.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnThickCrust.Location = new System.Drawing.Point(31, 43);
            this.rbtnThickCrust.Name = "rbtnThickCrust";
            this.rbtnThickCrust.Size = new System.Drawing.Size(79, 17);
            this.rbtnThickCrust.TabIndex = 4;
            this.rbtnThickCrust.Tag = "10";
            this.rbtnThickCrust.Text = "Thick Crust";
            this.rbtnThickCrust.UseVisualStyleBackColor = true;
            this.rbtnThickCrust.CheckedChanged += new System.EventHandler(this.rbtnThickCrust_CheckedChanged);
            // 
            // rbtnThinCrust
            // 
            this.rbtnThinCrust.AutoSize = true;
            this.rbtnThinCrust.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnThinCrust.Location = new System.Drawing.Point(32, 20);
            this.rbtnThinCrust.Name = "rbtnThinCrust";
            this.rbtnThinCrust.Size = new System.Drawing.Size(73, 17);
            this.rbtnThinCrust.TabIndex = 3;
            this.rbtnThinCrust.Text = "Thin Crust";
            this.rbtnThinCrust.UseVisualStyleBackColor = true;
            this.rbtnThinCrust.CheckedChanged += new System.EventHandler(this.rbtnThinCrust_CheckedChanged);
            // 
            // gboxWhereToEat
            // 
            this.gboxWhereToEat.BackColor = System.Drawing.Color.Brown;
            this.gboxWhereToEat.Controls.Add(this.rbtnTakeOut);
            this.gboxWhereToEat.Controls.Add(this.rbtnEatIn);
            this.gboxWhereToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gboxWhereToEat.Location = new System.Drawing.Point(547, 234);
            this.gboxWhereToEat.Name = "gboxWhereToEat";
            this.gboxWhereToEat.Size = new System.Drawing.Size(264, 48);
            this.gboxWhereToEat.TabIndex = 8;
            this.gboxWhereToEat.TabStop = false;
            this.gboxWhereToEat.Text = "Where To Eat";
            this.gboxWhereToEat.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // rbtnTakeOut
            // 
            this.rbtnTakeOut.AutoSize = true;
            this.rbtnTakeOut.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnTakeOut.Location = new System.Drawing.Point(120, 20);
            this.rbtnTakeOut.Name = "rbtnTakeOut";
            this.rbtnTakeOut.Size = new System.Drawing.Size(70, 17);
            this.rbtnTakeOut.TabIndex = 4;
            this.rbtnTakeOut.Text = "Take Out";
            this.rbtnTakeOut.UseVisualStyleBackColor = true;
            this.rbtnTakeOut.CheckedChanged += new System.EventHandler(this.rbtnTakeOut_CheckedChanged);
            // 
            // rbtnEatIn
            // 
            this.rbtnEatIn.AutoSize = true;
            this.rbtnEatIn.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnEatIn.Location = new System.Drawing.Point(32, 20);
            this.rbtnEatIn.Name = "rbtnEatIn";
            this.rbtnEatIn.Size = new System.Drawing.Size(53, 17);
            this.rbtnEatIn.TabIndex = 3;
            this.rbtnEatIn.Text = "Eat In";
            this.rbtnEatIn.UseVisualStyleBackColor = true;
            this.rbtnEatIn.CheckedChanged += new System.EventHandler(this.rbtnEatIn_CheckedChanged);
            // 
            // cboxExtraChees
            // 
            this.cboxExtraChees.AutoSize = true;
            this.cboxExtraChees.Location = new System.Drawing.Point(34, 30);
            this.cboxExtraChees.Name = "cboxExtraChees";
            this.cboxExtraChees.Size = new System.Drawing.Size(83, 17);
            this.cboxExtraChees.TabIndex = 9;
            this.cboxExtraChees.Tag = "5";
            this.cboxExtraChees.Text = "Extra Chees";
            this.cboxExtraChees.UseVisualStyleBackColor = true;
            this.cboxExtraChees.CheckedChanged += new System.EventHandler(this.cboxExtraChees_CheckedChanged);
            // 
            // cboxMushrooms
            // 
            this.cboxMushrooms.AutoSize = true;
            this.cboxMushrooms.Location = new System.Drawing.Point(34, 54);
            this.cboxMushrooms.Name = "cboxMushrooms";
            this.cboxMushrooms.Size = new System.Drawing.Size(80, 17);
            this.cboxMushrooms.TabIndex = 10;
            this.cboxMushrooms.Tag = "5";
            this.cboxMushrooms.Text = "Mushrooms";
            this.cboxMushrooms.UseVisualStyleBackColor = true;
            this.cboxMushrooms.CheckedChanged += new System.EventHandler(this.cboxMushrooms_CheckedChanged);
            // 
            // cboxTomatoes
            // 
            this.cboxTomatoes.AutoSize = true;
            this.cboxTomatoes.Location = new System.Drawing.Point(34, 82);
            this.cboxTomatoes.Name = "cboxTomatoes";
            this.cboxTomatoes.Size = new System.Drawing.Size(73, 17);
            this.cboxTomatoes.TabIndex = 11;
            this.cboxTomatoes.Tag = "5";
            this.cboxTomatoes.Text = "Tomatoes";
            this.cboxTomatoes.UseVisualStyleBackColor = true;
            this.cboxTomatoes.CheckedChanged += new System.EventHandler(this.cboxTomatoes_CheckedChanged);
            // 
            // cboxOnion
            // 
            this.cboxOnion.AutoSize = true;
            this.cboxOnion.Location = new System.Drawing.Point(151, 30);
            this.cboxOnion.Name = "cboxOnion";
            this.cboxOnion.Size = new System.Drawing.Size(54, 17);
            this.cboxOnion.TabIndex = 12;
            this.cboxOnion.Tag = "5";
            this.cboxOnion.Text = "Onion";
            this.cboxOnion.UseVisualStyleBackColor = true;
            this.cboxOnion.CheckedChanged += new System.EventHandler(this.cboxOnion_CheckedChanged);
            // 
            // cboxOlives
            // 
            this.cboxOlives.AutoSize = true;
            this.cboxOlives.Location = new System.Drawing.Point(151, 53);
            this.cboxOlives.Name = "cboxOlives";
            this.cboxOlives.Size = new System.Drawing.Size(55, 17);
            this.cboxOlives.TabIndex = 13;
            this.cboxOlives.Tag = "5";
            this.cboxOlives.Text = "Olives";
            this.cboxOlives.UseVisualStyleBackColor = true;
            this.cboxOlives.CheckedChanged += new System.EventHandler(this.cboxOlives_CheckedChanged);
            // 
            // cboxGreenPeppers
            // 
            this.cboxGreenPeppers.AutoSize = true;
            this.cboxGreenPeppers.Location = new System.Drawing.Point(151, 82);
            this.cboxGreenPeppers.Name = "cboxGreenPeppers";
            this.cboxGreenPeppers.Size = new System.Drawing.Size(97, 17);
            this.cboxGreenPeppers.TabIndex = 14;
            this.cboxGreenPeppers.Tag = "5";
            this.cboxGreenPeppers.Text = "Green Peppers";
            this.cboxGreenPeppers.UseVisualStyleBackColor = true;
            this.cboxGreenPeppers.CheckedChanged += new System.EventHandler(this.cboxGreenPeppers_CheckedChanged);
            // 
            // gboToppings
            // 
            this.gboToppings.BackColor = System.Drawing.Color.Brown;
            this.gboToppings.Controls.Add(this.cboxGreenPeppers);
            this.gboToppings.Controls.Add(this.cboxOlives);
            this.gboToppings.Controls.Add(this.cboxOnion);
            this.gboToppings.Controls.Add(this.cboxTomatoes);
            this.gboToppings.Controls.Add(this.cboxMushrooms);
            this.gboToppings.Controls.Add(this.cboxExtraChees);
            this.gboToppings.Location = new System.Drawing.Point(547, 109);
            this.gboToppings.Name = "gboToppings";
            this.gboToppings.Size = new System.Drawing.Size(264, 119);
            this.gboToppings.TabIndex = 0;
            this.gboToppings.TabStop = false;
            this.gboToppings.Text = "Toppings";
            // 
            // labOrdrerSummary
            // 
            this.labOrdrerSummary.AutoSize = true;
            this.labOrdrerSummary.Font = new System.Drawing.Font("Monotype Corsiva", 20.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labOrdrerSummary.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.labOrdrerSummary.Location = new System.Drawing.Point(419, 289);
            this.labOrdrerSummary.Name = "labOrdrerSummary";
            this.labOrdrerSummary.Size = new System.Drawing.Size(175, 33);
            this.labOrdrerSummary.TabIndex = 9;
            this.labOrdrerSummary.Text = "Order Summary";
            // 
            // labSize
            // 
            this.labSize.AutoSize = true;
            this.labSize.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labSize.Location = new System.Drawing.Point(506, 336);
            this.labSize.Name = "labSize";
            this.labSize.Size = new System.Drawing.Size(57, 45);
            this.labSize.TabIndex = 10;
            this.labSize.Text = "Size:";
            // 
            // labCrustType
            // 
            this.labCrustType.AutoSize = true;
            this.labCrustType.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labCrustType.Location = new System.Drawing.Point(506, 483);
            this.labCrustType.Name = "labCrustType";
            this.labCrustType.Size = new System.Drawing.Size(114, 45);
            this.labCrustType.TabIndex = 11;
            this.labCrustType.Text = "Crust Type:";
            // 
            // labToppings
            // 
            this.labToppings.AutoSize = true;
            this.labToppings.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labToppings.Location = new System.Drawing.Point(506, 376);
            this.labToppings.Name = "labToppings";
            this.labToppings.Size = new System.Drawing.Size(101, 45);
            this.labToppings.TabIndex = 12;
            this.labToppings.Text = "Toppings:";
            // 
            // labWhereToEat
            // 
            this.labWhereToEat.AutoSize = true;
            this.labWhereToEat.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labWhereToEat.Location = new System.Drawing.Point(506, 531);
            this.labWhereToEat.Name = "labWhereToEat";
            this.labWhereToEat.Size = new System.Drawing.Size(135, 45);
            this.labWhereToEat.TabIndex = 13;
            this.labWhereToEat.Text = "Where To Eat:";
            // 
            // labTotalPrice
            // 
            this.labTotalPrice.AutoSize = true;
            this.labTotalPrice.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labTotalPrice.Location = new System.Drawing.Point(506, 591);
            this.labTotalPrice.Name = "labTotalPrice";
            this.labTotalPrice.Size = new System.Drawing.Size(121, 45);
            this.labTotalPrice.TabIndex = 14;
            this.labTotalPrice.Text = "Total Pricce:";
            // 
            // labTotalPriceNum
            // 
            this.labTotalPriceNum.AutoSize = true;
            this.labTotalPriceNum.Font = new System.Drawing.Font("Georgia", 36F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labTotalPriceNum.ForeColor = System.Drawing.Color.ForestGreen;
            this.labTotalPriceNum.Location = new System.Drawing.Point(647, 591);
            this.labTotalPriceNum.Name = "labTotalPriceNum";
            this.labTotalPriceNum.Size = new System.Drawing.Size(89, 56);
            this.labTotalPriceNum.TabIndex = 19;
            this.labTotalPriceNum.Text = "$0";
            this.labTotalPriceNum.Click += new System.EventHandler(this.labTotalPriceNum_Click);
            // 
            // labCrustTypeOp
            // 
            this.labCrustTypeOp.AutoSize = true;
            this.labCrustTypeOp.Font = new System.Drawing.Font("Gadugi", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labCrustTypeOp.Location = new System.Drawing.Point(633, 500);
            this.labCrustTypeOp.Name = "labCrustTypeOp";
            this.labCrustTypeOp.Size = new System.Drawing.Size(80, 19);
            this.labCrustTypeOp.TabIndex = 18;
            this.labCrustTypeOp.Text = "Thick Crust";
            // 
            // labToppingsOp
            // 
            this.labToppingsOp.AutoEllipsis = true;
            this.labToppingsOp.Font = new System.Drawing.Font("Gadugi", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labToppingsOp.Location = new System.Drawing.Point(562, 432);
            this.labToppingsOp.Name = "labToppingsOp";
            this.labToppingsOp.Size = new System.Drawing.Size(259, 51);
            this.labToppingsOp.TabIndex = 17;
            this.labToppingsOp.Text = "No Toppings";
            // 
            // labWhereToEatOp
            // 
            this.labWhereToEatOp.AutoSize = true;
            this.labWhereToEatOp.Font = new System.Drawing.Font("Gadugi", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labWhereToEatOp.Location = new System.Drawing.Point(662, 548);
            this.labWhereToEatOp.Name = "labWhereToEatOp";
            this.labWhereToEatOp.Size = new System.Drawing.Size(46, 19);
            this.labWhereToEatOp.TabIndex = 16;
            this.labWhereToEatOp.Text = "Eat In";
            // 
            // labSizeOp
            // 
            this.labSizeOp.AutoSize = true;
            this.labSizeOp.Font = new System.Drawing.Font("Gadugi", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labSizeOp.Location = new System.Drawing.Point(562, 353);
            this.labSizeOp.Name = "labSizeOp";
            this.labSizeOp.Size = new System.Drawing.Size(46, 19);
            this.labSizeOp.TabIndex = 15;
            this.labSizeOp.Text = "Small";
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.BackColor = System.Drawing.Color.White;
            this.btnOrderPizza.FlatAppearance.BorderColor = System.Drawing.Color.Maroon;
            this.btnOrderPizza.Font = new System.Drawing.Font("Microsoft YaHei", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnOrderPizza.Location = new System.Drawing.Point(485, 680);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(83, 26);
            this.btnOrderPizza.TabIndex = 20;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = false;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            // 
            // btnRestForm
            // 
            this.btnRestForm.Location = new System.Drawing.Point(637, 680);
            this.btnRestForm.Name = "btnRestForm";
            this.btnRestForm.Size = new System.Drawing.Size(83, 26);
            this.btnRestForm.TabIndex = 21;
            this.btnRestForm.Text = "Reset Form";
            this.btnRestForm.UseVisualStyleBackColor = true;
            this.btnRestForm.Click += new System.EventHandler(this.btnRestForm_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.CausesValidation = false;
            this.ClientSize = new System.Drawing.Size(877, 743);
            this.Controls.Add(this.labToppingsOp);
            this.Controls.Add(this.btnRestForm);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.labTotalPriceNum);
            this.Controls.Add(this.labCrustTypeOp);
            this.Controls.Add(this.labWhereToEatOp);
            this.Controls.Add(this.labSizeOp);
            this.Controls.Add(this.labTotalPrice);
            this.Controls.Add(this.labWhereToEat);
            this.Controls.Add(this.labCrustType);
            this.Controls.Add(this.labSize);
            this.Controls.Add(this.labOrdrerSummary);
            this.Controls.Add(this.gboToppings);
            this.Controls.Add(this.gboxWhereToEat);
            this.Controls.Add(this.gboxCrustType);
            this.Controls.Add(this.gboxSize);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.labToppings);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.gboxSize.ResumeLayout(false);
            this.gboxSize.PerformLayout();
            this.gboxCrustType.ResumeLayout(false);
            this.gboxCrustType.PerformLayout();
            this.gboxWhereToEat.ResumeLayout(false);
            this.gboxWhereToEat.PerformLayout();
            this.gboToppings.ResumeLayout(false);
            this.gboToppings.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RadioButton rbtnSmall;
        private System.Windows.Forms.RadioButton rbtnMedium;
        private System.Windows.Forms.RadioButton rbtnLarg;
        private System.Windows.Forms.GroupBox gboxSize;
        private System.Windows.Forms.GroupBox gboxCrustType;
        private System.Windows.Forms.RadioButton rbtnThickCrust;
        private System.Windows.Forms.RadioButton rbtnThinCrust;
        private System.Windows.Forms.GroupBox gboxWhereToEat;
        private System.Windows.Forms.RadioButton rbtnTakeOut;
        private System.Windows.Forms.RadioButton rbtnEatIn;
        private System.Windows.Forms.CheckBox cboxExtraChees;
        private System.Windows.Forms.CheckBox cboxMushrooms;
        private System.Windows.Forms.CheckBox cboxTomatoes;
        private System.Windows.Forms.CheckBox cboxOnion;
        private System.Windows.Forms.CheckBox cboxOlives;
        private System.Windows.Forms.CheckBox cboxGreenPeppers;
        private System.Windows.Forms.GroupBox gboToppings;
        private System.Windows.Forms.Label labOrdrerSummary;
        private System.Windows.Forms.Label labSize;
        private System.Windows.Forms.Label labCrustType;
        private System.Windows.Forms.Label labToppings;
        private System.Windows.Forms.Label labWhereToEat;
        private System.Windows.Forms.Label labTotalPrice;
        private System.Windows.Forms.Label labTotalPriceNum;
        private System.Windows.Forms.Label labCrustTypeOp;
        private System.Windows.Forms.Label labToppingsOp;
        private System.Windows.Forms.Label labWhereToEatOp;
        private System.Windows.Forms.Label labSizeOp;
        private System.Windows.Forms.Button btnOrderPizza;
        private System.Windows.Forms.Button btnRestForm;
    }
}

