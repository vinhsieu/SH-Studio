using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TilesetGenerator
{
    public partial class Form1 : Form
    {

        string filepath;
        Bitmap image;
        Bitmap temp=new Bitmap(16,16);
        List<Bitmap> TileSet = new List<Bitmap>();
        Bitmap ExportImage = new Bitmap(1, 1);
        string matrix;

        string filename;
        int bit = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void btn_filepath_Click(object sender, EventArgs e)
        {
            if(openFileDialog1.ShowDialog()==DialogResult.OK)
            {
                filepath = openFileDialog1.FileName;
                textBox1.Text = filepath;
                image = new Bitmap(filepath);
                pictureBox_Export.SizeMode =PictureBoxSizeMode.StretchImage;
                pictureBox_Export.Image = image;

            }
        }

        private void btn_Generator_Click(object sender, EventArgs e)
        {
            #region CheckFile anh
            if (rBtn_16bit.Checked ==false  & rBtn_32bit.Checked==false)
            {
                MessageBox.Show("Vui long chon kich co");
                return;
            }
           if(rBtn_16bit.Checked)
            {
                bit = 16;
                if(image.Width%bit !=0 | image.Height%bit !=0)
                {
                    MessageBox.Show("Kich Co Ban Chon Khong Phu Hop voi File anh" );
                    rBtn_16bit.Checked = false;
                    return;
                }
            }
           else
            {
                bit = 32;
                if (image.Width % bit != 0 | image.Height % bit != 0)
                {
                    MessageBox.Show("Kich Co Ban Chon Khong Phu Hop voi File anh");
                    rBtn_32bit.Checked = false;
                    return;
                }
            }
            #endregion
            #region Xulianh
            for (int i = 0; i < image.Height; i += bit)
            {
                for (int j = 0; j < image.Width; j += bit)
                {
                    temp = new Bitmap(bit, bit);
                    for (int k = i; k < bit + i; k++)
                    {
                        for (int m = j; m < bit + j; m++)
                        {
                            Color a = image.GetPixel(m, k);
                            temp.SetPixel(m - j, k - i, a);
                            //MessageBox.Show(i.ToString() + " " + j.ToString());
                        }
                    }

                   
                    int result = Compare(TileSet, temp);
                    if (result == -1)
                    {
                        AddTile(TileSet, temp);
                        matrix +=  (TileSet.Count-1).ToString()+ " " ;
                       
                    }
                    else
                    {
                        matrix +=  result.ToString()+" " ;
                        
                    }
                }
                matrix += "\n";
            }
            #endregion
            richTextBox_Matrix.Text = matrix;
            System.IO.File.WriteAllText("MatrixOut.txt", matrix);
            #region ghepanh
            ExportImage = new Bitmap(TileSet.Count * bit, bit);
           for (int i = 0; i < TileSet.Count; i++)
           {
                for (int j = i * bit; j < i * bit + bit; j++)
                {
                    for (int k = 0; k < bit; k++)
                    {
                        Color a = TileSet[i].GetPixel(j - i * bit, k);
                        ExportImage.SetPixel(j, k, a);
                    }
                }
           }
            #endregion
            pictureBox_Export.SizeMode = PictureBoxSizeMode.Normal;
            pictureBox_Export.Image = ExportImage;
            btn_Export.Enabled = true;
            //panel_Image.BackgroundImage = Tileset;
        }
        void AddTile(List<Bitmap> bm, Bitmap add)
        {
            bm.Add(add);
        }
        int Compare(List<Bitmap> bm, Bitmap add)
        {
            for(int i=0;i<bm.Count;i++)
            {
                if(CompareSingle(bm[i],add)==1)
                {
                    return i;
                }
            }
            return -1;
           
        }
        int CompareSingle(Bitmap bm, Bitmap add)
        {
            for(int i=0; i<bm.Height;i++)
            {
                for(int j=0;j<bm.Width;j++)
                {
                    if(bm.GetPixel(j,i)!=add.GetPixel(j,i))
                    {
                        return -1;// khac
                    }
                }
            }
            return 1;
        }

        private void btn_Export_Click(object sender, EventArgs e)
        {

            
            //panel_Image.Size = ExportImage.Size;
            //panel_Image.BackgroundImage = ExportImage;
            pictureBox_Export.Image = ExportImage;
            SaveFileDialog sfdlg = new SaveFileDialog();
            sfdlg.Title = "Save Image As";
            sfdlg.OverwritePrompt = true;
            sfdlg.CheckPathExists = true;
            sfdlg.ShowHelp = true;

            sfdlg.Filter = "Image Files (JPEG, GIF, BMP, etc.)|" +
"*.jpg;*.jpeg;*.gif;*.bmp;*.tif;*.tiff;*.png|" +
"JPEG files (*.jpg;*.jpeg)|*.jpg;*.jpeg|" +
"GIF Files (*.gif)|*.gif|" +
"BMP Files (*.bmp)|*.bmp|" +
"TIFF Files (*.tif;*.tiff)|*.tif;*.tiff|" +
"PNG Files (*.png)|*.png|" +
"All files (*.*)|*.*";
            if (sfdlg.ShowDialog()==DialogResult.OK)
            {
                filename = sfdlg.FileName.ToString();
            }
            pictureBox_Export.Image.Save(filename, ImageFormat.Png);

        }
    }
}
