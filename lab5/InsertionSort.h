#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "credit.h"
long long * stack_start;
long long * stack_end;
void InsertInOrder(CC * cc,long long ind,CC rec);
void InsertionSort(CC * cc,long long ind);
