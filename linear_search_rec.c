#include <stdio.h>

int linearSearch(int arr[], int n, int key, int index) {
    if (index == n)        
        return -1;

    if (arr[index] == key) 
        return index;

    return linearSearch(arr, n, key, index + 1); 
}

int main() {
    int n, arr[50], key, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int pos = linearSearch(arr, n, key, 0);

    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", pos);

    return 0;
}
