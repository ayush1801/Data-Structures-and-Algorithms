#include "merge.h"

void merge(Element Ls1[],Element Ls2[],int sz1,int sz2,Element Ls[])
{
	int k=0,j=0,i=0;
	while(i<sz1 && j<sz2)
	{
                if(Ls1[i].cg<=Ls2[j].cg) Ls[k++]=Ls1[i++];
                else Ls[k++]=Ls2[j++];
         
        }
        while(i<sz1) Ls[k++]=Ls1[i++];
        while(j<sz2) Ls[k++]=Ls2[j++];
}

