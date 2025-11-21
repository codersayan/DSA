#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root = NULL;

void create(int e) {
    node *p = (node*)malloc(sizeof(node));
    p->key = e;
    p->left = p->right = NULL;

    if (!root) { root = p; return; }

    node *cur = root, *parent;
    while (cur) { parent = cur; if (e < cur->key) cur = cur->left; else cur = cur->right; }

    if (e < parent->key) parent->left = p;
    else parent->right = p;
}

int findMin() {
    node *curr = root;
    while (curr->left) curr = curr->left;
    return curr->key;
}

int findMax() {
    node *curr = root;
    while (curr->right) curr = curr->right;
    return curr->key;
}

int main() {
    int n,i, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        scanf("%d", &val);
        create(val);
    }

    printf("Minimum = %d\n", findMin());
    printf("Maximum = %d\n", findMax());
    return 0;
}

