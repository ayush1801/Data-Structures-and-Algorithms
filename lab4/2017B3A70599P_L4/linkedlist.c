#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
#include "mem2.h"
void insertfirst(Ls head,int ele){
	Node * link=(Node *)myalloc(sizeof(Node));
	link->element=ele;
	link->next=head->first;
	head->first=link;
	head->count++;
}

Node * deletefirst(Ls head){
	if(head->first==NULL)
	return NULL;
	Node * temp=head->first;
	head->first=head->first->next;
	head->count--;
	return temp; 
}

void printlist(Ls head)
{
	Node * currlink=head->first;
	while(currlink!=NULL)
	{
		printf("%d\n ",currlink->element);
		currlink=currlink->next;
	}
	printf("\n\n");
}
int search(Ls head,int ele)
{
	Node * temp=head->first;
	while(temp!=NULL){
		if(temp->element==ele)
		{
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}
Node * retNodebe(Ls head,int ele)
{
	if(search(head,ele)==0) return NULL;
	Node * temp=head->first;
	while(temp!=NULL)
	{
		if(temp->element==ele)
		{
			return temp;
		}
		temp=temp->next;
	}
}
Node * retNodebc(Ls head,int c)
{
	if((head->count==0)||(c>head->count)) return NULL;
	Node * temp=head->first;
	if(c==1) return temp;
	for(int i=2;i<=c;i++)
	{
		temp=temp->next;
	}
	return temp;
}
Node * deletes(Ls head,int ele)
{
	if(search(head,ele)==0) return NULL;
	head->count--;
	Node * temp=head->first;
	if(temp->element==ele)
	{
		head->first=head->first->next;
		return temp;
	}
		
	while(temp->next!=NULL)
	{
		if(temp->next->element==ele)
		{
			Node * temp2= temp;
			temp->next=temp->next->next;
			return temp2->next;
			
			
		}
	
		temp=temp->next;
	}
}
	
void insertafter(Ls  head,int ele)
{
	Node * ptr=(struct node *)myalloc(sizeof(Node));
	head->count++;
	ptr->element=ele;
	ptr->next=NULL;
	if(head->first==NULL)
	{
		head->first=ptr;
		return;
	}
	Node * temp=head->first;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ptr;
	return;
}
		
