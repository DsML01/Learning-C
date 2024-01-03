#include <stdio.h>
#include <time.h>

void print(int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    puts("");

    return;
}


void selectionsort(int *v, int n)
{
    int i, min, iaux, aux;

    for(i = 0; i < n; i++)
    {
        int min = v[i];
        iaux = i;

        for(int j = i; j < n; j++)
        {
            if(v[j] < min) 
            {
                min = v[j];
                iaux = j;
            }
            
        }

        aux = v[i];
        v[i] = min;
        v[iaux] = aux;

        //print(v, n);
    }

    return;
}

void randomize(int *v, int n)
{
    srand(time(NULL));

    for(int i = 0; i < n; i++)
        v[i] = rand()/100000000;
    
    return;
}

int main()
{
    //int v[] = {5,4,3,2,1};
    //int n = sizeof(v)/sizeof(int); //funcao para descobrir quantos elementos tem em um vetor
    
    int n = 5;
    int v[n];
    
    randomize(v, n);
    
    print(v, n);

    selectionsort(v, n);

    print(v, n);

    return 0;
}