#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void binarysearch(int *v, int start, int end, int key)
{
    int mid = start + (end - start) / 2;

    if(start <= end)
    {
        if(v[mid] == key)
        {
            puts("The number exists and was found!");
            printf("%d\n", key);
        }

        else if(key > v[mid])
        {
            binarysearch(v, mid + 1, end, key);
        }
        else
        {
            binarysearch(v, start, mid - 1, key);
        }
    }
    else
    {
        if(v[mid] == key)
        {
            puts("The number exists and was found!");
            printf("%d\n", key);
        }
        else
            puts("The number does not exist and was not found!");
    }

    return;
}

void bs(int *v, int n)
{
    int key;
    puts("Which number do you want to find?");
    scanf("%d", &key);

    binarysearch(v, 0, n - 1, key);

    return;
}

void print(int *v, int tam)
{
    int i;
    for(i = 0; i <= tam; i++)
        printf("%d ", v[i]);
    puts("");
}

void randomize(int v[], int n)
{
    //srand(time(NULL));

    for(int i = 0; i <= n; i++)
    {
        v[i] = rand()/100000;
    }

    return;
}

int main()
{
    int n = 1000;

    //array de teste
    //v[n] = {47, 35, 12, 49, 56, 25, 71, 83, 5, 3};

    int v[n];

    randomize(v, n - 1);

    //Printa o array antes de fazer o sort
    print(v, n - 1);
    puts("\n\n\n\n\n");
    
    quicksort(v, 0, n - 1);
    
    print(v, n - 1);
    puts("\n\n\n\n\n");

    bs(v, n);

    return 0;
}