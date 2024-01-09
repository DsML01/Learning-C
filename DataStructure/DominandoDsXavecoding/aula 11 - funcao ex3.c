#include <stdio.h>

int soma(int x, int y, int *p1)
{
    *p1 = x + y;

    int subtracao = x - y;

    return subtracao;
}

int main()
{
    int a = 10, b = 20, c;
    int *p1 = &c;

    puts("ENDERECO DE c E DE p1\n");
    printf("%p %p\n", &c, p1);

    soma(a, b, p1);

    printf("\na + b = %d\n", c);

    printf("a - b = %d\n", soma(a,b,&c));

    return 0;
}