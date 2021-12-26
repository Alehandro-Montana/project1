using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TP_Lab3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics gr = CreateGraphics();
            Pen BlPen = new Pen(Color.Black);
            BlPen.Width = 8.0F;
            gr.DrawLine(BlPen, 100, 100, 500, 100);

            BlPen.Width = 2.0F;

            for (int i = 0; i < 10; i++)
            {
                gr.DrawLine(BlPen, 120 + i * 400 / 10, 100, 120 + i * 400 / 10, 60);
                gr.DrawLine(BlPen, 120 + i * 400 / 10, 100, 120 + i * 400 / 10 - 5, 85);
                gr.DrawLine(BlPen, 120 + i * 400 / 10, 100, 120 + i * 400 / 10 + 5, 85);
            };
            gr.DrawLine(BlPen, 120, 60, 480, 60);

            if (checkBox1.Checked == true)
            //  Рисуем треугольник обозначающий «Шарнир» на левом краю балки
            {
                gr.DrawLine(BlPen, 102, 104, 80, 120);
                gr.DrawLine(BlPen, 80, 120, 120, 120);
                gr.DrawLine(BlPen, 120, 120, 102, 104);
            }
            //  если выделено «Заделка», то изменить отображение на вертикальную линию
            if (checkBox2.Checked == true)
            {
                gr.DrawLine(BlPen, 100, 70, 100, 130);
            }

            if (checkBox3.Checked == true)
            //  Рисуем треугольник обозначающий «Шарнир» на левом краю балки
            {
                gr.DrawLine(BlPen, 498, 104, 476, 120);
                gr.DrawLine(BlPen, 476, 120, 516, 120);
                gr.DrawLine(BlPen, 516, 120, 498, 104);
            }
            //  если выделено «Заделка», то изменить отображение на вертикальную линию
            if (checkBox4.Checked == true)
            {
                gr.DrawLine(BlPen, 500, 70, 500, 130);
            }

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked == true)        
            {
                checkBox1.Checked = false;        
            }
            this.Refresh();                                  
            Application.DoEvents();

        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
            {
                checkBox2.Checked = false;
            }
            this.Refresh();
            Application.DoEvents();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            if ((e.Button == System.Windows.Forms.MouseButtons.Right) && (e.X > 80) && (e.X < 120) && (e.Y > 100) && (e.X < 120))
            {
                panel1.Visible = true;
            }
            if ((e.Button == System.Windows.Forms.MouseButtons.Left) && (e.X > 80) && (e.X < 120) && (e.Y > 100) && (e.X < 120))
            {
                panel1.Visible = false;
            }

            if ((e.Button == System.Windows.Forms.MouseButtons.Right) && (e.X > 480) && (e.X < 520) && (e.Y > 100) && (e.X < 520))
            {
                panel2.Visible = true;
            }
            if ((e.Button == System.Windows.Forms.MouseButtons.Left) && (e.X > 480) && (e.X < 520) && (e.Y > 100) && (e.X < 520))
            {
                panel2.Visible = false;
            }

        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked == true)
            {
                checkBox3.Checked = false;
            }
            this.Refresh();
            Application.DoEvents();
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked == true)
            {
                checkBox4.Checked = false;
            }
            this.Refresh();
            Application.DoEvents();
        }
    }
}
