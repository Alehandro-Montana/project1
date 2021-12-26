#include "constant.h"
#include <cmath>
#include <QtMath>





Constant::Constant(double X0,double Y0)
{
     xf=X0;
     yf=Y0;

}

void Constant:: myconst(double X0,double Y0)
{
   xf=X0;
   yf=Y0;
      C=(xf*xf)+yf;
    }
