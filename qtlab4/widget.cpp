#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400,400);
    edit = new QLineEdit(this);
        spin = new QSpinBox(this);
        lbl = new QLabel("&lbl", this);
        val = new QIntValidator(0,999,this);
        lbl -> move(10,10);
        lbl-> setBuddy(edit);

        edit -> setValidator(val);
        edit -> move(10,40);

        spin -> move(120,40);
        spin -> setMinimum(0);
        spin -> setMaximum(100);
        spin -> setSingleStep(1);


        connect(spin, SIGNAL(valueChanged(QString)), edit, SLOT(setText(QString)));
        connect(edit, SIGNAL(textEdited(QString)), this, SLOT(Rsec()));
        connect(edit, SIGNAL(textChanged(QString)), this, SLOT(setTitle(const QString &)));

}


void Widget :: setTitle(const QString &t)
{
    setWindowTitle(t);
}
void Widget :: Top(int t)
{
    spin -> setMaximum(t);
}
void Widget :: Rsec()
{
    QString a = edit -> text();
    int b = a.toInt();
    spin -> setValue(b);
}

Widget::~Widget()
{
}

