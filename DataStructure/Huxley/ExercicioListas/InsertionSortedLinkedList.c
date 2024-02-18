#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
} LISTA;



// Inicializa a lista deixando-a pronta para ser utilizada.
void inicializar(LISTA *l)
{
    l->cabeca = NULL;
}


// Cria um novo no com o item passado e tendo NULL como prox
NO* criarNo(ITEM item, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
    pNovo->prox = prox;
    return pNovo;
}


// Retornar o tamanho da lista
int tamanho(LISTA *l)
{
    NO* p = l->cabeca;
    int tam = 0;
    while (p)  // p != NULL
    {
        tam++;
        p = p->prox;
    }
    return tam;
}


// Retorna true se a lista esta vazia (Cabeca = NULL)
bool vazia(LISTA *l)
{
    return l->cabeca == NULL;
}


// Exibicao da lista sequencial
void exibirLista(LISTA *l)
{
    NO* p = l->cabeca;
    while (p)  // p != NULL
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}


// Liberacao das variaveis dinamicas dos nos da lista, iniciando da cabeca
void destruir(LISTA *l)
{
    NO* atual = l->cabeca;
    while (atual) {
        NO* prox = atual->prox; // guarda proxima posicao
        free(atual);            // libera memoria apontada por atual
        atual = prox;
    }
    l->cabeca = NULL; // ajusta inicio da lista (vazia)
}


void imprimirLista(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}


/////////////////////////////////////////////////////

/*
 Objetivo: Inserir em uma lista ordenada o item passado e garantir
           que nao havera duplicacao.
*/
bool inserirNaOrdem(ITEM item, LISTA *l)
{
    NO *new_node = criarNo(item, NULL);

    // Caso a lista esteja vazia ou a chave do novo item seja menor que a chave do primeiro item
    if (vazia(l) || item.chave < l->cabeca->item.chave)
    {
        new_node->prox = l->cabeca;
        l->cabeca = new_node;
        return true;
    }

    // Caso a chave do novo item seja igual à chave do primeiro item, não permitir duplicação
    if (item.chave == l->cabeca->item.chave) return false;

    // Percorrer a lista para encontrar a posição correta
    NO *previous_node = NULL;
    NO *current_node = l->cabeca;
    //while current_node != NULL (ESSA LINHA DE CÓDIGO ABAIXO QUER DIZER ISSO)
    while (current_node && item.chave > current_node->item.chave)
    {
        previous_node = current_node;
        current_node = current_node->prox;
    }

    // Caso a chave do novo item seja igual à chave de algum item na lista, não permitir duplicação
    //if(current_node != NULL)
    if (current_node && item.chave == current_node->item.chave) return false;

    // Inserir o novo nó na posição correta
    new_node->prox = current_node;
    previous_node->prox = new_node;

    return true;
}

//////////////////////////////////////////////////////////////


void lerItens(LISTA *l)
{
    int n;
    scanf("%d", &n);

    // insere os valores n pares chave,valor
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        inserirNaOrdem(item, l);
    }
}


int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l);
    
  lerItens(&l);
  imprimirLista(&l);

  destruir(&l);
  return 0;
}