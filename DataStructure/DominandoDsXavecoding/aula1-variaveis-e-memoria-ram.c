#include <stdio.h>
// o %p eh usado para endereço de memoria

int main()
{
    int a = 10;
    int b,c;
    
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    
    b = 20;
    c = a + b;
    
    printf("\n");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);
    
    return 0;
}