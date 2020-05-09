#include "complete.h"
#include<sys/time.h>
int Partition(Ls * ls,int st,int en)
{
	int x=(ls[en].empid);
	int i=st-1;
	for(int j=st;j<=en-1;j++)
	{
		if((ls[j].empid)<=x)
		{
			i++;
			Ls temp=ls[i];
			ls[i]=ls[j];
			ls[j]=temp;
		}
	}
	Ls temp=ls[i+1];
	ls[i+1]=ls[en];
	ls[en]=temp;
	return (i+1);
}


void IQuickSort(Ls * ls,int st,int en,int S)
{
	//declaration of stack
	int * stack=(int *)malloc((en-st+1)*sizeof(int));

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
			int p=Partition(ls,st,en);
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

void InsertionSort(Ls *ls,int st,int en)
{
	for(int i=st+1;i<=en;i++)
	{
		int j=i-1;
		Ls key=ls[i];
		while(j>=0 && (ls[j].empid)>(key.empid))
		{
			ls[j+1]=ls[j];
			j--;
		}
		ls[j+1]=key;
	}
}

double  MixedSort(Ls * ls,int st,int en,int S)
{
	struct timeval t1,t2;
        double elapsedTime=0;
        gettimeofday(&t1,NULL);
        IQuickSort(ls,st,en,S);
        InsertionSort(ls,st,en);
        gettimeofday(&t2,NULL);
        elapsedTime=(t2.tv_sec -t1.tv_sec)*1000.0;
        elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
        return elapsedTime;
}

Time testRun(Ls *ls,int size)
{               Ls * ls1=(Ls *)malloc(size * sizeof(Ls));
		Ls * ls2=(Ls *)malloc(size * sizeof(Ls));
		for(int i=0;i<size;i++)
		{
			ls2[i]=ls[i];
			ls1[i]=ls[i];
		}
		Time T;
		struct timeval t1,t2;
		double elapsedTime=0;
		gettimeofday(&t1,NULL);
		InsertionSort(ls1,0,size-1);
		gettimeofday(&t2,NULL);
		elapsedTime=(t2.tv_sec -t1.tv_sec)*1000.0;
		elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
		T.IS=elapsedTime;
		
		elapsedTime=0;
		gettimeofday(&t1,NULL);
		IQuickSort(ls2,0,size-1,-1);
		gettimeofday(&t2,NULL);
		elapsedTime=(t2.tv_sec -t1.tv_sec)*1000.0;
		elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
		T.QS=elapsedTime;
	//	printf("IS: %lf  QS :%lf\n",T.IS,T.QS);
		return T;
}

int estimateCutoff(Ls*ls,int size)
{
		Time T;
		int min=1;
		int max=size;
		T=testRun(ls,size);
		if(T.QS>=T.IS)
		{
			 return size;
		}
		while(T.IS != T.QS)
		{
			int mid=(min+max)/2;
			T=testRun(ls,mid);
			if(T.QS <= (T.IS+0.0001) && T.QS >= (T.IS-0.0001))
			{
					return mid;
			}
			if(T.IS>T.QS)
			{
				min=0;
				max=mid;
				continue;
			}
			T=testRun(ls,max);
			if(T.QS <= (T.IS+0.0001) && T.QS >= (T.IS-0.0001))
			{
					return max;
			}
			if(T.IS>T.QS)
			{
				min=mid;
				max=max;
			}
		}
}

int bisection(Ls * ls,int size)
{
	return estimateCutoff(ls,size);
}

/*int main()
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
}*/
