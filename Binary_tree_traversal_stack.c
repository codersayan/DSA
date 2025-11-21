#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root = NULL, *stack[SIZE];
int top = -1;

void create(int);
void inorder();
void preorder();
void push(node *);
node *pop();

int main()
{
    int n, e;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &e);
        create(e);
    }

    printf("\nInorder Traversal:\n");
    inorder();

    printf("\nPreorder Traversal:\n");
    preorder();

    return 0;
}

void create(int e)
{
    node *p = (node *)malloc(sizeof(node));
    p->key = e;
    p->left = p->right = NULL;

    if (root == NULL) {
        root = p;
        return;
    }

    node *cur = root, *parent;

    while (cur != NULL)
    {
        parent = cur;
        if (e < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (e < parent->key)
        parent->left = p;
    else
        parent->right = p;
}

void inorder()
{
    node *curr = root;

    while (curr != NULL || top != -1)
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }

        curr = pop();
        printf("%d ", curr->key);

        curr = curr->right;
    }
    printf("\n");
}

void preorder()
{
    if (root == NULL) return;

    push(root);

    while (top != -1)
    {
        node *temp = pop();
        printf("%d ", temp->key);

        if (temp->right) push(temp->right);
        if (temp->left) push(temp->left);
    }
    printf("\n");
}

void push(node *n)
{
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = n;
}

node *pop()
{
    if (top == -1) {
        return NULL;
    }
    return stack[top--];
}
