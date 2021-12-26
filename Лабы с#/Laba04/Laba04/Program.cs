using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tao.OpenGl; // для работы с библиотекой OpenGL
using Tao.FreeGlut; // для работы с библиотекой FreeGLUT
using Tao.Platform.Windows; // для работы с элементом управления SimpleOpenGLControl

namespace Laba04
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
