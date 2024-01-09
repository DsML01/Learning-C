#include <stdio.h>

void funcao(int *px, int *py)
{
    px = py;

    *py = (*py) * (*px);

    *px = *px + 2;

    return;
}

int main()
{
    int x, y;

    scanf("%d%d", &x, &y);

    funcao(&x, &y);

    printf("x = %d, y = %d\n", x, y);

    return 0;
}