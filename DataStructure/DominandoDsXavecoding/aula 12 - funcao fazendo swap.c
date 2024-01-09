#include <stdio.h>

void swap(int *x, int *y)
{
    int aux = *x;

    *x = *y;

    *y = aux;

    return;
}

int main()
{
    int a = 10, b = 20;

    puts("\nANTES DA FUNCAO\n");
    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b);

    puts("\nDEPOIS DA FUNCAO\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}