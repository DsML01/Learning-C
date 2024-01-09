#include <stdio.h>
#include <stdlib.h>

//Primeira questao

int main()
{
    int i, n = 5;
    int* v;
    
    v = (int*) malloc(n * sizeof(int));
    
    for(i = 0; i < 5; i++)
    {
        v[i] = i;
    }
    
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", v[i]);
    }
    
}