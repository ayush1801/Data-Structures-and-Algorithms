#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Ls
{
	char name[11];
	int empid;
}Ls;

typedef struct Time
{
	double IS;
	double QS;
}Time;

void IQuickSort(Ls * ls,int st,int en,int S);
void InsertionSort(Ls * ls,int st,int en);
void MixedSort(Ls *ls,int st,int en,int S);
int Partition(Ls *ls,int st,int en);
int bisection(Ls *ls,int size);
Time testRun(Ls *ls,int size);
int estimateCutoff(Ls *ls,int size);
