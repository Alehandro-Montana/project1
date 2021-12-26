using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

using Tao.FreeGlut;
using Tao.OpenGl;
using Tao.Platform;

class LetterA
{
    double[] startPos = new double[3];
    double[] startRot = new double[3];
    double[] startScale = new double[3];

    float[] Coord = {
            // Front
            1f, 1f, 1f,
            1f, 5f, 9f,
            3f, 7f, 0f,
            2f, 7f, 0f,

            5f, 0f, 0f,
            4f, 0f, 0f,
            2f, 7f, 0f,
            3f, 7f, 0f,

            1f, 2f, 0f,
            4f, 2f, 0f,
            3.5f, 3f, 0f,
            1.5f, 3f, 0f,
            //

            // Back
            0f, 0f, -2f,
            1f, 0f, -2f,
            3f, 7f, -2f,
            2f, 7f, -2f,

            5f, 0f, -2f,
            4f, 0f, -2f,
            2f, 7f, -2f,
            3f, 7f, -2f,

            1f, 2f, -2f,
            4f, 2f, -2f,
            3.5f, 3f, -2f,
            1.5f, 3f, -2f,
            //

            // Left
            1f, 0f, 1f,
            2f, 7f, 0f,
            2f, 7f, -2f,
            0f, 0f, -2f,
            //

            // Right
            5f, 0f, 6f,
            3f, 7f, 0f,
            3f, 7f, -2f,
            5f, 0f, -2f,
            //

            // Top
            2f, 7f, 0f,
            3f, 7f, 0f,
            3f, 7f, -2f,
            2f, 7f, -2f,

            1f, 3f, 0f,
            4f, 3f, 0f,
            4f, 3f, -2f,
            1f, 3f, -2f,
            //

            // Bottom
            0f, 0f, 0f,
            1f, 0f, 0f,
            1f, 0f, -2f,
            0f, 0f, -2f,

            5f, 0f, 0f,
            4f, 0f, 0f,
            4f, 0f, -2f,
            5f, 0f, -2f,

            1f, 2f, 0f,
            4f, 2f, 0f,
            4f, 2f, -2f,
            1f, 2f, -2f
            //
        };

    public LetterA(double[] location_, double[] rotation_, double[] scale_)
    {
        startPos = location_;
        startRot = rotation_;
        startScale = scale_;
    }
    public void Draw(Tao.Platform.Windows.SimpleOpenGlControl GlCont, double[] location, double[] rotation, double[] scale)
    {
        Gl.glClearColor(1, 1, 1, 1);
        Gl.glLoadIdentity();
        Gl.glPushMatrix();

        Gl.glTranslated(startPos[0] + location[0], startPos[1] + location[1], startPos[2] + location[2]);
        Gl.glRotated(startRot[0] + rotation[0], 1, 0, 0);
        Gl.glRotated(startRot[1] + rotation[1], 0, 1, 0);
        Gl.glRotated(startRot[2] + rotation[2], 0, 0, 1);
        Gl.glScaled(scale[0] / startScale[0], scale[1] / startScale[1], scale[2] / startScale[2]);

        Gl.glTranslated(-2.5, -3.5, 1);

        Debug.WriteLine(startPos[0] + location[0]);
        for (int a = 0; a < Coord.Length / 12; a++)
        {
            Gl.glColor3d(255, 0, 255);
            Gl.glBegin(Gl.GL_POLYGON);
            for (int i = a * 12; i < a * 12 + 12; i += 3)
            {
                Gl.glVertex3f(Coord[i + 0], Coord[i + 1], Coord[i + 2]);
            }
            Gl.glEnd();
        }
        Gl.glTranslated(2.5, 3.5, -1);

        Gl.glPopMatrix();// возвращаем состояние матрицы
        Gl.glFlush();// завершаем рисование
        GlCont.Invalidate();// обновляем элемент
    }
}


namespace Lab6
{
    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
