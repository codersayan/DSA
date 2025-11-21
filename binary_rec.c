#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)     
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)   // key found
        return mid;

    else if (key < arr[mid])   // search in left half
        return binarySearch(arr, low, mid - 1, key);

    else                        // search in right half
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, arr[50], key, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int pos = binarySearch(arr, 0, n - 1, key);

    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", pos);

    return 0;
}
