#include <stdio.h>

int soma (int x, int y)
{
    int z = x + y;
    return z;
    //return x + y; Eh a mesma coisa
}

int main()
{
    printf("%d\n", soma(1,1));
    return 0;
}