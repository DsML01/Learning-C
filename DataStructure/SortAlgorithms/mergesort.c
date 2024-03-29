#include <stdio.h>
#include <limits.h>
#include <time.h>

void merge(int *v, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1 + 1], R[n2 + 1];

    for(int i = 0; i < n1; i++)
    {
        L[i] = v[l + i];
    }
    for(int j = 0; j < n2; j++)
    {
        R[j] = v[m + 1 + j];
    }
    
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;

    for(int k = l; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
    }

    return;
}

void mergesort(int *v, int l, int r)
{
    int m;

    //print(v, r + 1);

    if(l < r)
    {
        m = (l + r)/2;

        mergesort(v, l, m);
        
        mergesort(v, m + 1, r);

        merge(v, l, m, r); 
    }

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

void print(int *v, int n)
{
    for(int i = 0; i < n; i ++)
        printf("%d ", v[i]);
    puts("");

    return;
}

int main()
{
    int n = 9;
    int v[n];

    //int v[] = {5,4,3,2,1};
    //int n = sizeof(v)/sizeof(int);

    randomize(v,n);

    print(v,n);

    mergesort(v, 0, n - 1);

    print(v,n);


    return 0;
}