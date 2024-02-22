#include <stdio.h>
#include <stdlib.h>

typedef struct _tree
{
    int item;
    struct _tree *left;
    struct _tree *right;
} tree;

tree *start_tree()
{
    tree *new_tree = (tree *) calloc(1 , sizeof(tree));

    new_tree = NULL;

    return new_tree;
}

tree *create_tree_node(int item)
{
    tree *new_tree_node = (tree *) calloc(1 , sizeof(tree));

    new_tree_node->item = item;

    new_tree_node->left = NULL;

    new_tree_node->right = NULL;

    return new_tree_node;
}

void printtree(tree *root)
{
    if(root == NULL)
    {
        printf("  ()");
    }
    else
    {
        printf("  ( %d", root->item);
        printtree(root->left);
        printtree(root->right);
        printf(" )");
    }
}

tree *insert_tree(tree *root, int item)
{
    if(root == NULL) return create_tree_node(item);

    if (item < root->item) root->left = insert_tree(root->left, item);
    
    else root->right = insert_tree(root->right, item);

    return root;
}

int main()
{
    int item;
    tree *root = start_tree();

    puts("----");
    while(scanf("%d", &item) == 1)
    {
        //if(root != NULL) printf("RAÍZ->ITEM = %d\n", root->item);
        printf("Adicionando %d\n ", item);
        root = insert_tree(root, item);
        printtree(root);
        puts(" \n----");
    }

    return 0;
}