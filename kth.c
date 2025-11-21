#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE], n;

// Swap function
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// Quick Sort
int partition(int a[], int low, int high) {
	int j;
    int pivot = a[high], i = low - 1;
    for(j = low; j < high; j++) {
        if(a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

// Display array
void display() {
	int i;
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Kth largest element
int kthLargest(int k) {
    if(k<=0 || k>n) return -1;
    return arr[n-k]; // after sorting ascending
}

// Median element
float median() {
    if(n%2!=0)
        return arr[n/2];
    else
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
}

// Main program
int main() {
    int choice,i, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quickSort(arr,0,n-1); // sort once

    while(1) {
        printf("\n1. Display Array\n2. Kth Largest\n3. Median\n0. Exit\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: 
                display(); 
                break;
            case 2:
                printf("Enter k: ");
                scanf("%d",&k);
                if(kthLargest(k)!=-1)
                    printf("%dth largest = %d\n",k,kthLargest(k));
                else
                    printf("Invalid k!\n");
                break;
            case 3:
                printf("Median = %.2f\n",median());
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

