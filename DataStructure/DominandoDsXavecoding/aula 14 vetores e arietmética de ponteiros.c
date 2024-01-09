#include <stdio.h>

int main()
{
    int v[5] = {7, 47, 5, 9, 84};
    
    printf("&v = %p, v = %p\n\n", &v, v);
    
    for(int i = 0; i < 5; i++)
    {
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
        printf("(v + %d) = %p, *(v + %d) = %d\n\n", i, (v + i), i, *(v + i));  //ESTA AQUI É OUTRA MANEIRA DE VISUALIZAR OS PONTEIROS
    }   
    
    return 0;
}