#include <stdio.h>
#include <stdlib.h>

typedef struct _stack {
    struct _node *head;
} STACK;

typedef struct _node {
    int element;
    struct _node *next;
} NODE;

STACK* create_stack() {
    STACK *new_stack = (STACK*)calloc(1, sizeof(STACK));
    new_stack->head = NULL;
    return new_stack;
}

NODE* create_node(int element) {
    NODE *new_node = (NODE*)calloc(1, sizeof(NODE));
    new_node->element = element;
    new_node->next = NULL;
    return new_node;
}

int is_empty(STACK* stack) {
    return stack->head == NULL;
}

int pop(STACK* stack) {
    if (is_empty(stack)) {
        puts("Underflow");
        return -1;
    }

    NODE *aux = stack->head;
    stack->head = aux->next;
    int element = aux->element;
    free(aux);
    return element;
}

void push(STACK* stack, int element) {
    NODE *new_node = create_node(element);
    new_node->next = stack->head;
    stack->head = new_node;
}

void result(STACK* stack, char operation) {
    int b = pop(stack);
    int a = pop(stack);
    int resultado;

    switch (operation) {
        case '+':
            resultado = a + b;
            break;
        case '-':
            resultado = a - b;
            break;
        case '*':
            resultado = a * b;
            break;
        case '/':
            if (b != 0) {
                resultado = a / b;
            } else {
                puts("Erro: Divisão por zero");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            puts("Operação inválida");
            exit(EXIT_FAILURE);
    }

    push(stack, resultado);
}

void calculadora(STACK* calculadora, int size) {
    for (int i = 0; i < size; i++) {
        char entrada[100];
        scanf("%s", entrada);

        if (entrada[0] == '+' || entrada[0] == '-' || entrada[0] == '/' || entrada[0] == '*') {
            result(calculadora, entrada[0]);
        } else {
            int item = atoi(entrada);
            push(calculadora, item);
        }
    }
}

int main() {
    STACK* calculadora = create_stack();
    int k;

    scanf("%d", &k);
    calculadora(calculadora, k);
    int coordenada1 = pop(calculadora);

    scanf("%d", &k);
    calculadora(calculadora, k);
    int coordenada2 = pop(calculadora);

    printf("Coordenada 1: %d\n", coordenada1);
    printf("Coordenada 2: %d\n", coordenada2);

    return 0;
}
