#include <stdio.h>

int main()
{
    int nz = 2, ny = 2, nx = 3;
    int m[nz][ny][nx];

    int count = 1;

    for(int iz = 0; iz < nz; iz++)
    {
        for(int iy = 0; iy < ny; iy++)
        {
            for(int ix = 0; ix < nx; ix++)
            {
                m[iz][iy][ix] = count++;
            }
        }
    }

    printf("&m = %p, m = %p\n\n", &m, m);

    for(int iz = 0; iz < nz; iz++)
    {
        for(int iy = 0; iy < ny; iy++)
        {
            for(int ix = 0; ix < nx; ix++)
            {
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n\n", iz, iy, ix, &m[iz][iy][ix], iz, iy, ix, m[iz][iy][ix]);
            }
        }
    }

    return 0;
    //JA FIZ NA STACK, AGORA FALTA NA DINAMICA
    //POR FAVOR, SEGUIR PARA O PROXIMO ARQUIVO
    //PAREI NA AULA 23, AOS 22:33
}