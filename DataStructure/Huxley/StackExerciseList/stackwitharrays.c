#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM  200000

typedef struct _stack
{
    int *vet[TAM];
    int tam[TAM];
    int topo;
} stack;

void create(stack *s)
{
    s->topo = -1;
}

int isfull(stack *s)
{
    return s->topo == TAM;
}

int isempty(stack *s)
{
    return s->topo == -1;
}

void push(stack *s, int x[], int n)
{
    if(isfull(s))
    {
        //acho que nao vai ter muita utilidade aqui
    }
    
    s->topo++;
    //printf("%d\n", s->topo);
    s->vet[s->topo] = calloc(n, sizeof(int));
    memcpy(s->vet[s->topo], x, n * sizeof(int));

    s->tam[s->topo] = n;
}

int *pop(stack *s, int *newn)
{
    if(isempty(s) == 1)
    {
        *newn = 0;
        return NULL;
    }

    *newn = s->tam[s->topo];
    int *x = calloc(*newn, sizeof(int));

    memcpy(x, s->vet[s->topo], *newn * sizeof(int));

    s->topo--;
    return x;
}

void printarray(int v[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", v[i]);

        printf(i == n-1 ? "\n" : " "); 
    }

    return;
}

void removeNewLine(char *string)
{
    int newlinePos = strcspn(string, "\n");
    string[newlinePos] = '\0';
    return;
}

void scanstack(stack *s)
{
    char string[10];
    int vetor[TAM];

    while(fgets(string, 10, stdin) != NULL)
    {
        if(strcmp(string, "PUSH\n") == 0)
        {

            int i = 0;
            char aux;

            while(scanf("%d%c", &vetor[i], &aux) == 2 && aux != '\n')
            {
                i++;
            }
            i++;

            push(s, vetor, i);
        }  

        else
        {
            int naux;
            int *v = pop(s, &naux);

            if(naux > 0)
            {
                printarray(v,naux);
            }

            else puts("EMPTY STACK");
        
        }
    }

    return;
}

int main()
{
    stack s;

    create(&s);

    scanstack(&s);

    return 0;
}