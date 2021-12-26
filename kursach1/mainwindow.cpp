#include "mainwindow.h"

#include <cmath>
#include <QDebug>
#include <QMessageBox>
#include <QtMath>
#include <QString>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "constant.h"
#include <QSpinBox>
#include <QApplication>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
      this->setFixedSize(850,450);
    Height = 400;
    Width = 525;
    flex = 0.1;
    leftllimitX = -5;rightlimitX = 5;
    leftLimitY = -2;rightLimitY = 2;



    QAction *save, *quit,*find,*draw;
    QPixmap quitpix("quit.png");
    QPixmap savepix("save.png");
    QPixmap drawpix("draw.png");
    QPixmap findpix("find.png");
    save = new QAction(savepix, "&Save", this);
    quit = new QAction(quitpix, "&Quit", this);
    find = new QAction(findpix, "&Find",this);
    draw=new QAction(drawpix,"&Draw",this);
    quit->setShortcut(tr("CTRL+Q"));
    save->setShortcut(tr("CTRL+S"));
    find->setShortcut(tr("CTRL+F"));
    draw->setShortcut(tr("CTRL+D"));

    // Создаем объект класса QMenu (меню)

      file=new QMenu("",this);
      file = menuBar()->addMenu("&Menu");
      file->addAction(quit);
      file->addAction(save);
      file->addAction(find);
      file->addAction(draw); // добавляем действие "New"
      qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);
      connect(quit, &QAction::triggered, qApp, QApplication::quit);
      connect(save, SIGNAL(triggered()),this, SLOT(savegraph()));
      connect(find,SIGNAL(triggered()),this,SLOT(findC()));
      connect(draw,SIGNAL(triggered()),this,SLOT(paint()));

      Formula=new QLabel("| formula : x^2 + C |",this);
      Formula->setGeometry(150,25,110,20);


    label = new QLabel("",this);
        label->setGeometry(20,40,540,380);

    X = new QLabel("Limit X",this);
        X->setGeometry(470,20,50,30);

    LeftXL = new QLineEdit("-7",this);
        LeftXL->setGeometry(510,25,50,20);

    RightXL = new QLineEdit("7", this);
        RightXL->setGeometry(580,25,50,20);

    Y = new QLabel("Limit Y",this);
        Y->setGeometry(690,20,50,30);

    DwnY = new QLineEdit("-2",this);
        DwnY->setGeometry(725,25,50,20);

    UPY = new QLineEdit("7", this);
        UPY->setGeometry(800,25,50,20);



    X0 = new QLineEdit("X0", this);
        X0->setGeometry(20,25,50,20);

    Y0 = new QLineEdit("Y0", this);
         Y0->setGeometry(90,25,50,20);


    Flexsilon = new QLabel("Flex",this);
         Flexsilon->setGeometry(275,20,50,30);

    Flex = new QLineEdit("10", this);
         Flex->setGeometry(300,25,50,20);





    ctrl = new QIntValidator(-15,25,this);
         DwnY->setValidator(ctrl);

    ctrl2 = new QIntValidator(-15,25,this);
          UPY->setValidator(ctrl2);








}

MainWindow::~MainWindow()
{
}

double MainWindow::funct(double x)
{
 return x*x+C;
}

void MainWindow::calcPix()// метод вычисляет середину экрана и пересчитывает количество пикселей
{
    PixelX = 540/(rightlimitX-leftllimitX);
    PixelY = 400/(rightLimitY-leftLimitY);
    Ox = fabs(leftllimitX);Oy = rightLimitY;
}

void MainWindow::Limits()
{
    leftllimitX = LeftXL->text().toDouble();
    rightlimitX =RightXL->text().toDouble();
    leftLimitY = DwnY->text().toDouble();
    rightLimitY = UPY->text().toDouble();
    fstX=X0->text().toDouble();
    fstY=Y0->text().toDouble();
    flex = 1.0/Flex->text().toDouble();
}

void MainWindow::drawGraph(bool notEmpty)
{
    QPixmap mypict(540,370);
    QPainter paint;
    paint.begin(&mypict);
    paint.eraseRect(0,0,540,370);
    paint.drawLine(Ox*PixelX,0,Ox*PixelX,Height);
    paint.drawLine(0,Oy*PixelY,Width,Oy*PixelY);
    paint.setPen(QPen(Qt::black,4));
     for(double i = leftllimitX;i<=rightlimitX;i+=1.0)
         {
             paint.drawPoint((i+Ox)*PixelX,Oy*PixelY);
             QString str = QString::number(i);
             QFont font("Arial", 8, QFont::Bold,true);
             paint.setFont(font);
             paint.drawText((i+Ox)*PixelX,Oy*PixelY+11,str);
          }

      for(double i = leftLimitY;i<=rightLimitY;i+=1.0)
         {
             paint.drawPoint(Ox*PixelX,(Oy-i)*PixelY);
             QString str = QString::number(i);
             QFont font("Arial", 8, QFont::Bold,true);
             paint.setFont(font);
             paint.drawText(Ox*PixelX+10,(Oy-i)*PixelY,str);
          }


      QFont one("Arial", 10, QFont::Bold,true);
      paint.setFont(one);
      paint.drawText(PixelX+470,leftLimitY+300,"X");

      QFont two("Arial", 10, QFont::Bold,true);
      paint.setFont(two);
      paint.drawText(Width-280,Height-384,"Y");

        paint.setRenderHint(QPainter::Antialiasing, true);
        QPainterPath path;
        for(double i = (double)leftllimitX+flex;i<=(double)rightlimitX;i+=flex)
        {
           path.lineTo((i+Ox)*PixelX,(Oy-funct(i))*PixelY);
        }

            paint.setPen(QPen(Qt::red,3,Qt::SolidLine));
            paint.drawPath(path);

        if(!notEmpty){// если мы не рисуем график, то отображаем координатную ось и выключаемся
            paint.end();
            label->setPixmap(mypict);
           return;
        }


    }


void MainWindow::paint()

{
    Limits();
    calcPix();
    drawGraph();

}

void MainWindow::findC()
{
    myconst(fstX,fstY);

    QMessageBox msg;
    msg.resize(100,100);
    msg.setStandardButtons(QMessageBox::Cancel);
    msg.setText(" Your C:"+QString::number(C,'f',3));
    msg.exec();

}

void MainWindow::myconst(double fstX,double fstY)
{
    Limits();
    Constant c(fstX,fstY);
   c.myconst(fstX,fstY);
    C=c.getC();
}




void MainWindow::savegraph()
{
//получаем объект из картинки QLabel
    QString filters;
    foreach(QByteArray byte,QImageWriter::supportedImageFormats()){// возвращает типы разрешений для сохр и создает байтовый массив
       QString format =byte;
       filters+=QString("%1 (%2)\n")      //составляем список поддерживаемых фильтров
               .arg(format.toUpper())   //переводим в верхний регистр
               .arg("*."+format);
    }
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save as.."),"img.png",filters);// вызываем диалог
    if(fileName.isEmpty() || fileName.isNull())
        return;
    label->pixmap()->save(fileName);
}


