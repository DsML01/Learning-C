#include <stdio.h>

int soma(int x, int y, int *z)
{
    *z = x + y;

    int subtracao = x - y;

    return subtracao;
}

int main()
{
    int a = 10, b = 20, c;
    
    soma(a, b, &c);

    printf("a + b = %d\n", c);

    printf("a - b = %d\n", soma(a,b,&c));

    return 0;
}