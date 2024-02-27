#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct _btree
{
    int item;
    struct _btree *left;
    struct _btree *right;
} btree;

typedef struct _input
{
    int node_value;
    int left_son;
    int right_son;
} input;

btree *create_btree(input *inputs, int i)
{
    if(i == -1) return NULL;

    btree* new_btree = (btree*) calloc(1, sizeof(btree));
    new_btree->item = inputs[i].node_value;
    new_btree->left = NULL;
    new_btree->right = NULL;

    new_btree->left = create_btree(inputs, inputs[i].left_son);
    new_btree->right = create_btree(inputs, inputs[i].right_son);

    return new_btree;
}

int tree_height(btree *tree)
{
    if(tree == NULL) return 0;

    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

void minmax(btree *tree, int maximum[], int minimum[], int current_height)
{
    if (tree == NULL) return;

    if(tree->item > maximum[current_height]) maximum[current_height] = tree->item;

    if(tree->item < minimum[current_height]) minimum[current_height] = tree->item;

    minmax(tree->left, maximum, minimum, current_height + 1);
    minmax(tree->right, maximum, minimum, current_height + 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    input inputs[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &inputs[i].node_value, &inputs[i].left_son, &inputs[i].right_son);
    }

    btree *root = create_btree(inputs, 0);

    //printf("PAI = %d, FILHO ESQUERDO = %d, FILHO DIREITO = %d\n\n\n\n\n", root->item, root->left->item, root->right->item);

    int height = tree_height(root);
    //printf("HEIGHT = %d\n", height);

    int maximum[height];
    int minimum[height];

    for(int i = 0; i < height; i++)
    {
        maximum[i] = INT_MIN;
        minimum[i] = INT_MAX;
    }

    minmax(root, maximum, minimum, 0);

    for(int i = 0; i < height; i++)
    {
        printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, maximum[i], minimum[i]);
    }

    return 0;
}