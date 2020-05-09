#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"
int main(int argc,char *argv[])
{
        FILE * fptr=fopen(argv[1],"r");
        struct linkedlist * head =(struct linkedlist *)malloc(sizeof(struct linkedlist));
while(!feof(fptr))
{
        int temp;
        fscanf(fptr,"%d ",&temp);
	printf(" %d\n ",temp);
        Push(head,temp);
}
fclose(fptr);
printlist(head);
int lim=head->count;
for(int i=0;i<lim;i++)
{
	Pop(head);
	printlist(head);
}
Pop(head);
printlist(head);
}
