#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int item;
    int n;
    struct _node *next;
} node;

void printlinkedlist(node *head)
{
    node *aux = head;

    while(aux != NULL)
    {
        printf("%c", aux->item);
        aux = aux->next;
    }
    puts("");
}

void greatestsequence(node *head, int n)
{
    int i = 0, currentgreatest = 0, currentstart, currentend, start = -1, end = -1, cont = 1;

    while( i != n)
    {
        if(head->item == 0)
        {
            if(currentstart == -1)
            {
                start = i;
                end = i;
                cont++;
            }
            else
            {
                end = i;
            }
        }
        else
        {

        }

        i++;
    }

    printf("%d %d\n", );

}

node *addnodefinal(node *head, int item, int n)
{
    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->item = item;
    new_node->n = n;
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

int main()
{
    node *list = NULL;
    int item;
    int n;

    while(scanf("%d", &item) != 0)
    {   
        int tam = ceil(log10(item + 1));
        list = addnodefinal(list, item, tam);
    }
    
    //printlinkedlist(list);



    return 0;
}