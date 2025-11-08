#include "advanced_ops.h"

double mymod(double a, double b){
    int quotient = (int)(a / b);
    double result = a - (b * quotient);
    return result;
}