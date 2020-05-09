#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "linkedlist.h"
//LINK REVERSAL ALGORITHM USAGE

bool testCyclic(Ls head)
{
	if(head->first==NULL) return false; //Empty linkedlist
	if(head->first->next==NULL) return false; //Singlely linkedlist
	Node * StartNode=head->first;
	Node * PrevNode=NULL;
	Node * NextNode=NULL;
	Node * CurNode=head->first;
	
	while(CurNode)
	{
		NextNode=CurNode->next;
		CurNode->next=PrevNode;
		PrevNode=CurNode;
		CurNode=NextNode;
	}
	return (PrevNode==StartNode);
}
	
