#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btree
{
    int item;
    int height;
    struct _btree *left;
    struct _btree *right;

} btree;

btree *create_tree(int item, btree *left, btree *right, int height)
{
    btree *new_tree = (btree *) calloc(1, sizeof(btree));

    new_tree->item = item;

    new_tree->left = left;

    new_tree->right = right;

    new_tree->height = height;

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


btree *construct_btree(char tree[], int *i, int height)
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
        almost_numbers[j] = tree[*i];
        (*i) += 1;
        j++;
    }

    almost_numbers[j] = '\0';

    int finally_numbers = atoi(almost_numbers);

    btree *reggae_roots = create_tree(finally_numbers, NULL, NULL, height);

    reggae_roots->left = construct_btree(tree, i, height + 1);
    reggae_roots->right = construct_btree(tree, i, height + 1);

    if(tree[*i] == ')') *i += 1;

    return reggae_roots;
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

    int i = 0, altura = 0;

    btree *root = construct_btree(nice_tree, &i, altura);

    int procurado;
    
    scanf("%d", &procurado);

    btree *pecheur = NULL;
    btree *TEMSIM = receba_a_inteligencia(root,procurado, &pecheur);

    if(TEMSIM == NULL) 
    {
        puts("NAO ESTA NA ARVORE\n-1");
        return 0;
    }

    printf("ESTA NA ARVORE\n%d\n", pecheur->height);

    return 0;
}