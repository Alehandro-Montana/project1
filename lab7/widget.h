#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QKeyEvent>
#include <QEvent>
#include <QKeyEvent>


class Widget : public QWidget
{
    Q_OBJECT
    QSpinBox *sbox1;
    QSpinBox *sbox2;
    bool spin1,spin2;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();



protected:
void keyPressEvent(QKeyEvent *e);
void mousePressEvent (QMouseEvent *e);


};
#endif // WIDGET_H
