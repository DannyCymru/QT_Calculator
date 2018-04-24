#include "advanced_math.h"

char edp2_c_op{'p'};
advanced_math::advanced_math()
{

}

double advanced_math::edp2_add(double edp2_val_1, double edp2_val_2){
    edp2_returned_val = edp2_val_1 + edp2_val_2;
    return edp2_returned_val;
}

double advanced_math::edp2_subtract(double edp2_val_1, double edp2_val_2){
    edp2_returned_val = edp2_val_1 - edp2_val_2;
    return edp2_returned_val;
}

double advanced_math::edp2_multiply(double edp2_val_1, double edp2_val_2){
    edp2_returned_val = edp2_val_1 * edp2_val_2;
    return edp2_returned_val;
}

double advanced_math::edp2_divide(double edp2_val_1, double edp2_val_2){
    edp2_returned_val = edp2_val_1 / edp2_val_2;
    return edp2_returned_val;
}

double advanced_math::edp2_sin(double edp2_val_2){
    edp2_returned_val = sin(edp2_val_2);
    return edp2_returned_val;
}

double advanced_math::edp2_tan(double edp2_val_1){
    edp2_returned_val = tan(edp2_val_1);
    return edp2_returned_val;
}

double advanced_math::edp2_cos(double edp2_val_1){
    edp2_returned_val = cos(edp2_val_1);
    return edp2_returned_val;
}

double advanced_math::edp2_log(double edp2_val_1){
    edp2_returned_val = log(edp2_val_1);
    return edp2_returned_val;
}
