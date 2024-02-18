#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    int index;
    int cont;
    struct _node *next;
} node;

node *addnodefinal(node *head, int cont, int index)
{
    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->cont = cont;
    new_node->index = index;
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

void addcont(node *head, int i)
{
    node *aux = head;
    while(aux->index != i)
    {
        aux = aux->next;
    }

    aux->cont += 1;

    return;
}

void printlinkedlist(node *head)
{
    while(head != NULL)
    {

        if(head->cont > 0) printf("%c %d\n", head->index, head->cont);

        head = head->next;
    }

}

int main()
{
    node *list = NULL;
    
    for(int i = 255; i >= 0 ; i--)
    {
        list = addnodefinal(list, 0, i);
    }

    char item[1000];

    fgets(item, 1000, stdin);

    int n = strlen(item);

    /*for(int i = 0; i < n; i++)
    {
        printf("%c", item[i]);
    }
    puts("");*/

    for(int i = 0; i < n; i++)
    {
        addcont(list, item[i]);
    }

    printlinkedlist(list);

    return 0;
}