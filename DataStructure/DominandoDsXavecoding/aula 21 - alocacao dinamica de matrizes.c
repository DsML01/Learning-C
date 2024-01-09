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

    int count = 0;

    printf(" &m = %p, m = %p\n\n", &m, m);

    for(int iy = 0; iy < ny; iy++)
    {
        printf("&m[%d] = %p, m[%d] = %p\n", iy, &m[iy], iy, m[iy]);
        
        for(int ix = 0; ix < nx; ix++)
        {
            m[iy][ix] = count++;
            //primeiramente ele atribui o valor e depois
            //adiciona o +=1.
            
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", iy, ix, &m[iy][ix], iy, ix, m[iy][ix]);
        }
        puts("");
    }
    //AQUI ELE MOSTRA QUE A ALOCAO DE MEMORIA
    //PARA UMA MATRIZ NAO EH IGUAL A DE UM VETOR
    //QUE EH SEQUENCIAL

    //FALTA DESALOCAR A MEMORIA

}