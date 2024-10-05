#include <stdio.h>
#include "utils.h"
#include "MLP.h"
#include "dataloader.h"


int main(){
    // here the MLP will be initialized and managed
    
    // TODO: remove, tests of activation functions
    // float x = 0.0;
    // float y = sigmoid(x);
    // printf("sigmoid(%f) = %f\n", x, y);
    // y = reLu(x);
    // printf("ReLu(%f) = %f\n", x, y);
    // y = leakyReLu(x);
    // printf("leakyReLu(%f) = %f\n", x, y);

    // load the data
    const char *filename = "./datasets/dataset1.txt";
    DataLoader *data = loadfile(filename);
    if (data) {
        //print_data_loader(data);
        free_data_loader(data); // Free the memory allocated for the data loader
    }

    int layer_sizes[] = {3, 5, 2};  // 3 input neurons, 5 neurons in the hidden layer, 2 output neurons
    MLP *mlp = create_mlp(3, layer_sizes);

    free_mlp(mlp);

    return 0;

}