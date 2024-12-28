#include <stdio.h>
#include <stdlib.h>
 
int bool = 0;
 
typedef struct arvore_avl
{
    int item;
    int altura;
    struct arvore_avl *left;
    struct arvore_avl *right;
} avl;
 
int maximo(int a, int b)
{
    return (a > b) ? a : b;
}
 
int altura(avl *arvore)
{
    if(arvore == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + maximo(altura(arvore->left), altura(arvore->right));
    }
}
 
avl *criar_avl(int item, avl *left, avl *right)
{
    avl *nova_avl = (avl*)malloc(sizeof(avl));
    nova_avl->item = item;
    nova_avl->left = left;
    nova_avl->right = right;
    nova_avl->altura = altura(nova_avl);
    return nova_avl;
}
 
avl *rotacionar_left(avl *arvore)
{
    avl *raiz_subarvore = NULL;
    if(arvore != NULL && arvore->right != NULL) 
    {
        raiz_subarvore = arvore->right;
        arvore->right = raiz_subarvore->left;
        raiz_subarvore->left = arvore;
    }
    raiz_subarvore->altura = altura(raiz_subarvore);
    arvore->altura = altura(arvore);
    return raiz_subarvore;
}
 
avl *rotacionar_right(avl *arvore)
{
    avl *raiz_subarvore = NULL;
    if(arvore != NULL && arvore->left != NULL)
    {
        raiz_subarvore = arvore->left;
        arvore->left = raiz_subarvore->right;
        raiz_subarvore->right = arvore;
    }
    raiz_subarvore->altura = altura(raiz_subarvore);
    arvore->altura = altura(arvore);
    return raiz_subarvore;
}
 
int fator_balanceamento(avl *arvore)
{
    if(arvore != NULL)
    {
        return (altura(arvore->left) - altura(arvore->right));
    }
    return 0;
}
 
void gerar_parenteses_arvore(avl *arvore)
{
    printf(" (");
    if(arvore != NULL)
    {
        printf(" %d ", arvore->item);
        gerar_parenteses_arvore(arvore->left);
        gerar_parenteses_arvore(arvore->right);
    }
    printf(") ");
}
 
avl *adicionar_folha_avl(avl *salvar, avl *arvore, int item)
{
    if(arvore == NULL)
    {
        return criar_avl(item, NULL, NULL);
    }

    else if(arvore->item > item)
    {
        arvore->left = adicionar_folha_avl(salvar, arvore->left, item);
    }

    else
    {
        arvore->right = adicionar_folha_avl(salvar, arvore->right, item);
    }

    arvore->altura = altura(arvore);

    avl *filho;

    if(fator_balanceamento(arvore) == 2 || fator_balanceamento(arvore) == -2)
    {
        printf("Antes de ajustar balanceamento...\n  ");
        gerar_parenteses_arvore(salvar);

        if(fator_balanceamento(arvore) == 2)
        {
            filho = arvore->left;
            if(fator_balanceamento(filho) == -1)
            {
                arvore->left = rotacionar_left(filho);
            }
            arvore = rotacionar_right(arvore);
        }

        else if(fator_balanceamento(arvore) == -2)
        {
            filho = arvore->right;
            if(fator_balanceamento(filho) == 1)
            {
                arvore->right = rotacionar_right(filho);
            }
            arvore = rotacionar_left(arvore);
        }

        bool = 1;
    }
    return arvore;
}
 
int main() {
    int item;
    avl *arvore_avl = NULL;

    while(scanf("%d", &item) != EOF)
    {
        printf("----\n");
        printf("Adicionando %d\n", item);

        arvore_avl = adicionar_folha_avl(arvore_avl, arvore_avl, item);

        if (!bool)
        {
            printf("Continuou AVL...\n");
        }
        else
        {
            printf("\nDepois de ajustar balanceamento...\n");
        }

        printf("  ");
        gerar_parenteses_arvore(arvore_avl);
        printf("\n");

        bool = 0;
    }
    printf("----\n");
    return 0;
}
