#include "complete.h"

int main(int argv,char * argc[])
{
  int size=atoi(argc[1]);
  Ls * ls=(Ls *)malloc(size*sizeof(Ls));
  FILE * fptr=fopen(argc[1],"r");
    int i=0;
    while(fscanf(fptr,"%[^ ] %d\n",ls[i].name,&ls[i].empid)!=EOF)
    {
      i++;
    }
  fclose(fptr);
  Time T=testRun(ls,size);
//  printf(" IS= %lf QS= %lf\n",T.IS,T.QS); 
  int mid=bisection(ls,size);
  printf(" mid %d \n",mid);
  MixedSort(ls,0,size-1,mid);
 // fptr=fopen("output.txt","w");
 // for(int i=0;i<size;i++)
//  {
//	fprintf(fptr,"%s %d\n",ls[i].name,ls[i].empid);
 // }
//  fclose(fptr); */
}
