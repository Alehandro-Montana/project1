using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tao.OpenGl; // для работы с библиотекой OpenGL
using Tao.FreeGlut; // для работы с библиотекой FreeGLUT
using Tao.Platform.Windows; // для работы с элементом управления SimpleOpenGLControl

namespace Laba04
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            simpleOpenGlControl1.InitializeContexts();
        }

        private void simpleOpenGlControl1_Load(object sender, EventArgs e)
        {
            Glut.glutInit();// инициализация Glut 
            Glut.glutInitDisplayMode(Glut.GLUT_RGB | Glut.GLUT_DOUBLE | Glut.GLUT_DEPTH);
            Gl.glClearColor(0, 0, 0, 1); // очистка окна (0,0,0 – черный; 1,1,1 - белый)
            Gl.glViewport(0, 0, simpleOpenGlControl1.Width, simpleOpenGlControl1.Height); // установка порта вывода в соответствии с размерами элемента
            Gl.glMatrixMode(Gl.GL_PROJECTION); // настройка проекции
            Gl.glLoadIdentity();// настройка параметров OpenGL для визуализации
            // корректно настраиваем 2D ортогональную проекцию в зависимости от размеров сторон окна визуализации
            if ((float)simpleOpenGlControl1.Width <= (float)simpleOpenGlControl1.Height)
            {
                //настройку 2D ортогональной проекции
                Glu.gluOrtho2D(0.0, 30.0f * (float)simpleOpenGlControl1.Height / (float)simpleOpenGlControl1.Width, 0.0, 30);
            }
            else
            {
                //настройку 2D ортогональной проекции
                Glu.gluOrtho2D(0.0, 30.0f * (float)simpleOpenGlControl1.Width / (float)simpleOpenGlControl1.Height, 0.0, 30);
                // Glu.gluOrtho2D помещает начало координат в левый нижний квадрат, а наблюдатель в этом случае находиться на оси Z
            }
            Gl.glMatrixMode(Gl.GL_MODELVIEW);
            Gl.glLoadIdentity();

        }


        private void button1_Click(object sender, EventArgs e)
        {
            Gl.glClear(Gl.GL_COLOR_BUFFER_BIT); // очищаем буфер цвета
            Gl.glLoadIdentity();// очищаем текущую матрицу
           // Gl.glColor3f(0, 1, 0); // устанавливаем текущий цвет рисования- красный
            // активируем режим рисования линий, на основе последовательного соединения всех вершин в отрезки
            Gl.glBegin(Gl.GL_POLYGON);
            Gl.glColor3d(11, 1, 0);
            Gl.glVertex2d(19, 15);
            Gl.glVertex2d(19, 7);
            Gl.glVertex2d(13, 15);
            Gl.glVertex2d(13, 7);
            Gl.glVertex2d(19, 7);



            Gl.glEnd();// завершаем режим рисования
            Gl.glBegin(Gl.GL_TRIANGLES); // вторая линия
            Gl.glColor3d(5, 1, 0);
            Gl.glVertex2d(19, 15);
            Gl.glColor3d(5, 1, 0);
            Gl.glVertex2d(16, 25);
            Gl.glColor3d(5, 1, 0);
            Gl.glVertex2d(13, 15);
            Gl.glEnd();// завершаем режим рисования
            Gl.glFlush(); //дожидаемся конца визуализации кадра
            simpleOpenGlControl1.Invalidate(); // посылаем сигнал перерисовки элемента simpleOpenGlControl1

        }
    }
}
