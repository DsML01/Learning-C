#include <stdio.h>
#include<string.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);
    double preco[n];
    double kg[n];
    char frutas[1000];

    for(int i = 0; i<n; i++)
    {
        scanf("%lf\n",&preco[i]);
        
        fgets(frutas,1000,stdin);

        double quilos = 1;

        for(int newi = 0; newi<strlen(frutas);newi++)
        {
            if(frutas[newi] ==' ') quilos += 1;
        }
        kg[i] = quilos;
        printf("dia %d: %.0lf kg\n", i+1, quilos);
    }

    double medidakg = 0, mediapreco;
    for(int i = 0; i<n; i++)
    {
        mediakg += kg[i];
        mediapreco += preco[i];
    }

    printf("%.2lf kg por dia\n", mediakg/n);
    printf("R$ %.2lf por dia\n", mediapreco/n);
    
    return 0;
}