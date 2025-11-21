#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];    
    int i = low - 1;          

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {   // elements smaller than pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // place pivot to its correct sorted position
    swap(&arr[i + 1], &arr[high]);

    return i + 1;   // return pivot index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {   
        int pi = partition(arr, low, high);   // pivot index

        quickSort(arr, low, pi - 1);   // sort left part
        quickSort(arr, pi + 1, high);  // sort right part
    }
}

int main() {
    int n, arr[50];

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
