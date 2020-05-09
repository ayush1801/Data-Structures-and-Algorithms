#include<stdio.h>
#include<stdlib.h>

void  merge(int *arr1,int *arr2,int sz1,int sz2,int * arr)
{
	printf(" h ");
	int k=0,j=0,i=0;
	for(int l=0;l<sz1+sz2;l++)
	{
		if(i==sz1) 
		{
			arr[k++]=arr2[j++];
			continue;
		}
		if(j==sz2)
		{
			arr[k++]=arr1[i++];
			continue;
		}
		if(arr1[i]<=arr2[j]) 
		{
			arr[k++]=arr1[i++];
		}
		else 
		{
			arr[k++]=arr2[j++];
		}
		printf("i");
		
		
	}
}

int main()
{
	int arr1[]={0,2,4,5};
	int arr2[]={1,3,4,6,7};
	int arr[9];
	printf(" k ");
	merge(arr1,arr2,4,5,arr);
	for(int i=0;i<9;i++) printf("%d\n",arr[i]);
}
		
