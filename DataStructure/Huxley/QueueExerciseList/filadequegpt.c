#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

typedef struct deque {
    ITEM vet[TAM];
    int front, rear;
} TDeque;

void create(TDeque *d) {
    d->front = d->rear = 0;
}

void destroy(TDeque *d) {
    d->front = d->rear;
}

int isfull(TDeque *d) {
    return (d->front == 0 && d->rear == TAM - 1) /*|| (d->rear + 1 == d->front*/;
}

int isempty(TDeque *d) {
    return d->front == d->rear;
}

void store(TDeque *d, int extremidade, ITEM x) {
    if (isfull(d)) {
        puts("overflow");
        abort();
    }

    if (extremidade == 1)
    { // enfileirar no início
        for(int i = d->rear; i > d->front; i--)
        {
            d->vet[i] = d->vet[i - 1];
        }

        d->rear += 1;
        d->vet[d->front] = x;
    } 

    else if (extremidade == 2) 
    { // enfileirar no fim
        d->vet[d->rear] = x;
        d->rear += 1;
    } 

    else
    {
        puts("Extremidade inválida");
        abort();
    }
}

ITEM retrieve(TDeque *d, int extremidade) {
    if (isempty(d)) {
        puts("underflow");
        abort();
    }

    ITEM aux;
    if (extremidade == 1) 
    { // desenfileirar do início
        aux = d->vet[d->front];
        for(int i = d->front; i < d->rear; i++)
        {
            d->vet[i] = d->vet[i + 1];
        }
        d->rear--;
    }

    else if (extremidade == 2) 
    { // desenfileirar do fim
        d->rear--;
        aux = d->vet[d->rear];

    } 
    
    else 
    {
        puts("Extremidade inválida");
        abort();
    }

    return aux;
}

void preenche(TDeque *d) {
    ITEM x;
    int qtd, extremidade, i;

    scanf("%d%*c", &qtd);

    for (i = 0; i < qtd; i++) {
        scanf("%c %d%*c", &x, &extremidade);
        store(d, extremidade, x);
    }
}

void exibe(TDeque *d) {
    int extremidade;

    while (scanf("%d", &extremidade) != EOF) {
        if (extremidade == 1)
            printf("INICIO = %c\n", retrieve(d, extremidade));
        else if (extremidade == 2)
            printf("FIM = %c\n", retrieve(d, extremidade));
        else {
            puts("Extremidade inválida");
            abort();
        }
    }
}

int main(void) {
    TDeque d;

    create(&d);
    preenche(&d);
    exibe(&d);
    destroy(&d);

    return 0;
}
