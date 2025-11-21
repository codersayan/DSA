#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Create new node
Node* createNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Queue for level-order insertion
Node* queue[100];
int front = 0, rear = 0;

void enqueue(Node* n) { queue[rear++] = n; }
Node* dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

// Height of tree
int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    Node *root = NULL;

    printf("Enter values (negative to stop):\n");

    while (1) {
        int x;
        scanf("%d", &x);

        if (x < 0) break;

        Node* newNodePtr = createNode(x);

        if (root == NULL) {
            root = newNodePtr;
            enqueue(root);
        }
        else {
            // Find first node with empty child (BFS)
            while (1) {
                Node* temp = queue[front];

                if (temp->left == NULL) {
                    temp->left = newNodePtr;
                    enqueue(newNodePtr);
                    break;
                }
                else if (temp->right == NULL) {
                    temp->right = newNodePtr;
                    enqueue(newNodePtr);
                    break;
                }
                else {
                    dequeue();  // this node has both children → move ahead
                }
            }
        }
    }

    printf("\nHeight of the tree = %d\n", height(root));
    return 0;
}
