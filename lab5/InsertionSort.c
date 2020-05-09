#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "InsertionSort.h"

//recursive Insertion Sort

void InsertInOrder(CC * cc,long long ind,CC rec)
{
	long long curind=ind+1;
	for(long long i=ind;i>=0;i--)
	{
		if(cc[i].cn>rec.cn)
		{
			CC temp=cc[i];
			cc[i]=rec;
			cc[curind]=temp;
			curind=i;
		}
	}
}

void InsertionSort(CC * cc,long long tind)
{
	if(tind==0) 
	{
		stack_end=&tind;
		return;
	}
	InsertionSort(cc,tind-1);
	InsertInOrder(cc,tind-1,cc[tind]);
	return;
}

