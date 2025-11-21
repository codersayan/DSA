#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* root = NULL;

// ============= STACK for iterative traversal =============
Node* stack[100];
int top = -1;

void push(Node* n) { stack[++top] = n; }
Node* pop() { return stack[top--]; }
int empty() { return top == -1; }

// ============= CREATE NEW NODE =============
Node* create(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// ============= INSERT INTO BST =============
void insert(int data) {
    Node *curr = root, *prev = NULL;

    Node* n = create(data);

    if (root == NULL) {
        root = n;
        return;
    }

    while (curr != NULL) {
        prev = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (data < prev->data)
        prev->left = n;
    else
        prev->right = n;
}

// ============= FIND INORDER SUCCESSOR =============
Node* inorderSuccessor(Node* r) {
    r = r->right;
    while (r && r->left)
        r = r->left;
    return r;
}

// ============= DELETE NODE =============
Node* deleteNode(Node* r, int key) {
    if (r == NULL)
        return r;

    if (key < r->data)
        r->left = deleteNode(r->left, key);

    else if (key > r->data)
        r->right = deleteNode(r->right, key);

    else {
        // Case 1: No child
        if (r->left == NULL && r->right == NULL) {
            free(r);
            return NULL;
        }

        // Case 2: One child
        else if (r->left == NULL) {
            Node* temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == NULL) {
            Node* temp = r->left;
            free(r);
            return temp;
        }

        // Case 3: Two children
        Node* succ = inorderSuccessor(r);
        r->data = succ->data;
        r->right = deleteNode(r->right, succ->data);
    }
    return r;
}

// ============= RECURSIVE TRAVERSALS =============
void inorder(Node* r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(Node* r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(Node* r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

// ============= ITERATIVE INORDER =============
void inorder_iter() {
    Node* curr = root;
    top = -1;

    while (curr || !empty()) {
        while (curr) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// ============= ITERATIVE PREORDER =============
void preorder_iter() {
    Node* curr = root;
    top = -1;

    while (curr || !empty()) {
        while (curr) {
            printf("%d ", curr->data);
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        curr = curr->right;
    }
}

// ============= MAIN =============
int main() {
    int ch, val;

    while (1) {
        printf("\n1. Insert\n2. Inorder (Recursive)\n3. Preorder (Recursive)\n4. Postorder (Recursive)\n");
        printf("5. Inorder (Iterative)\n6. Preorder (Iterative)\n7. Delete Node\n0. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Inorder (Iterative): ");
                inorder_iter();
                printf("\n");
                break;

            case 6:
                printf("Preorder (Iterative): ");
                preorder_iter();
                printf("\n");
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("Deleted.\n");
                break;

            case 0:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

