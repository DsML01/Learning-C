#include <stdio.h>

int main()
{
    int a,b;
    int *p1, *p2;
    a = 4, b = 3;

    p1 = &a;
    p2 = p1;

    printf("P1 e P2 %d %d\n", *p1, *p2);

    *p2 = *p1 + 3;
    
    printf("P1 e P2 %d %d\n", *p1, *p2);

    b = b * (*p1);
    
    printf("A e B %d %d\n", a, b);
    
    *p2 += 1;
    
    printf("P1 e P2 %d %d\n", *p1, *p2);

    p1 = &b;

    printf("%d %d\n", *p1, *p2);
    printf("%d %d\n", a, b);
    
    return 0;
}