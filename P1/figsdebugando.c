#include <stdio.h>

int verifica(int serie[], int i, int n)
{
    if(i == -1) return 0;
    if(serie[i] == n) return 1;
    return verifica(serie, i-1, n);
}

void soma(int serie[], int i, int n, int joaosum, int mariasum)
{
    if(i == n)
    {
        if(joaosum > mariasum) printf("%d", joaosum);
        else printf("%d", mariasum);
        return;
    }

    int a = verifica(serie, i-1, serie[i]);

    if(a == 0)
    {
        if(serie[i] % 2 == 0) joaosum += serie[i];
        else mariasum += serie[i];
    }
    return soma(serie, i+1, n, joaosum, mariasum);
}

void scan(int serie[], int i, int n, int cj, int cm)
{
    if (i == n)
    {
        printf("%d\n%d\n", cj, cm);
        soma(serie, 0, n, 0, 0);
    }

    else
    {
        scanf("%d", &serie[i]);

        if(serie[i] % 2 == 0) cj += 1;

        else cm += 1;

        return scan(serie, i + 1, n, cj, cm);
    }
}

int main ()
{
    int n;
    scanf("%d", &n);
    int serie[n], joao[n], maria[n];

    scan(serie, 0, n, 0, 0);

    return 0;
}