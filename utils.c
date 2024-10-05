#include <math.h>

/*----------Activation functions--------------*/

float sigmoid(float x){
    return 1/(1+exp(-x));
}

float reLu(float x){
    return x > 0 ? x : 0;
}

float leakyReLu(float x){
    return x > 0 ? x : 0.01*x;
}