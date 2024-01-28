#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int item;
    struct _node *next;
} node;

node *createlinkedlist(){
    return NULL;
}

node *addnodeinicio(node *head, int item)
{
    node *new_node = (node*) calloc(1,sizeof(node));
    new_node->item = item;
    new_node->next = head;
    return new_node;
}

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

int main()
{
    node *list = createlinkedlist();

    int scan;
    while(scanf("%d", &scan) != EOF)
    {
        list = addnodeinicio(list,scan);
    }

    printlinkedlist(list);

    return 0;
}