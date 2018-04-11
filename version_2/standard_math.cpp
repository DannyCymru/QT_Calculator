#include "standard_math.h"


char c_op{'n'};

standard_math::standard_math()
{

}

double standard_math::add(double val_1, double val_2){
    returned_val = val_1 + val_2;
    return returned_val;
}

double standard_math::subtract(double val_1, double val_2){
    returned_val = val_1 - val_2;
    return returned_val;
}

double standard_math::multiply(double val_1, double val_2){
    returned_val = val_1 * val_2;
    return returned_val;
}

double standard_math::divide(double val_1, double val_2){
    returned_val = val_1 / val_2;
    return returned_val;
}
