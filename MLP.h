#ifndef MLP_H
#define MLP_H

#define LEARNING_RATE 0.01

typedef struct {
    int input_size;
    int output_size;
    float *weights;
    float *biases;
    float *output;
    float *delta;
} Layer;

typedef struct {
    int num_layers;
    Layer *layers;
} MLP;

void initialize_layer();

void forward();

void backprop();

#endif // MLP_H