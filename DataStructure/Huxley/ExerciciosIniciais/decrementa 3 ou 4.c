#include <stdio.h>

int recursao(int n, int resultado)
{
    if(resultado < 10)
    {
        if(resultado % 2 == 0)
        {
            return n-4;
        }
        else return n-3;
    }
    
    return recursao(n, resultado/10);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    printf("%d\n", recursao(n,n));
}