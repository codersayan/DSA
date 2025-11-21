#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root_iter = NULL;
node *root_rec  = NULL;

/* ---------------- ITERATIVE INSERT ---------------- */
void insert_iter(int val)
{
    node *p = (node*)malloc(sizeof(node));
    p->key = val;
    p->left = p->right = NULL;

    if (root_iter == NULL) {
        root_iter = p;
        return;
    }

    node *cur = root_iter, *parent = NULL;

    while (cur != NULL) {
        parent = cur;
        if (val < cur->key)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (val < parent->key)
        parent->left = p;
    else
        parent->right = p;
}

/* ---------------- RECURSIVE INSERT ---------------- */
node* insert_rec(node *root, int val)
{
    if (root == NULL) {
        node *p = (node*)malloc(sizeof(node));
        p->key = val;
        p->left = p->right = NULL;
        return p;
    }

    if (val < root->key)
        root->left = insert_rec(root->left, val);
    else
        root->right = insert_rec(root->right, val);

    return root;
}

/* ---------------- SIMPLE INORDER TO VERIFY ---------------- */
void inorder(node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main()
{
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("\n--- ITERATIVE INSERT ---\n");
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        insert_iter(x);
    }

    printf("\n--- RECURSIVE INSERT ---\n");
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        root_rec = insert_rec(root_rec, x);
    }

    printf("\nInorder of Iterative BST: ");
    inorder(root_iter);

    printf("\nInorder of Recursive BST: ");
    inorder(root_rec);

    printf("\n");
    return 0;
}
