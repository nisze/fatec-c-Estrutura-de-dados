#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

Node* findParent(Node *root, int val) {
    if (!root) 
        return NULL;

    if (val <= root->value) {
        if (!root->left) 
            return root;
        return findParent(root->left, val);
    } else {
        if (!root->right) 
            return root;
        return findParent(root->right, val);
    }
}

void printTree(Node *root, int mode) {
    if (root) {
        if (mode == 1) { // Pre-Order
            printf(" %d", root->value);
            printTree(root->left, mode);
            printTree(root->right, mode);
        } else if (mode == 2) { // In-Order
            printTree(root->left, mode);
            printf(" %d", root->value);
            printTree(root->right, mode);
        } else if (mode == 3) { // Post-Order
            printTree(root->left, mode);
            printTree(root->right, mode);
            printf(" %d", root->value);
        }
    }
}

int main() {
    int cases, nodes, value, caseNum;

    scanf("%d", &cases);

    for (caseNum = 1; caseNum <= cases; caseNum++) {
        Node *root = NULL;

        scanf("%d", &nodes);

        for (int i = 0; i < nodes; i++) {
            scanf("%d", &value);

            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->value = value;
            newNode->left = newNode->right = NULL;

            Node *parent = findParent(root, value);
            if (!parent) {
                root = newNode;
            } else if (value <= parent->value) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }

        printf("Case %d:\n", caseNum);
        
        printf("Pre.:");
        printTree(root, 1);
        printf("\nIn..:");
        printTree(root, 2);
        printf("\nPost:");
        printTree(root, 3);
        printf("\n\n");
    }

    return 0;
}
