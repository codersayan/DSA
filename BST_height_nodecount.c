#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree *left, *right;
} node;

/* Create a new node */
node* create(int val) {
    node *p = (node*)malloc(sizeof(node));
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

/* Height of tree */
int height(node *root) {
    if (root == NULL)
        return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    return (h1 > h2 ? h1 : h2) + 1;
}

/* Count total nodes */
int count(node *root) {
    if (root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

int main() {
    /* VERY SIMPLE FIXED TREE:
              10
             /  \
            5    20
           /
          3
    */

    node *root = create(10);
    root->left = create(5);
    root->right = create(20);
    root->left->left = create(3);

    printf("Height = %d\n", height(root));
    printf("Total nodes = %d\n", count(root));

    return 0;
}
