#include <stdio.h>

void soma(int x, int y, int *z)
{
    *z = x + y;

    return;
}

int main()
{
    int a = 10, b = 20, c;
    
    soma(a, b, &c);

    printf("a + b = %d\n", c);

    return 0;
}   