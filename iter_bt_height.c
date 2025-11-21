//Print Number of Nodes at Each Level & Total Levels (Height) Iteratively 
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


void printLevelInfo() {
	int i;
    if (!root) return;

    node *queue[SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int level = 0;

    while (front < rear) {
        int count = rear - front; // nodes at this level
        printf("Level %d has %d nodes\n", level + 1, count);
        for (i = 0; i < count; i++) {
            node *temp = queue[front++];
            if (temp->left) queue[rear++] = temp->left;
            if (temp->right) queue[rear++] = temp->right;
        }
        level++;
    }

    printf("Total levels (height) = %d\n", level);
}

int main() {
    int n,i, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        create(val);
    }

    printLevelInfo();
    return 0;
}

