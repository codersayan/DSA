#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Tree {
    struct Tree *left, *right;
    char key;
    float weight;
} node;

node *root = NULL;
node *arr[SIZE];
int n;

// Function to create the input characters and probabilities
void create() {
    int i;
    char c;
    float f;
    for (i = 0; i < n; i++) {
        arr[i] = (node *)malloc(sizeof(node));
        printf("Enter the character: ");
        scanf(" %c", &c);
        printf("Enter the probability: ");
        scanf("%f", &f);

        arr[i]->key = c;
        arr[i]->weight = f;
        arr[i]->left = arr[i]->right = NULL;
    }
}

// Function to find the two nodes with smallest weight
void findTwoSmallest(int count, int *x, int *y) {
    int i;
    int min1 = -1, min2 = -1;
    for (i = 0; i < count; i++) {
        if (arr[i] == NULL) continue;
        if (min1 == -1 || arr[i]->weight < arr[min1]->weight) {
            min2 = min1;
            min1 = i;
        } else if (min2 == -1 || arr[i]->weight < arr[min2]->weight) {
            min2 = i;
        }
    }
    *x = min1;
    *y = min2;
}

// Function to create Huffman tree
void huffman() {
    int count = n;
    while (count > 1) {
        int x, y;
        findTwoSmallest(n, &x, &y);

        node *newNode = (node *)malloc(sizeof(node));
        newNode->weight = arr[x]->weight + arr[y]->weight;
        newNode->key = '\0';
        newNode->left = arr[x];
        newNode->right = arr[y];

        arr[x] = newNode;
        arr[y] = NULL;

        root = newNode; // update root
        count--;
    }
}

// Recursive function to display Huffman codes
void display(node *root, int code[], int depth) {
    if (!root) return;

    if (!root->left && !root->right) {
        int i;
        printf("%c: ", root->key);
        for (i = 0; i < depth; i++)
            printf("%d", code[i]);
        printf("\n");
    }

    code[depth] = 0;
    display(root->left, code, depth + 1);

    code[depth] = 1;
    display(root->right, code, depth + 1);
}

int main() {
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    create();
    huffman();

    int code[20];
    printf("\nHuffman Codes:\n");
    display(root, code, 0);

    return 0;
}

