#ifndef CONSTANT_H
#define CONSTANT_H
#include <QtWidgets>
class Constant
{
public:
    Constant(double X0,double Y0);
    void myconst(double X0,double Y0);
    double getC() {
        return C;
    }
private:

    double C;
    double xf;
    double yf;
};

#endif // CONSTANT_H
