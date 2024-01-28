#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int item;
    struct _node *next;
} node;

void printlinkedlist(node *head)
{
    node *aux = head;

    while(aux != NULL)
    {
        printf("%d ", aux->item);
        aux = aux->next;
    }
    puts("");
}

node *addnodefinal(node *head, int item)
{
    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->item = item;
    new_node->next = NULL;

    if(head == NULL) return new_node;

    node *aux = head;

    while(aux->next != NULL)
    {
        aux = aux->next;
    }

    aux->next = new_node;

    return head;
}


/*node *BubbleSortLinkedList(node *head)
{
    if(head == NULL || head->next == NULL) return head; //empty list or with just one element, that is already sorted

    int swapped;
    node *aux;
    node *lastsorted = NULL;



}*/

node *bubblesortlinkedlist(node *head)
{
    node *aux = head;
    int swapped = 1, item;

    while(swapped != 0)
    {
        swapped = 0;

        while(aux->next != NULL)
        {
            if(aux->item > (aux->next)->item)
            {
                int aux1 = aux->item;
                aux->item = (aux->next)->item;
                (aux->next)->item = aux1;
                swapped++;
            }
            
            aux = aux->next;
        }

        aux = head;
    }

    return head;
}

int main()
{
    int item;
    node *list = NULL;

    while( scanf("%d ", &item) != EOF )
    {
        list = addnodefinal(list, item);
    }

    bubblesortlinkedlist(list);

    printlinkedlist(list);

    return 0;
}