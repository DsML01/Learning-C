#include <stdio.h>

int main()
{
    int ny = 2, nx = 3; 
    //primeiro numero representa as linhas
    //segundo numero representa as colunas
    int m[2][3] = {{0, 1, 2},{3, 4, 5}};
    //apesar de ser uma matriz, na memoria ram
    //os espacos sao alocados de maneira sequencial

    printf("&m = %p, m = %p\n\n", &m, m);

    for(int iy = 0; iy < ny; iy++)
    {
        for(int ix = 0; ix < nx; ix++)
        {
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", iy, ix, &m[iy][ix], iy, ix, m[iy][ix]);
        }
        puts("");
    }

    return 0;
}