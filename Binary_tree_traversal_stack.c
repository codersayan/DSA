#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root = NULL, *stack[SIZE];
int top = -1;

// Function prototypes
void create(int);
void inorder();
void preorder();
void postorder();
void push(node *);
node* pop();

int main()
{
    int n, i, e;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &e);
        create(e);
    }

    printf("\nInorder Traversal:\n");
    inorder();

    printf("\nPreorder Traversal:\n");
    preorder();

    printf("\nPostorder Traversal:\n");
    postorder();

    return 0;
}

// Iterative BST insertion
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

// Iterative inorder traversal
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

// Iterative preorder traversal
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

// Iterative postorder traversal using two stacks
void postorder()
{
    if (root == NULL) return;

    node *stack1[SIZE], *stack2[SIZE];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1)
    {
        node *temp = stack1[top1--];
        stack2[++top2] = temp;

        if (temp->left) stack1[++top1] = temp->left;
        if (temp->right) stack1[++top1] = temp->right;
    }

    while (top2 != -1)
    {
        printf("%d ", stack2[top2--]->key);
    }
    printf("\n");
}

// Stack push
void push(node *n)
{
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = n;
}

// Stack pop
node *pop()
{
    if (top == -1) return NULL;
    return stack[top--];
}

