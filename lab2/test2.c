#include<stdio.h>
int main(int argc, char *argv[])
{	
	for(int i=0;i<argc;i++)
	{
	int val=atoi(argv[0]);
	if(val!=0) printf("%d",val);
	else printf(" %s ",argv[i]);
	} 
}

