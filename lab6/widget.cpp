#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)

{
    layout=new QBoxLayout(QBoxLayout::LeftToRight,this);
    resize(400,400);
  edit1=new QLineEdit(this);
  edit2=new QLineEdit(this);


  edit3=new QLineEdit(this);
  edit4=new QLineEdit(this);

  edit5=new QLineEdit(this);
  edit6=new QLineEdit(this);


  edit7=new QLineEdit(this);
  edit8=new QLineEdit(this);
      layout -> addWidget(edit1);
      layout -> addWidget(edit2);
      layout -> addWidget(edit3);
      layout -> addWidget(edit4);
      layout -> addWidget(edit5);
      layout -> addWidget(edit6);
      layout -> addWidget(edit7);
      layout -> addWidget(edit8);

  lbl1=new QLabel(this);
  lbl1->move(10,100);
  lbl2=new QLabel(this);
  lbl2->move(300,100);

  btR=0;
  btL=0;

    setMouseTracking(true);
    QApplication::instance()->installEventFilter(this);

}

Widget::~Widget()
{


}

void Widget::resizeEvent(QResizeEvent *e)
{
    QSize size = e->size();
    int w = size.width();
    int h = size.height();
    edit3->setText(QString::number(w));
    edit4->setText(QString::number(h));
}


void Widget::mouseMoveEvent(QMouseEvent *e)
{
    int x1 = e->x();
    int y1 = e->y();
    int gx = e->globalX();
    int gy = e->globalY();
    edit5->setText(QString::number(x1));
    edit6->setText(QString::number(y1));
    edit7->setText(QString::number(gx));
    edit8->setText(QString::number(gy));
}

void Widget::moveEvent(QMoveEvent *e)
{
    QPoint pos = e->pos();
    int x = pos.x();
    int y = pos.y();
    edit1->setText(QString::number(x));
    edit2->setText(QString::number(y));
}



bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress){
        if(obj == this){
            QMouseEvent* mevent = static_cast<QMouseEvent*>(e);
            if(mevent->button() == Qt::MouseButton::LeftButton)
                lbl1->setText(QString::number(lbl1->text().toInt() + 1));
            if(mevent->button() == Qt::MouseButton::RightButton)
                lbl2->setText(QString::number(lbl2->text().toInt() + 1));
        }
    }

    if(e->type() == QEvent::KeyPress){
        QKeyEvent* kevent = static_cast<QKeyEvent*>(e);
        if(kevent->key() == 'R')
            lbl1->setText("0");
        if(kevent->text() == "L" || kevent->text()=="l")
            lbl2->setText("0");
    }
    return false;

}
