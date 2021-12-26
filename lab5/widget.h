#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QList>
#include <QListWidget>
#include <QSlider>
#include <QPushButton>
#include <QLCDNumber>


class Widget : public QWidget
{
    Q_OBJECT
    QLCDNumber *lcd;

        QComboBox *cmbox;
        QListWidget *list;
        QSlider *sld;
        QPushButton *btn;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
            void CboxChange();
            void LWChange();
            void SLDChange(int i);

};
#endif // WIDGET_H
