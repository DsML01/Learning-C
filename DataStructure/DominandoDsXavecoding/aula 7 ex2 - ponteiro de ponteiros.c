#include <stdio.h>
#include <stdlib.h>

int main()
{
    double messi = 10;
    double *jaiminho = &messi;
    double **antonio = &jaiminho;

    printf("&messi = %p, messi = %.0lf\n", &messi, messi);
    printf("&jaiminho = %p, jaiminho = %p, *jaiminho = %.0lf\n", &jaiminho, jaiminho, *jaiminho);
    printf("&antonio = %p, antonio = %p, *antonio = %p, **antonio = %.0lf\n\n", &antonio, antonio, *antonio, **antonio);

    **antonio = 30;

    printf("&messi = %p, messi = %.0lf\n", &messi, messi);
    printf("&jaiminho = %p, jaiminho = %p, *jaiminho = %.0lf\n", &jaiminho, jaiminho, *jaiminho);
    printf("&antonio = %p, antonio = %p, *antonio = %p, **antonio = %.0lf\n\n", &antonio, antonio, *antonio, **antonio);

    return 0;
}