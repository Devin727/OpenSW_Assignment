#include "advanced_ops.h"

double mymod(double a, double b){
    int quotient = (int)(a/b);
    double remainder = a - (quotient * b);
    return remainder;
}