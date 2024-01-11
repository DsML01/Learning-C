#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _aluno{
    char nome[100];
    int idade;
} Aluno;

int main()
{
    //para acessar os campos de uma struct partindo
    //de um ponteiro, usamos '->'
   Aluno *davi = (Aluno*) calloc(1, sizeof(Aluno));
   strcpy(davi->nome, "Davi");
   davi->idade = 19; 

    return 0;
}