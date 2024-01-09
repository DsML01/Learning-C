#include <stdio.h>

int soma(int x, int y)
{
    int z = x + y;
    return z;
}

int main()
{
    int a = 10, b = 20, c = soma(a,b);

    printf("%d\n", c);

    return 0;
}