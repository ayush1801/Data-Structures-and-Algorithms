#include "merge.h"
void mergesortint(Element Ls[],int sz);

int main()
{
	FILE * fptr=fopen("1024.txt","r");
	Element * ptr=(Element *)malloc(30*sizeof(Element));
	int i=0;
	
	while(fscanf(fptr,"%[^,],%f\n",ptr[i].name,&ptr[i].cg)!=EOF)
	{
		i++;
		if(i==30) break;
	}
	fclose(fptr);
	printf(" BEFORE SORINTG...\n");
	for(int i=0;i<30;i++)
	{
		printf("%s,%f\n",ptr[i].name,ptr[i].cg);
	}
	mergesortint(ptr,30);
	printf(" AFTER SORTING... \n");
	for(int i=0;i<30;i++) 
	{
		printf("%s,%f\n",ptr[i].name,ptr[i].cg);
	}
	
}
	

