#include <stdio.h>

int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int contx = 0;


    //exibir sequencia de 1 a Y, com valores incrementados pelo valore
    //de Z, passando para a proxima linha a cada X num impressos na linha.
    for(int i = 1; i <= y; i += z)
    {
        printf("%d", i);
        
        contx += 1;
        if(contx % x == 0) printf("\n");
        else printf(" ");
    }


    return 0;
}