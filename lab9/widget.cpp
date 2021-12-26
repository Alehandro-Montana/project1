#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(1220,500);
       edit1 = new QLineEdit("",this);
       edit2 = new QLineEdit("",this);

       cmbx = new QComboBox(this);

       button1 = new QPushButton("Open", this);
       button2 = new QPushButton("Save", this);
       button3 = new QPushButton("Vertical", this);
       button4 = new QPushButton("Horizontal",this);
       edit1 -> move(100,40);
       edit2 -> move(250, 40);


       cmbx -> move(400, 0);

       button1 -> move(100, 0);
       button2 -> move(200,0);
       button3 -> move(300,0);

       cmbx -> addItem("720");
       cmbx -> addItem("680");

       connect(button1, SIGNAL(clicked()), this, SLOT(openfile()));
       connect(button2, SIGNAL(clicked()), this, SLOT(savefile()));
       connect(button3, SIGNAL(clicked()), this, SLOT(VerticalCH()));
       connect(button4, SIGNAL(clicked()), this, SLOT(HorizontalCH()));



}

Widget::~Widget()
{

}

void Widget::openfile()
{
    QString str = cmbx -> currentText();                       //получаем текст
    int one = str.toInt();
    QString str2 = cmbx -> currentText();
    int second = str2.toInt();
    QString a = edit1 -> text();
    QString file = QFileDialog::getOpenFileName(this, "Open File", a, "*.jpg\n *.png\n *.bmp\n");
    img.load(file);
    QSize size(one,second);
    img=img.scaled(size,Qt::KeepAspectRatio);
    repaint();
}

void Widget::savefile()
{
    QString k = edit2 -> text();
    QString save = QFileDialog :: getSaveFileName(this, "Save File", k, "BITMAP (*.bmp)\n JPG (*.jpg)\n PNG (*.png)\n");
    QString strk=save.right(3);  //возвращаем строку последни крайних символов
    img.save(save, strk.toStdString().c_str());
}
void Widget :: paintEvent(QPaintEvent *e)
{
    QPainter p;
    p.begin(this);
    p.drawImage(QPoint(500,0), img);
    p.end();
}
void Widget::VerticalCH()
{
   img = img.mirrored(false,true);
   repaint();

}
void Widget::HorizontalCH()
{

   img = img.mirrored(true,false);
   repaint();
}
