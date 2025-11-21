//Create a Binary Tree Iteratively & Find Sum of All Nodes 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root = NULL, *stack[SIZE];
int top = -1;

void push(node *n) {
    stack[++top] = n;
}

node* pop() {
    if (top == -1) return NULL;
    return stack[top--];
}

// Iterative insertion (BST style)
void create(int e) {
    node *p = (node*)malloc(sizeof(node));
    p->key = e;
    p->left = p->right = NULL;

    if (!root) {
        root = p;
        return;
    }

    node *cur = root, *parent;
    while (cur) {
        parent = cur;
        if (e < cur->key) cur = cur->left;
        else cur = cur->right;
    }

    if (e < parent->key) parent->left = p;
    else parent->right = p;
}

// Sum using iterative inorder traversal with stack
int findSum() {
    int sum = 0;
    node *curr = root;

    while (curr || top != -1) {
        while (curr) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        sum += curr->key;
        curr = curr->right;
    }

    return sum;
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

    printf("Sum of all nodes = %d\n", findSum());
    return 0;
}

