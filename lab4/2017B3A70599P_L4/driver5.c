#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
#include "cycle.h"
#include "mem2.h"
#include<time.h>
#include<sys/time.h>
Ls  createList(int n)
{	srand(time(0));
	if(n==0) return NULL;
	Ls  head=(Ls)myalloc(sizeof(struct linkedlist));
	for(int i=0;i<n;i++)
	{
		int ele=rand();   //random numbers would be between 0 and 50
		insertfirst(head,ele);
	}
	return head;
}

Ls  createCycle(Ls head)
{	srand(time(0));
	int num=rand();
	int res=num%2;
	if(res==0)
	{
		printf("\n Its HEADS!!! SO LINEAR WOULD BE FINE\n");
		return head;
	}
	else
	{	
		printf(" Its TAILS!!! SO CYCLIC LIST IS MADE\n");
		int c=(rand()%(head->count)+1);
		Node * tnode=retNodebc(head,c);
		if(tnode!=NULL)
		{
			Node * temp=head->first;
			while(temp->next!=NULL) temp=temp->next;
			temp->next=tnode;
		}
		else printf(" LIST MUST BE EMPTY\n");
		return head;
	}		
}

Ls makeCircularList(Ls head)
{	
	if(!testCyclic(head))    //assuming that hare and tortoise algo is used otherwise structure of linkedlist wouold be disturbed
	{
		Node * temp=head->first;
		while(temp->next!=NULL) temp=temp->next;
		temp->next=head->first;
		return head;
	}
	else
	{
		Node * hare=head->first;
		Node * tort=head->first;
		while(true)
		{
			hare=hare->next->next;
			tort=tort->next;
			if(hare==tort) break;
		}
		Node * temp=head->first;
		while(true)
		{
			if(temp==hare) return head;
			hare=hare->next;
			Node * temp2=temp;
			temp=temp->next;
			head->first=temp;
			myfree((Node *)temp2);
			head->count--;
			printf(" total heap space used %d \n",heap);
		}


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
	Ls head=createList(atoi(argv[2]));
	if(head==NULL) return 0;
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
	printf(" Total time used is %lf \n",elapsedTime);

	//Making circular list
	head=makeCircularList(head);
//	printlist(head);
	printf(" headcount is %d\n",head->count);
}
	
		
