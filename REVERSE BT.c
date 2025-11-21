#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
typedef struct Node {
    int val;
    struct Node *l, *r;
} Node;

// Create a new node
Node* newNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = v;
    n->l = n->r = NULL;
    return n;
}

// Inorder traversal (for display)
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->l);
    printf("%d ", root->val);
    inorder(root->r);
}

// Function to reverse (mirror) the binary tree
void reverseTree(Node* root) {
    if (root == NULL)
        return;

    // Swap left and right child
    Node* temp = root->l;
    root->l = root->r;
    root->r = temp;

    // Recur for left and right subtrees
    reverseTree(root->l);
    reverseTree(root->r);
}

int main() {
    

    Node* root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);
    root->l->l = newNode(4);
    root->l->r = newNode(5);
    root->r->r = newNode(6);

    printf("Inorder before reversing: ");
    inorder(root);
    printf("\n");

    reverseTree(root);

    printf("Inorder after reversing: ");
    inorder(root);
    printf("\n");

    return 0;
}
