#include <stdio.h>
#include <stdlib.h>
//TUTORIAL DE QUICK SORT FEITO PELO CANAL PROGRAME SEU FUTURO

int particiona(int *v, int inicio, int fim)
{
    //nesse caso o professor escolheu como pivot um numero que seja a media entre o primeiro valor, o valor do meio e o do final
    int pivot = (v[inicio] + v[(inicio + fim) / 2] + v[fim])/3;

    while (inicio < fim)
    {
        while(inicio < fim && v[inicio] <= pivot)
            inicio = inicio + 1;
        while(inicio < fim && v[fim] > pivot)
            fim = fim - 1;

        //SWAP
        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;

    }
    return inicio;
}

void quicksort(int *v, int inicio, int fim)
{
    if(inicio < fim)
    {
        int posicao = particiona(v, inicio, fim);
        quicksort(v, inicio, posicao - 1);
        quicksort(v, posicao, fim);
    }

    return;
}

void print(int *v, int tam)
{
    int i;
    for(i = 0; i <= tam; i++)
        printf("%d, ", v[i]);
    puts("");
}

int main()
{
    int vet[] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1 ,70, 99, 10, 61};

    print(vet, 14);
    
    quicksort(vet, 0, 14);
    
    print(vet, 14);

    return 0;
}