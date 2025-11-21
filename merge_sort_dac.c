#include<stdio.h>
#define SIZE 100

void mergeSort(int*,int,int);
void merge(int*,int,int,int);

int main()
{
	int arr[SIZE],n,i;
	
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter arr[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	
	mergeSort(arr,0,n-1);
	
	printf("Sorte array...\n");
	
	for(i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}

void mergeSort(int *arr,int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

void merge(int *arr,int low,int mid,int high)
{
	int b[SIZE],i=low,j=mid+1,k=low;
	
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			b[k]=arr[i];
			i++;
		}
		else
		{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	
	if(i>mid) 
	{
		while(j<=high)
		{                                     
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	else 
	{
		while(i<=high)
		{
			b[k]=arr[i];
			i++;
			k++;
		}
	}
	
	for(i=low;i<=high;i++) arr[i]=b[i];
}
	
	
	
	
	