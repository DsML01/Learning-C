#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _aluno {
    char nome[100];
    int idade;
} Aluno;

int main()
{
    //quando declaramos uma variavel da struct, alocamos na memoria
    //stack, sequencialmente, bytes o suficiente para armazenar todos
    //os dados da struct (Nesse caso, 104 bytes).
    Aluno davi;
    //essa funcao copia a string digitada para outra string
    //funcao da string.h
    strcpy(davi.nome, "Davi");
    davi.idade = 19;

    //atribuir valores assim que se declara uma nova variavel
    //do tipo da struct
    Aluno iury = {.nome = "Iury", .idade = 19};

    return 0;
}