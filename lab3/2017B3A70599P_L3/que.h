#include<stdio.h>
#include<stdbool.h>
typedef struct Task{
int tid;
int p;
}Task;
struct Node{
	Task elem;
	struct Node * next;
	};
typedef struct Queue{
	struct Node * head;
	struct Node * tail;
	}Queue;
extern Queue newQ();
extern bool isEmptyQ(Queue q);
extern Queue delQ(Queue q);
extern Task front(Queue q);
extern Queue addQ(Queue q,Task e);
extern int lengthQ(Queue q);
