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
    QLineEdit *edit1;
    QLineEdit *edit2;


    QComboBox *cmbx;

    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QImage img;
private slots:

    void openfile();
    void savefile();
    void VerticalCH();
    void HorizontalCH();

protected:
    QFileDialog *dial;
    void paintEvent(QPaintEvent *e);
//    void slotCounter(int);




};
#endif // WIDGET_H
