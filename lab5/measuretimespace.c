#include "InsertionSort.h"
#include<sys/time.h>
int main( )
{
	struct timeval t1,t2;
	double elapsedTime;
	int l=0;
	long long tsize=10;
	char filename[10];
	FILE * fptr1=fopen("OutputTime_ISort.txt","w");
	fprintf(fptr1," FILE SIZE  TIME TAKEN \n");
	FILE * fptr2=fopen("OutputTime_StSp.txt","w");
	fprintf(fptr2," FILE SIZE   STACK-BOTTOM   STACK-TOP   SPACE USED(APPX)\n");  
	while(l<=4)
	{
		sprintf(filename,"%llu",tsize);
		CC * cc=conv(filename);

    /*for(long long i=0;i<tsize;i++)
        {
                printf("%llu %s %s %s %s\n",cc[i].cn,cc[i].bc,cc[i].ed,cc[i].fn,cc[i].ln);
        }*/
	//start timer
		gettimeofday(&t1,NULL);
		long long tind=tsize-1;
		stack_start=&tind;
		InsertionSort(cc,tind);

	//stop timer
		gettimeofday(&t2,NULL);

	//calculation of time in MilliSecs.
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	//	printf("SORTING TIME FOR %llu length is %lf\n",tsize,elapsedTime);
	//	printf("STACK SPACE REQUIRED WILL BE %u\n",stack_end-stack_start);
	/*printf(" \n SORTING BY CARD NUMBER \n");
        for(long long i=0;i<tsize;i++)
        {
                printf("%llu %s %s %s %s\n",cc[i].cn,cc[i].bc,cc[i].ed,cc[i].fn,cc[i].ln);
        }*/
		fprintf(fptr1,"%10llu %10lf ms.\n",tsize,elapsedTime);
		fprintf(fptr2,"%10llu %10llu %10llu %10llu\n",tsize,stack_start,stack_end,stack_start-stack_end); 
		tsize=tsize*10;
		l=l+1;
	}
	fclose(fptr1);
	fclose(fptr2);
}

