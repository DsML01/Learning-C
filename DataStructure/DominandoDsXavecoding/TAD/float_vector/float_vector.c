#include "float_vector.h"
#include <stdlib.h>

typedef struct float_vector {
    int capacity; //número máximo de elementos do vetor
    int size; //qtd de elementos armazenados atualmente
    float *data; //vetor de floats
};

FloatVector *create(int capacity)
{
    FloatVector *v = (FloatVector*) calloc(1, sizeof(FloatVector));
    v->size = 0;
    v->capacity = capacity;
    v->data = (float*) calloc(capacity, sizeof(float));
}