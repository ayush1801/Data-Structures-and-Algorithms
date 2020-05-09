#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "linkedlist.h"
bool testCyclic(Ls head)
{
	Node * hare=head->first;
	Node * tort=head->first;
	if(head->first==NULL) return false;
	while(hare->next!=NULL && hare->next->next!=NULL)
	{
		hare=hare->next->next;
		tort=tort->next;
		if(hare==tort) return true;
	}
	return false;
}
	
