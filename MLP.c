#include <stdio.h>
#include <math.h>
#include "utils.h"
#include "MLP.h"
#include <stdlib.h>

MLP* create_mlp(int num_layers, int *number_of_neurons) { 

    // printf("Creating MLP with %d layers\n", num_layers);
    // printf("Number of neurons in each layer: ");
    // for (int i = 0; i < num_layers; i++) {
    //     printf("%d ", number_of_neurons[i]);
    // }
    // printf("\n");

    MLP *mlp = malloc(sizeof(MLP));
    mlp->num_layers = num_layers;
    mlp->layers = malloc(num_layers * sizeof(Layer)); // allocate memory for the layers

    // Now allocate memory for the weights, biases, output and errors of each layer
    for (int i = 0; i < num_layers; i++) { 
        mlp->layers[i].input_size = (i == 0) ? number_of_neurons[i] : number_of_neurons[i - 1];
        mlp->layers[i].output_size = number_of_neurons[i];
        mlp->layers[i].weights = malloc(number_of_neurons[i] * (mlp->layers[i].input_size) * sizeof(float));
        mlp->layers[i].biases = malloc(number_of_neurons[i] * sizeof(float));
        mlp->layers[i].output = malloc(number_of_neurons[i] * sizeof(float));
        mlp->layers[i].errors = malloc(number_of_neurons[i] * sizeof(float));

        // random initialization of weights and biases
        for (int j = 0; j < number_of_neurons[i]; j++) {
            mlp->layers[i].biases[j] = 1.0;
            for (int k = 0; k < mlp->layers[i].input_size; k++) {
                mlp->layers[i].weights[j * mlp->layers[i].input_size + k] = (float)rand() / (float)RAND_MAX;  // Valore in [0, 1)
                //printf("Weight: %f\n", mlp->layers[i].weights[j * mlp->layers[i].input_size + k]);
            }
        }
    }

    return mlp;
}

void free_mlp(MLP *mlp) {
    for (int i = 0; i < mlp->num_layers; i++) {
        free(mlp->layers[i].weights);
        free(mlp->layers[i].biases);
        free(mlp->layers[i].output);
        free(mlp->layers[i].errors);
    }
    free(mlp->layers);
    free(mlp);
}



void forward() {
    // TODO: implementazione forward pass 
     
}

void backprop() {
    // TODO  implementazione backpropagation
     
}