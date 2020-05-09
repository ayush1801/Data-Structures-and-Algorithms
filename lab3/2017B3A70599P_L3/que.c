#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "que.h"
Queue newQ()
{
	Queue q;
	q.head=NULL;
	q.tail=NULL;
	return q;
}

bool isEmptyQ(Queue q)
{
	if(q.head==NULL && q.tail==NULL)
	{
		return true;
	}
	return false;
}

Queue delQ(Queue q)
{
	if(isEmptyQ(q))
	{
		printf("Darling Queue is Empty\n");
		exit(0);
	}
	if(q.head==q.tail)
	{
		q.head=NULL;
		q.tail=NULL;
		return q;
	}
	q.head=q.head->next;
	return q;
}

Task front(Queue q)
{
	if(isEmptyQ(q))
	{
		printf("Darling Queue is Empty\n");
		exit(0);
	}
	return q.head->elem;
}
Queue addQ(Queue q, Task e)
{
	struct Node *  Nadd=(struct Node *)malloc(sizeof(struct Node));
	Nadd->elem=e;
	Nadd->next=NULL;
	if(isEmptyQ(q))
	{
		q.head=Nadd;
		q.tail=Nadd;
		return q;
	}
	q.tail->next=Nadd;
	q.tail=Nadd;
	return q;
}
int lengthQ(Queue q)
{
	int count=0;
	struct Node *temp=q.head;
	if(isEmptyQ(q)) return 0;
	while(temp!=q.tail)
	{
		count++;
		temp=temp->next;
	}
	count=count+1;	
	return count;
}
