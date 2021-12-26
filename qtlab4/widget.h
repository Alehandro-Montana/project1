#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QIntValidator>
#include <QString>

class Widget : public QWidget
{
    Q_OBJECT
    QLineEdit *edit;
    QSpinBox *spin;
    QLabel *lbl;
    QIntValidator *val;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void setTitle(const QString &t);
    void Top(int a);
    void Rsec();
};

#endif // WIDGET_H
