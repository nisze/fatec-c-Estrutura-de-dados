#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int valor;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree* rPai(Tree *root, int valor) {
    if (root == NULL) 
        return NULL;

    if (valor == root->valor) 
        return root;

    if (valor < root->valor) {
        if (root->left == NULL) 
            return root;
        return rPai(root->left, valor);
    } else {
        if (root->right == NULL) 
            return root;
        return rPai(root->right, valor);
    }
}

void printLevelOrder(Tree *root) {
    if (root == NULL) return;

    Tree *queue[1000];
    int start = 0, end = 0;

    queue[end++] = root;

    while (start < end) {
        Tree *current = queue[start++];

        printf("%d", current->valor);

        if (current->left != NULL) 
            queue[end++] = current->left;

        if (current->right != NULL) 
            queue[end++] = current->right;

        if (start < end) 
            printf(" ");
    }
}

int main() {
    int testCases, count, caseNum, valor, i;

    scanf("%d", &testCases);

    for (caseNum = 1; caseNum <= testCases; caseNum++) {
        Tree *root = NULL;

        scanf("%d", &count);

        for (i = 0; i < count; i++) {
            scanf("%d", &valor);

            Tree *newNode = (Tree *)malloc(sizeof(Tree));
            newNode->valor = valor;
            newNode->left = newNode->right = NULL;

            Tree *parent = rPai(root, valor);

            if (parent == NULL) {
                root = newNode;
            } else if (parent->valor != valor) {
                if (valor < parent->valor) 
                    parent->left = newNode;
                else 
                    parent->right = newNode;
            }
        }

        printf("Case %d:\n", caseNum);
        printLevelOrder(root);
        printf("\n\n");
    }

    return 0;
}
