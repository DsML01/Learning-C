#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct _node{
    int item;
    struct _node *next;
} node;

node *excludezerosbefore(node *head)
{
    node *aux = head;

    while(aux->item == 0)
    {
        aux = aux->next;
        //printf("ITS WORKING\n");
    }

    return aux;
}

void printlinkedlist(node *head)
{

    if(head == NULL)
    {
        puts("Lista vazia!");

        return;
    }

    node *aux;
    //puts("teste");
    aux = excludezerosbefore(head);

    while(aux != NULL)
    {
        printf("%d ", aux->item);
        aux = aux->next;
    }
    puts("");

    return;
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

node *addnodeinicio(node *head, int item)
{
    node *new_node = (node*) calloc(1,sizeof(node));
    new_node->item = item;
    new_node->next = head;
    return new_node;
}

node *sum2linkedlists(node *list1, node *list2, node *result)
{
    node *aux1 = list1, *aux2 = list2;

    int resto = 0;

    while(aux1 != NULL && aux2 != NULL)
    {
        if((aux1->item + aux2->item + resto) >= 10)
        {
            if(aux1->next == NULL)
            {
                aux1->next = calloc(1, sizeof(node));
                aux2->next = calloc(1, sizeof(node));

                resto = (aux1->item + aux2-> item) / 10;
                
                (aux1->next)->item += resto;

                result = addnodeinicio(result, (aux1->item + aux2->item) % 10);
                resto = 0;
            }
            else
            {
                resto = (aux1->item + aux2-> item) / 10;
                
                (aux1->next)->item += resto;

                result = addnodeinicio(result, (aux1->item + aux2->item) % 10);
                resto = 0;
            }
        }
        else
        {
            result = addnodeinicio(result, (aux1->item + aux2->item));
        }

        aux1 = aux1->next;
        aux2 = aux2->next;
    }

    return result;
}

int main()
{
    node *list1 = NULL;
    node *list2 = NULL;
    node *result = NULL;

    char letra;
    int list = 1;
    int n1 = 0, n2 = 0;

    while(scanf(" %c\n", &letra) != EOF)
    {
        if(letra == '=') break;

        //printf("%c ", letra);

        if(letra == '+') list = 2;

        if(list == 1 && letra != '+')
        {
            list1 = addnodeinicio(list1, letra - '0');
            n1++;
        }
        else if (list == 2 && letra != '+')
        {
            list2 = addnodeinicio(list2, letra - '0');
            n2++;
        }
    }

    if(n1 > n2)
    {
        while(n1 != n2)
        {
            list2 = addnodefinal(list2, 0);
            n2++;
        }
    }

    if(n2 > n1)
    {
        while(n2 != n1)
        {
            list1 = addnodefinal(list1, 0);
            n1++;
        }
    }

    /*printlinkedlist(list1);
    printlinkedlist(list2);*/

    result = sum2linkedlists(list1, list2, result);

    printlinkedlist(result);

    return 0;
}