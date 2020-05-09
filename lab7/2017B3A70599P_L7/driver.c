#include "complete.h"
#include<string.h>
int main( )
{
  int size=10;
// Run bisection to estimate the cutoff for 10000 inputs
  Ls * ls=(Ls *)malloc(1000*sizeof(Ls));
  FILE * fptr=fopen("1000","r");
    int i=0;
    while(fscanf(fptr,"%[^ ] %d\n",ls[i].name,&ls[i].empid)!=EOF)
    {
      i++;
    }
  int mid=bisection(ls,1000);
  FILE * fptr1=fopen("TimeofMixedSort.txt","w");
  fprintf(fptr1," INPUT SIZE   OPT TIME(IN ms.)\n");
  fprintf(fptr1,"*****************************\n");
// running inputs till 10^6 for time constraints
  while(size<=1000000)
  {
  Ls * ls=(Ls *)malloc(size*sizeof(Ls));
  char inp[15];
  sprintf(inp,"%d",size);
  fptr=fopen(inp,"r");
    int i=0;
    while(fscanf(fptr,"%[^ ] %d\n",ls[i].name,&ls[i].empid)!=EOF)
    {
      i++;
    }
  fclose(fptr);
  Time T=testRun(ls,size);
  double tt=MixedSort(ls,0,size-1,mid);
  fprintf(fptr1,"%9d      %5lf ms.\n",size,tt);
  char filename[]="Output";
  strcat(filename,inp);
  fptr=fopen(filename,"w");
  for(int i=0;i<size;i++)
  {
	fprintf(fptr,"%s %d\n",ls[i].name,ls[i].empid);
  }
  fclose(fptr);
  size=size*10;
}
fclose(fptr1);
}
