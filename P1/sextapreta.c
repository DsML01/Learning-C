#include <stdio.h>

void analise(double p[], int i, int cont) {


    if (i == 10) printf("%d", cont);

    scanf("%lf%lf", &p[i],&p[i + 1]);
    
    if (p[i] - p[i+1] >= p[i]*0.2) 
    {
        return analise(p, i + 2, cont+1);
    }
        else 
    {
        return analise(p, i + 2, cont);
    }
} 

int main () {
    double p[10];
    int cont;

    analise(p ,0, 0);

    return 0;
}   