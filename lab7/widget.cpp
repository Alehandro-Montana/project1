#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   resize(300,300);
   sbox1=new QSpinBox(this);
   sbox1->move(150,150);
   sbox1->setMaximum(300);
sbox1->setFocusPolicy(Qt::NoFocus);

   sbox2=new QSpinBox(this);
   sbox2->move(90,150);
   sbox2->setMaximum(300);
   sbox2->setFocusPolicy(Qt::NoFocus);

   int x = sbox2->x();
   sbox1->setValue(x);
 spin1=false;
 spin2 =false;



   int y = sbox1->y();
       sbox2->setValue(y);





}



void Widget::keyPressEvent(QKeyEvent *e)
{


 {
        int counterx1 = sbox1->x();       int countery1 = sbox1->y();
        int counterx2 = sbox2->x();   int countery2 = sbox2->y();

        if(spin1==true){


    switch ( e->key() )
        {

        case Qt::Key_A:
    {
                int wx = counterx1 - 10;
                sbox1->move(wx, countery1);
            }


            break;
        case Qt::Key_D:
           {
        int wx = counterx1 + 10;
                    sbox1->move(wx, countery1);

                    int x = sbox2->x();
                    sbox1->setValue(x);



    }


            break;
    case Qt::Key_W:
    {
        int hy = countery1 - 10;
                   sbox1->move(counterx1, hy);

                   int y = sbox1->y();
                   sbox2->setValue(y);

            break;
    }
    case Qt::Key_S:
    {
        int hy = countery1 + 10;
                   sbox1->move(counterx1, hy);

                   int y = sbox1->y();
                   sbox2->setValue(y);
    }

        }
}
 else if(spin2==true){
    switch ( e->key() )
        {

        case Qt::Key_A:
    {
                int wx = counterx2 - 10;
                sbox2->move(wx, countery2);


                int x = sbox2->x();
                           sbox1->setValue(x);

            }


            break;
        case Qt::Key_D:
           {
        int wx = counterx2 + 10;
                    sbox2->move(wx, countery2);

                    int x = sbox2->x();
                    sbox1->setValue(x);



    }


            break;
    case Qt::Key_W:
    {
        int hy = countery2 - 10;
                   sbox2->move(counterx2, hy);

                  int y = sbox1->y();
                   sbox2->setValue(y);

            break;
    }
    case Qt::Key_S:
    {
        int hy = countery2 + 10;
                   sbox2->move(counterx2, hy);

                   int y = sbox1->y();
                   sbox2->setValue(y);
    }

        }

}

}
}


void Widget::mousePressEvent (QMouseEvent *e)
{
    if (Qt::LeftButton&e->button())
    {
        spin1 = true; spin2 = false;
     }
    else if (Qt::RightButton&e->button())
    {
        spin1 = false; spin2 = true;
    }
}


Widget::~Widget()
{
}



























/*  if(a == true)
  {
      if(Qt::Key_W == e->key())
      {
          int newy = countery1 - 10;
          sbox1->move(counterx1, newy);

          int y = sbox1->y();
          sbox2->setValue(y);
      }
      else if(Qt::Key_S == e->key())
      {
          int newy = countery1 + 10;
          sbox1->move(counterx1, newy);

          int y = sbox1->y();
          sbox2->setValue(y);
      }
      else if(Qt::Key_A == e->key())
      {
          int newx = counterx1 - 10;
          sbox1->move(newx, countery1);
      }
      else if(Qt::Key_D == e->key())
      {
          int newx = counterx1 + 10;
          sbox1->move(newx,countery1);
      }
  }
  else if(b == true)
  {
      if(Qt::Key_W == e->key())
      {
          int newy = countery2 - 10;
          sbox2->move(counterx2, newy);
      }
      else if(Qt::Key_S == e->key())
      {
          int newy = countery2 + 10;
          sbox2->move(counterx2, newy);
      }
      else if(Qt::Key_A == e->key())
      {
          int newx = counterx2 - 10;
          sbox2->move(newx, countery2);

          int x = sbox2->x();
          sbox1->setValue(x);
      }
      else if(Qt::Key_D == e->key())
      {
          int newx = counterx2 + 10;
          sbox2->move(newx, countery2);

          int x = sbox2->x();
          sbox1->setValue(x);
      }
  }
}
*/
