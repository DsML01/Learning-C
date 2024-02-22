#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó da árvore
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função auxiliar para imprimir a árvore no formato de parênteses
void printTree(struct TreeNode* root) {
    if (root == NULL) {
        printf("() ");
    } else {
        printf("( %d ", root->value);
        printTree(root->left);
        printTree(root->right);
        printf(") ");
    }
}

// Função para inserir um valor na árvore
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
    int num;
    struct TreeNode* root = NULL;

    puts("----");
    while (scanf("%d", &num) == 1) {
        printf("Adicionando %d\n", num);
        root = insert(root, num);
        printTree(root);
        printf("\n----\n");
    }

    return 0;
}
