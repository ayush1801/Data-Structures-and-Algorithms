#include<stdio.h>
#include<stdlib.h>
#include "mem2.h"
#include<stdbool.h>
int randomn(int lower,int upper)
{
	int num=(rand()%(upper-lower+1))+lower;
	return num;
}
int main()
{
	bool failure=false;
	while(!failure)
	{
		int num=randomn(10000,25000);
		int * ptr=(int *)malloc(num*sizeof(int));
		if(ptr=NULL) 
		{
			failure=true;
			break;
		}
		printf(" first location: %u\n",ptr);
		printf(" last location: %u\n",&ptr[num-1]);
	}
}
		
	
