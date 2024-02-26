#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btree
{
    int item;
    struct _btree *left;
    struct _btree *right;
} btree;

btree *create_tree(int item, btree *left, btree *right)
{
    btree *new_tree = (btree *) calloc(1, sizeof(btree));

    new_tree->item = item;

    new_tree->left = left;

    new_tree->right = right;

    return new_tree;
}

int jatem(btree *arvore, int wanted, btree **pecheur)
{
    *pecheur = arvore;

    if(arvore == NULL) return 0;

    if(arvore->item == wanted) return 1;

    jatem(arvore->left, wanted, pecheur);
    jatem(arvore->right, wanted, pecheur);
   
   return jatem(arvore->left, wanted, pecheur) || jatem(arvore->right, wanted, pecheur);
}

btree *receba_a_inteligencia(btree *arvore, int wanted, btree **pecheur)
{
    return jatem(arvore, wanted, pecheur) == 1 ? arvore : NULL; 
}

btree *construct_btree(char tree[], int *i)
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

    reggae_roots->left = construct_btree(tree, i);
    reggae_roots->right = construct_btree(tree,i);

    if(tree[*i] == ')') *i += 1;

    return reggae_roots;
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

int main()
{
    char bad_matriz[1000];

    fgets(bad_matriz, 1000, stdin);

    int n1 = strlen(bad_matriz);
    
    int j = 0;

    char matriz[1000];

    for(int i = 0; i < n1; i++)
    {
        if(bad_matriz[i] != ' ')
        {
            matriz[j] = bad_matriz[i];
            j++;
        }
    }

    int i = 0;
    btree *root = construct_btree(matriz, &i);

    //provavelmente essa logica esta correta
    while(1)
    {
        char badtree[1000];

        fgets(badtree, 1000, stdin);
        int n = strlen(badtree);

        if(n <= 3) break;

        char nice_tree[1000];

        int j = 0;

        for(int i = 0; i < n; i++)
        {
            if(badtree[i] != ' ')
            {
                nice_tree[j] = badtree[i];
                j++;
            }
        }

        int i2 = 0;
        btree *aux_root = construct_btree(nice_tree, &i2);
        int procurado = aux_root->item;

        btree *pecheur = NULL;
        btree *TEMSIM = receba_a_inteligencia(root, procurado, &pecheur);

        printf("%d\n\n\n\n", pecheur->item);

        pecheur = aux_root;

        printf("%d\n\n\n\n", pecheur->left->item);
    }

    printarvore(root);
    puts("");
    
    return 0;
}