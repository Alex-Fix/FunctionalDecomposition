
namespace UI
{
    partial class MainForm
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
            this.DimensionNUD = new System.Windows.Forms.NumericUpDown();
            this.SetBtn = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.CalculateBtn = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.ClearBtn = new System.Windows.Forms.Button();
            this.tableLayoutPanel4 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel5 = new System.Windows.Forms.TableLayoutPanel();
            this.C1Radio = new System.Windows.Forms.RadioButton();
            this.B1Radio = new System.Windows.Forms.RadioButton();
            this.B2Radio = new System.Windows.Forms.RadioButton();
            this.A2Radio = new System.Windows.Forms.RadioButton();
            this.A1Radio = new System.Windows.Forms.RadioButton();
            this.label8 = new System.Windows.Forms.Label();
            this.ARadio = new System.Windows.Forms.RadioButton();
            this.tableLayoutPanel6 = new System.Windows.Forms.TableLayoutPanel();
            this.FilRandomlyBtn = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.DataGrid = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.DimensionNUD)).BeginInit();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.tableLayoutPanel4.SuspendLayout();
            this.tableLayoutPanel5.SuspendLayout();
            this.tableLayoutPanel6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.DataGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // DimensionNUD
            // 
            this.DimensionNUD.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.DimensionNUD.Location = new System.Drawing.Point(3, 3);
            this.DimensionNUD.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.DimensionNUD.Name = "DimensionNUD";
            this.DimensionNUD.Size = new System.Drawing.Size(170, 26);
            this.DimensionNUD.TabIndex = 1;
            this.DimensionNUD.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.DimensionNUD.ValueChanged += new System.EventHandler(this.DimentionNUDChanged);
            // 
            // SetBtn
            // 
            this.SetBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.SetBtn.Location = new System.Drawing.Point(355, 3);
            this.SetBtn.Name = "SetBtn";
            this.SetBtn.Size = new System.Drawing.Size(172, 28);
            this.SetBtn.TabIndex = 3;
            this.SetBtn.Text = "Задати";
            this.SetBtn.UseVisualStyleBackColor = true;
            this.SetBtn.Click += new System.EventHandler(this.FillMatrixClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(952, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "label1";
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel2, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.DataGrid, 1, 0);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(12, 12);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(1085, 645);
            this.tableLayoutPanel1.TabIndex = 7;
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 1;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel2.Controls.Add(this.CalculateBtn, 0, 8);
            this.tableLayoutPanel2.Controls.Add(this.label7, 0, 5);
            this.tableLayoutPanel2.Controls.Add(this.label6, 0, 4);
            this.tableLayoutPanel2.Controls.Add(this.label5, 0, 3);
            this.tableLayoutPanel2.Controls.Add(this.label3, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.label2, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.label4, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.tableLayoutPanel3, 0, 6);
            this.tableLayoutPanel2.Controls.Add(this.tableLayoutPanel4, 0, 7);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(3, 3);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 9;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.Size = new System.Drawing.Size(536, 639);
            this.tableLayoutPanel2.TabIndex = 1;
            // 
            // CalculateBtn
            // 
            this.CalculateBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CalculateBtn.Location = new System.Drawing.Point(3, 398);
            this.CalculateBtn.Name = "CalculateBtn";
            this.CalculateBtn.Size = new System.Drawing.Size(530, 240);
            this.CalculateBtn.TabIndex = 15;
            this.CalculateBtn.Text = "Розрахувати";
            this.CalculateBtn.UseVisualStyleBackColor = true;
            this.CalculateBtn.Click += new System.EventHandler(this.CalculateBtnClick);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label7.Location = new System.Drawing.Point(3, 100);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(173, 20);
            this.label7.TabIndex = 12;
            this.label7.Text = "Задати розмірність N";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label6.Location = new System.Drawing.Point(3, 80);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(115, 20);
            this.label6.TabIndex = 11;
            this.label6.Text = "y2=A2*(B2-C2)";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(3, 60);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(134, 20);
            this.label5.TabIndex = 10;
            this.label5.Text = "y1=A1*(12*b1-c1)";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(3, 20);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(257, 20);
            this.label3.TabIndex = 8;
            this.label3.Text = "b=i^2/12, i - парне ; b=i, i - непарне";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(3, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(295, 20);
            this.label2.TabIndex = 8;
            this.label2.Text = "x=y\'2+((y\'1*(Y3^2*y1+y2)*Y3+y1+y\'1)*y2)\'";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(3, 40);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(97, 20);
            this.label4.TabIndex = 9;
            this.label4.Text = "Cji = 1/(i+j^2)";
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 3;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel3.Controls.Add(this.ClearBtn, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.DimensionNUD, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.SetBtn, 1, 0);
            this.tableLayoutPanel3.Location = new System.Drawing.Point(3, 123);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 1;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(530, 34);
            this.tableLayoutPanel3.TabIndex = 13;
            // 
            // ClearBtn
            // 
            this.ClearBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ClearBtn.Location = new System.Drawing.Point(179, 3);
            this.ClearBtn.Name = "ClearBtn";
            this.ClearBtn.Size = new System.Drawing.Size(170, 28);
            this.ClearBtn.TabIndex = 4;
            this.ClearBtn.Text = "Очистити";
            this.ClearBtn.UseVisualStyleBackColor = true;
            this.ClearBtn.Click += new System.EventHandler(this.ClearBtnClick);
            // 
            // tableLayoutPanel4
            // 
            this.tableLayoutPanel4.ColumnCount = 2;
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.Controls.Add(this.tableLayoutPanel5, 0, 0);
            this.tableLayoutPanel4.Controls.Add(this.tableLayoutPanel6, 1, 0);
            this.tableLayoutPanel4.Location = new System.Drawing.Point(3, 163);
            this.tableLayoutPanel4.Name = "tableLayoutPanel4";
            this.tableLayoutPanel4.RowCount = 1;
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.Size = new System.Drawing.Size(530, 229);
            this.tableLayoutPanel4.TabIndex = 14;
            // 
            // tableLayoutPanel5
            // 
            this.tableLayoutPanel5.ColumnCount = 1;
            this.tableLayoutPanel5.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel5.Controls.Add(this.C1Radio, 0, 6);
            this.tableLayoutPanel5.Controls.Add(this.B1Radio, 0, 5);
            this.tableLayoutPanel5.Controls.Add(this.B2Radio, 0, 4);
            this.tableLayoutPanel5.Controls.Add(this.A2Radio, 0, 3);
            this.tableLayoutPanel5.Controls.Add(this.A1Radio, 0, 2);
            this.tableLayoutPanel5.Controls.Add(this.label8, 0, 0);
            this.tableLayoutPanel5.Controls.Add(this.ARadio, 0, 1);
            this.tableLayoutPanel5.Location = new System.Drawing.Point(3, 3);
            this.tableLayoutPanel5.Name = "tableLayoutPanel5";
            this.tableLayoutPanel5.RowCount = 7;
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel5.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel5.Size = new System.Drawing.Size(259, 223);
            this.tableLayoutPanel5.TabIndex = 0;
            // 
            // C1Radio
            // 
            this.C1Radio.AutoSize = true;
            this.C1Radio.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.C1Radio.Location = new System.Drawing.Point(3, 173);
            this.C1Radio.Name = "C1Radio";
            this.C1Radio.Size = new System.Drawing.Size(122, 24);
            this.C1Radio.TabIndex = 19;
            this.C1Radio.TabStop = true;
            this.C1Radio.Text = "Стовпець c1";
            this.C1Radio.UseVisualStyleBackColor = true;
            this.C1Radio.CheckedChanged += new System.EventHandler(this.RadioCheckedChanged);
            // 
            // B1Radio
            // 
            this.B1Radio.AutoSize = true;
            this.B1Radio.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.B1Radio.Location = new System.Drawing.Point(3, 143);
            this.B1Radio.Name = "B1Radio";
            this.B1Radio.Size = new System.Drawing.Size(123, 24);
            this.B1Radio.TabIndex = 18;
            this.B1Radio.TabStop = true;
            this.B1Radio.Text = "Стовпець b1";
            this.B1Radio.UseVisualStyleBackColor = true;
            this.B1Radio.CheckedChanged += new System.EventHandler(this.RadioCheckedChanged);
            // 
            // B2Radio
            // 
            this.B2Radio.AutoSize = true;
            this.B2Radio.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.B2Radio.Location = new System.Drawing.Point(3, 113);
            this.B2Radio.Name = "B2Radio";
            this.B2Radio.Size = new System.Drawing.Size(118, 24);
            this.B2Radio.TabIndex = 17;
            this.B2Radio.TabStop = true;
            this.B2Radio.Text = "Матриця B2";
            this.B2Radio.UseVisualStyleBackColor = true;
            this.B2Radio.CheckedChanged += new System.EventHandler(this.RadioCheckedChanged);
            // 
            // A2Radio
            // 
            this.A2Radio.AutoSize = true;
            this.A2Radio.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.A2Radio.Location = new System.Drawing.Point(3, 83);
            this.A2Radio.Name = "A2Radio";
            this.A2Radio.Size = new System.Drawing.Size(118, 24);
            this.A2Radio.TabIndex = 16;
            this.A2Radio.TabStop = true;
            this.A2Radio.Text = "Матриця А2";
            this.A2Radio.UseVisualStyleBackColor = true;
            this.A2Radio.CheckedChanged += new System.EventHandler(this.RadioCheckedChanged);
            // 
            // A1Radio
            // 
            this.A1Radio.AutoSize = true;
            this.A1Radio.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.A1Radio.Location = new System.Drawing.Point(3, 53);
            this.A1Radio.Name = "A1Radio";
            this.A1Radio.Size = new System.Drawing.Size(118, 24);
            this.A1Radio.TabIndex = 15;
            this.A1Radio.TabStop = true;
            this.A1Radio.Text = "Матриця А1";
            this.A1Radio.UseVisualStyleBackColor = true;
            this.A1Radio.CheckedChanged += new System.EventHandler(this.RadioCheckedChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label8.Location = new System.Drawing.Point(3, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(127, 20);
            this.label8.TabIndex = 13;
            this.label8.Text = "Вибір елементу";
            // 
            // ARadio
            // 
            this.ARadio.AutoSize = true;
            this.ARadio.Checked = true;
            this.ARadio.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ARadio.Location = new System.Drawing.Point(3, 23);
            this.ARadio.Name = "ARadio";
            this.ARadio.Size = new System.Drawing.Size(109, 24);
            this.ARadio.TabIndex = 14;
            this.ARadio.TabStop = true;
            this.ARadio.Text = "Матриця А";
            this.ARadio.UseVisualStyleBackColor = true;
            this.ARadio.CheckedChanged += new System.EventHandler(this.RadioCheckedChanged);
            // 
            // tableLayoutPanel6
            // 
            this.tableLayoutPanel6.ColumnCount = 1;
            this.tableLayoutPanel6.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel6.Controls.Add(this.FilRandomlyBtn, 0, 1);
            this.tableLayoutPanel6.Controls.Add(this.label9, 0, 0);
            this.tableLayoutPanel6.Location = new System.Drawing.Point(268, 3);
            this.tableLayoutPanel6.Name = "tableLayoutPanel6";
            this.tableLayoutPanel6.RowCount = 2;
            this.tableLayoutPanel6.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.23358F));
            this.tableLayoutPanel6.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 85.76643F));
            this.tableLayoutPanel6.Size = new System.Drawing.Size(259, 223);
            this.tableLayoutPanel6.TabIndex = 1;
            // 
            // FilRandomlyBtn
            // 
            this.FilRandomlyBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.FilRandomlyBtn.Location = new System.Drawing.Point(3, 34);
            this.FilRandomlyBtn.Name = "FilRandomlyBtn";
            this.FilRandomlyBtn.Size = new System.Drawing.Size(253, 186);
            this.FilRandomlyBtn.TabIndex = 16;
            this.FilRandomlyBtn.Text = "Заповнити випадковими числами";
            this.FilRandomlyBtn.UseVisualStyleBackColor = true;
            this.FilRandomlyBtn.Click += new System.EventHandler(this.FillMatrixRandomly);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label9.Location = new System.Drawing.Point(3, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(178, 20);
            this.label9.TabIndex = 14;
            this.label9.Text = "Заповнення елементу";
            // 
            // DataGrid
            // 
            this.DataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DataGrid.Location = new System.Drawing.Point(545, 3);
            this.DataGrid.Name = "DataGrid";
            this.DataGrid.Size = new System.Drawing.Size(537, 639);
            this.DataGrid.TabIndex = 2;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1103, 665);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.label1);
            this.Name = "MainForm";
            this.Text = "MainForm";
            ((System.ComponentModel.ISupportInitialize)(this.DimensionNUD)).EndInit();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel4.ResumeLayout(false);
            this.tableLayoutPanel5.ResumeLayout(false);
            this.tableLayoutPanel5.PerformLayout();
            this.tableLayoutPanel6.ResumeLayout(false);
            this.tableLayoutPanel6.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.DataGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.NumericUpDown DimensionNUD;
        private System.Windows.Forms.Button SetBtn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel4;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel5;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.RadioButton C1Radio;
        private System.Windows.Forms.RadioButton B1Radio;
        private System.Windows.Forms.RadioButton B2Radio;
        private System.Windows.Forms.RadioButton A2Radio;
        private System.Windows.Forms.RadioButton A1Radio;
        private System.Windows.Forms.RadioButton ARadio;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel6;
        private System.Windows.Forms.Button FilRandomlyBtn;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button CalculateBtn;
        private System.Windows.Forms.DataGridView DataGrid;
        private System.Windows.Forms.Button ClearBtn;
    }
}