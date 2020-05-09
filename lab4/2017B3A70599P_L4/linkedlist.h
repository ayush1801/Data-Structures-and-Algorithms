#include<stdio.h>
// Structure definitions
// Structure of the linked list node. it contains an element

typedef struct node {
	int element;
	struct node * next;
	}Node;

//structure of the linked list: head stores count of elements and the pointer to the first node of the list

struct linkedlist {
	int count;
	struct node * first;
};

typedef struct linkedlist * Ls;

//function declarations

void insertfirst (Ls head,int ele);
// this inserts a given element at the beginning of the list

Node * deletefirst(Ls  head);
//deletes the first element of the list and returns pointer to the deleted node.

void printlist(Ls  head);
//prints all the elements of the list

int search(Ls head,int ele);
// searches for a given element in the linkedlist. 1 if found 0 otherwise

Node * retNodebe(Ls head,int ele);
//searches for the given element returns the node containing the element and NULL if not found

Node * retNodebc(Ls head,int c);
//searches for the given node index and returns the node

Node * deletes(Ls head, int ele);
//deletes the first node in the list that contains the element = ele and returns it. if the element is not found it returns an error message saying element not found

void insertafter (Ls head,int ele);
//this inserts a given element at the last of the linkedlist
// END OF linkedlist.h

