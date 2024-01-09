#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **m = NULL;
    int ny = 2, nx = 3;

    //alocao dinamica de matrizes
    m = (int**) calloc(ny, sizeof(int*));

    /* O NUMERO DE DIMENSOES QUE TEM O VETOR, E O NUMERO
    DE PONTEIROS QUE ELE VAI TER. OU SEJA, O 'm' VAI SER
    ALOCADO PARA O NUMERO DE LINHAS, E COMO RESULTADO,
    TEREMOS PONTEIROS DE PONTEIROS, E CADA LINHA DESSA VAI
    GUARDAR O ENDERECO DE CADA COLUNA.
    */

    for(int iy = 0; iy < ny; iy++)
    {
        m[iy] = (int*) calloc(nx, sizeof(int));
        //AQUI, ESTAMOS ALOCANDO CADA LINHA DA MATRIZ 
    }

    //DESALOCANDO MATRIZ 2D
    for(int iy = 0; iy < ny; iy++)
    {
    //AQUI DESALOCAMOS OS PONTEIROS QUE APONTAM PARA AS COLUNAS
        free(m[iy]);
    }
    //E AQUI PRO PONTEIRO QUE APONTA PARA A SEQUENCIA DAS LINHAS
    free(m);
    m = NULL;
    

}