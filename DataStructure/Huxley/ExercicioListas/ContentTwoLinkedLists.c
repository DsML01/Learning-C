#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int item;
    struct _node *next;
} node;

int IsSubconjunt(node *list1, node *list2, int nx1, int nx2)
{
    int cont = 0;

    node *aux1 = list1, *aux2 = list2; 

    while(aux2 != NULL)
    {
        while(aux1 != NULL)
        {
            if(aux1->item == aux2->item)
            {
                cont++;
                break;
            }

            aux1 = aux1->next;
        }

        aux1 = list1;
        aux2 = aux2->next;
    }

    //printf("%d\n", cont);

    if(cont == nx2) return 1;
    
    return 0;
}

node *addnodefinal(node *head, char item)
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

void ScanLinkedListComLimite(void *head, int *nx)
{
    scanf("%d", nx);

    for(int ix = 0; ix < *nx; ix++)
    {
        int item;
        scanf("%d", &item);

        head = addnodefinal(head,item);
    }
    return;
}

int main()
{
    int nx1, nx2;
    
    node *list1 = NULL;
    node *list2 = NULL;

   /*ScanLinkedListComLimite(list1, &nx1);

    ScanLinkedListComLimite(list2, &nx2);

    printf("%d\n", IsSubconjunt(list1, list2, nx1, nx2));*/
    
    scanf("%d", &nx1);

    for(int ix = 0; ix < nx1; ix++)
    {
        int item;
        scanf("%d", &item);

        list1 = addnodefinal(list1,item);
    }

    scanf("%d", &nx2);

    for(int ix = 0; ix < nx2; ix++)
    {
        int item;
        scanf("%d", &item);

        list2 = addnodefinal(list2,item);
    }

    printf("%d\n", IsSubconjunt(list1, list2, nx1, nx2));

    return 0;
}