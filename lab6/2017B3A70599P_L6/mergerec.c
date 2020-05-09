#include "merge.h"
void mergesortrec(Element Ls[],int left,int right)
{
        if(left<right)
        {
                int mid=(left+right)/2;
                mergesortrec(Ls,left,mid);
                mergesortrec(Ls,mid+1,right);
                Element narr[right-left+1];
                merge(Ls+left,Ls+mid+1,mid-left+1,right-mid,narr);
                for(int i=0;i<(right-left+1);i++) Ls[left+i]=narr[i];
        }
	else rtop=&left;
}

