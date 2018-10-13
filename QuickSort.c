#include <stdio.h>
#include <conio.h>
#include <math.h>
int partition(int* A,int l,int r);
void quicksort(int* A,int l,int r);

void quicksort(int* A,int l, int r)
{
	int p;
	if(r>l)
	{
		p=partition(A,l,r);
		quicksort(A,l,p-1);
		quicksort(A,p+1,r);
	}
}

int partition(int *A,int l,int r)
{
	int i=l-1,j=l,temp;
	//Assuming pivot is the rightmost element
	while(j<r)
	{
		if(A[j]<A[r])
		{
			//swap A[i+1] with A[j]
			temp=A[i+1];
			A[i+1]=A[j];
			A[j]=temp;
			i++;
		}
		j++;
	}
	temp=A[r];
	A[r]=A[i+1];
	A[i+1]=temp;
	return (i+1);
}

int main()
{
	//int A[]={1,16,5,3,4,7,9};
	int *A, i=0,n;
	printf("Input the number of elements:  ");
	scanf("%d\n",&n);
	while(i<n)
	{
		scanf("%d",&A[i]);
		i++;
	}
	printf("Original Array:  ");
	i=0;
	while(i<n)
	{
		printf("%d ",A[i]);
		i++;
	}
	quicksort(A,0,n-1);
	printf("Sorted Array:  ");
	i=0;
	while(i<n)
	{
		printf("%d ",A[i]);
		i++;
	}
}