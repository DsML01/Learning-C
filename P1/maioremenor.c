#include <stdio.h>

void bubble (int a[], int i, int n)
{
    if (i == n) return;

    if (a[i] < a[i + 1] )
    {
        int aux = a[i];
        a[i] = a[i + 1];
        a[i + 1] = aux;
    }
    bubble(a, i + 1, n);

}

void ordenar(int a[], int n)
{
    if (n == 0) return;
    
    bolha(a, 0, n);

    ordenar(a, n - 1);
}

void ler(int a[], int i, int n)
{
    if (i == n) return;

    else
    {
        scanf("%d", &a[i]);

        ler(a, i + 1, n);
    }

}

int main () 
{
    int a[6];

    ler(a, 0, 6);

    ordenar(a, n - 1);

    printf("%d\n%d", a[0], a[5]);

    return 0;
}