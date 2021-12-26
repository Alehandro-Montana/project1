#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QtGui>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawGraph(bool notEmpty = 0);
    void calcPix();
    void Limits();
    double funct(double x);
    int C;

public slots:


    void paint();
void savegraph();
    void findC();

private:

        QLabel *label,*X,*Flexsilon,*Y,*YourY,*YourX,*Formula;
        QLineEdit *LeftXL,*RightXL,*Flex,*DwnY,*UPY,*X0,*Y0;
        QIntValidator *ctrl,*ctrl2;
        QMenu *file;


        double leftllimitX,rightlimitX;
        double leftLimitY,rightLimitY;
        double fstX, fstY ;

        int Width,Height;
        double flex;
        double PixelX,PixelY;
        double Ox,Oy;
        void myconst(double fstX,double fstY);


};
#endif // MAINWINDOW_H
