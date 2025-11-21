#include <stdio.h>

#define MAX 100

// --------------------- RECURSIVE BINARY SEARCH ---------------------
int binarySearch(int arr[], int left, int right, int key) {
    if (left > right)
        return -1;   // Not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;

    else if (key < arr[mid])
        return binarySearch(arr, left, mid - 1, key);

    else
        return binarySearch(arr, mid + 1, right, key);
}

// ----------------------- INSERT (Sorted Array) -----------------------
int insert(int arr[], int n, int key) {
    if (n == MAX) {
        printf("\nArray Full! Cannot insert.\n");
        return n;
    }

    int i = n - 1;
    while (i >= 0 && arr[i] > key) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;

    return n + 1;
}

// ----------------------- DELETE ELEMENT -----------------------
int delete(int arr[], int n, int key) {
    int pos = binarySearch(arr, 0, n - 1, key);
    if (pos == -1) {
        printf("\nElement not found! Cannot delete.\n");
        return n;
    }
    int i;

    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

// ---------------------------- MAIN ----------------------------
int main() {

    int arr[MAX], n, choice, key,i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (sorted): ");
    for ( i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\n\n---- MENU ----\n");
        printf("1. Search (Recursive Binary Search)\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                int pos;
                pos = binarySearch(arr, 0, n - 1, key);
                if (pos == -1)
                    printf("Element not found!\n");
                else
                    printf("Element found at index %d\n", pos);
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                n = insert(arr, n, key);
                printf("Inserted successfully!\n");
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                n = delete(arr, n, key);
                break;

            case 4:
                printf("Array: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

