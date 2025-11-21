#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node *root = NULL;   

// ----- GLOBAL STACK -----
Node* stack[100];
int top = -1;

void push(Node* n) { stack[++top] = n; }
Node* pop() { return stack[top--]; }
int empty() { return top == -1; }

// ----- CREATE NEW NODE -----
Node* create(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// ----- INSERT INTO BST -----
void insert(int x) {
    Node *curr = root, *prev = NULL;

    Node* n = create(x);

    if (root == NULL) {
        root = n;
        return;
    }

    while (curr != NULL) {
        prev = curr;
        if (x < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (x < prev->data) prev->left = n;
    else prev->right = n;
}

// ----- INORDER TRAVERSAL USING STACK -----
void inorder() {
    Node *curr = root;
    top = -1;

    while (curr != NULL || !empty()) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// ----- HEIGHT OF BST -----
int height(Node* r) {
    if (!r) return 0;
    int lh = height(r->left);
    int rh = height(r->right);
    return (lh > rh ? lh : rh) + 1;
}

// ----- COUNT NODES -----
int countNodes(Node* r) {
    if (!r) return 0;
    return 1 + countNodes(r->left) + countNodes(r->right);
}

// ----- FIND INORDER SUCCESSOR -----
Node* inorderSuccessor(Node* r) {
    r = r->right;
    while (r && r->left)
        r = r->left;
    return r;
}

// ----- DELETE NODE (LEAF / HALF / FULL) -----
Node* deleteNode(Node* r, int key) {
    if (r == NULL) return r;

    if (key < r->data) 
        r->left = deleteNode(r->left, key);

    else if (key > r->data)
        r->right = deleteNode(r->right, key);

    else {
        // Leaf node
        if (!r->left && !r->right) {
            free(r);
            return NULL;
        }

        // Half node (one child)
        if (!r->left) {
            Node* temp = r->right;
            free(r);
            return temp;
        }
        else if (!r->right) {
            Node* temp = r->left;
            free(r);
            return temp;
        }

        // Full node (two children)
        Node* succ = inorderSuccessor(r);
        r->data = succ->data;
        r->right = deleteNode(r->right, succ->data);
    }
    return r;
}

// ----- MAIN -----
int main() {
    int ch, val;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal (Iterative)\n");
        printf("3. Delete Node\n");
        printf("4. Count Nodes\n");
        printf("5. Height of Tree\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert(val);
            break;

        case 2:
            printf("Inorder Traversal: ");
            inorder();
            printf("\n");
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            printf("Deleted.\n");
            break;

        case 4:
            printf("Total nodes = %d\n", countNodes(root));
            break;

        case 5:
            printf("Height of tree = %d\n", height(root));
            break;

        case 0:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
