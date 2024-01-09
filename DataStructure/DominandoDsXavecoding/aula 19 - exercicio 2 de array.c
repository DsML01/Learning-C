#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int v1[5];
    
    for(i = 0; i < 5; i++)
    {
        v1[i] = i;
    }

    for(i = 0; i < 5; i++)
    {
        printf("%d\n", v1[i]);
    }

    int *v2, *p;

    p = v1;
    p[3] = p[4] - 10;

    v2 = (int*) malloc(5 * sizeof(int));

    for(i = 0; i < 5; i++)
    {
        v2[i] = v1[i];
    }

    puts("");
   
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", v2[i]);
    }

    //O FREE SO FUNCIONA PARA DESALOCAR NA MEMORIA HEAP
    //NA MEMORIA STACK A FUNCAO NAO FUNCIONA.
    free(v2);
    v2 = NULL;

    return 0;
}