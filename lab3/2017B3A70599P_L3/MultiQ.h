#include<stdio.h>
#include<stdlib.h>
#include "que.h"
// Queue MultiQ
typedef struct MultiQ
{
	Queue * mqa;
	int arrlen;
} MultiQ;
MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
bool isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq,int p);
Queue getQueueFromMQ(MultiQ mq,int p);
