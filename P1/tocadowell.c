#include <stdio.h>

void Ler(int Array[], int IndiceAtual, int TotalIndices)
{
    if (IndiceAtual == TotalIndices)
    {
        return;
    }

    int Buraco;
    scanf("%d", &Buraco);
    Array[IndiceAtual] = Buraco;
    Ler(Array, IndiceAtual + 1, TotalIndices);
}

int ProximoIndice(int Array[], int IndiceAtual, int TotalIndices)
{
    if (IndiceAtual == TotalIndices)
    {
        return -1;
    }
    if(Array[IndiceAtual] == -1)
    {
        return ProximoIndice(Array, IndiceAtual + 1, TotalIndices);
    }
    return IndiceAtual;
}

int VisitarToca(int Array[], int IndiceAtual, int TotalIndices, int Tocas)
{
    if (IndiceAtual == -1)
    {
        return Tocas;
    }
    else
    {
        int ProximoBuraco;
        if(Array[IndiceAtual] == -1)
        {
            Tocas += 1;
            ProximoBuraco = ProximoIndice(Array, IndiceAtual, TotalIndices);
        }
        else
        {
            ProximoBuraco = Array[IndiceAtual];
            if(ProximoBuraco >= TotalIndices)
            {
                ProximoBuraco = 0;
            }
            Array[IndiceAtual] = -1;
        }
        return VisitarToca(Array, ProximoBuraco, TotalIndices, Tocas);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int Buracos[n];
    Ler(Buracos, 0, n);
    printf("%d\n", VisitarToca(Buracos, 0, n, 0));
    return 0;
}