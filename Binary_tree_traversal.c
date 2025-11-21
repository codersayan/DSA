// binary tree level order traversal using queue

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root = NULL;

/* Queue for Level Order */
node *queue[SIZE];
int front = -1, rear = -1;

void create(int);
void levelorder();
void enqueue(node *);
node *dequeue();

int main()
{
    int n, e;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &e);
        create(e);
    }

    printf("\nLevel Order Traversal:\n");
    levelorder();

    return 0;
}

// Insert into BST (iterative) 
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

/* LEVEL ORDER using QUEUE */
void levelorder()
{
    if (root == NULL) return;

    enqueue(root);

    while (front != -1)
    {
        node *temp = dequeue();
        printf("%d ", temp->key);

        if (temp->left)  enqueue(temp->left);
        if (temp->right) enqueue(temp->right);
    }

    printf("\n");
}


void enqueue(node *n)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) front = 0;

    queue[++rear] = n;
}

node *dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return NULL;
    }

    node *temp = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return temp;
}
