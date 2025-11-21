#include <stdio.h>


void insertionSort(int arr[], int n) {
    
    if (n <= 1)
        return;

    // Sort first n-1 elements recursively
    insertionSort(arr, n - 1);

    // Insert last element into sorted part
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements to the right until correct position is found
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
