#include "advanced_ops.h"

double mypow(double a, double b){
    double result = 1;
    for(int i = 0; i < b; i++){
        result *= a;
    }
    return result;
}