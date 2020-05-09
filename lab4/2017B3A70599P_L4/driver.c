#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
#include "cycle.h"
#include "mem2.h"
#include<time.h>
#include<sys/time.h>
Ls  createList(int n)
{	
	srand(time(0));
	Ls  head=(Ls)myalloc(sizeof(struct linkedlist));
	for(int i=0;i<n;i++)
	{
		int ele=rand()%50;   //random numbers would be between 0 and 50
		insertfirst(head,ele);
	}
	return head;
}

Ls  createCycle(Ls head)
{
	srand(time(0));
	int num=rand();
	int res=num%2; 
	if(res==0) 
		{
			printf(" \nITS HEADS !!! LINEAR SHOULD BE FINE\n");
			return head;
		}
	else
	{	
		printf("ITS TAILS !!! CYCLIC IS MADE\n");
		int c=(rand()%(head->count))+1;
		Node * tnode=retNodebc(head,c);
		Node * temp=head->first;
		if(tnode!=NULL)
		{	
			while(temp->next!=NULL) temp=temp->next;
			temp->next=tnode;
		}
		else printf(" LIST MUST BE EMPTY \n");
	
	return head;
}	
}

int main(int argc,char * argv[])
{
	struct timeval t1,t2;
	double elapsedTime;
	//start timer
	gettimeofday(&t1,NULL);

	heap=0;
	FILE * ptr=fopen(argv[1],"w");
	if(atoi(argv[2])==0) return 0;
	Ls head=createList(atoi(argv[2]));
	Node * temp=head->first;
	while(temp->next!=NULL)
	{
		fprintf(ptr," %d \n",temp->element);
		temp=temp->next;
	}
	fprintf(ptr," %d ",temp->element);
	fclose(ptr);
	head=createCycle(head);
	if(testCyclic(head)) printf("TESTING... it is a cycle \n");
	else printf("TESTING... it is a linear \n");
	printf("\n Total heap usage is %d \n",heap);

	//stop timer
	gettimeofday(&t2,NULL);

	//computing time in millisec
	elapsedTime=(t2.tv_sec -t1.tv_sec)*1000.0;
	elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
	printf(" Total time used is %lf ms. \n",elapsedTime);

}
	
		
