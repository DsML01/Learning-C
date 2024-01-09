#include <stdio.h>
#include <stdlib.h> //aqui temos contidos NULL, calloc, malloc, free e etc...
//TEMOS DOIS TIPOS DE MEMORIA, STACK E HEAP, A STACK É MENOR QUE A HEAP
//APRENDEMOS A ALOCAR MEMÓRIA MANUALMENTE PARA QUE POSSAMOS USAR A MEMÓRIA HEAP, QUE ESTA DISPONIVEL EM ABUNDANCIA

int main()
{

    //alocacao de um vetor estatico (memoria stack)
    int vs[5] = {1, 4, 3, 5, 9};

    puts("VETOR ESTATICO"); //PUTS PULA UMA LINHA AUTOMATICAMENTE
    printf("&vs = %p, vs = %p\n\n", &vs, vs);

    for(int i = 0; i < 5; i++)
    {
        printf("&vs[%d] = %p, vs[%d] = %d\n", i, &vs[i], i, vs[i]);
    }
    puts("\n");

    //alocacao de um vetor dinamico em malloc (memoria heap)
    int *memheapmalloc = (int *) malloc(5 * sizeof(int)); //todos os elementos terao lixo de memoria
    
    puts("VETOR DINAMICO USANDO MALLOC"); 
    printf("&memheapmalloc = %p, memheapmalloc = %p\n\n", &memheapmalloc, memheapmalloc);

    for(int i = 0; i < 5; i++)
    {
        printf("&memheapmalloc[%d] = %p, memheapmalloc[%d] = %d\n", i, &memheapmalloc[i], i, memheapmalloc[i]);
    }
    puts("\n");

    //alocacao de um vetor dinamico em calloc (memoria heap)
    //calloc garante que todos os elementos terao 0 e nao lixos de memoria

    int *memheapcalloc = (int *) calloc(5, sizeof(int)); 
    
    puts("VETOR DINAMICO USANDO CALLOC"); 
    printf("&memheapcalloc = %p, memheapcalloc = %p\n\n", &memheapcalloc, memheapcalloc);
    
    for(int i = 0; i < 5; i++)
    {
        printf("&memheapcalloc[%d] = %p, memheapcalloc[%d] = %d\n", i, &memheapcalloc[i], i, memheapcalloc[i]);
    }
    puts("\n");

    //AQUI, NAO DESALOCAMOS AS MEMORIAS QUE ALOCAMOS

    return 0;
}