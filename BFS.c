#include <stdio.h>

#define MAX 10

void BFS(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0}, queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 5;
    int adj[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,1,0},
        {0,1,1,0,1},
        {0,1,0,1,0}
    };

    BFS(adj, n, 0); // Start BFS from node 0
    return 0;
}
