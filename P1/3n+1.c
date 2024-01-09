#include <stdio.h>

void maior(int resultados[], int greatest, int i, int n)
{
    if(i == n)
    {
        printf("%d\n", greatest);
        return;
    }
    else
    {
        if(greatest < resultados[i])
        {
            greatest = resultados[i];
        }
        return maior(resultados, greatest, i + 1, n);
    }

}

void analise(int i, int resultados[], int ir, int cont)
{
    if(i == 1)
    {
        resultados[ir] = cont;
        return;
    }
    else
    {
        if(i % 2 == 0) i /= 2;
        else i = (i*3) + 1;
        return analise(i , resultados, ir,cont + 1);
    }
}

void logistica(int i, int j, int ir)
{
    int resultados[10000];
    if(i == j + 1)
    {
        int greatest = resultados[0];
        maior(resultados, greatest, 0, ir + 1);
        return;
    }
    else
    {
        ir += 1;
        analise(i, resultados, ir, 0);
    }

}

void ler()
{
    int i, j;

    if(scanf("%d%d", &i,&j) == eof)
    {
        return;
    }
    else
    {
        printf("%d %d ", i, j);
        logistica(i,j, -1);
        return ler();
    }
}

int main()
{
    ler();

    return 0;
}