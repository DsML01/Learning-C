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

    int count = 1;

    printf("&m = %p, m = %p\n\n", &m, m);

    for(int iz = 0; iz < nz; iz++)
    {
        for(int iy = 0; iy < ny; iy++)
        {
            for(int ix = 0; ix < nx; ix++)
            {
                m[iz][iy][ix] = count++;
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n\n", iz, iy, ix, &m[iz][iy][ix], iz, iy, ix, m[iz][iy][ix]);
            }
        }
    }
    //PROXIMA AULA, DESALOCANDO MATRIZES DINAMICAS

}