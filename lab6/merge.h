#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Student
{
	char name[11];
	float cg;
}Element;
int * ibottom;
int * itop;
int * rbottom;
int * rtop;

void merge(Element Ls1[],Element Ls2[],int sz1,int sz2,Element Ls[]);



