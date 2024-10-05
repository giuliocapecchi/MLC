#ifndef DATALOADER_H
#define DATALOADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *x; // array for x coordinates
    float *y; // array for y coordinates
    size_t size; // number of points
} DataLoader;

DataLoader* loadfile(const char *filename);
void free_data_loader(DataLoader *data);
void print_data_loader(const DataLoader *data);

#endif // DATALOADER_H