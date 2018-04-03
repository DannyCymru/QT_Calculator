#ifndef STANDARD_MATH_H
#define STANDARD_MATH_H

#include <QMainWindow>
#include <QWidget>
#include <string>

    extern double returned_val;
    extern double val_1;
    extern double val_2;
    extern char c_op;

class standard_math
{

public:
    standard_math();

    double add(double val_1, double val_2);
    double subtract(double val_1, double val_2);
    double multiply(double val_1, double val_2);
    double divide(double val_1, double val_2);

private:

};

#endif // STANDARD_MATH_H
