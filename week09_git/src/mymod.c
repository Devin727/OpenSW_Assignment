#include "myops.h"

double mymod(double a, double b){
    int quotinent = (int)(a / b);

    double result = a - (quotinent * b);
    
    return result;
}
