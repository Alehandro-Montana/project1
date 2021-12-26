#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(380,400);

    slider = new QSlider(Qt::Vertical,this);
       timer = new QTimer(this);
       slider->setRange(1,1000);
       slider->setValue(1000);
       slider->setTickPosition(QSlider::TicksBothSides);

       lcd = new QLCDNumber(this);
       lcd->move(300, 25);


       slider->move(250, 25);
        tm=0;
       timer->start(1000);

       connect(slider, SIGNAL(sliderMoved(int)), this, SLOT(slotSlider(int)));
       connect(timer, SIGNAL(timeout()), this, SLOT(moveTriangle()));
       connect(slider, SIGNAL(valueChanged(int)),this, SLOT(SLDChange(int)));

}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent* e){
    QPainter painter(this);
    //painter.begin(this);
    painter.setBackgroundMode(Qt::OpaqueMode);
    painter.setBackground(Qt::white);
    QBrush Brush;
    Brush.setColor(Qt::black);
    Brush.setStyle(Qt::SolidPattern);
    painter.setBrush(Brush);






       QPolygon polygon;
       polygon << QPoint(x, y+30)
               << QPoint(x+30, y)
               << QPoint(x+30,y+60);
       painter.drawPolygon(polygon);
       painter.end();

}

void Widget::slotSlider(int t){
    timer->setInterval(t);
}
void Widget::SLDChange(int i)
{
   // slider->setValue(i);
    lcd->display(i);
}
void Widget::moveTriangle()
{
    if (tm==0){
           tm=1;
           x=0;
           y=0;
           repaint();
       }
    else if(tm==1){
        tm=2;
        x=12;
        y=12;
        repaint();
    }
    else if(tm==2){
        tm=3;
        x=25;
        y=25;
        repaint();
    }
    else if(tm==3){
        tm=4;
        x=50;
        y=50;
        repaint();
    }
       else if(tm==4){
           tm=5;
           x=75;
           y=75;
           repaint();
       }
    else if(tm==5){
        tm=6;
        x=100;
        y=100;
        repaint();
    }
    else if(tm==6){
        tm=7;
        x=125;
        y=125;
        repaint();
    }
       else if(tm==7){
           tm=8;
           x=150;
           y=150;
           repaint();
       }
    else if(tm==8){
        tm=9;
        x=175;
        y=175;
        repaint();
    }
    else if(tm==9){
        tm=10;
        x=200;
        y=200;
        repaint();
    }
    else if(tm==10){
        tm=11;
        x=225;
        y=225;
        repaint();
    }
    else if(tm==11){
        tm=12;
        x=250;
        y=250;
        repaint();
    }
    else if(tm==12){
        tm=13;
        x=275;
        y=275;
        repaint();
    }
       else if(tm==13){
           tm=14;
           x=300;
           y=300;
           repaint();
       }
    else if(tm==14){
        tm=0;
        x=345;
        y=335;
        repaint();
    }
}






























/* for(int i = 0; i <6 ; i++){
        y-=i;
        repaint();
     }
     QThread::msleep(100);

     for(int i = 0; i < 8; i++){
        x+=i;
        repaint();
     }
     QThread::msleep(100);
     for(int i = 0; i < 8; i++){
        y+=i;
        repaint();
     }
  QThread::msleep(100);
     for(int i = 0; i < 6; i++){
        x-=i;
        repaint();
     }
     QThread::msleep(100);*/
