#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "MultiQ.h"
//#include<stdbool.h>
MultiQ createMQ(int num)
{
	MultiQ mq;
	mq.mqa=(Queue *)calloc(num,sizeof(newQ()));
	mq.arrlen=num;
	return mq;
}
MultiQ addMQ(MultiQ mq,Task t)
{
	mq.mqa[t.p-1]=addQ(mq.mqa[t.p-1],t);  //priorities are from 1 not 0     
//	printf("(%d %d)",front(mq[t.p-1]).tid,front(mq[t.p-1]).p); //for testing
	return mq;
}
Task nextMQ(MultiQ mq)
{
	int i;
	for(i=0;i<mq.arrlen;i++)
	{
		if(!isEmptyQ(mq.mqa[i])) break;
	}
	return front(mq.mqa[i]);
}
MultiQ delNextMQ(MultiQ mq)
{	
	if(isEmptyMQ(mq))
	{
		 printf("Cant do this operation \n");
		 exit(0);
	}
	int i;
	for(i=0;i<mq.arrlen;i++)
	{
		if(!isEmptyQ(mq.mqa[i])) break;
	}
	mq.mqa[i]=delQ(mq.mqa[i]);
	return mq;
}
bool isEmptyMQ(MultiQ mq)
{
	int i;
	for(i=0;i<mq.arrlen;i++)
	{
		if(!isEmptyQ(mq.mqa[i])) return false;
	}
	return true;
}
int sizeMQ(MultiQ mq)
{
	int count=0,i;
	for( i=0;i<mq.arrlen;i++)
	{
		count=count+lengthQ(mq.mqa[i]);
	}
	return count;
}
int sizeMQbyPriority(MultiQ mq,int p)
{
	return lengthQ(mq.mqa[p-1]);

}
Queue getQueueFromMQ(MultiQ mq,int p)
{
	return mq.mqa[p-1];
}
