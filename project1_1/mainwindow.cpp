#include "mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    {
        edit = new QLineEdit(this);
        edit -> move(10,40);
        edit -> resize(70,20);
        spin = new QSpinBox(this);
        spin -> move(100,40);
        spin -> setMaximum(-2);

        spin -> resize(70,20);
        lbl2 = new QLabel("Text2",this);
        lbl2 -> move(100,10);

        lbl1 = new QLabel("&Text1",this);
        lbl1 ->setBuddy(edit);
        lbl1 -> move(10,10);


        val = new QIntValidator(-51,-1,this);
        edit ->setValidator(val);


        connect(edit,SIGNAL(textChanged(QString)),this,SLOT(setTitle(QString)));
        connect(spin,SIGNAL(valueChanged(int)),this,SLOT(setBt(int)));
       connect(spin,SIGNAL(valueChanged(int)),this,SLOT(setSS()));



    }
    void MainWindow :: setTitle(const QString &title)
    {
        setWindowTitle(title);
    }

    void MainWindow :: setBt(int a)
    {
        spin->setMinimum(a);


    }
    void MainWindow :: setSS()
    {

       QString a;
       edit->text();
       int b =a.toInt();
       spin->setValue(b);
     if((b<0)&&(b%2)==2){
         this->setWindowTitle("");
                 edit->setText("only nechet");
    }
   else
     {

     }
}
MainWindow::~MainWindow()
{

}
