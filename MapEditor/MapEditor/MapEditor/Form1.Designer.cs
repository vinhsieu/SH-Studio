namespace MapEditor
{
    partial class Form
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
            this.colorDialog = new System.Windows.Forms.ColorDialog();
            this.openImage = new System.Windows.Forms.OpenFileDialog();
            this.panel3 = new System.Windows.Forms.Panel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.cPanel1 = new MapEditor.CPanel();
            this.pictureBox_Map = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.button_ExportGrid = new System.Windows.Forms.Button();
            this.button_ZoomOut = new System.Windows.Forms.Button();
            this.button_ZoomIn = new System.Windows.Forms.Button();
            this.checkBox_fillColor = new System.Windows.Forms.CheckBox();
            this.label10 = new System.Windows.Forms.Label();
            this.button_Clear = new System.Windows.Forms.Button();
            this.button_Delete = new System.Windows.Forms.Button();
            this.textBox_NumObject = new System.Windows.Forms.TextBox();
            this.dataGridView_Object = new System.Windows.Forms.DataGridView();
            this.NameObject = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Type = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Direction = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Location = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.comboBox_Type = new System.Windows.Forms.ComboBox();
            this.comboBox_Direction = new System.Windows.Forms.ComboBox();
            this.comboBox_Name = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button_Reload = new System.Windows.Forms.Button();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.textBox_Cells_Width = new System.Windows.Forms.TextBox();
            this.textBox_Cells_Hight = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.button_ChooseFile = new System.Windows.Forms.Button();
            this.panel3.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.cPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Map)).BeginInit();
            this.panel2.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_Object)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.groupBox3);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel3.Location = new System.Drawing.Point(0, 0);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(1127, 520);
            this.panel3.TabIndex = 3;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.cPanel1);
            this.groupBox3.Controls.Add(this.panel2);
            this.groupBox3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox3.Location = new System.Drawing.Point(0, 0);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(1127, 520);
            this.groupBox3.TabIndex = 1;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Map";
            // 
            // cPanel1
            // 
            this.cPanel1.AutoScroll = true;
            this.cPanel1.Controls.Add(this.pictureBox_Map);
            this.cPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cPanel1.Location = new System.Drawing.Point(3, 16);
            this.cPanel1.Name = "cPanel1";
            this.cPanel1.Size = new System.Drawing.Size(1121, 366);
            this.cPanel1.TabIndex = 1;
            // 
            // pictureBox_Map
            // 
            this.pictureBox_Map.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.pictureBox_Map.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.pictureBox_Map.Location = new System.Drawing.Point(0, 0);
            this.pictureBox_Map.Name = "pictureBox_Map";
            this.pictureBox_Map.Size = new System.Drawing.Size(1012, 126);
            this.pictureBox_Map.TabIndex = 0;
            this.pictureBox_Map.TabStop = false;
            this.pictureBox_Map.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox_Map_Paint);
            this.pictureBox_Map.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox_Map_MouseDown);
            this.pictureBox_Map.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox_Map_MouseMove);
            this.pictureBox_Map.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBox_Map_MouseUp);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.groupBox2);
            this.panel2.Controls.Add(this.groupBox1);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel2.Location = new System.Drawing.Point(3, 382);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(1121, 135);
            this.panel2.TabIndex = 1;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.button_ExportGrid);
            this.groupBox2.Controls.Add(this.button_ZoomOut);
            this.groupBox2.Controls.Add(this.button_ZoomIn);
            this.groupBox2.Controls.Add(this.checkBox_fillColor);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.button_Clear);
            this.groupBox2.Controls.Add(this.button_Delete);
            this.groupBox2.Controls.Add(this.textBox_NumObject);
            this.groupBox2.Controls.Add(this.dataGridView_Object);
            this.groupBox2.Controls.Add(this.comboBox_Type);
            this.groupBox2.Controls.Add(this.comboBox_Direction);
            this.groupBox2.Controls.Add(this.comboBox_Name);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Left;
            this.groupBox2.Location = new System.Drawing.Point(228, 0);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(893, 135);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Setting Object";
            // 
            // button_ExportGrid
            // 
            this.button_ExportGrid.Location = new System.Drawing.Point(785, 79);
            this.button_ExportGrid.Name = "button_ExportGrid";
            this.button_ExportGrid.Size = new System.Drawing.Size(75, 23);
            this.button_ExportGrid.TabIndex = 16;
            this.button_ExportGrid.Text = "Export Grid";
            this.button_ExportGrid.UseVisualStyleBackColor = true;
            this.button_ExportGrid.Click += new System.EventHandler(this.button_ExportGrid_Click);
            // 
            // button_ZoomOut
            // 
            this.button_ZoomOut.Location = new System.Drawing.Point(87, 103);
            this.button_ZoomOut.Name = "button_ZoomOut";
            this.button_ZoomOut.Size = new System.Drawing.Size(75, 23);
            this.button_ZoomOut.TabIndex = 15;
            this.button_ZoomOut.Text = "Zoom Out";
            this.button_ZoomOut.UseVisualStyleBackColor = true;
            this.button_ZoomOut.Click += new System.EventHandler(this.button_ZoomOut_Click);
            // 
            // button_ZoomIn
            // 
            this.button_ZoomIn.Location = new System.Drawing.Point(6, 103);
            this.button_ZoomIn.Name = "button_ZoomIn";
            this.button_ZoomIn.Size = new System.Drawing.Size(75, 23);
            this.button_ZoomIn.TabIndex = 14;
            this.button_ZoomIn.Text = "Zoom In";
            this.button_ZoomIn.UseVisualStyleBackColor = true;
            this.button_ZoomIn.Click += new System.EventHandler(this.button_ZoomIn_Click);
            // 
            // checkBox_fillColor
            // 
            this.checkBox_fillColor.AutoSize = true;
            this.checkBox_fillColor.Location = new System.Drawing.Point(795, 108);
            this.checkBox_fillColor.Name = "checkBox_fillColor";
            this.checkBox_fillColor.Size = new System.Drawing.Size(65, 17);
            this.checkBox_fillColor.TabIndex = 13;
            this.checkBox_fillColor.Text = "Fill Color";
            this.checkBox_fillColor.UseVisualStyleBackColor = true;
            this.checkBox_fillColor.CheckedChanged += new System.EventHandler(this.checkBox_fillColor_CheckedChanged);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(765, 23);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(36, 16);
            this.label10.TabIndex = 12;
            this.label10.Text = "Num";
            // 
            // button_Clear
            // 
            this.button_Clear.Location = new System.Drawing.Point(818, 50);
            this.button_Clear.Name = "button_Clear";
            this.button_Clear.Size = new System.Drawing.Size(56, 23);
            this.button_Clear.TabIndex = 11;
            this.button_Clear.Text = "Clear";
            this.button_Clear.UseVisualStyleBackColor = true;
            this.button_Clear.Click += new System.EventHandler(this.button_Clear_Click);
            // 
            // button_Delete
            // 
            this.button_Delete.Location = new System.Drawing.Point(765, 50);
            this.button_Delete.Name = "button_Delete";
            this.button_Delete.Size = new System.Drawing.Size(50, 23);
            this.button_Delete.TabIndex = 10;
            this.button_Delete.Text = "Delete";
            this.button_Delete.UseVisualStyleBackColor = true;
            this.button_Delete.Click += new System.EventHandler(this.button_Delete_Click);
            // 
            // textBox_NumObject
            // 
            this.textBox_NumObject.Location = new System.Drawing.Point(818, 22);
            this.textBox_NumObject.Name = "textBox_NumObject";
            this.textBox_NumObject.Size = new System.Drawing.Size(56, 20);
            this.textBox_NumObject.TabIndex = 9;
            // 
            // dataGridView_Object
            // 
            this.dataGridView_Object.AllowUserToAddRows = false;
            this.dataGridView_Object.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView_Object.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            this.dataGridView_Object.CellBorderStyle = System.Windows.Forms.DataGridViewCellBorderStyle.None;
            this.dataGridView_Object.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.Single;
            this.dataGridView_Object.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView_Object.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.NameObject,
            this.Type,
            this.Direction,
            this.Location});
            this.dataGridView_Object.Cursor = System.Windows.Forms.Cursors.Default;
            this.dataGridView_Object.Location = new System.Drawing.Point(186, 9);
            this.dataGridView_Object.Name = "dataGridView_Object";
            this.dataGridView_Object.ReadOnly = true;
            this.dataGridView_Object.RowHeadersVisible = false;
            this.dataGridView_Object.Size = new System.Drawing.Size(573, 112);
            this.dataGridView_Object.TabIndex = 7;
            // 
            // NameObject
            // 
            this.NameObject.FillWeight = 70.17551F;
            this.NameObject.HeaderText = "Name";
            this.NameObject.Name = "NameObject";
            this.NameObject.ReadOnly = true;
            // 
            // Type
            // 
            this.Type.FillWeight = 76.65892F;
            this.Type.HeaderText = "Type";
            this.Type.Name = "Type";
            this.Type.ReadOnly = true;
            // 
            // Direction
            // 
            this.Direction.FillWeight = 81.21828F;
            this.Direction.HeaderText = "Direction";
            this.Direction.Name = "Direction";
            this.Direction.ReadOnly = true;
            // 
            // Location
            // 
            this.Location.FillWeight = 171.9473F;
            this.Location.HeaderText = "Location";
            this.Location.Name = "Location";
            this.Location.ReadOnly = true;
            // 
            // comboBox_Type
            // 
            this.comboBox_Type.AutoCompleteCustomSource.AddRange(new string[] {
            "Static",
            "Dynamic"});
            this.comboBox_Type.FormattingEnabled = true;
            this.comboBox_Type.Items.AddRange(new object[] {
            "Static",
            "Dynamic"});
            this.comboBox_Type.Location = new System.Drawing.Point(73, 48);
            this.comboBox_Type.Name = "comboBox_Type";
            this.comboBox_Type.Size = new System.Drawing.Size(107, 21);
            this.comboBox_Type.TabIndex = 6;
            // 
            // comboBox_Direction
            // 
            this.comboBox_Direction.FormattingEnabled = true;
            this.comboBox_Direction.Items.AddRange(new object[] {
            "Left",
            "Right"});
            this.comboBox_Direction.Location = new System.Drawing.Point(73, 76);
            this.comboBox_Direction.Name = "comboBox_Direction";
            this.comboBox_Direction.Size = new System.Drawing.Size(107, 21);
            this.comboBox_Direction.TabIndex = 5;
            // 
            // comboBox_Name
            // 
            this.comboBox_Name.FormattingEnabled = true;
            this.comboBox_Name.Items.AddRange(new object[] {
            "BRICK",
            "STAIR",
            "Dagger",
            "BrownBird",
            "Blade",
            "Panther",
            "BombGun",
            "Footballguy",
            "GunRage",
            "GATE"});
            this.comboBox_Name.Location = new System.Drawing.Point(73, 21);
            this.comboBox_Name.Name = "comboBox_Name";
            this.comboBox_Name.Size = new System.Drawing.Size(107, 21);
            this.comboBox_Name.TabIndex = 4;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(6, 77);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(61, 16);
            this.label8.TabIndex = 2;
            this.label8.Text = "Direction";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(6, 49);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(40, 16);
            this.label7.TabIndex = 1;
            this.label7.Text = "Type";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(6, 22);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(45, 16);
            this.label6.TabIndex = 0;
            this.label6.Text = "Name";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button_Reload);
            this.groupBox1.Controls.Add(this.checkBox1);
            this.groupBox1.Controls.Add(this.textBox_Cells_Width);
            this.groupBox1.Controls.Add(this.textBox_Cells_Hight);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.button_ChooseFile);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Left;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(228, 135);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Image Setting";
            // 
            // button_Reload
            // 
            this.button_Reload.Location = new System.Drawing.Point(108, 99);
            this.button_Reload.Name = "button_Reload";
            this.button_Reload.Size = new System.Drawing.Size(75, 23);
            this.button_Reload.TabIndex = 9;
            this.button_Reload.Text = "Reload";
            this.button_Reload.UseVisualStyleBackColor = true;
            this.button_Reload.Click += new System.EventHandler(this.button_Reload_Click);
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Checked = true;
            this.checkBox1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBox1.Location = new System.Drawing.Point(5, 103);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(78, 17);
            this.checkBox1.TabIndex = 8;
            this.checkBox1.Text = "Show Cells";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // textBox_Cells_Width
            // 
            this.textBox_Cells_Width.Location = new System.Drawing.Point(158, 73);
            this.textBox_Cells_Width.Name = "textBox_Cells_Width";
            this.textBox_Cells_Width.Size = new System.Drawing.Size(45, 20);
            this.textBox_Cells_Width.TabIndex = 7;
            // 
            // textBox_Cells_Hight
            // 
            this.textBox_Cells_Hight.Location = new System.Drawing.Point(86, 73);
            this.textBox_Cells_Hight.Name = "textBox_Cells_Hight";
            this.textBox_Cells_Hight.Size = new System.Drawing.Size(45, 20);
            this.textBox_Cells_Hight.TabIndex = 6;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(138, 76);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(14, 13);
            this.label5.TabIndex = 5;
            this.label5.Text = "X";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(2, 78);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(67, 16);
            this.label4.TabIndex = 4;
            this.label4.Text = "Cells Size";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(128, 50);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(34, 16);
            this.label3.TabIndex = 3;
            this.label3.Text = "0 x 0";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(2, 50);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 16);
            this.label2.TabIndex = 2;
            this.label2.Text = "FileSize";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(2, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Choose File";
            // 
            // button_ChooseFile
            // 
            this.button_ChooseFile.Location = new System.Drawing.Point(108, 20);
            this.button_ChooseFile.Name = "button_ChooseFile";
            this.button_ChooseFile.Size = new System.Drawing.Size(75, 23);
            this.button_ChooseFile.TabIndex = 0;
            this.button_ChooseFile.Text = "Choose";
            this.button_ChooseFile.UseVisualStyleBackColor = true;
            this.button_ChooseFile.Click += new System.EventHandler(this.button_ChooseFile_Click);
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1127, 520);
            this.Controls.Add(this.panel3);
            this.Name = "Form";
            this.Text = "MapEditor";
            this.panel3.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.cPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Map)).EndInit();
            this.panel2.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView_Object)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.ColorDialog colorDialog;
        private System.Windows.Forms.OpenFileDialog openImage;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button_Reload;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.TextBox textBox_Cells_Width;
        private System.Windows.Forms.TextBox textBox_Cells_Hight;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button_ChooseFile;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Button button_Clear;
        private System.Windows.Forms.Button button_Delete;
        private System.Windows.Forms.TextBox textBox_NumObject;
        private System.Windows.Forms.DataGridView dataGridView_Object;
        private System.Windows.Forms.ComboBox comboBox_Type;
        private System.Windows.Forms.ComboBox comboBox_Direction;
        private System.Windows.Forms.ComboBox comboBox_Name;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Panel panel2;
        private CPanel cPanel1;
        private System.Windows.Forms.PictureBox pictureBox_Map;
        private System.Windows.Forms.CheckBox checkBox_fillColor;
        private System.Windows.Forms.Button button_ZoomOut;
        private System.Windows.Forms.Button button_ZoomIn;
        private System.Windows.Forms.DataGridViewTextBoxColumn NameObject;
        private System.Windows.Forms.DataGridViewTextBoxColumn Type;
        private System.Windows.Forms.DataGridViewTextBoxColumn Direction;
        private System.Windows.Forms.DataGridViewTextBoxColumn Location;
        private System.Windows.Forms.Button button_ExportGrid;
    }
}

