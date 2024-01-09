#include <stdio.h>

int main()
{
    int ncasas, njogadores, nrodadas;
    scanf("%d%d%d", &ncasas, &njogadores, &nrodadas);
    int ny = njogadores, nx = nrodadas;

    int casa[ncasas], valores[ny][nx];

    for(int i = 0; i<ncasas; i++)
    {
        scanf("%d", &casa[i]);
    }

    for(int iy = 0; iy<ny; iy++)
    {
        for(int ix = 0; ix<nx; ix++)
        {
            scanf("%d", &valores[iy][ix]);
        }
    }

    int posicao[njogadores];
    for(int i = 0; i<njogadores; i++)
    {
        posicao[i] = 0;
    }


    //ANALISAR SE ESSE SEGUNDO FOR É REALMENTE NECESSÁRIO!!!!!!!
    for(int i = 0; i<njogadores; i++)
    {
        //for(int iy = 0; iy<ny; iy++)
        //{
            for(int ix = 0; ix<nx; ix++)
            {
                posicao[i] += valores[i][ix];
                if(posicao[i] > ncasas) posicao[i] %= 10;
                else if(posicao[i]<0) 
                {
                    posicao[i] *= -1;
                    posicao[i] %= 10;
                }

                posicao[i] += casa[posicao[i]];

                if(posicao[i] > ncasas) posicao[i] %= 10;
                else if(posicao[i]<0) 
                {
                    posicao[i] *= -1;
                    posicao[i] %= 10;
                }
            }
            printf("%d\n", posicao[i]);
        //}
    }


    return 0;
}