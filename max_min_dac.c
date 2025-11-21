#include <stdio.h>

void maxMin(int arr[], int low, int high, int *max, int *min) {

    // If only one element
    if (low == high) {
        *max = *min = arr[low];
        return;
    }

    // If two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int max1, min1, max2, min2;

    // Divide
    maxMin(arr, low, mid, &max1, &min1);
    maxMin(arr, mid + 1, high, &max2, &min2);

    // Conquer (combine results)
    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}

int main() {
    int n, arr[50], max, min;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    maxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}
