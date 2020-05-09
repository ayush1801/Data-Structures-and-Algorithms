#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void  merge(int *arr1,int *arr2,int sz1,int sz2,int * arr)
{
	int k=0,j=0,i=0;
	while(i<sz1 && j<sz2)
	{
		if(arr1[i]<=arr2[j]) arr[k++]=arr1[i++];
		else arr[k++]=arr2[j++];
		
	}
	while(i<sz1) arr[k++]=arr1[i++];
	while(j<sz2) arr[k++]=arr2[j++];
}

void mergesortrec(int * arr,int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		mergesortrec(arr,left,mid);
		mergesortrec(arr,mid+1,right);
		int narr[right-left+1];
		merge(arr+left,arr+mid+1,mid-left+1,right-mid,narr);
		for(int i=0;i<(right-left+1);i++) arr[left+i]=narr[i];
	}
}

void mergesortint(int * arr,int sz)
{
	int curr;
	int left;
	for(curr=1;curr<sz;curr=2*curr)
	{
		for(left=0;left<sz-1;left+=2*curr)
		{
			int mid=0;int right=0;
			if((left+curr-1)<(sz-1)) 
			{
				mid=left+curr-1;
			}
			else 
			{
				mid=sz-1;
			}
			if((left+2*curr-1)<(sz-1)) 
			{
				right=left+2*curr-1;
			}
			else 
			{
				right=sz-1;
			}
			int narr[right-left+1];
			merge(arr+left,arr+mid+1,mid-left+1,right-mid,narr);
			for(int i=0;i<(right-left+1);i++) arr[left+i]=narr[i];
		}
	}
}
		
		
	
int main()
{
	int arr[]={0,2,4,5,34,2,98,8};
	mergesortint(arr,8);
	for(int i=0;i<8;i++) printf("%d\n",arr[i]);
}
		
