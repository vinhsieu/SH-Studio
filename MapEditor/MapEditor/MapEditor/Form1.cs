using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class Form : System.Windows.Forms.Form
    {
        private int id = 0;//id Objects
        private int idName = 0;
        private int width = 0;
        private int height = 0;

        private int widthMap = 0;
        private int heightMap = 0;

        private int rows;
        private int cols;
        
        private float zoom = 1.0f;
        //private int depth = 10;
        

        private bool isDrawCells = true;
        
        
        private Bitmap image;
        
        private Pen pen;

        private bool isDraw = false;

        private Dictionary<int, CObject> objects;
        private Dictionary<int, string> names;

        private Point start;
        private Point end;
        private List<CObject> selectObjects;
        private readonly Random random = new Random();
        public Form()
        {
            InitializeComponent();
            pictureBox_Map.Size = System.Drawing.Size.Empty;
            pictureBox_Map.Size = System.Drawing.Size.Empty;

            cPanel1.HorizontalScroll.LargeChange = 5;
            cPanel1.VerticalScroll.LargeChange = 5;
            label3.Text = string.Empty;
            objects = new Dictionary<int, CObject>();

            selectObjects = new List<CObject>();
            names = new Dictionary<int, string>();

            pen = new Pen(Color.SeaGreen);
            //cbbType.SelectedIndex = 0;
            //cbbName.SelectedIndex = 0;
            //cbbExport.SelectedIndex = 0;
            //cbbDirection.SelectedIndex = 0;
        }

        private void button_ChooseFile_Click(object sender, EventArgs e)
        {
            txb_Leave(textBox_Cells_Hight, null);
            txb_Leave(textBox_Cells_Width, null);
            objects.Clear();
            textBox_NumObject.Text = "0";
            if (openImage.ShowDialog() == DialogResult.OK)
            {
                //label1.Text = Path.GetFileName(openImage.FileName);
                image = (Bitmap)Image.FromFile(openImage.FileName);//layer draw background

                widthMap = image.Width;
                heightMap = image.Height;

                GetCellSize();

                pictureBox_Map.BackgroundImage = (Bitmap)image.Clone();
                pictureBox_Map.Width = pictureBox_Map.BackgroundImage.Width;
                //panel1.Width = pictureBox_Map.BackgroundImage.Width;
                pictureBox_Map.Height = pictureBox_Map.BackgroundImage.Height;
                label3.Text = pictureBox_Map.Width + " X " + pictureBox_Map.Height;


                pictureBox_Map.Image = new Bitmap(widthMap, heightMap);//layer draw cells

                DrawCells();
            };
        }
        private void txb_Leave(object sender, EventArgs e)
        {
            var txtBox = ((TextBox)sender);
            if (txtBox.Text == "0")
                txtBox.Text = "1";
        }
        private void DrawCells()
        {
            if (!isDrawCells || pictureBox_Map.Image is null) return;
            Bitmap bmp = new Bitmap(pictureBox_Map.Width, pictureBox_Map.Height);
            using (Graphics graphic = Graphics.FromImage(bmp)) 
            {
                graphic.Clear(Color.Transparent);
                DrawCols(graphic, pen, cols);
                DrawRows(graphic, pen, rows);
                pictureBox_Map.Image = bmp;
            }
           
            pictureBox_Map.Invalidate();//refesh
        }
        private void DrawCols(Graphics graphic, Pen pen, int cols)
        {
            for (int i = 0; i < cols; ++i)
            {
                graphic.DrawLine(pen, new Point((int)(i * width * zoom), 0), new Point((int)(i * width * zoom), pictureBox_Map.Height));
            }
        }

        private void DrawRows(Graphics graphic, Pen pen, int rows)
        {
            for (int i = 0; i < rows; ++i)
            {
                graphic.DrawLine(pen, new Point(0,(int)(i * height *zoom)), new Point(pictureBox_Map.Width, (int)(i * height * zoom)));
            }
        }
        private void GetCellSize()
        {
            CheckValueTrue(textBox_Cells_Width, 16, out width);
            CheckValueTrue(textBox_Cells_Hight, 16, out height);

            cols = (int)(widthMap / (float)width +1.0f);
            rows = (int)(heightMap / (float)height + 1.0f);

           textBox_NumObject.Text = (rows * cols).ToString();
        }
        private void CheckValueTrue(TextBox textBox, int defaultValue, out int value)
        {
            if (int.TryParse(textBox.Text, out value))
            {
                if (value > 0)
                    return;
            }

            textBox.Text = defaultValue.ToString();
            value = defaultValue;
        }

        private void button_Reload_Click(object sender, EventArgs e)
        {
            if (image is null) return;
            txb_Leave(textBox_Cells_Width, null);
            txb_Leave(textBox_Cells_Hight, null);
            GetCellSize();
            DrawCells();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            isDrawCells = !isDrawCells;
            DrawCells();
            
            if (!isDrawCells)
            {
                ClearCells(pictureBox_Map);
                
            }
        }
        private void ClearCells(PictureBox pictureBox)
        {
            if (pictureBox.Image is null) return;
            using (Graphics graphic = Graphics.FromImage(pictureBox.Image))
            {
                graphic.Clear(Color.Transparent);
            }
            pictureBox.Invalidate();//redraw


        }

        private void pictureBox_Map_Paint(object sender, PaintEventArgs e)
        {
            if (objects.Count > 0)
            {
                if (checkBox_fillColor.Checked)
                    foreach (var item in objects)
                    {
                        Rectangle temp= item.Value.region;
                        temp.X = (int)(temp.X * zoom);
                        temp.Y = (int)(temp.Y * zoom);
                        temp.Width = (int)(temp.Width * zoom);
                        temp.Height = (int)(temp.Height * zoom);
                        e.Graphics.FillRectangle(new SolidBrush(Color.Red), temp);
                    }
                else
                    foreach (var item in objects)
                    {
                        Rectangle temp = item.Value.region;
                        temp.X = (int)(temp.X * zoom);
                        temp.Y = (int)(temp.Y * zoom);
                        temp.Width = (int)(temp.Width * zoom);
                        temp.Height = (int)(temp.Height * zoom);
                        e.Graphics.DrawRectangle(new Pen(Color.Red) { Width = 3 }, temp);
                    }

                for (int i = 0; i < selectObjects.Count; ++i)
                {
                    e.Graphics.DrawRectangle(new Pen(Color.Red) { Width = 6 }, selectObjects[i].region);
                }
            }
            Rectangle temp1 = GetRectangle();
            temp1.X = (int)(temp1.X * zoom);
            temp1.Y = (int)(temp1.Y * zoom);
            temp1.Width = (int)(temp1.Width * zoom);
            temp1.Height = (int)(temp1.Height * zoom);
            if (isDraw) e.Graphics.DrawRectangle(new Pen(Color.Red), temp1);
        }
        private Rectangle GetRectangle()
        {
            return new Rectangle(
                Math.Min(start.X, end.X),
                Math.Min(start.Y, end.Y),
                Math.Abs(start.X - end.X),
                Math.Abs(start.Y - end.Y));
        }
        private void pictureBox_Map_MouseDown(object sender, MouseEventArgs e)
        {
            if (comboBox_Name.Text == "") return;
            if (e.Button == MouseButtons.Left)
            {
                if (e.X <= pictureBox_Map.Width && e.Y <= pictureBox_Map.Height)
                {
                    isDraw = true;
                    Point temp = new Point((int)(e.Location.X / zoom), (int)(e.Location.Y / zoom));
                    start = end = temp ;
                    button_ZoomIn.Enabled = false;
                    button_ZoomOut.Enabled = false;
                }
            }
        }

        private void pictureBox_Map_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDraw)
            {
                Point temp = new Point((int)(e.Location.X / zoom), (int)(e.Location.Y / zoom));
                end = temp;

                pictureBox_Map.Invalidate();
            }
        }

        private void pictureBox_Map_MouseUp(object sender, MouseEventArgs e)
        {
            if (isDraw)
            {
                isDraw = false;
                Rectangle rect = GetRectangle();
                if (rect.Width > 0 && rect.Height > 0)
                {
                    objects.Add(id, new CObject(id++, rect, comboBox_Name.SelectedItem.ToString(), comboBox_Type.SelectedIndex, comboBox_Direction.SelectedIndex ));
                    AddGridView(rect, comboBox_Name.Text, comboBox_Type.Text, comboBox_Direction.Text);

                    pictureBox_Map.Invalidate();
                    textBox_NumObject.Text = objects.Count.ToString();
                }
            }
        }
        private void AddGridView(Rectangle rect, string name, string type, string direction)
        {
            dataGridView_Object.Rows.Add(name, type, direction, rect.ToString());
            dataGridView_Object.Rows[dataGridView_Object.RowCount - 1].Tag = id - 1;
        }
        
        private void button_ZoomIn_Click(object sender, EventArgs e)
        {
            zoom += 0.1f;
            pictureBox_Map.Width = (int)(zoom * widthMap);
            pictureBox_Map.Height = (int)(zoom * heightMap);
            ClearCells(pictureBox_Map);
            DrawCells();
            
        }

        private void button_ZoomOut_Click(object sender, EventArgs e)
        {
            zoom -= 0.1f;
            pictureBox_Map.Width = (int)(zoom * widthMap);
            pictureBox_Map.Height = (int)(zoom * heightMap);
            ClearCells(pictureBox_Map);
            DrawCells();
            
        }

        private void checkBox_fillColor_CheckedChanged(object sender, EventArgs e)
        {
            pictureBox_Map.Invalidate();
        }

        private void button_Delete_Click(object sender, EventArgs e)
        {
            if (dataGridView_Object.SelectedRows.Count > 0)
            {
                foreach (DataGridViewRow row in dataGridView_Object.SelectedRows)
                {
                    dataGridView_Object.Rows.Remove(row);
                    objects.Remove((int)row.Tag);
                    textBox_NumObject.Text = objects.Count.ToString();
                }
                pictureBox_Map.Invalidate();
            }
        }

        private void button_Clear_Click(object sender, EventArgs e)
        {
            dataGridView_Object.Rows.Clear();
            objects.Clear();
            pictureBox_Map.Invalidate();
            textBox_NumObject.Text = "0";
            button_ZoomIn.Enabled = true;
            button_ZoomOut.Enabled = true;
        }

        private void button_ExportGrid_Click(object sender, EventArgs e)
        {
            int numObject = objects.Count();
            System.IO.File.WriteAllText("output.txt",string.Empty);
            System.IO.File.AppendAllText("output.txt", numObject.ToString() + Environment.NewLine);
            for (int i=0;i<numObject;i++)
            {
                string line = objects[i].Output();
                System.IO.File.AppendAllText("output.txt", line + Environment.NewLine);
            }
            MessageBox.Show("Da Xuat Ra file output.txt trong debug");
        }
    }
}
