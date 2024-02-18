#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 100

typedef struct pilha {
    ITEM vet[TAM];
    int topo;
} TPilha;

void create(TPilha *p) {
    p->topo = -1;
}

void destroy(TPilha *p) {
    p->topo = -1;
}

int isfull(TPilha *p) {
    return p->topo == TAM;
}

int isempty(TPilha *p) {
    return p->topo == -1;
}

void push(TPilha *p, ITEM x) {
    if( isfull(p) ) {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}

ITEM pop(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    ITEM x = p->vet[p->topo];
    p->topo--;
    return x;
}

ITEM top(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    return p->vet[p->topo];
}

void inverte_palavras_frase(char frase[]) {
    TPilha pilha;
    create(&pilha);

    int iatual = 0;

    int i = 0;
    while(frase[i] != '\0')
    {
        if(frase[i] != ' ')
        {
            push(&pilha, frase[i]);
        }
        else
        {
            while(iatual < i)
            {
                //puts("TA INDO");
                frase[iatual] = pop(&pilha);
                iatual++;
            }

            iatual = i + 1;
            destroy(&pilha);
        }
        i++;
    }

    while(iatual < i)
    {
        frase[iatual] = pop(&pilha);
        iatual++;
    }

    destroy(&pilha);
}

int main(void) {
    char frase[TAM];

    gets(frase);
    printf("original = %s\n", frase);
    inverte_palavras_frase(frase);
    printf("invertida = %s\n", frase);
    
    return 0;
}
