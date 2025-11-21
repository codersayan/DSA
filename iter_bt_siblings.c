//Check Whether Two Nodes Are Siblings 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root = NULL, *stack[SIZE];
int top = -1;

void push(node *n) { stack[++top] = n; }
node* pop() { return (top == -1) ? NULL : stack[top--]; }

// Iterative BST insertion
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

// Check siblings iteratively
int areSiblings(int a, int b) {
    if (!root) return 0;

    push(root);

    while (top != -1) {
        node *temp = pop();
        if (temp->left && temp->right) {
            if ((temp->left->key == a && temp->right->key == b) ||
                (temp->left->key == b && temp->right->key == a))
                return 1; // siblings
        }
        if (temp->right) push(temp->right);
        if (temp->left) push(temp->left);
    }
    return 0;
}

int main() {
    int n, val, x, y;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        create(val);
    }

    printf("Enter two nodes to check if they are siblings: ");
    scanf("%d %d", &x, &y);

    if (areSiblings(x, y))
        printf("%d and %d are siblings\n", x, y);
    else
        printf("%d and %d are NOT siblings\n", x, y);

    return 0;
}

