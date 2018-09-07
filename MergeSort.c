#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* Merge(int *left,int *right,int llength,int rlength,int mid)
{
	int *B=malloc((llength+rlength)*sizeof(int));
	int i=0,j=0,k=0;
	//printf("r-l=%d\n",(r-l));
	while(i<llength &&j<rlength)
	{
		//printf("i=%d j=%d mid=%d r=%d\n",i,j,mid,r);
		//printf("left[%d]=%d and right[%d]=%d \n",i,left[i],j,right[j]);
		if(left[i]<=right[j])
		{
			B[k]=left[i];
			k++;i++;
		}
		else
		{
			B[k]=right[j];
			k++;j++;
		}
	}
	while(i<llength)
	{
		B[k]=left[i];
		k++;i++;
	}
	while(j<rlength)
	{
		B[k]=right[j];
		k++;j++;
	}
	//printf("k=%d\n",k);	printf("i=%d\n",i);	printf("j=%d\n",j);
	//printf("After Merge Step for left=%d and right=%d\n",l,r);	
	i=0;
	//k=r-l+1;
	while(i<k)
	{
		printf("%d ",B[i]);
		i++;
	}
	printf("\n");
	return B;
}
int* MergeSort(int *A,int l,int r)
{
	int mid,length=(r-l+1);
	int *left; int *right;
	int *p=malloc(sizeof(int));
	int llength=(int)ceil(length/2.0);
	int rlength=length-llength;
	//printf("llength=%d rlength=%d\n",llength,rlength);
	if(l==r)
	{
		*p=A[l];
		return p;
	}
	else
	{
		mid=(l+r)/2;
		left=MergeSort(A,l,mid);
		right=MergeSort(A,mid+1,r);
		return Merge(left,right,llength,rlength,mid);
	}
}


int main()
{
	//int A[]={1,3,11,2,17,5};
	//int A[]={1,11,3,2,4,5};
	int n;
	int *B;
	int i=0; int x;
	printf("Input the length of the array: ");	scanf("%d",&n);
	B=malloc(n*sizeof(int));
	printf("Input the elements of the array: \n");
	for(i=0;i<n;i++)
	{
		//scanf("%d",B[i]);
		//printf("\n");
		scanf("%d",&x);
		B[i]=x;
	}
	printf("***********Beginning Sorting Part**************\n");
	B=MergeSort(B,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",B[i]);
	}
}