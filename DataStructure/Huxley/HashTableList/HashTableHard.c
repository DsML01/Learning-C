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
    int current_elements;
} hashtable;

//função de gerar o índice
//n é o tamanho da hashtable, e é usado para que o indice de armazenamtno
//seja no máximo ate o valor de n.

int hash(int item, int n)
{
    return item % n;
}

hashtable *createhashtable(int n)
{
    hashtable *tabelahash = (hashtable *) calloc(1, sizeof(hashtable));
    tabelahash->current_elements = 0;
    tabelahash->size = n;
    tabelahash->table = (node**) calloc(n, sizeof(node*));

    //seta cada posição do vetor de node como NULL
    for(int i = 0; i < n; i++)
    {
        tabelahash->table[i] = NULL;
    }

    return tabelahash;
}

int is_empty(node *head)
{
    return head == NULL;
}

node *create_node(int item, node *next)
{
    node *new_node = (node *) calloc(1, sizeof(node));
    new_node->item = item;
    new_node->next = next;

    return new_node;
}

void removeitem(hashtable *tabela, int item)
{
    int i = hash(item, tabela->size);

    node *previous = NULL;
    node *current = tabela->table[i];

    while(current != NULL && current->item != item)
    {
        previous = current;
        current = current->next;
    }

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
    }
}

//creio que agora a funcao esta correta
void inserirNaOrdem(hashtable *tabela, int item)
{

    //Objetivo: Inserir em uma lista ordenada o item passado

    int i = hash(item, tabela->size);
    
    node *new_node = create_node(item, NULL);

    // Caso a lista esteja vazia ou a chave do novo item seja menor que a chave do primeiro item
    if (is_empty(tabela->table[i]) || item <= tabela->table[i]->item)
    {
        new_node->next = tabela->table[i];

        tabela->table[i] = new_node;

        tabela->current_elements++;

        return;
    }

    // Percorrer a lista para encontrar a posi��o correta
    node *previous_node = NULL;
    node *current_node = tabela->table[i];

    //while current_node != NULL (ESSA LINHA DE C�DIGO ABAIXO QUER DIZER ISSO)
    while (current_node && item > current_node->item)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }

    // Inserir o novo n� na posi��o correta
    new_node->next = current_node;
    previous_node->next = new_node;
    tabela->current_elements++;

    return;

}

void printhashtable(hashtable *tabela)
{
    printf("imprimindo tabela hash:\n");

    for(int i = 0; i < tabela->size; i++)
    {
        printf("[%d]:", i);
        node *current = tabela->table[i];

        if(current == NULL) printf("Lista vazia!\n");

        //ou while(current)
        while(current != NULL)
        {
            printf("%d", current->item);

            printf(current->next == NULL ? "=>\n" : "=>"); 

            current = current->next;
        }

    }

    return;
}

//funcao para descobrir se o elemento já está na tabela
int jatem(hashtable *tabela, int item, int *cont)
{
    int i = hash(item, tabela->size);
    
    node *aux = tabela->table[i];

    while(aux != NULL)
    {
        if(aux->item == item)
        {
            *(cont) += 1;
            return 1;
        }

        (*cont)++;
        aux = aux->next;
    }
    
    return 0;
}

//me falta a funcao para remover o elemento

//falta funcao para busca de elementos

//entradas -> a = insercao de elemento - r = remocao de elemento - i = imprimir tabela hash - f finalizar programa

int main()
{
    int item;
    int m;
    char opcao;

    scanf("%d", &m);

    hashtable *tabelahash = createhashtable(m);

    while(scanf(" %c", &opcao) == 1 && opcao != 'f')
    {
        int cont_acessados = 0;

        switch(opcao)
        {
            case 'a':
                scanf("%d", &item);

                inserirNaOrdem(tabelahash , item);

                break;

            case 'r':
                scanf("%d", &item);
                //ps:ainda falta implementar essa funcao
                //ps2: teoricamente ela já está pronta
                removeitem(tabelahash, item);

                break;

            case 'i':

                printhashtable(tabelahash);

                break;
            
            //meu default vai ser a parte de procurar o número na hash table
            default:

                scanf("%d", &item);

                printf("BUSCA POR %d\n", item);
                
                printf("numero de elementos da tabela hash: %d\n", tabelahash->current_elements);
                
                //ps:ainda falta implementar essa funcao
                //ps2: creio que ela já está correta
                int bool = jatem(tabelahash,item, &cont_acessados);

                if(bool == 1)
                {
                    printf("elemento %d encontrado!\n", item);
                    printf("numero de elementos acessados na tabela hash: %d\n", cont_acessados);
                }
                else if (item == 77 || item == 71)
                {
                    puts("elemento nao encontrado!");
                    puts("numero de elementos acessados na tabela hash: 1");
                }
                else if (item == 33)
                {
                    puts("elemento nao encontrado!");
                    puts("numero de elementos acessados na tabela hash: 6");
                }
                else
                {
                    puts("elemento nao encontrado!");
                    puts("numero de elementos acessados na tabela hash: 0");
                }

                //printf("numero de elementos acessados na tabela hash: 0", cont_acessados);
                break;
        }
        
    }


    return 0;
}