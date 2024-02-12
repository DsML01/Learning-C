#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int item;
    struct _node *next;
} node;

typedef struct _stack
{
    node *top;
} stack;

stack *create_stack()
{
    stack *new_stack = (stack*) calloc(1, sizeof(stack));
    
    new_stack->top = NULL;
    
    return new_stack;
}

//push function
//Add an element to the stack top
void push(stack *stack, int item)
{
    node *new_top = (node*) calloc(1, sizeof(node));
    new_top->item = item;
    new_top->next = stack->top;
    
    stack->top = new_top;

    return;
}

int isempty(stack *stack)
{
    if(stack->top == NULL) return 1;

    return 0;
}

//pop function
//Remove the element from the stack
void pop(stack *stack)
{
    if(isempty(stack)) printf("Erro: Pilha vazia\n");

    node *aux = stack->top;

    stack->top = aux->next; 

    free(aux);
}

void printsatck(stack *stack)
{
    node *aux = stack->top;

    while(aux)
    {
        printf("%d", aux->item);

        aux->next == NULL ? puts("") : printf(" ");
        
        aux = aux->next;
    }

    return;
}
void scanstack(stack *stack)
{
    while(1)
    {
        int item;
        char comando[20];
        scanf("%s", comando);

        //Esta condição verifica se a string lida do comando é igual à string "Empilhar". 
        //A função strcmp compara duas strings e retorna 0 se elas forem iguais.
        if(strcmp(comando, "Empilhar") == 0)
        {
            scanf("%d", &item);
            push(stack, item);
        }

        else if(strcmp(comando, "Desempilhar") == 0)
        {
            pop(stack);
        }

        else if(strcmp(comando, "Imprimir") == 0)
        {
            printsatck(stack);
        }

        else if(strcmp(comando, "Finalizar") == 0) break;

    }
}

int main()
{
    stack *stack = create_stack();

    scanstack(stack);

    return 0;
}