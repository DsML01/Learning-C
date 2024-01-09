#include <stdio.h>
#include <stdlib.h>

typedef struct _livro
{
    char titulo[100];
    double preco;
    int n_paginas;
} Livro;

int main()
{
    Livro livro1;
    Livro *livro2 = (Livro *) calloc(1, sizeof(Livro));

    printf("Tamanho Livro: %ld\n", sizeof(livro1));
    printf("Tamanho Livro: %ld\n", sizeof(livro2));
    printf("Tamanho Livro: %ld\n", sizeof(*livro2));        

}