    #include <stdio.h>

    int main()
    {
        int vezes;
        scanf("%d", &vezes);

        int ny = 9, nx = 9;
        int matriz[ny][nx];

        for(int i = 1; i<=vezes; i++)
        {
            for(int iy = 0; iy<ny; iy++)
            {
                for(int ix = 0; ix<nx-1; ix++)
                {
                    scanf("%d", &matriz[iy][ix]);
                }
            }

            for(int iy = 0; iy<ny; iy++)
            {
                //so para controlar o numero de vezes que a ordenacao vai acontecer
                //que eh igual ao tamanho do array
                for(int j = 0; j<=nx-1; j++) 
                {
                    for(int ix = 0; ix<nx-1-j; ix++)
                    {
                        if(matriz[iy][ix] > matriz[iy][ix+1])
                        {
                            int aux = matriz[iy][ix];
                            matriz[iy][ix] = matriz[iy][ix+1];
                            matriz[iy][ix+1] = aux;
                        }
                    }
                }
            }
            int pontuacao = 0;
            for(int iy = 0; iy<ny; iy++)
            {
                for(int ix = 0; ix<nx-1; ix++)
                {
                    if(matriz[iy][ix] == ix+1) pontuacao += ix+1;
                }
            }
            printf("%d", pontuacao);
            if(pontuacao == 405) printf("\nInstancia %d\nSIM\n", i);
            else printf("\nInstancia %d\nNAO\n", i);
        }
        return 0;
    }