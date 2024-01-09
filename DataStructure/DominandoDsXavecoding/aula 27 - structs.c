#include<stdio.h>
#include<stdlib.h>

//declarando struct
typedef struct alunos{
    char nome[100];
    int idade;
} Aluno;

int main()
{
    /*struct Aluno{
        char nome[100];
        int idade;
    }Leo, Lucas, Cristiano;
    //aqui eu declarei algumas variaveis da struct
    //mas isso nao me impede de declarar novas variaveis depois
    //como eu fiz logo abaixo.*/

    Aluno davi;

    return 0;
}