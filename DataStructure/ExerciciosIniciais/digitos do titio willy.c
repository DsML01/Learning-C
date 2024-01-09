#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int recursao(int a, int n)
{
    int i = 1;
    int soma = 0;
    for(i = 1; i<=a; i++)
    {
        if(((n%10) % 2) == 0)
        {
            soma += (n%10) * 2 * i;
        }
        else
        {
            soma += (n%10) * 3 * i;
        }

        n /= 10;
    }
    return soma;
}

int main()
{
    int n, a;

    while(1){

    scanf("%d", &n);
    if (n == 0) {
        break;
    }

    a = ceil(log10(n+1));

    printf("%d\n", recursao(a,n));
    }

    return 0;
}