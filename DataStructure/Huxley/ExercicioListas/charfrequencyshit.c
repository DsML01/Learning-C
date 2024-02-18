#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int item;
    int cont;
    struct _node *next;
} node;

node *addnodeinicio(node *head, int item, int cont)
{
    node *new_node = (node*) calloc(1,sizeof(node));
    new_node->item = item;
    new_node->cont = cont;
    new_node->next = head;
    return new_node;
}

void printlinkedlist(node *head)
{
    while(head != NULL)
    {

        if(head->cont > 0) printf("%c %d\n", head->item, head->cont);

        head = head->next;
    }

}

int particiona(int *v, int inicio, int fim)
{
    //nesse caso o professor escolheu como pivot um numero que seja a media entre o primeiro valor, o valor do meio e o do final
    int pivot = (v[inicio] + v[(inicio + fim) / 2] + v[fim])/3;

    while (inicio < fim)
    {
        while(inicio < fim && v[inicio] <= pivot)
            inicio = inicio + 1;
        while(inicio < fim && v[fim] > pivot)
            fim = fim - 1;

        //SWAP
        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
    }
    return inicio;
}

void quicksort(int *v, int inicio, int fim)
{
    if(inicio < fim)
    {
        int posicao = particiona(v, inicio, fim);
        quicksort(v, inicio, posicao - 1);
        quicksort(v, posicao, fim);
    }

    return;
}

int main()
{
    node *list = NULL;
    
    char string[1000];

    fgets(string, 1000, stdin);

    int n = strlen(string);

    int item[n];

    for(int i = 0; i < n; i++)
    {
        item[i] = string[i];
    }

    quicksort(item, 0, n - 1);

    /*for(int i = 0; i < n; i++)
    {
        printf("%d ", item[i]);
    }
    puts("");*/

    int cont = 0, anterior = -1;;

    for(int i = 0; i < n; i++)
    {
        if(anterior != item[i])
        {
            if(anterior == -1)
            {
                cont++;
                anterior = item[i];            
            }

            if(item[i + 1] != item[i])
            {
                list = addnodeinicio(list, item[i], cont);
                anterior = -1;
                cont = 0;
            }
        }
        
        else if(item[i] != item[i + 1])
        {
            cont++;
            list = addnodeinicio(list, item[i], cont);
            cont = 0;
            anterior = -1;
        }

        else
        {
            anterior = item[i];
            cont++;
        }
        
    }

    printlinkedlist(list);

    return 0;
}