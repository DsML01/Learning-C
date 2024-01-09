#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nz = 2, ny = 2, nx = 3;
    int ***m = (int***) calloc(nz,sizeof(int**));
    //SEMPRE LEMBRAR DE INDICAR O TIPO QUE ESTA
    //RETORNANDO. NESSE CASO, UM INT**

    for(int iz = 0; iz < nz; iz++)
    {
        m[iz] = (int **) calloc(ny, sizeof(int*));
        for(int iy = 0; iy < ny; iy++)
        {
            m[iz][iy] = (int *) calloc(nx, sizeof(int)); 
        }
    }

    //DESALOCANDO MATRIZ 2D
   for(int iz = 0; iz < nz; iz++)
   {
       for(int iy = 0; iy < ny; iy++)
       {
           free(m[iz][iy]);
       }
       free(m[iz]);
   }
    //E AQUI PRO PONTEIRO QUE APONTA PARA A SEQUENCIA DAS LINHAS
    free(m);
    m = NULL;

}