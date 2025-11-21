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

// Mirror iteratively using stack
void mirror() {
    if (!root) return;

    push(root);

    while (top != -1) {
        node *curr = pop();
        node *temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        if (curr->left) push(curr->left);
        if (curr->right) push(curr->right);
    }
}

// Iterative inorder traversal
void inorder() {
    node *curr = root;

    while (curr || top != -1) {
        while (curr) { push(curr); curr = curr->left; }

        curr = pop();
        printf("%d ", curr->key);
        curr = curr->right;
    }
    printf("\n");
}

int main() {
    int n, i, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        create(val);
    }

    mirror();
    printf("Inorder of mirrored tree: ");
    inorder();
    return 0;
}

