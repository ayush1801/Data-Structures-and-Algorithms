#include "merge.h"
#include<sys/time.h>
void mergesortrec(Element Ls[],int left,int right);
void mergesortint(Element Ls[],int sz);

int main()
{
int loop=0;
while(loop<2)
{
FILE * fptr;
Element * ptr;
int sz=0,right=0;
if(loop==0)
{	
	fptr=fopen("1024.txt","r");
	sz=1024;
	right=1023;
	ptr=(Element *)malloc(1024*sizeof(Element));
}
else 
{
	fptr=fopen("10240.txt","r");
	sz=10240;
	right=10239;
        ptr=(Element *)malloc(10240*sizeof(Element));
}
	int i=0;

        while(fscanf(fptr,"%[^,],%f\n",ptr[i].name,&ptr[i].cg)!=EOF)
        {
                i++;
        }
        fclose(fptr);

struct timeval t1, t2;
	double elapsedTime;
	int left=0;
	rbottom=&left;
	gettimeofday(&t1, NULL);
	mergesortrec(ptr,left,right);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Recursive mergeSorted %d elements in %lf milliseconds.\n",sz,elapsedTime);
	printf("Space used by Recursive MergeSort: %p %p %p\n",(int *)rtop,(int *)rbottom,(int*)(rbottom-rtop));

	gettimeofday(&t1, NULL);
	ibottom=&sz;
	mergesortint(ptr,sz);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Iterative mergeSorted %d elements in %lf milliseconds.\n",sz,elapsedTime);
printf("Space used by Iterative MergeSort: %p %p %p\n",(int *)itop,(int *)ibottom,(int *)(ibottom-itop));
loop++;
}

}
