#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Estrutura para representar um nó da árvore
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Função auxiliar para verificar se uma árvore é BST
/*bool isBSTUtil(Node* root, int min, int max) {
    // Árvore vazia é uma BST
    if (root == NULL) {
        return true;
    }

    // Verifica se o valor do nó está no intervalo válido
    if (root->value < min || root->value > max) {
        return false;
    }

    // Verifica recursivamente as subárvores esquerda e direita
    return isBSTUtil(root->left, min, root->value - 1) && isBSTUtil(root->right, root->value + 1, max);
}

// Função principal para verificar se uma árvore é BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}*/

// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para analisar uma árvore binária representada por parênteses
Node* parseTree(char str[], int* index) {
    if (str[*index] == '(' && str[*index + 1] == ')') {
        *index += 2; // Pula "()"
        return NULL;
    }

    // Lê o valor do nó
    int value = 0;
    while (str[*index] >= '0' && str[*index] <= '9') {
        value = value * 10 + (str[*index] - '0');
        (*index)++;
    }

    // Cria o nó
    Node* root = createNode(value);

    // Move para o próximo caractere (deve ser '(')
    (*index)++;

    // Recursivamente analisa as subárvores esquerda e direita
    root->left = parseTree(str, index);
    root->right = parseTree(str, index);

    // Move para o próximo caractere (deve ser ')')
    (*index)++;

    return root;
}

int main() {
    char input[1000]; // Ajuste o tamanho conforme necessário

    // Leitura da árvore binária representada por parênteses
    printf("Digite a árvore binária representada por parênteses: ");
    fgets(input, sizeof(input), stdin);

    int index = 0;
    Node* root = parseTree(input, &index);

    // Verificação se a árvore é BST
    /*if (isBST(root)) {
        printf("A árvore é uma Árvore de Busca Binária (BST).\n");
    } else {
        printf("A árvore não é uma BST.\n");
    }*/

    return 0;
}
