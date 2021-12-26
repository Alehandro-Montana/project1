#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:

    QSlider *slider;
    QLCDNumber *lcd;
    QTimer *timer;
    int x=0,y=0,tm;
private slots:
    void slotSlider(int);
    void moveTriangle();
    void SLDChange(int i);
protected:
    void paintEvent(QPaintEvent* e);

};
#endif // WIDGET_H
