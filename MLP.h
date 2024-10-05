#ifndef MLP_H
#define MLP_H

#define LEARNING_RATE 0.01

typedef struct {
    int input_size;
    int output_size;
    float *weights;
    float *biases;
    float *output;
    float *errors;
} Layer;

typedef struct {
    int num_layers;
    Layer *layers;
} MLP;


MLP* create_mlp(int num_layers, int *number_of_neurons);

void free_mlp(MLP *mlp);


void forward();

void backprop();

#endif // MLP_H