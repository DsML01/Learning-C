#include <stdio.h>
#include <stdlib.h>
//TODO PONTEIRO OCUPA 8 BYTES DE MEMÓRIA

int main()
{
    int a = 10;
    int *p1 = NULL; //NULL == NADA ((VOID)NÃO TEM LIXO DE MEMÓRIA;
    int *p2; //NESSE CASO, COMO NÃO ATRIBUIMOS NENHUM VALOR, TEREMOS LIXO DE MEMÓRIA.
    
    /*É INTERESSANTE QUE SEMPRE QUE FOR CRIAR UM PONTEIRO, SE NAO FOR O USAR DE IMEDIATO, ATRIBUIR A ELE O VALOR DE 'NULL'
    PARA NAO DAR NENHUM ERRO DESCONHECIDO CASO SEJA O DEV ESQUECA DE ATRIBUIR UM VALOR A ELE DEPOIS */
    
    printf("&a = %p, a = %d\n", &a, a);
    printf("&p1 = %p, p1 = %p\n", &p1, p1);
    printf("&p2 = %p, p2 = %p\n", &p2, p2);

    p1 = &a; //aponta para o endereco de memoria da variavel
    p2 = p1; //aponta para o endereco de memoria que o p1 esta apontando
    *p2 = 4; //NESSE CASO, MUDAMOS O VALOR (CONTEUDO)NO ENDERECO DE MEMORIA QUE O P2 ESTA APONTANDO
    //OU SEJA, a AGORA É == 4;

    /* O '*' SIGNIFICA QUE ESTAMOS FALANDO DO CONTEUDO DO ENDERECO DE MEMORIA
    QUE O PONTEIRO ESTA APONTANDO */
    printf("\nFIZEMOS A MUDANÇA DO *p2 PARA 4, ASSIM, MUDANDO O VALOR NO ENDERECO QUE p2 APONTA, QUE E O ENDERECO DA VARIAVEL a.\n");

    printf("\n");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&p1 = %p, p1 = %p, *p1 = %d\n", &p1, p1, *p1);
    printf("&p2 = %p, p2 = %p, *p2 = %d\n", &p2, p2, *p2);


    return 0;
}