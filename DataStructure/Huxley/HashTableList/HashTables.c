#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int item;
    struct _node *next;
} node;

typedef struct _hashtable
{
    int size;
    node **table;
} hashtable;

//função de gerar o índice
int hash(int item, int n)
{
    return item % n;
}

hashtable *createhashtable(int n)
{
    hashtable *tabelahash = (hashtable *) calloc(1, sizeof(hashtable));
    tabelahash->size = n;
    tabelahash->table = (node**) calloc(n, sizeof(node*));

    //seta cada posição do vetor de node como NULL
    for(int i = 0; i < n; i++)
    {
        tabelahash->table[i] = NULL;
    }

    return tabelahash;
}

void insert(hashtable *tabela, int item)
{
    int i = hash(item, tabela->size);

    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->item = item;
    new_node->next = NULL;

    if(tabela->table[i] == NULL) tabela->table[i] = new_node;

    else
    {
        node *current = tabela->table[i];

        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
    }
}

void printhashtable(hashtable *tabela)
{
    for(int i = 0; i < tabela->size; i++)
    {
        printf("%d -> ", i);
        node *current = tabela->table[i];

        if(current == NULL) printf("\\\n");

        while(current != NULL)
        {
            printf("%d", current->item);

            printf(current->next == NULL ? " -> \\\n" : " -> "); 

            current = current->next;
        }

    }

    return;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        //m == quantidade de endereços-base na tabela
        //c == qunatidade de chaves a serem armazenadas
        int m, c; 
        scanf("%d %d", &m, &c);

        hashtable *tabelahash = createhashtable(m);

        for(int j = 0; j < c; j++)
        {
            int item;
            scanf("%d", &item);
            //inserir na tabela hash
            insert(tabelahash, item);
        }

        printhashtable(tabelahash);
        
        if(i != n - 1) puts("");
        
    }

    return 0;
}