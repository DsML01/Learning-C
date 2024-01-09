#include <stdio.h>
#include <limits.h>

int main()
{
    int ny = 3, nx = 3;
    double matriz[ny][nx];
    int iy, ix;

    //scan
    for(iy = 0; iy < ny; iy++)
    {
        for(ix = 0; ix < nx; ix++)
        {
            scanf("%lf", &matriz[iy][ix]);
        }
    }
    
    //somar os positivos da matriz
    double sumpositive = 0;

    for(iy = 0; iy < ny; iy++)
    {
        for(ix = 0; ix < nx; ix++)
        {
            if(matriz[iy][ix] > 0) sumpositive += matriz[iy][ix];
        }
    }

    //o menor valor lido
    int menor = INT_MAX;
    for(iy = 0; iy < ny; iy++)
    {
        for(ix = 0; ix < nx; ix++)
        {
            if(menor > matriz[iy][ix])
            {
                menor = matriz[iy][ix];
            }
        }
    }

    //soma de todos que não estão na diagonal principal
    double sum_nondiagonal = 0;

    for(iy = 0; iy < ny; iy++)
    {
        for(ix = 0; ix < nx; ix++)
        {
            if(ix == iy) sum_nondiagonal += 0;
            else sum_nondiagonal += matriz[iy][ix];
        }
    }

    printf("%.2lf ", sumpositive/(iy*ix));

    printf("%d ", menor);

    if(menor % 2 == 0) printf("1 ");
    else printf("0 ");

    printf("%.0lf ", sum_nondiagonal);

    return 0;
}