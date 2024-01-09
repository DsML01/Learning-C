#include <stdio.h>

int ler(int maior) {
    int n;

    scanf("%d", &n);

    if (n==0) printf ("%d", maior);
    
    else
    {
        if(n > maior) 
        {
            maior = n;
            ler(maior);
        }
        else ler(maior);
    }
}

int main () {
    int maior;

    ler(0);

    return 0;
}