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
            this.pictureBox1.Location = new System.Drawing.Point(-7, -1);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(520, 876);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Cursor = System.Windows.Forms.Cursors.Default;
            this.label1.Font = new System.Drawing.Font("Monotype Corsiva", 48F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.label1.Location = new System.Drawing.Point(515, -1);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(560, 97);
            this.label1.TabIndex = 1;
            this.label1.Text = "Make Your Pizza";
            // 
            // rbtnSmall
            // 
            this.rbtnSmall.AutoSize = true;
            this.rbtnSmall.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnSmall.Location = new System.Drawing.Point(44, 23);
            this.rbtnSmall.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbtnSmall.Name = "rbtnSmall";
            this.rbtnSmall.Size = new System.Drawing.Size(63, 21);
            this.rbtnSmall.TabIndex = 3;
            this.rbtnSmall.Text = "Small";
            this.rbtnSmall.UseVisualStyleBackColor = true;
            this.rbtnSmall.CheckedChanged += new System.EventHandler(this.rbtnSmall_CheckedChanged);
            // 
            // rbtnMedium
            // 
            this.rbtnMedium.AutoSize = true;
            this.rbtnMedium.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnMedium.Location = new System.Drawing.Point(44, 52);
            this.rbtnMedium.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbtnMedium.Name = "rbtnMedium";
            this.rbtnMedium.Size = new System.Drawing.Size(78, 21);
            this.rbtnMedium.TabIndex = 4;
            this.rbtnMedium.Text = "Medium";
            this.rbtnMedium.UseVisualStyleBackColor = true;
            this.rbtnMedium.CheckedChanged += new System.EventHandler(this.rbtnMedium_CheckedChanged);
            // 
            // rbtnLarg
            // 
            this.rbtnLarg.AutoSize = true;
            this.rbtnLarg.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnLarg.Location = new System.Drawing.Point(44, 80);
            this.rbtnLarg.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbtnLarg.Name = "rbtnLarg";
            this.rbtnLarg.Size = new System.Drawing.Size(58, 21);
            this.rbtnLarg.TabIndex = 5;
            this.rbtnLarg.Text = "Larg";
            this.rbtnLarg.UseVisualStyleBackColor = true;
            this.rbtnLarg.CheckedChanged += new System.EventHandler(this.rbtnLarg_CheckedChanged);
            // 
            // gboxSize
            // 
            this.gboxSize.Controls.Add(this.rbtnLarg);
            this.gboxSize.Controls.Add(this.rbtnMedium);
            this.gboxSize.Controls.Add(this.rbtnSmall);
            this.gboxSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gboxSize.Location = new System.Drawing.Point(520, 128);
            this.gboxSize.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.gboxSize.Name = "gboxSize";
            this.gboxSize.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.gboxSize.Size = new System.Drawing.Size(148, 108);
            this.gboxSize.TabIndex = 6;
            this.gboxSize.TabStop = false;
            this.gboxSize.Text = "Size";
            // 
            // gboxCrustType
            // 
            this.gboxCrustType.Controls.Add(this.rbtnThickCrust);
            this.gboxCrustType.Controls.Add(this.rbtnThinCrust);
            this.gboxCrustType.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gboxCrustType.Location = new System.Drawing.Point(516, 262);
            this.gboxCrustType.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.gboxCrustType.Name = "gboxCrustType";
            this.gboxCrustType.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.gboxCrustType.Size = new System.Drawing.Size(148, 79);
            this.gboxCrustType.TabIndex = 7;
            this.gboxCrustType.TabStop = false;
            this.gboxCrustType.Text = "Crust Type";
            // 
            // rbtnThickCrust
            // 
            this.rbtnThickCrust.AutoSize = true;
            this.rbtnThickCrust.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnThickCrust.Location = new System.Drawing.Point(41, 53);
            this.rbtnThickCrust.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbtnThickCrust.Name = "rbtnThickCrust";
            this.rbtnThickCrust.Size = new System.Drawing.Size(100, 21);
            this.rbtnThickCrust.TabIndex = 4;
            this.rbtnThickCrust.Text = "Thick Crust";
            this.rbtnThickCrust.UseVisualStyleBackColor = true;
            this.rbtnThickCrust.CheckedChanged += new System.EventHandler(this.rbtnThickCrust_CheckedChanged);
            // 
            // rbtnThinCrust
            // 
            this.rbtnThinCrust.AutoSize = true;
            this.rbtnThinCrust.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnThinCrust.Location = new System.Drawing.Point(43, 25);
            this.rbtnThinCrust.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbtnThinCrust.Name = "rbtnThinCrust";
            this.rbtnThinCrust.Size = new System.Drawing.Size(94, 21);
            this.rbtnThinCrust.TabIndex = 3;
            this.rbtnThinCrust.Text = "Thin Crust";
            this.rbtnThinCrust.UseVisualStyleBackColor = true;
            this.rbtnThinCrust.CheckedChanged += new System.EventHandler(this.rbtnThinCrust_CheckedChanged);
            // 
            // gboxWhereToEat
            // 
            this.gboxWhereToEat.Controls.Add(this.rbtnTakeOut);
            this.gboxWhereToEat.Controls.Add(this.rbtnEatIn);
            this.gboxWhereToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gboxWhereToEat.Location = new System.Drawing.Point(693, 282);
            this.gboxWhereToEat.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.gboxWhereToEat.Name = "gboxWhereToEat";
            this.gboxWhereToEat.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.gboxWhereToEat.Size = new System.Drawing.Size(352, 59);
            this.gboxWhereToEat.TabIndex = 8;
            this.gboxWhereToEat.TabStop = false;
            this.gboxWhereToEat.Text = "Where To Eat";
            this.gboxWhereToEat.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // rbtnTakeOut
            // 
            this.rbtnTakeOut.AutoSize = true;
            this.rbtnTakeOut.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnTakeOut.Location = new System.Drawing.Point(160, 25);
            this.rbtnTakeOut.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbtnTakeOut.Name = "rbtnTakeOut";
            this.rbtnTakeOut.Size = new System.Drawing.Size(88, 21);
            this.rbtnTakeOut.TabIndex = 4;
            this.rbtnTakeOut.Text = "Take Out";
            this.rbtnTakeOut.UseVisualStyleBackColor = true;
            this.rbtnTakeOut.CheckedChanged += new System.EventHandler(this.rbtnTakeOut_CheckedChanged);
            // 
            // rbtnEatIn
            // 
            this.rbtnEatIn.AutoSize = true;
            this.rbtnEatIn.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rbtnEatIn.Location = new System.Drawing.Point(43, 25);
            this.rbtnEatIn.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.rbtnEatIn.Name = "rbtnEatIn";
            this.rbtnEatIn.Size = new System.Drawing.Size(65, 21);
            this.rbtnEatIn.TabIndex = 3;
            this.rbtnEatIn.Text = "Eat In";
            this.rbtnEatIn.UseVisualStyleBackColor = true;
            this.rbtnEatIn.CheckedChanged += new System.EventHandler(this.rbtnEatIn_CheckedChanged);
            // 
            // cboxExtraChees
            // 
            this.cboxExtraChees.AutoSize = true;
            this.cboxExtraChees.Location = new System.Drawing.Point(45, 37);
            this.cboxExtraChees.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboxExtraChees.Name = "cboxExtraChees";
            this.cboxExtraChees.Size = new System.Drawing.Size(101, 20);
            this.cboxExtraChees.TabIndex = 9;
            this.cboxExtraChees.Text = "Extra Chees";
            this.cboxExtraChees.UseVisualStyleBackColor = true;
            this.cboxExtraChees.CheckedChanged += new System.EventHandler(this.cboxExtraChees_CheckedChanged);
            // 
            // cboxMushrooms
            // 
            this.cboxMushrooms.AutoSize = true;
            this.cboxMushrooms.Location = new System.Drawing.Point(45, 66);
            this.cboxMushrooms.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboxMushrooms.Name = "cboxMushrooms";
            this.cboxMushrooms.Size = new System.Drawing.Size(99, 20);
            this.cboxMushrooms.TabIndex = 10;
            this.cboxMushrooms.Text = "Mushrooms";
            this.cboxMushrooms.UseVisualStyleBackColor = true;
            this.cboxMushrooms.CheckedChanged += new System.EventHandler(this.cboxMushrooms_CheckedChanged);
            // 
            // cboxTomatoes
            // 
            this.cboxTomatoes.AutoSize = true;
            this.cboxTomatoes.Location = new System.Drawing.Point(45, 101);
            this.cboxTomatoes.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboxTomatoes.Name = "cboxTomatoes";
            this.cboxTomatoes.Size = new System.Drawing.Size(91, 20);
            this.cboxTomatoes.TabIndex = 11;
            this.cboxTomatoes.Text = "Tomatoes";
            this.cboxTomatoes.UseVisualStyleBackColor = true;
            this.cboxTomatoes.CheckedChanged += new System.EventHandler(this.cboxTomatoes_CheckedChanged);
            // 
            // cboxOnion
            // 
            this.cboxOnion.AutoSize = true;
            this.cboxOnion.Location = new System.Drawing.Point(201, 37);
            this.cboxOnion.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboxOnion.Name = "cboxOnion";
            this.cboxOnion.Size = new System.Drawing.Size(64, 20);
            this.cboxOnion.TabIndex = 12;
            this.cboxOnion.Text = "Onion";
            this.cboxOnion.UseVisualStyleBackColor = true;
            this.cboxOnion.CheckedChanged += new System.EventHandler(this.cboxOnion_CheckedChanged);
            // 
            // cboxOlives
            // 
            this.cboxOlives.AutoSize = true;
            this.cboxOlives.Location = new System.Drawing.Point(201, 65);
            this.cboxOlives.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboxOlives.Name = "cboxOlives";
            this.cboxOlives.Size = new System.Drawing.Size(67, 20);
            this.cboxOlives.TabIndex = 13;
            this.cboxOlives.Text = "Olives";
            this.cboxOlives.UseVisualStyleBackColor = true;
            this.cboxOlives.CheckedChanged += new System.EventHandler(this.cboxOlives_CheckedChanged);
            // 
            // cboxGreenPeppers
            // 
            this.cboxGreenPeppers.AutoSize = true;
            this.cboxGreenPeppers.Location = new System.Drawing.Point(201, 101);
            this.cboxGreenPeppers.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.cboxGreenPeppers.Name = "cboxGreenPeppers";
            this.cboxGreenPeppers.Size = new System.Drawing.Size(121, 20);
            this.cboxGreenPeppers.TabIndex = 14;
            this.cboxGreenPeppers.Text = "Green Peppers";
            this.cboxGreenPeppers.UseVisualStyleBackColor = true;
            this.cboxGreenPeppers.CheckedChanged += new System.EventHandler(this.cboxGreenPeppers_CheckedChanged);
            // 
            // gboToppings
            // 
            this.gboToppings.Controls.Add(this.cboxGreenPeppers);
            this.gboToppings.Controls.Add(this.cboxOlives);
            this.gboToppings.Controls.Add(this.cboxOnion);
            this.gboToppings.Controls.Add(this.cboxTomatoes);
            this.gboToppings.Controls.Add(this.cboxMushrooms);
            this.gboToppings.Controls.Add(this.cboxExtraChees);
            this.gboToppings.Location = new System.Drawing.Point(693, 128);
            this.gboToppings.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.gboToppings.Name = "gboToppings";
            this.gboToppings.Padding = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.gboToppings.Size = new System.Drawing.Size(352, 146);
            this.gboToppings.TabIndex = 0;
            this.gboToppings.TabStop = false;
            this.gboToppings.Text = "Toppings";
            // 
            // labOrdrerSummary
            // 
            this.labOrdrerSummary.AutoSize = true;
            this.labOrdrerSummary.Font = new System.Drawing.Font("Monotype Corsiva", 20.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labOrdrerSummary.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.labOrdrerSummary.Location = new System.Drawing.Point(580, 369);
            this.labOrdrerSummary.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labOrdrerSummary.Name = "labOrdrerSummary";
            this.labOrdrerSummary.Size = new System.Drawing.Size(217, 41);
            this.labOrdrerSummary.TabIndex = 9;
            this.labOrdrerSummary.Text = "Order Summary";
            // 
            // labSize
            // 
            this.labSize.AutoSize = true;
            this.labSize.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labSize.Location = new System.Drawing.Point(673, 415);
            this.labSize.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labSize.Name = "labSize";
            this.labSize.Size = new System.Drawing.Size(70, 55);
            this.labSize.TabIndex = 10;
            this.labSize.Text = "Size:";
            // 
            // labCrustType
            // 
            this.labCrustType.AutoSize = true;
            this.labCrustType.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labCrustType.Location = new System.Drawing.Point(673, 560);
            this.labCrustType.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labCrustType.Name = "labCrustType";
            this.labCrustType.Size = new System.Drawing.Size(138, 55);
            this.labCrustType.TabIndex = 11;
            this.labCrustType.Text = "Crust Type:";
            // 
            // labToppings
            // 
            this.labToppings.AutoSize = true;
            this.labToppings.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labToppings.Location = new System.Drawing.Point(673, 454);
            this.labToppings.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labToppings.Name = "labToppings";
            this.labToppings.Size = new System.Drawing.Size(122, 55);
            this.labToppings.TabIndex = 12;
            this.labToppings.Text = "Toppings:";
            // 
            // labWhereToEat
            // 
            this.labWhereToEat.AutoSize = true;
            this.labWhereToEat.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labWhereToEat.Location = new System.Drawing.Point(673, 607);
            this.labWhereToEat.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labWhereToEat.Name = "labWhereToEat";
            this.labWhereToEat.Size = new System.Drawing.Size(164, 55);
            this.labWhereToEat.TabIndex = 13;
            this.labWhereToEat.Text = "Where To Eat:";
            // 
            // labTotalPrice
            // 
            this.labTotalPrice.AutoSize = true;
            this.labTotalPrice.Font = new System.Drawing.Font("Gabriola", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labTotalPrice.Location = new System.Drawing.Point(673, 666);
            this.labTotalPrice.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labTotalPrice.Name = "labTotalPrice";
            this.labTotalPrice.Size = new System.Drawing.Size(146, 55);
            this.labTotalPrice.TabIndex = 14;
            this.labTotalPrice.Text = "Total Pricce:";
            // 
            // labTotalPriceNum
            // 
            this.labTotalPriceNum.AutoSize = true;
            this.labTotalPriceNum.Font = new System.Drawing.Font("Georgia", 36F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labTotalPriceNum.ForeColor = System.Drawing.Color.ForestGreen;
            this.labTotalPriceNum.Location = new System.Drawing.Point(823, 666);
            this.labTotalPriceNum.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labTotalPriceNum.Name = "labTotalPriceNum";
            this.labTotalPriceNum.Size = new System.Drawing.Size(72, 69);
            this.labTotalPriceNum.TabIndex = 19;
            this.labTotalPriceNum.Text = "0";
            this.labTotalPriceNum.Click += new System.EventHandler(this.labTotalPriceNum_Click);
            // 
            // labCrustTypeOp
            // 
            this.labCrustTypeOp.AutoSize = true;
            this.labCrustTypeOp.Font = new System.Drawing.Font("Gadugi", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labCrustTypeOp.Location = new System.Drawing.Point(808, 577);
            this.labCrustTypeOp.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labCrustTypeOp.Name = "labCrustTypeOp";
            this.labCrustTypeOp.Size = new System.Drawing.Size(103, 22);
            this.labCrustTypeOp.TabIndex = 18;
            this.labCrustTypeOp.Text = "Thick Crust";
            // 
            // labToppingsOp
            // 
            this.labToppingsOp.AutoSize = true;
            this.labToppingsOp.Font = new System.Drawing.Font("Gadugi", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labToppingsOp.Location = new System.Drawing.Point(733, 510);
            this.labToppingsOp.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labToppingsOp.Name = "labToppingsOp";
            this.labToppingsOp.Size = new System.Drawing.Size(118, 22);
            this.labToppingsOp.TabIndex = 17;
            this.labToppingsOp.Text = "No Toppings";
            // 
            // labWhereToEatOp
            // 
            this.labWhereToEatOp.AutoSize = true;
            this.labWhereToEatOp.Font = new System.Drawing.Font("Gadugi", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labWhereToEatOp.Location = new System.Drawing.Point(839, 624);
            this.labWhereToEatOp.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labWhereToEatOp.Name = "labWhereToEatOp";
            this.labWhereToEatOp.Size = new System.Drawing.Size(57, 22);
            this.labWhereToEatOp.TabIndex = 16;
            this.labWhereToEatOp.Text = "Eat In";
            // 
            // labSizeOp
            // 
            this.labSizeOp.AutoSize = true;
            this.labSizeOp.Font = new System.Drawing.Font("Gadugi", 11.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labSizeOp.Location = new System.Drawing.Point(733, 432);
            this.labSizeOp.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labSizeOp.Name = "labSizeOp";
            this.labSizeOp.Size = new System.Drawing.Size(56, 22);
            this.labSizeOp.TabIndex = 15;
            this.labSizeOp.Text = "Small";
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.BackColor = System.Drawing.Color.White;
            this.btnOrderPizza.FlatAppearance.BorderColor = System.Drawing.Color.Maroon;
            this.btnOrderPizza.Font = new System.Drawing.Font("Microsoft YaHei", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnOrderPizza.Location = new System.Drawing.Point(647, 802);
            this.btnOrderPizza.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(111, 32);
            this.btnOrderPizza.TabIndex = 20;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = false;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            // 
            // btnRestForm
            // 
            this.btnRestForm.Location = new System.Drawing.Point(836, 802);
            this.btnRestForm.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnRestForm.Name = "btnRestForm";
            this.btnRestForm.Size = new System.Drawing.Size(111, 32);
            this.btnRestForm.TabIndex = 21;
            this.btnRestForm.Text = "Reset Form";
            this.btnRestForm.UseVisualStyleBackColor = true;
            this.btnRestForm.Click += new System.EventHandler(this.btnRestForm_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.CausesValidation = false;
            this.ClientSize = new System.Drawing.Size(1096, 878);
            this.Controls.Add(this.btnRestForm);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.labTotalPriceNum);
            this.Controls.Add(this.labCrustTypeOp);
            this.Controls.Add(this.labToppingsOp);
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
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
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

