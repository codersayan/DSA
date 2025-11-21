#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *l, *r;
} Node;

// Create new node
Node* newNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->l = n->r = NULL;
    return n;
}

// Inorder traversal (for display)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->l);
    printf("%d ", root->val);
    inorder(root->r);
}

// Mirror the tree
void mirror(Node* root) {
    if (root == NULL) return;

    // Swap left and right child
    Node* temp = root->l;
    root->l = root->r;
    root->r = temp;

    // Recur for left and right subtrees
    mirror(root->l);
    mirror(root->r);
}

int main() {
    /*
           1
          / \
         2   3
        / \   \
       4   5   6
    */
    Node* root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);
    root->l->l = newNode(4);
    root->l->r = newNode(5);
    root->r->r = newNode(6);

    printf("Inorder before mirror: ");
    inorder(root);
    printf("\n");

    mirror(root);

    printf("Inorder after mirror: ");
    inorder(root);
    printf("\n");

    return 0;
}
