using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Tao.OpenGl;
using Tao.FreeGlut;
using Tao.Platform.Windows;


namespace Lab6
{
    
    public partial class Form1 : Form
    {
        double[] loc = { 0, 0, 0 };
        double[] rot = { 0, 0, 0 };
        double[] scale = { 1, 1, 1 };

        LetterA A;
        public Form1()
        {
            InitializeComponent();
            simpleOpenGlControl1.InitializeContexts();
        }


        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            loc[0] = (double)(trackBar1.Value) / 1000;
        }



        private void simpleOpenGlControl1_Load(object sender, EventArgs e)
        {
            Glut.glutInit();
            Glut.glutInitDisplayMode(Glut.GLUT_RGB | Glut.GLUT_DOUBLE);

            Gl.glClearColor(255, 255, 255, 1);
            Gl.glViewport(0, 0, simpleOpenGlControl1.Width, simpleOpenGlControl1.Height);
            Gl.glMatrixMode(Gl.GL_PROJECTION);
            Gl.glLoadIdentity();
            Glu.gluPerspective(45, (float)simpleOpenGlControl1.Width / (float)simpleOpenGlControl1.Height, 0.1, 200);
            Gl.glMatrixMode(Gl.GL_MODELVIEW);
            Gl.glLoadIdentity();
            Gl.glEnable(Gl.GL_DEPTH_TEST);
            

            timer1.Start();

            double[] location = { -4, -4, -20 };
            double[] rotation = { 0, 0, 0 };
            double[] scale = { 0.75, 0.75, 0.75 };
            A = new LetterA(location, rotation, scale);

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Draw();
        }

        private void Draw()
        {
            Gl.glClear(Gl.GL_COLOR_BUFFER_BIT | Gl.GL_DEPTH_BUFFER_BIT);
            A.Draw(simpleOpenGlControl1, loc, rot, scale);
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            loc[1] = (double)(trackBar1.Value) / 1000;
        }

        private void trackBar3_Scroll(object sender, EventArgs e)
        {
            loc[2] = (double)(trackBar1.Value) / 1000;
        }

        private void trackBar4_Scroll(object sender, EventArgs e)
        {
            rot[0] = (double)(trackBar4.Value) / 1000;
        }

        private void trackBar5_Scroll(object sender, EventArgs e)
        {
            scale[0] = (double)(trackBar5.Value) / 1000;
        }
    }
}
