#include <stdio.h>

int soma(int a, int b)
{
    int c = a + b;

    //QUANDO PRINTADOS, PODEMOS VER QUE OS ENDERECOS DE MEMORIA SAO DIFERENTES DOS DA MAIN, APESAR DE QUE TEM O MESMO NOME DE VARIAVEL

    puts("\nNA FUNCAO\n"); //PRINTA APENAS STRING, VOCE NAO CONSEGUE PASSAR ARGUMENTOS
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);

    return c;
}

int main()
{
    int a = 10, b = 20, c;

    puts("\nANTES DA FUNCAO\n"); //PRINTA APENAS STRING, VOCE NAO CONSEGUE PASSAR ARGUMENTOS
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);

    c = soma(a,b);

    puts("\nDEPOIS DA FUNCAO\n"); //PRINTA APENAS STRING, VOCE NAO CONSEGUE PASSAR ARGUMENTOS
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);


    return 0;
}