#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *l, *r;
} Node;

Node* newNode(int v) {
    Node* n = malloc(sizeof(Node));
    n->val = v;
    n->l = n->r = NULL;
    return n;
}

/* Build tree from user input */
Node* buildTree(Node* nodes[], int n) {
    Node *root = nodes[1];
    printf("Enter left and right child of each node (0 if none):\n");
    for (int i = 1; i <= n; i++) {
        int l, r;
        printf("Node %d: ", i);
        scanf("%d %d", &l, &r);
        if (l != 0) nodes[i]->l = nodes[l];
        if (r != 0) nodes[i]->r = nodes[r];
    }
    return root;
}
