#include <stdio.h>

/*void bubble (int serie[], int i, int n)
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

void ordenar(int serie[], int n)
{
    if (n == 0) return;
    
    bolha(a, 0, n);

    ordenar(a, n - 1);
}*/

int soma(int joao[], int maria[], int i, int n, int joaosum, int mariasum)
{
    if (i == n + 1)
    {
        /* if(joao > maria) return joaosum;
        else mariasum; */
        printf("%d\n%d\n", joaosum, mariasum);
    }
    else
    {   
        if(joao[i] == 0 && maria[i] == 0) return soma(joao, maria, i + 1, n, joaosum, mariasum);
        
        if (joao[i] == joao[i + 1])
        {
            if (i == n) joaosum += joao[i];

            else
            {
                joao[i + 1] = 0;

                joaosum += joao[i];
            }
        }
        else joaosum += joao[i];

        if (maria[i] == maria[i + 1])
        {
            if(i == n) mariasum += maria[i];

            else
            {
                maria [i + 1] = 0;

                mariasum += maria[i];

            }
        }
        else mariasum += maria[i];

        return soma(joao, maria, i + 1, n, joaosum, mariasum);
    }
}

void ordenar(int joao[], int maria[], int i, int n, int times)
{
    if (i == n)
    {
        if (times == 0) return;
        else ordenar(joao, maria, 0, n - 1, times - 1);
    }
    else
    {
        if (joao[i] > joao[i + 1] )
        {
            int aux = joao[i];
            joao[i] = joao[i + 1];
            joao[i + 1] = aux;
        }

        if (maria[i] > maria[i + 1] )
        {
            int aux = maria[i];
            maria[i] = maria[i + 1];
            maria[i + 1] = aux;
        }
        ordenar(joao, maria, i + 1, n, times);
    }
}

void eh_par (int serie[], int joao[], int maria[], int i, int n, int contj, int contm) {
    if (i == n)
    {
        printf("%d\n%d\n", contj, contm);

        return;
    }

    if (serie[i] % 2 == 0)
    {
        joao[i] = serie[i];

        maria[i] = 0;

        return eh_par(serie, joao, maria, i + 1, n, contj + 1, contm);
    }
    else
    {
        maria[i] = serie[i];
        
        joao[i] = 0;

        return eh_par(serie, joao, maria, i + 1, n, contj, contm + 1);

    }
    
}

void scan(int serie[], int i, int n)
{
    if (i == n) return;

    scanf("%d", &serie[i]);

    scan(serie, i + 1, n);
}

int main ()
{
    int n;

    scanf("%d", &n);

    int serie[n], joao[n], maria[n];

    scan(serie, 0, n);

    eh_par(serie, joao, maria, 0, n, 0, 0);

    ordenar(joao, maria, 0, n-1, 0);

    soma(joao, maria, 0, n, 0, 0);

    return 0;
}