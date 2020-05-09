#include<stdio.h>
#include<stdlib.h>

int main()
{
//	int *p=(int*)malloc(sizeof(int));
	int *p;
	int a=4;
//	(*p)=a;
//	(*p)=4;
	p=&a;
	printf("%d",*p);
}
