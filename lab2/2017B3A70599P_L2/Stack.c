#include<stdlib.h>
#include "Stack.h"
void Push(struct linkedlist * head,int ele)
{
	insertfirst(head,ele);
}
int Pop(struct linkedlist * head)
{
	if(head->count==0) exit(0);
	struct node * node_ele=deletefirst(head);
	return node_ele->element;
}
