#include <stdio.h>

#define TAM 8

// fim = inclusivo
void bolha(int a[], int pos, int fim)
{    
    // Condição de parada
    if (pos == fim) return;
    
    /* 
    se o elemento anterior for maior do que o posterior, então
    devemos trocar de lugar.
    */
    if (a[pos] < a[pos + 1])
    {
        int aux = a[pos];
        a[pos] = a[pos + 1];
        a[pos + 1] = aux;
    }
    bolha(a, pos +1, fim);
}

// fim = inclusivo
void ordenar(int a[], int fim)
{
    if (fim == 0) return;
    bolha(a, 0, fim);

    ordenar(a, fim -1);
}

void imprimir(int a[], int i, int tam)
{
    if (i == tam)
    {
        printf("\n");
        return;
    } 

    printf("%d ", a[i]);

    imprimir(a, i+1, tam);
}

void ler(int a[], int i, int tam)
{
    if (i == tam) return;

    scanf("%d", &a[i]);

    ler(a, i+1, tam);
}

int main()
{
    int a[TAM]; 

    ler(a, 0, TAM);
    imprimir(a, 0, TAM);
    ordenar(a, TAM -1 );
    imprimir(a, 0, TAM);
    
    return 0;
}