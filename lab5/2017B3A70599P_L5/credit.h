#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct CREDIT
{
	unsigned long long  cn;
	char bc[10];
	char ed[10];
	char fn[10];
	char ln[10];
}CC;

CC * conv(char * filename);
