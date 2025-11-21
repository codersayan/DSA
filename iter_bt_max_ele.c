//Create a Binary Tree Iteratively and Find Maximum Element
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int data) {
    if (!root) return createNode(data);

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];

        if (!temp->left) {
            temp->left = createNode(data);
            break;
        } else
            queue[rear++] = temp->left;

        if (!temp->right) {
            temp->right = createNode(data);
            break;
        } else
            queue[rear++] = temp->right;
    }

    return root;
}


int findMax(Node* root) {
    if (!root) return -1; // or INT_MIN
    int max = root->data;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];
        if (temp->data > max) max = temp->data;
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    return max;
}

int main() {
    Node* root = NULL;
    int n,i, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Maximum element in tree: %d\n", findMax(root));
    return 0;
}

