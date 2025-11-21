#include <stdio.h>
#define SIZE 100

//int binarySearch(int*,int,int,int);
int binarySearchRec(int*,int,int,int);

int main()
{
    int arr[SIZE], n, e, i;

    printf("Enter the no. of terms: ");
    scanf("%d", &n);

    printf("Enter the %d numbers in sorted order:\n", n);
    for(i=0; i<n; i++) scanf("%d", &arr[i]);

    printf("Enter the number to be searched: ");
    scanf("%d", &e);

    
    int loc = binarySearchRec(arr, 0, n-1, e);

    if(loc == -1)
        printf("%d is not present in the array...\n", e);
    else
        printf("%d is present at index %d\n", e, loc);

    return 0;
}



//Recursive Binary Search
int binarySearchRec(int *arr, int low, int high, int e)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == e) 
        return mid;
    else if(arr[mid] > e)
        return binarySearchRec(arr, low, mid - 1, e);
    else
        return binarySearchRec(arr, mid + 1, high, e);
}

