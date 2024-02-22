#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct _node
{
    int item;
    struct _node *next;
} node;

typedef struct _hashtable
{
    int current_elements;
    int size;
    node **table;
    int *adjlist_current_size;
} hashtable;

int hash(int item, int n)
{
    return item % n;
}

hashtable *createhashtable(int n)
{
    hashtable *tabelahash = (hashtable*) calloc(1 , sizeof(hashtable));

    tabelahash->size = n;

    tabelahash->current_elements = 0;

    tabelahash->table = (node**) calloc(n , sizeof(node*));

    tabelahash->adjlist_current_size = (int *) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++)
    {
        tabelahash->table[i] = NULL;
        tabelahash->adjlist_current_size[i] = 0;
    }

    return tabelahash;
}

//funcao para descobrir se o elemento já está na tabela
int jatem(hashtable *tabela, int item, int *cont)
{
    int i = hash(item, tabela->size);
    
    node *aux = tabela->table[i];
    //printf("PRIMEIRO ITEM DA LINHA = %d\n", tabela->table[i]->item);

    while(aux != NULL)
    {
        if(aux->item == item)
        {
            (*cont) += 1;
            return 1;
        }

        (*cont) += 1;
        aux = aux->next;
    }
    
    return 0;
}

//essa funcao ainda esta problematica
//falta adicionar o contador de acessos
//falta adicionar a remocao do tamanho da lista adjacente

//provavelmente eu ja adicionei os dois, se der problema a funcao, voltar neles
int removeitem(hashtable *tabela, int item, int *cont)
{
    //puts("ENTROU NA FUNCAO");
    int i = hash(item, tabela->size);

    node *previous = NULL;
    node *current = tabela->table[i];

    int jafoimano = 0;

    if(current != NULL && current->item == item)
    {
        (*cont) += 1;
        jafoimano = 1;
    }

    while(current != NULL && current->item != item)
    {
        (*cont) += 1;
        previous = current;
        current = current->next;
    }

    if(current != NULL && current->item == item && jafoimano == 0) (*cont) += 1;

    if(current)
    {
        if(previous)
        {
            previous->next = current->next;
            current->next = NULL;
            //tabela->current_elements--;
        }

        else 
        {
            tabela->table[i] = current->next;
            //tabela->current_elements--;    
        }

        tabela->current_elements--;
        tabela->adjlist_current_size[i]--;
        return 1;
    }

    return 0;
}

int insert(hashtable *tabela, int item, int *cont)
{
    int i = hash(item, tabela->size);

    if(jatem(tabela, item, cont) == 1) return 0;

    node *new_node = (node*) calloc(1, sizeof(node));
    new_node->item = item;

    new_node->next = tabela->table[i];

    tabela->table[i] = new_node;

    tabela->adjlist_current_size[i]++;

    tabela->current_elements++;
    
    return 1;
}

hashtable *rehash(hashtable *table, int n)
{
    //printf("NOVO m = %d\n", 2 * n - 1);
    hashtable *new_hashtable = createhashtable((2 * n) - 1);

    for(int i = 0; i < n; i++)
    {
        node *aux = table->table[i];

        while(aux != NULL)
        {
            int cont;

            insert(new_hashtable ,aux->item, &cont);

            aux = aux->next;
        }
    }

    return new_hashtable;
}

int maior_comprimento_de_lista(int *v, int n)
{
    int maior = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(v[i] > maior)
        {
            maior = v[i];
        }
    }

    return maior;
}

void removenewline(char *string)
{
    int newlinePos = strcspn(string, "\n");
    string[newlinePos] = '\0';
    return;
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
    int m = 7;
    hashtable *tabelahash = createhashtable(m);

    char string[5];
    int item;
    int cont_acessados;

    for(int i = 0; scanf("%s", string) != EOF; i++)
    {
        
        cont_acessados = 0;
        removenewline(string);

        if(string[0] == 'A')
        {
            scanf("%d", &item);

            int bool = insert(tabelahash, item, &cont_acessados);

            double a = (double) tabelahash->current_elements / tabelahash->size;

            if(a >= 0.75) tabelahash = rehash(tabelahash, tabelahash->size);

            printf("%d %d %d\n", i, bool, cont_acessados);

        }

        if(string[0] == 'D')
        {
            scanf("%d", &item);

            /*if(i == 30)
            {
                puts("");
                printhashtable(tabelahash);
            }

            if(i == 94)
            {
                puts("");
                printhashtable(tabelahash);
            }*/
            
            //a linha do print esta pronta, mas eu ainda nao fiz a parte do conztador na funcao de remove
            //provavelmente eu ja o fiz, mas se der problema, voltar aqui

            int bool = removeitem(tabelahash, item, &cont_acessados);

            //printf("CONT_ACESSADOS NO REMOVE = %d\n", cont_acessados);

            printf("%d %d %d\n", i, bool, cont_acessados);

        }

        if(string[0] == 'H')
        {
            scanf("%d", &item);

            int bool = jatem(tabelahash, item, &cont_acessados);

            printf("%d %d %d\n", i, bool, cont_acessados);
            
        }

        if(string[0] == 'P')
        {
            printf("%d %d %d %d\n", i, tabelahash->size, tabelahash->current_elements, maior_comprimento_de_lista(tabelahash->adjlist_current_size, tabelahash->size));            
        }
    }

    /*puts("");
    printhashtable(tabelahash);*/

    return 0;
}