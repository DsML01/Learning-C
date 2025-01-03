#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btree
{
    int item;
    struct _btree *left;
    struct _btree *right;

} btree;

typedef struct _node
{
    int item;
    int left;
    int right;
    struct _node *next; 
} node;

typedef struct _simplenode
{
    int item;
    struct _simplenode *next;
} simplenode;

simplenode *addsimplenodefinal(simplenode *head, int item)
{
    simplenode *new_node = (simplenode*) calloc(1, sizeof(simplenode));
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
        simplenode *aux = head;

        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = new_node;

        return head;
    }
}

// Correção na função addnodefinal para aceitar um ponteiro para o nó da árvore
node *addnodefinal(btree *tree, node *head)
{
    node *new_node = (node*) calloc(1, sizeof(node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    new_node->item = tree->item;
    new_node->left = tree->left != NULL ? (tree->left->item) : (-1);
    new_node->right = tree->right != NULL ? (tree->right->item) : (-1);
    new_node->next = NULL;

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

// Correção na chamada da função addnodefinal na função preencher
node *preencher(btree *tree, node *result) {
    if (tree != NULL) {
        result = preencher(tree->left, result);
        result = addnodefinal(tree, result); // Passar o ponteiro para o nó da árvore
        result = preencher(tree->right, result);
    }
    return result;
}


void printarvore(btree *reggae_roots)
{
    //printf("(");
    if(reggae_roots != NULL) printf("(%d", reggae_roots->item);
    else printf("()");

    if(reggae_roots != NULL) printarvore(reggae_roots->left);
    //printf(")");

    if(reggae_roots != NULL) printarvore(reggae_roots->right);
    if(reggae_roots != NULL) printf(")");

    return;
}

btree *create_tree(int item, btree *left, btree *right)
{
    btree *new_tree = (btree *) calloc(1, sizeof(btree));

    new_tree->item = item;

    new_tree->left = left;

    new_tree->right = right;

    return new_tree;
}

btree *construct_btree(char tree[], int *i, int *cont)
{
    if(tree[*i] == '(' && tree[*i + 1] == ')')
    {
        *i += 2;
        return NULL;
    }

    else if(tree[*i] == '(') *i += 1;

    char almost_numbers[100];
    
    int j = 0;
    while(tree[*i] != '(' && tree[*i] != ')')
    {
        if(tree[*i] == ' ')
        {
            (*i) += 1;
        }
        else
        {
            almost_numbers[j] = tree[*i];
            (*i) += 1;
            j++;
        }
    }

    almost_numbers[j] = '\0';

    int finally_numbers = atoi(almost_numbers);

    btree *reggae_roots = create_tree(finally_numbers, NULL, NULL);
    (*cont) += 1;

    reggae_roots->left = construct_btree(tree, i, cont);
    reggae_roots->right = construct_btree(tree,i, cont);

    if(tree[*i] == ')') *i += 1;

    return reggae_roots;
}

simplenode *descubra(node *head, int *cont, simplenode *simplehead)
{
    if(head == NULL) return simplehead;

    if((head->left >= 0 && head->right >= 0)||(head->left == -1 && head->right == -1)) 
    {
        *cont += 1;
        descubra(head->next, cont, simplehead);
    }
    else if( (head->left == -1 && head->right >= 0) || (head->right == -1 && head->left >= 0))
    {
        simplehead = addsimplenodefinal(simplehead, head->item);
        descubra(head->next, cont, simplehead);
    }

}

void printlinkedlist(simplenode *head)
{
    simplenode *aux = head;

    while(aux != NULL)
    {
        printf(" %d", aux->item);
        aux = aux->next;
    }
    puts("");
}

int main()
{
    char tree[1000];

    fgets(tree, 1000, stdin);

    int n = strlen(tree);

    char nice_tree[1000];

    int j = 0;

    for(int i = 0; i < n; i++)
    {
        if(tree[i] != ' ')
        {
            nice_tree[j] = tree[i];
            j++;
        }
    }

    int i = 0, num_nodes = 0;

    btree *root = construct_btree(nice_tree, &i, &num_nodes);

    //printf("NUMERO DE NODES = %d\n", num_nodes);

    node *result = NULL;

    result = preencher(root, result);

    //printarvore(root);
    //printf("RESULTADO = %d\nESQUERDA = %d\nDIREITA = %d\n", result->next->next->next->item, result->next->next->next->left, result->next->next->next->right);

    int complete_nodes = 0;

    simplenode *errados = NULL;
    errados = descubra(result, &complete_nodes, errados);

    if(complete_nodes == num_nodes)
    {
        puts("completa");
        printf("total de nos: %d\n", num_nodes);
        return 0;
    }

    puts("nao completa");
    printf("nos com um filho:");

    printlinkedlist(errados);

    return 0;
}