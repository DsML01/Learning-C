#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btree
{
    int item;
    struct _btree *left;
    struct _btree *right;

} btree;

int descubra(btree *root, int achar, int soma)
{
    if (!root) {
        return 0;
    }

    soma += root->item;

    if (!root->left && !root->right)
    {
        if (soma == achar) return 1;
        else return 0;
    }

    return descubra(root->left, achar, soma) || descubra(root->right, achar, soma);
}

btree *create_tree(int item, btree *left, btree *right)
{
    btree *new_tree = (btree *) calloc(1, sizeof(btree));

    new_tree->item = item;
    new_tree->left = left;
    new_tree->right = right;

    return new_tree;
}

btree *construct_btree(char tree[], int *i)
{
    if (tree[*i] == '(' && tree[*i + 1] == ')')
    {
        *i += 2;
        return NULL;
    }

    else if (tree[*i] == '(') *i += 1;

    char almost_numbers[100] = {0};
    int j = 0;

    while (tree[*i] != '(' && tree[*i] != ')')
    {
        if (tree[*i] != ' ')
        {
            almost_numbers[j++] = tree[*i];
        }
        (*i)++;
    }

    int finally_numbers = atoi(almost_numbers);

    btree *reggae_roots = create_tree(finally_numbers, NULL, NULL);

    reggae_roots->left = construct_btree(tree, i);
    reggae_roots->right = construct_btree(tree, i);

    if (tree[*i] == ')') *i += 1;

    return reggae_roots;
}

char *ler_parenteses(int *n)
{
    int i = 0, barra_aberta = 0, barra_fechada = 0;
    char character;
    char *string = (char *) calloc(1000, sizeof(char));

    while(1)
    {
        scanf("%c", &character);

        if(character != ' ' && character != '\n') {
            string[i++] = character;
        }
        if(character == '(') {
            barra_aberta++;
        } else if(character == ')') {
            barra_fechada++;
        }
        if(barra_aberta == barra_fechada) {
            break;
        }
    }

    string[i] = '\0';

    printf("i = %d\n",i);

    *n = i;

    return string;
}


int leitura(int item)
{
    int n = 0;
    char *tree = ler_parenteses(&n);

    /*char tree[1000];

    fgets(tree, 1000, stdin);*/

    //int n = strlen(tree);

    printf("n = %d\n", n);

    char nice_tree[1000];

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (tree[i] != ' ')
        {
            nice_tree[j++] = tree[i];
        }
    }

    int i = 0;
    btree *root = construct_btree(nice_tree, &i);

    int resposta = descubra(root, item, 0);

    printf(resposta == 0 ? "nao\n" : "sim\n");

    int prox_item;
    scanf("%d", &prox_item);

    return prox_item;
}

int main()
{
    int item;
    scanf("%d", &item);
    int prox_item = leitura(item);

    while (1)
    {
        if (prox_item == -1000) return 0;
        prox_item = leitura(prox_item);
    }
}
