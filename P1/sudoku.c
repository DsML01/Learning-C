#include <stdio.h>

int main()
{
    int QtdMatrizes;

    scanf("%d", &QtdMatrizes);

    int ny = 9 * QtdMatrizes, nx = 9;

    int matriz[ny][nx];

    for(int iy = 0; iy < ny; iy++)
    {
        for(int ix = 0; ix < ix; ix++)
        {
            scanf("%d", &matriz[iy][ix]);
        }
    }

    int n = QtdMatrizes;
    int instancia[n];
    int ix = 0; iy = 0;
    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0;
    int cont7 = 0, cont8 = 0, cont9 = 0, pontos = 0;  

    for(i = 0; i < n; i++)
    {
        for(;iy < (9 * (i+1)); iy++)
        {
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 1) cont1 = 1;
            }
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 2) cont2 = 1;
            }
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 3) cont3 = 1;
            }
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 4) cont4 = 1;
            }
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 5) cont5 = 1;
            }
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 6) cont6 = 1;
            }
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 7) cont7 = 1;
            }
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 8) cont8 = 1;
            }
            for(ix = 0; ix < nx; ix++)
            {
                if(matriz[iy][ix] == 9) cont9 = 1;
            }
            int somah = (cont1 + cont2 + cont3 + cont4 + cont5 + cont6 + cont7 + cont8 + cont9);
            if(somah == 9) pontos++;
            cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, cont7 = 0, cont 8 = 0, cont9 = 0;


        }
    }

    return 0;
}