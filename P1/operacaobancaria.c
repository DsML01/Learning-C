#include <stdio.h>

int main()
{
    /*
    -ler as operacoes bancaruas e execytar as mesmas
    
    -o programa aceita até 100 operacoes de credito e debito
    
    -Tem de ser dividido em 3 partes
    1- le as operacoes salvando-as em uma matriz
    2- varre o array executando as operacoes
    3- imprime um resumo com os totais de valores
        a) creditados
        b) debitados
        c) resultado final
    Todas as acoes sao feitas nas mesmas contas bancarias e seu
    saldo inicial e zero
    */
    int ny = 100, nx = 2;
    int iy = 0, ix = 0;
    double banco[ny][nx];

    for(iy = 0; banco[iy-1][0] != -1; iy++)
    {
        for(ix = 0; ix < nx; ix++)
        {
            scanf("%lf", &banco[iy][ix]);
            if(banco[iy][0] == -1)
            {
                banco[iy][ix] = -1;
                ix += 1;
            }
            
        }
    }    
    ny = iy;

    double credito = 0, debito = 0;
    for(iy = 0; iy < ny; iy++)
    {
        for(ix = 0; ix < nx; ix += 2)
        {
            if(banco[iy][ix] == 0)
            {
                credito += banco[iy][ix+1];
            }
            else debito += banco[iy][ix+1];
        }
    }

    printf("Creditos: R$ %.2lf\n", credito);
    printf("Debitos: R$ %.2lf\n", debito);
    printf("Saldo: R$ %.2lf\n", credito-debito);


    return 0;
}