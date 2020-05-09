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
// Quick Sort with cutoff size

void InsertionSort(Ls * ls,int st,int en);
//Insertion Sort

double MixedSort(Ls *ls,int st,int en,int S);
//hybrid algo returns time for the Algo
 
int Partition(Ls *ls,int st,int en);
//used in QuickSort

int bisection(Ls *ls,int size);
//used for calculating cutoff 

Time testRun(Ls *ls,int size);
//runs for insertion sort and Quick Sort separately

int estimateCutoff(Ls *ls,int size);
//same as bisection but in accordance with the question
