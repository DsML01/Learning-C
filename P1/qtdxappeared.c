#include <stdio.h>

int analise(p[], n, i, x, cont) {
    if (i == n)
    {
        printf("%d", cont);

        return 0;
    }
    else
    {
        if (p[i] == x) return analise(p, n, i + 1, x, cont + 1);
        else return analise(p, n, i + 1, x, cont;
    }
}

int ler(p[], n, i) {
    int x;

    if(i == n) 
    {
        scanf("%d", &x);

        analise(p, 10, 0, x, 0);
    }
    else
    {
        scanf("%d", p[i]);

        return ler(p, n, i + 1);
    }
}

int main () {

    int p[10];

    ler(p, 10, 0);

    return 0;
}