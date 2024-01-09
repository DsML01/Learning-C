#include <stdio.h>

int eh_primo (int n, int m)
{
   if (m == 1)
    {
        return 1;
    }
    else
    {
        if (n%m == 0)
        {
            return 0;
        }
        else
        {
            int p;
            p = eh_primo (n, m - 1);
            
            return p;
        }
    } 
}

int proximo_primo (int n)
{
    int m;
    m = eh_primo (n + 1, n);

    if (m == 1)
    {
        return n + 1;
    }
    else if (m == 0)
    {
        return proximo_primo (n + 1);
    }
}

int fat (int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n*fat(n - 1);
    }
}

double serie (int m, int n)
{
    if (m == 1)
    {
        printf("1!/1");

        return 1 + serie (m + 1, n);
    }
    else if (m > 1 && m <= n)
    {
        int x, y;
        double z;

        x = eh_primo(m, m - 1);

        if (x == 1)
        {
            y = m;
        }
        else if (x == 0)
        {
            y = proximo_primo (m);
        }

        z = fat (m);

        printf(" + %d!/%d", m, y);

        double a;

        a = z/y;

        return a + serie (m + 1, n);
    }
    if (m > n)
    {   
        printf("\n");

        return 0;
    }
}

int main ()
{
    int n;
    double b;

    scanf("%d", &n);
    
    if (n == 0)
    {
        printf("0.00\n");
    }
    else
    {
        b = serie (1, n);

        printf("%.2lf\n", b);
    }

    return 0;
}