#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE]; // global array
int n;

// Function prototypes
void quickSort(int l, int h);
int partition(int l, int h);
void mergeSort(int l, int h);
void merge(int l, int m, int h);
void bubbleSortRecursive(int end);

void printArray() {
	int i;
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice,i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nChoose Sorting Method:\n");
    printf("1. Quick Sort\n2. Merge Sort\n3. Bubble Sort (Recursive)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            quickSort(0, n-1);
            printf("Array after Quick Sort: ");
            printArray();
            break;
        case 2:
            mergeSort(0, n-1);
            printf("Array after Merge Sort: ");
            printArray();
            break;
        case 3:
            bubbleSortRecursive(n-1);
            printf("Array after Recursive Bubble Sort: ");
            printArray();
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// ================= Quick Sort =================
void quickSort(int l, int h) {
    if(l < h) {
        int pi = partition(l, h);
        quickSort(l, pi-1);
        quickSort(pi+1, h);
    }
}

int partition(int l, int h) {
	int j;
    int pivot = arr[h];
    int i = l-1;
    for(j=l; j<=h-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i+1]; arr[i+1] = arr[h]; arr[h] = temp;
    return i+1;
}

// ================= Merge Sort =================
void mergeSort(int l, int h) {
    if(l < h) {
        int m = (l+h)/2;
        mergeSort(l, m);
        mergeSort(m+1, h);
        merge(l, m, h);
    }
}

void merge(int l, int m, int h) {
    int i=l, j=m+1, k=0;
    int temp[SIZE];

    while(i <= m && j <= h) {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while(i <= m) temp[k++] = arr[i++];
    while(j <= h) temp[k++] = arr[j++];

    for(i=l, k=0; i<=h; i++, k++) arr[i] = temp[k];
}

// ================ Recursive Bubble Sort ================
void bubbleSortRecursive(int end) {
	int i;
    if(end == 0) return;
    for(i=0; i<end; i++) {
        if(arr[i] > arr[i+1]) {
            int temp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = temp;
        }
    }
    bubbleSortRecursive(end-1);
}

