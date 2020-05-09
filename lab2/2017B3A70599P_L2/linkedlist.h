#include<stdio.h>
// Structure definitions
// Structure of the linked list node. it contains an element

struct node {
	int element;
	struct node * next;
	};

//structure of the linked list: head stores count of elements and the pointer to the first node of the list

struct linkedlist {
	int count;
	struct node * first;
};

//function declarations

void insertfirst (struct linkedlist * head,int ele);
// this inserts a given element at the beginning of the list

struct node * deletefirst(struct linkedlist * head);
//deletes the first element of the list and returns pointer to the deleted node.
void printlist(struct linkedlist * head);
//prints all the elements of the list

int search(struct linkedlist * head,int ele);
// searches for a given element in the linkedlist. 1 if found 0 otherwise

struct node* deletes(struct linkedlist * head, int ele);
//deletes the first node in the list that contains the element = ele and returns it. if the element is not found it returns an error message saying element not found

// END OF linkedlist.h

