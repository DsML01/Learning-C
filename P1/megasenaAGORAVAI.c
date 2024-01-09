#include <stdio.h>

int main()
{
    int napostas;
    scanf("%d", &napostas);

    int ny = napostas, nx = 10;
    int matriz[ny][nx];

    for(int iy = 0; iy<ny; iy++)
    {
        for(int ix = 0; ix<nx; ix++)
        {
            matriz[iy][ix] = -1;
        }
    }

    for(int iy = 0; iy<ny; iy++)
    {
        for(int ix = 0; ix<nx; ix++)
        {
            printf("%d ", matriz[iy][ix]);
            if(ix == nx-1) printf("\n");
        }
    }
    printf("\n");
    int ix = 0;
    for(int iy = 0; iy<ny; iy++)
    {
        while(ix<nx)
        {
            char aux;
            scanf("%d %c", &matriz[iy][ix], &aux);
            if(aux == ',') ix++;
            else 
            {
                matriz[iy+1][0] = aux - '0';
                ix = 100;
            }
        }
        if(ix == 100) ix = 1;
        else ix = 0;
    }

    for(int iy = 0; iy<ny; iy++)
    {
        for(int ix = 0; ix<nx; ix++)
        {
            printf("%d ", matriz[iy][ix]);
            if(ix == nx-1) printf("\n");
        }
    }

    /*int numganhantes[6];

    for(int i = 0; i<6; i++)
    {
        scanf("%d", &numganhantes[i]);
    }

    int ganhadores = 0;
    for(int iy = 0; iy<ny; iy++)
    {
        int pontuacao = 0;
            for(int i = 0; i<6; i++)
            {
                for(int ix = 0; ix<nx; ix++)
                {
                    if(numganhantes[i] == matriz[iy][ix]) pontuacao += 1;
                }
            }
        if(pontuacao == 6) ganhadores += 1;
    }

    printf("Total de ganhadores: %d", ganhadores);*/

    return 0;
}