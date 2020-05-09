#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "mem2.h"

void * myalloc(int n)
{
	void * ptr = malloc(n+sizeof(int)); //+ sizeof(int) for store the amount of bytes for detecting amount of memory
	heap=heap+n; //increment in bytes
	*((int *)ptr)=n;
	return ptr+sizeof(int);
}

void myfree(void * ptr)
{
	int size=*((int*)(ptr-sizeof(int))); //for taking size stored before using sizeof(int)
	heap=heap-size; //decrement in bytes
	free(ptr-sizeof(int));
}
