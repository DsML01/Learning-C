#include<stdio.h>

int main()
{
    //reino das princesas unidas- ele precisa eleger sua representante
    //concordar = 1, discordar = 0 (isso para cada princesa)
    //COLHER OS VOTOS E APRESENTAR UM RELATORIO COM OS VOTOS DE CADA UMA

    int qtdPrincesas, qtdEleitores;
    scanf("%d\n%d", &qtdPrincesas, &qtdEleitores);

    int princesas[qtdEleitores][qtdPrincesas];
    //ler
    for(int iE = 0; iE < qtdEleitores; iE++)
    {
        for(int iP = 0; iP < qtdPrincesas; iP++)
        {
            scanf("%d", &princesas[iE][iP]);
        }
    }

    //somar na vertical
    int soma = 0;
    for(int iP = 0; iP < qtdPrincesas; iP++)
    {
        for(int iE = 0; iE < qtdEleitores; iE++)
        {
            soma += princesas[iE][iP];
        }
        printf("Princesa %d: %d voto(s)\n", iP+1, soma);
        soma = 0;
    }
    

    return 0;
}