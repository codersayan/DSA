#include <stdio.h>

int fib(int n) {
    if (n == 0) return 0;      // base case 1
    if (n == 1) return 1;      // base case 2
    return fib(n-1) + fib(n-2);   // recursive case
}

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Sequence:\n");
    
    for (i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }

    return 0;
}
