#include <stdio.h>
#include <time.h>

void insertionsort(int *v, int n)
{
    int i, key, j;

    for(i = 1; i < n; i++)
    {
        key = v[i];
        j = i - 1;

        while((j >= 0) && (v[j] > key))
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }

    return;
}

void print(int *v, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    
    puts("");

    return;
}

void randomize(int *v, int n)
{
    //funcao para preencher um vetor aleatoriamente

    srand(time(NULL));

    for(int i = 0; i < n; i++)
        v[i] = rand()/100000000;
    //a divisao eh para nao ter segmentation fault

    return;
    
}

int main()
{
    int n = 10;
    int v[n];

    randomize(v, n);

    print(v, n);

    insertionsort(v,n);

    print(v,n);

    return 0;
}