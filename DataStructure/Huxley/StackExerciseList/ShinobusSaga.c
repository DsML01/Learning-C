#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack()
{
    STACK *new_stack = (STACK*) calloc(1, sizeof(STACK));
    
    new_stack->head = NULL;
    
    return new_stack;
}

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element)
{
    NODE *new_node = calloc(1, sizeof(NODE));

    new_node->element = element;

    //new_node->next = NULL;

    return new_node;
}

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack)
{
    return stack->head == NULL;
}

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack)
{
    if(IS_EMPTY(stack))
    {
        puts("Underflow");
        return -1;
    }
    
    NODE *aux = stack->head;

    stack->head = aux->next;

    return aux->element;
}

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element)
{
    NODE *new_node = create_node(element);
    
    new_node->next = stack->head;

    stack->head = new_node;

    return;
}

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation)
{
    int a = POP(stack);
    int b = POP(stack);
    int resultado;

    if(operation == '+') resultado = b + a;

    if(operation == '-') resultado = b - a;

    if(operation == '*') resultado = b * a;
    
    if(operation == '/') resultado = b / a;

    PUSH(stack, resultado);

}

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size)
{

    for(int i = 0; i < size; i++)
    {
        char entrada[100];

        scanf("%s", entrada);

        if(entrada[0] == '+' || entrada[0] == '-' || entrada[0] == '/' || entrada[0] == '*')
        {
            result(calculadora,entrada[0]);
        }
        else
        {
            int item = atoi(entrada);
            PUSH(calculadora,item);
        }
    }

    return;
}

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}
//Insira o código aqui