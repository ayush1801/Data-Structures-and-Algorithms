#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int Partition(int * arr,int st,int en)
{
	int x=arr[en];
	int i=st-1;
	for(int j=st;j<=en-1;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	int temp=arr[i+1];
	arr[i+1]=arr[en];
	arr[en]=temp;
	return (i+1);
}


void quickSortI(int * arr,int st,int en,int S)
{
	//declaration of stack
	int stack[en-st+1];
	
	//init top of stack
	int top=-1;

	//push st and en
	stack[++top]=st;
	stack[++top]=en;
	while(top>=0)
	{
		//pop st and en
		en=stack[top--];
		st=stack[top--];
		if((en-st+1)>S)
		{
			//returning the pivot index
			int p=Partition(arr,st,en);
			//if elements present between the start and pivot first 
			// and if elements present between the pivot and last push them
			if(p-1>st && (p-st)>S)
			{
				stack[++top]=st;
				stack[++top]=p-1;
			}
			if(p+1<en && (en-p)>S)
			{
				stack[++top]=p+1;
				stack[++top]=en;
			}
		}

	}
}

void IS(int *arr,int st,int en)
{
	for(int i=st+1;i<=en;i++)
	{
		int j=i-1;
		int key=arr[i];
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
		
int main()
{
	int arr[]={12,34,65,1,3,87,9,10,21};

	int arr2[]={1,22,93,4,0,0,23,32,31};
	IS(arr2,0,8);
//	printf("%d mid index \n",i);
	for(int i=0;i<9;i++)
	{
		printf(" %d ,",arr2[i]);
	}
	printf("\n");
}
