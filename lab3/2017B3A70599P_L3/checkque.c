#include<stdio.h>
#include<stdlib.h>
#include "que.h"
int main(int argc,char *argv[])
{
	FILE * fptr=fopen(argv[1],"r");
	Queue q=newQ();
	int i=1;
	while(true)
	{
		int temp;
		if(fscanf(fptr,"%d",&temp)==EOF) break;
		Task elem;
		elem.tid=temp;
		elem.p=0;
		q=addQ(q,elem);
		printf("%d\n",i++);
	}
	fclose(fptr);
int num=lengthQ(q);
printf("length of the Queue is = %d\n",num);
q=delQ(q);
q=delQ(q);
for(int i=0;i<15;i++)
{
	q=delQ(q);
	printf("\n size of queue%d ",lengthQ(q));
	Task elem=front(q);
	printf("\n %d \n",elem.tid);

}
delQ(q);
printf(" length of the Queue is = %d\n",lengthQ(q));
}
