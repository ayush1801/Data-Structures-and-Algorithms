#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
void insertfirst(struct linkedlist * head,int ele){
	struct node * link=(struct node *)malloc(sizeof(struct node));
	link->element=ele;
	link->next=head->first;
	head->first=link;
	head->count++;
}

struct node * deletefirst(struct linkedlist * head){
	if(head->first==NULL)
	return NULL;
	struct node * temp=head->first;
	head->first=head->first->next;
	head->count--;
	return temp; 
}

void printlist(struct linkedlist* head)
{
	struct node* currlink=head->first;
	printf("\n[");
	while(currlink!=NULL)
	{
		printf("%d, ",currlink->element);
		currlink=currlink->next;
	}
	printf(" ]");
}
int search(struct linkedlist * head,int ele)
{
	struct node * temp=head->first;
	while(temp!=NULL){
		if(temp->element==ele)
		{
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}
struct node * deletes(struct linkedlist * head,int ele)
{
	if(search(head,ele)==0) return NULL;
	head->count--;
	struct node * temp=head->first;
	if(temp->element==ele)
	{
		head->first=head->first->next;
		return temp;
	}
		
	while(temp->next!=NULL)
	{
		if(temp->next->element==ele)
		{
			struct node * temp2= temp;
			temp->next=temp->next->next;
			return temp2->next;
			
			
		}
	
		temp=temp->next;
	}
}
	
	
