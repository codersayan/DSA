#include <stdio.h>

int main() {
    int r, c;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int A[r][c];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Row-wise sum
    printf("Row-wise sum:\n");
    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += A[i][j];
        }
        printf("Row %d = %d\n", i + 1, rowSum);
    }

    // Column-wise sum
    printf("Column-wise sum:\n");
    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += A[i][j];
        }
        printf("Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
