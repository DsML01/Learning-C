#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ny 2
#define nx 20

typedef struct _node
{
    int item;
    struct _node *next;
} node;

node *create_linkedlist ()
{
    return NULL;
}

void printlinkedlist(node *head)
{
    node *aux = head;

    if(aux == NULL)
    {
        printf("VAZIO\n");
        return ;
    }

    while(aux != NULL)
    {
        printf("%d\n", aux->item);
        aux = aux->next;
    }
    //puts("");
}

//add in the final of the list
node *addnodefinal(node *head, int item)
{
    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->item = item;
    //my goal here is to add in the final of the list
    //new_node->next = head;
    new_node->next = NULL;

    //if I want to put the head in the start of the linked list, I must erase everything under this line and
    //just "return new_node;"
    if(head == NULL)
    {
        return new_node;
    }
    else
    {
        node *aux = head;

        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = new_node;

        return head;
    }
}

int jatem(node *result, int item)
{
    node *aux = result;

    while(aux != NULL)
    {
        if(aux->item == item)
        {
            return 1;
        }

        aux = aux->next;
    }
    
    return 0;
}

void intersection(node *list1, node *list2)
{
    //node *aux1 = list1, *aux2 = list2;
    node *result = create_linkedlist();
    
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->item == list2->item)
        {
            if(jatem(result, list1->item) == 0) result = addnodefinal(result, list1->item);

            list1 = list1->next;
            list2 = list2->next;
 
            /*if(result == NULL || result->item != list1->item) result = addnodefinal(result, list1->item);

            list1 = list1->next;
            list2 = list2->next;*/
        }

        else if(list1->item > list2->item) list2 = list2->next;

        else list1 = list1->next; 
    }

    printlinkedlist(result);

    return;    
}

//function to scan a matrix
void ScanMatrix(int m[ny][nx])
{
    for(int iy = 0; iy < ny; iy++)
    {
        for(int ix = 0; ix < nx; ix++)
        {
            scanf("%d", &m[iy][ix]);
        }
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
    //int ny = 2, nx = 10;
    int m[ny][nx];
    int v[nx];

    //function to scan a matrix
    ScanMatrix(m);
    
    for(int iy = 0; iy < ny; iy++)
    {
        for(int ix = 0; ix < nx; ix++)
        {
            v[ix] = m[iy][ix];
        }

        quicksort(v, 0, nx - 1);

        for(int ix = 0; ix < nx; ix++)
        {
            m[iy][ix] = v[ix];
        }
    }

    node *list1 = create_linkedlist();
    node *list2 = create_linkedlist();

    int iy = 0, ix = 0;
    for(iy = 0; iy < ny; iy++)
    {
        for(ix = 0; ix < nx; ix++)
        {
            iy == 0 ? (list1 = addnodefinal(list1, m[iy][ix])) : (list2 = addnodefinal(list2, m[iy][ix]));
        }
    }

    /*maybe i'll print the two lists to know if everything is all right
    printlinkedlist(list1);
    printlinkedlist(list2);
    okay, I can print it in the right way*/
    //-----------------------------------------------------------//

    intersection(list1, list2);

    //now i'ma need to compare the two lists and print the intersection between 2 lists
    

    return 0;
}