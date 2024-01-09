#include <stdio.h>

int analise(double p[], double d[], int n, int i, int a, int pantes) {

    if (a == 4) 
    {
        if(i == n - 1) return 0;

        else
        {
            i += 1;
            return analise(p, d, n, i, 1, p[i]);
        }
        
    }
    else
    {
        if (p[i] <= 100)
        {
            if (p[i] <= 45)
            {

                printf("Jogo[%d] = R$%.2lf\n", i, p[i]);

                return analise(p, d, n, i, 4, pantes);

            }
            else
            {
                if(pantes > 100) d[i] = d[i]/2;

                p[i] = p[i] - (p[i] * d[i]);

                pantes = p[i];
                
                if(p[i] <= 45)
                {
                    p[i]=45.00;
                    printf("Jogo[%d] = R$%.2lf\n", i, p[i]);
                    return analise(p, d, n, i, 4, pantes);
                    
                }

                if (a == 3)
                {
                    printf("Jogo[%d] = R$%.2lf\n", i, p[i]);
                    return analise(p, d, n, i, 4, pantes);
                }

                else return analise(p, d, n, i, a + 1, pantes);
            }
        }

        else
        {
            p[i] -= p[i] * d[i];

            if (a == 3)
            {
                printf("Jogo[%d] = R$%.2lf\n", i, p[i]);

                return analise(p, d, n, i, a + 1, 0);

            }

            else return analise(p, d, n, i, a + 1);

        }
    }
}

int ler(double p[], double d[], int n, int i) {

    if (i == n) 
    {
        analise(p, d, n, 0, 1, p[0]);

        return 0;   
    }
    else
    {
        scanf("%lf%lf", &d[i], &p[i]);

        if( d[i] == 0 ) d[i] = .25;
        if( d[i] == 1 ) d[i] = .20;
        if( d[i] == 2 ) d[i] = .18;
        if( d[i] == 3 ) d[i] = .15;
        if( d[i] == 4 ) d[i] = .12;
        if( d[i] == 5 ) d[i] = .10;

        return ler(p, d, n, i + 1);

    }

}

int main () {

    int n;

    scanf("%d", &n);

    double p[n], d[n];

    ler(p, d, n, 0);

    return 0;
}