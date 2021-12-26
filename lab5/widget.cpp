#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,300);

        lcd = new QLCDNumber(5, this);
        lcd->move(270, 25);

        cmbox = new QComboBox(this);
        cmbox->move(270, 75);
        cmbox->setEditable(true);

        list = new QListWidget(this);
        list->resize(100, 100);
        list->move(270, 180);

        sld = new QSlider(Qt::Horizontal, this);
        sld->move(270, 140);
        sld->setTickPosition(QSlider::TicksBothSides);
        sld->setRange(1, 50);
        sld->setTracking(true);

        btn = new QPushButton("My Button",this);
        btn->move(270, 100);

        connect(cmbox, SIGNAL(currentIndexChanged(int)), this, SLOT(CboxChange()));

        connect(btn, SIGNAL(clicked()), this, SLOT(LWChange()));
        connect(sld, SIGNAL(valueChanged(int)),this, SLOT(SLDChange(int)));

}



Widget::~Widget()
{

}

void Widget::CboxChange()
{

    int n = cmbox->count();
    lcd->display(n);

}


void Widget::LWChange()
{
    QString str1;
    list->clear();
    for(int i = 0; i < cmbox->count(); i++)
    {
        str1 = cmbox->itemText(i); //считывание текстa с элемента
        list->insertItem(i, str1); //вставка элемента
    }
}

void Widget::SLDChange(int i)
{
    cmbox->setMaxCount(i);
    lcd->display(i);
}
