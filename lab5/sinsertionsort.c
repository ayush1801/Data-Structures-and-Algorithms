#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
 //recursion
void InsertInOrder(int arr[],int ind,int ele)
{
	int curind=ind+1;
	for(int i=ind;i>=0;i--)
	{
		if(arr[i]>ele)
		{
			int temp=arr[i];  //repeated swapping
			arr[i]=ele;
			arr[curind]=temp;
			curind=i;
		}
	}
	return ;
}

void InsertionSort(int arr[],int tind)
{
	if(tind==0) return;
	InsertionSort(arr,tind-1);
	InsertInOrder(arr,tind-1,arr[tind]);
	return;
}

int main(int argv,char * argc[])
{
	srand(time(0));
	int n=atoi(argc[1]);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%50;
		printf("%d\n",arr[i]);
	}
	InsertionSort(arr,n-1);
	printf("\n sorting.. \n");
	
	for(int i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	
}
	
	
