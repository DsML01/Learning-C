#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    struct _node *next;
} node;

node *addnodeinicio(node *head)
{
    node *new_node = (node*) calloc(1,sizeof(node));
    new_node->next = head;

    return new_node;
}

void removeNewLine(char *string)
{
    if(string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0';
    }

    return;
}

void pop(node *head)
{
    head = head->next;
    return;
}

int contback(node *head)
{
    int cont = -1;
    while(head != NULL)
    {
        cont++;
        head = head->next;
    }

    return cont;
}

int contforward(node *head)
{
    int cont = 0;
    while(head != NULL)
    {
        cont++;
        head = head->next;
    }

    return cont;
}


void scanstack(node *headback, node *headforward)
{
    char string[10];

    while(fgets(string,10,stdin) != NULL)
    {
        removeNewLine(string);
        //printf("%s\n", string);
        //CASO ALGO DE ERRADO, PRINTAR A STRING PRA VER SE ELA ESTÁ SAINDO CERTA
        if(strcmp(string, "ENTER") == 0)
        {
            headback = addnodeinicio(headback);
        }
        else if(strcmp(string, "BACK") == 0)
        {
            headforward = addnodeinicio(headforward);
            //falta implementar a pop
            pop(headback);
        }
        else if(strcmp(string, "FORWARD") == 0)
        {
            headforward = addnodeinicio(headback);
            pop(headforward);
        }
    }

    int forward = contforward(headforward);
    int back = contback(headback);

    printf("BACK: %d\nFORWARD: %d\n", back, forward);
}


int main()
{
    node *headback = NULL;
    node *headforward = NULL;

    scanstack(headback, headforward);

    return 0;
}