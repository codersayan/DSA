#include <stdio.h>

#define MAX 10

void DFS(int adj[MAX][MAX], int n, int start, int visited[MAX]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0)
            DFS(adj, n, i, visited);
    }
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

    int visited[MAX] = {0};

    printf("DFS Traversal: ");
    DFS(adj, n, 0, visited); // Start DFS from node 0
    printf("\n");

    return 0;
}
