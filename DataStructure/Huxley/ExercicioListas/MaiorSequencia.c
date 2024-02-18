#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
    int item;
    //int n;
    struct _node *next;
} node;

void printlinkedlist(node *head)
{
    node *aux = head;

    while(aux != NULL)
    {
        printf("%d", aux->item);
        aux = aux->next;
    }
    puts("");
}

void greatestsequence(node *head, int n)
{
    int i = 0, currentgreatest = -1, greateststart = -1, greatestend = -1, start = -1, end = -1, cont = 0;
    node *aux = head;

    while(i != n)
    {
        if(aux->item == 0)
        {
            if(start == -1)
            {
                start = i;
                end = i;
                cont++;
            }
            else
            {
                end = i;
                cont++;
            }
        }
        else
        {
            if(cont > currentgreatest)
            {
                currentgreatest = cont;
                greateststart = start;
                greatestend = end;
                start = -1;
                end = -1;
                cont = 0;
            }
            else
            {
                start = -1;
                end = -1;
                cont = 0;
            }

        }

        aux = aux->next;
        i++;
    }

    printf("%d %d\n", greateststart, greatestend);

}

node *addnodefinal(node *head, int item)
{
    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->item = item;
    //new_node->n = n;
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
    char item[1000];
    int n;

    while( (strlen(fgets(item,1000,stdin)) - 1) != 0)
    {   
        int nx = strlen(item) - 1;
        //printf("TAMANHO DA STRING = %d\n", nx);

        /*for(int ix = 0; ix < nx; ix++)
        {
            printf("%c", item[ix]);
        }
        puts("");*/

        for(int ix = 0; ix < nx; ix++)
        {
            list = addnodefinal(list, item[ix] - '0');
        }

        //printlinkedlist(list);

        greatestsequence(list, nx);

        list = NULL;

        /*int tam = ceil(log10(item + 1));
        list = addnodefinal(list, item, tam);*/
    }
    
    //printlinkedlist(list);



    return 0;
}