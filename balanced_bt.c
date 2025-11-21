#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 100

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root = NULL;

// Iterative BST insertion
void create(int e) {
    node *p = (node*)malloc(sizeof(node));
    p->key = e;
    p->left = p->right = NULL;

    if (!root) { root = p; return; }

    node *cur = root, *parent;
    while (cur) {
        parent = cur;
        if (e < cur->key) cur = cur->left;
        else cur = cur->right;
    }

    if (e < parent->key) parent->left = p;
    else parent->right = p;
}

// Simple recursive function to compute height
int height(node *root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Check balance recursively
int isBalanced(node *root) {
    if (!root) return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    int n, i, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        create(val);
    }

    if (isBalanced(root))
        printf("Tree is balanced\n");
    else
        printf("Tree is not balanced\n");

    return 0;
}

