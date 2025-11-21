#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct tree {
    int key;
    struct tree *left, *right;
} node;

node *root = NULL, *stk[SIZE];
int top = -1;

// Function Prototypes
void create(int);
void inorder();
void del(int);
void delNoChild(node*, node*);
void delOneChild(node*, node*);
void delTwoChildren(node*, node*);
void push(node*);
node* pop();

// ----------------------------------------------------

int main() {
    int n, e, ans;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter node value: ");
        scanf("%d", &e);
        create(e);
    }

    do {
        printf("\nEnter value to delete: ");
        scanf("%d", &e);

        del(e);
        printf("Inorder after deletion: ");
        inorder();

        printf("\nDelete more? (1/0): ");
        scanf("%d", &ans);

    } while(ans);

    return 0;
}

// ----------------------------------------------------
// BST INSERTION
// ----------------------------------------------------
void create(int e) {
    node *p = (node*)malloc(sizeof(node));
    p->key = e;
    p->left = p->right = NULL;

    if(!root) {
        root = p;
        return;
    }

    node *curr = root, *parent = NULL;

    while(curr) {
        parent = curr;
        if(e < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(e < parent->key)
        parent->left = p;
    else
        parent->right = p;
}

// ----------------------------------------------------
// INORDER (ITERATIVE USING STACK)
// ----------------------------------------------------
void inorder() {
    node *current = root;
    top = -1;

    while(current || top != -1) {
        while(current) {
            push(current);
            current = current->left;
        }
        current = pop();
        printf("%d ", current->key);
        current = current->right;
    }
    printf("\n");
}

void push(node *n) {
    stk[++top] = n;
}

node* pop() {
    if(top == -1) return NULL;
    return stk[top--];
}


void del(int e) {
    node *curr = root, *parent = NULL;

    while(curr && curr->key != e) {
        parent = curr;
        if(e < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(!curr) {
        printf("Element not found!\n");
        return;
    }

    // CASE 1: No children (Leaf)
    if(!curr->left && !curr->right)
        delNoChild(curr, parent);

    // CASE 2: One child
    else if(!curr->left || !curr->right)
        delOneChild(curr, parent);

    // CASE 3: Two children
    else
        delTwoChildren(curr, parent);
}


void delNoChild(node *n, node *parent) {
    if(!parent) {     // deleting root
        root = NULL;
        free(n);
        return;
    }

    if(parent->left == n) parent->left = NULL;
    else parent->right = NULL;

    free(n);
}


void delOneChild(node *n, node *parent) {
    node *child = (n->left) ? n->left : n->right;

    if(!parent) {     // deleting root
        root = child;
        free(n);
        return;
    }

    if(parent->left == n) parent->left = child;
    else parent->right = child;

    free(n);
}


void delTwoChildren(node *n, node *parent) {
    node *succParent = n;
    node *succ = n->right;

    
    while(succ->left) {
        succParent = succ;
        succ = succ->left;
    }

    
    n->key = succ->key;

   
    if(!succ->left && !succ->right)
        delNoChild(succ, succParent);
    else
        delOneChild(succ, succParent);
}
