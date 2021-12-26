#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QIntValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLineEdit *edit;
    QSpinBox *spin;
    QLabel *lbl1;
    QLabel *lbl2;

    QIntValidator *val;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void setTitle(const QString &title);
    void setBt(int);
    void setSS();

};
#endif // MAINWINDOW_H
