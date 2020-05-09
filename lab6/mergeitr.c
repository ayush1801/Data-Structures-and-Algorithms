#include "merge.h"
void mergesortint(Element Ls[],int sz)
{
        int curr;
        int left;
        for(curr=1;curr<sz;curr=2*curr)
        {
                for(left=0;left<sz-1;left+=2*curr)
                {
                        int mid=0;int right=0;
                        if((left+curr-1)<(sz-1))
                        {
                                mid=left+curr-1;
                        }
                        else
                        {
                                mid=sz-1;
                        }
                        if((left+2*curr-1)<(sz-1))
                        {
                                right=left+2*curr-1;
                        }
                        else
                        {
                                right=sz-1;
                        }
                        Element narr[right-left+1];
                        merge(Ls+left,Ls+mid+1,mid-left+1,right-mid,narr);
                        for(int i=0;i<(right-left+1);i++) Ls[left+i]=narr[i];
                }
        }
	itop=&sz;
}

