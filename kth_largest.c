#include<stdio.h>
#define SIZE 100

int selectKth(int*,int,int,int);
int partition(int*,int,int);
void swap(int*, int*);

int main()
{
    int i, n, k, val, arr[SIZE];
    
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    
    printf("Enter the %d elements: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the k-th value: ");
    scanf("%d", &k);

    if(k < 1 || k > n)
    {
        printf("%d-th largest element doesn't exist...\n", k);
        return 0;
    }
    
    val = selectKth(arr, 0, n-1, k-1);  
    
    printf("The %d-th largest element is: %d\n", k, val);
    
    return 0;
}

int selectKth(int *arr, int low, int high, int k)
{
    while(low <= high)
    {
        int pivot = partition(arr, low, high);

        if(k <= pivot)
            high = pivot-1;     
        else
            low = pivot + 1;  
    }

    return arr[k];  
}

int partition(int *a, int low, int high)
{
	int pivotloc,pivotkey,i;
	swap(&a[(low+high)/2],&a[low]);
	pivotloc=low;
	pivotkey=a[low];
	
	for(i=low+1;i<=high;i++) if(a[i]>pivotkey) swap(&a[++pivotloc],&a[i]);
	
	swap(&a[pivotloc],&a[low]);
	
	return pivotloc;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
	

