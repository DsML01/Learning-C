#include <stdio.h>
#include <stdlib.h>

typedef struct _tree
{
    int item;
    tree *left;
    tree *right;
} tree;

tree *create_tree(int item, tree *left, tree *right)
{
    tree *new_tree = (tree *) calloc(1 , sizeof(tree));
 
    new_tree->item = item;
    new_tree->left = left;
    new_tree->right = right;
 
    return new_tree;
}

void add_edge()
{

}

int main()
{

    return 0;
}