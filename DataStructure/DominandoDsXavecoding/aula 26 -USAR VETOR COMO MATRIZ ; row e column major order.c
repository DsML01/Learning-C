#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ny = 30, nx = 5, nyx = ny * nx;

    //ESTAMOS ALOCANDO UMA MATRIZ COMO SE FOSSE APENAS UM VETOR
    //PARA GARANTIR QUE OS DADOS ESTAO ARMAZENADOS SEQUENCIALMENTE
    //NA MEMORIA.
    int *m = (int *) calloc(nyx, sizeof(int));

    int count = 0;
    
    //FUNCAO PARA USAR UM VETOR COMO SE FOSSE UMA MATRIZ
    for(int iy = 0; iy < ny; iy++)
    {
        for(int ix = 0; ix < nx; ix++)
        {
            int iyx = (iy * ny) + ix;
            m[iyx] = count++;
        }
    }

    return 0;
}