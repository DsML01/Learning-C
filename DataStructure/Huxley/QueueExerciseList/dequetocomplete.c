#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _deque deque_t;
typedef struct _node   node_t;

struct _node {
    node_t *prev;
    node_t *next;
    int    value;
};

struct _deque {
    node_t *front;
    node_t *rear;
    int     size;
};

node_t* node_new(int value) {
    node_t *new_node = (node_t *) calloc( 1, sizeof(node_t));

    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->value = value;
    return new_node;
}

deque_t* construct() {
    deque_t *new_deque = (deque_t *) calloc(1, sizeof(deque_t));

    new_deque->front = NULL;
    new_deque->rear = NULL;
    new_deque->size = 0;

    return new_deque;
}

void destruct(deque_t *deque)
{
    node_t *current = deque->front;

    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    free(deque);
}

int size(deque_t *deque)
{
    return deque->size;
}

bool empty(deque_t *deque)
{
    return deque->size == 0;
}

int front(deque_t *deque)
{
    if (empty(deque)) {
        return INT_MIN;
    }
    return deque->front->value;
}

int rear(deque_t *deque)
{
    if (empty(deque)) 
    {
        return INT_MIN;
    }
    return deque->rear->value;
}

void enqueue_rear(deque_t *deque, int value) 
{
    node_t *new_node = node_new(value);

    if (empty(deque)) {
        deque->front = new_node;
        deque->rear = new_node;
    } 
    else 
    {
        new_node->prev = deque->rear;
        deque->rear->next = new_node;
        deque->rear = new_node;
    }

    deque->size++;
}

void enqueue_front(deque_t *deque, int value)
{
    node_t *new_node = node_new(value);

    if (empty(deque)) {
        deque->front = new_node;
        deque->rear = new_node;
    }
    else
    {
        new_node->next = deque->front;
        deque->front->prev = new_node;
        deque->front = new_node;
    }
    deque->size++;
}

void dequeue_rear(deque_t *deque)
{
    if (!empty(deque))
    {
        node_t *aux = deque->rear;
        deque->rear = aux->prev;

        if (deque->rear != NULL)
        {
            deque->rear->next = NULL;
        }
        else
        {
            deque->front = NULL;
        }

        free(aux);
        deque->size--;
    }
}

void dequeue_front(deque_t *deque)
{
    if (!empty(deque))
    {
        node_t *aux = deque->front;
        deque->front = aux->next;

        if (deque->front != NULL) {
            deque->front->prev = NULL;
        }
        else
        {
            deque->rear = NULL;
        }
        free(aux);
        deque->size--;
    }
}

void erase(deque_t *deque)
{
    while (!empty(deque))
    {
        dequeue_front(deque);
    }
}

void print(deque_t *deque) {
    node_t *current = deque->front;
    while (current != NULL)
    {
        printf("%d", current->value);

        printf(current->next == NULL ? "\n" : " ");

        current = current->next;
    }
}

int main() {
    int i, num;
    scanf("%d", &num);

    deque_t *deque = construct();

    int vector[num];
    for (i = 0; i < num; ++i)
        scanf("%d", &vector[i]);

    for (i = 0; i < num; ++i)
        enqueue_rear(deque, vector[i]);

    printf("%d\n", front(deque));
    printf("%d\n", rear(deque));

    if (!empty(deque))
        printf("The size of the deque %d\n", size(deque));
    else
        printf("The deque is empty\n");

    scanf("%d", &num);
    for (i = 0; i < num; ++i)
        enqueue_front(deque, i);
    print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear(deque);
    print(deque);

    erase(deque);
    for (i = 0; i < 3; ++i)
        enqueue_rear(deque, i);

    print(deque);
    destruct(deque);

    return 0;
}