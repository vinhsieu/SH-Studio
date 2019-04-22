namespace TilesetGenerator
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
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.btn_Generator = new System.Windows.Forms.Button();
            this.richTextBox_Matrix = new System.Windows.Forms.RichTextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.btn_filepath = new System.Windows.Forms.Button();
            this.btn_Export = new System.Windows.Forms.Button();
            this.rBtn_16bit = new System.Windows.Forms.RadioButton();
            this.rBtn_32bit = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox_Export = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Export)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // btn_Generator
            // 
            this.btn_Generator.Location = new System.Drawing.Point(667, 96);
            this.btn_Generator.Name = "btn_Generator";
            this.btn_Generator.Size = new System.Drawing.Size(75, 23);
            this.btn_Generator.TabIndex = 0;
            this.btn_Generator.Text = "Generator";
            this.btn_Generator.UseVisualStyleBackColor = true;
            this.btn_Generator.Click += new System.EventHandler(this.btn_Generator_Click);
            // 
            // richTextBox_Matrix
            // 
            this.richTextBox_Matrix.Location = new System.Drawing.Point(12, 96);
            this.richTextBox_Matrix.Name = "richTextBox_Matrix";
            this.richTextBox_Matrix.Size = new System.Drawing.Size(632, 96);
            this.richTextBox_Matrix.TabIndex = 1;
            this.richTextBox_Matrix.Text = "";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 48);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(510, 20);
            this.textBox1.TabIndex = 2;
            // 
            // btn_filepath
            // 
            this.btn_filepath.Location = new System.Drawing.Point(547, 48);
            this.btn_filepath.Name = "btn_filepath";
            this.btn_filepath.Size = new System.Drawing.Size(75, 23);
            this.btn_filepath.TabIndex = 3;
            this.btn_filepath.Text = "File Path";
            this.btn_filepath.UseVisualStyleBackColor = true;
            this.btn_filepath.Click += new System.EventHandler(this.btn_filepath_Click);
            // 
            // btn_Export
            // 
            this.btn_Export.Enabled = false;
            this.btn_Export.Location = new System.Drawing.Point(667, 125);
            this.btn_Export.Name = "btn_Export";
            this.btn_Export.Size = new System.Drawing.Size(75, 23);
            this.btn_Export.TabIndex = 5;
            this.btn_Export.Text = "Export";
            this.btn_Export.UseVisualStyleBackColor = true;
            this.btn_Export.Click += new System.EventHandler(this.btn_Export_Click);
            // 
            // rBtn_16bit
            // 
            this.rBtn_16bit.AutoSize = true;
            this.rBtn_16bit.Location = new System.Drawing.Point(667, 10);
            this.rBtn_16bit.Name = "rBtn_16bit";
            this.rBtn_16bit.Size = new System.Drawing.Size(52, 17);
            this.rBtn_16bit.TabIndex = 6;
            this.rBtn_16bit.Text = "16 Bit";
            this.rBtn_16bit.UseVisualStyleBackColor = true;
            // 
            // rBtn_32bit
            // 
            this.rBtn_32bit.AutoSize = true;
            this.rBtn_32bit.Location = new System.Drawing.Point(667, 34);
            this.rBtn_32bit.Name = "rBtn_32bit";
            this.rBtn_32bit.Size = new System.Drawing.Size(52, 17);
            this.rBtn_32bit.TabIndex = 7;
            this.rBtn_32bit.Text = "32 Bit";
            this.rBtn_32bit.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.Control;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.MenuHighlight;
            this.label1.Location = new System.Drawing.Point(22, 10);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(181, 25);
            this.label1.TabIndex = 8;
            this.label1.Text = "TileSet Generator";
            // 
            // pictureBox_Export
            // 
            this.pictureBox_Export.Location = new System.Drawing.Point(12, 236);
            this.pictureBox_Export.Name = "pictureBox_Export";
            this.pictureBox_Export.Size = new System.Drawing.Size(632, 136);
            this.pictureBox_Export.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_Export.TabIndex = 9;
            this.pictureBox_Export.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pictureBox_Export);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.rBtn_32bit);
            this.Controls.Add(this.rBtn_16bit);
            this.Controls.Add(this.btn_Export);
            this.Controls.Add(this.btn_filepath);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.richTextBox_Matrix);
            this.Controls.Add(this.btn_Generator);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Export)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button btn_Generator;
        private System.Windows.Forms.RichTextBox richTextBox_Matrix;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button btn_filepath;
        private System.Windows.Forms.Button btn_Export;
        private System.Windows.Forms.RadioButton rBtn_16bit;
        private System.Windows.Forms.RadioButton rBtn_32bit;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.PictureBox pictureBox_Export;
    }
}

