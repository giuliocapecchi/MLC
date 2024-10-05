#include <stdio.h>
#include <stdlib.h>
#include "dataloader.h"

DataLoader* loadfile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    size_t capacity = 10; // Initial capacity, this is used because realloc copies the data to a new location, and this can be an expensive operation
    size_t count = 0; // Number of points read

    DataLoader *data = malloc(sizeof(DataLoader));
    
    data->x = malloc(capacity * sizeof(float));
    data->y = malloc(capacity * sizeof(float));
    data->size = 0;

    if (!data->x || !data->y) {
        perror("Memory allocation failed");
        fclose(file);
        free(data);
        return NULL;
    }

    float x, y;

    while (fscanf_s(file, "%f %f", &x, &y) == 2) {
        // If array is full, double the capacity
        if (count >= capacity) {
            capacity *= 2;
            data->x = realloc(data->x, capacity * sizeof(float));
            data->y = realloc(data->y, capacity * sizeof(float));
            if (!data->x || !data->y) {
                perror("Memory allocation failed");
                fclose(file);
                free(data->x);
                free(data->y);
                free(data);
                return NULL;
            }
        }
        // Add the new point
        data->x[count] = x;
        data->y[count] = y;
        count++;
    }

    data->size = count; // Update the number of points

    fclose(file);
    return data; // Return the data
}

// Function to free the memory allocated for the data loader
void free_data_loader(DataLoader *data) {
    if (data) {
        free(data->x);
        free(data->y);
        free(data);
    }
}

// Function to print the data contained in the data loader
void print_data_loader(const DataLoader *data) {
    for (size_t i = 0; i < data->size; i++) {
        printf("Point: (%f, %f)\n", data->x[i], data->y[i]);
    }
    printf("Number of points: %zu\n", data->size); // zus is the format specifier for size_t
}

// Example of usage
// int main() {
//     const char *filename = "./datasets/dataset1.txt";
//     DataLoader *data = loadfile(filename);
//     if (data) {
//         print_data_loader(data);
//         free_data_loader(data); // free the memory allocated for the data loader
//     }
//     return 0;
// }
