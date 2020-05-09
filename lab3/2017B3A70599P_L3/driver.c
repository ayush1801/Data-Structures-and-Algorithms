#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "MultiQ.h"
#include<sys/time.h>

MultiQ loadData(char * file)
{
MultiQ mq=createMQ(10);
FILE *fp = fopen(file, "r");
        const char s[2] = ",";
        char *token;
        int i;

	struct timeval t1,t2;
	double elapsedTime=0;

        if(fp != NULL)
        {
                char line[20];
                while(fgets(line, sizeof line, fp) != NULL)
                {
                        token = strtok(line, s);
                        Task t;
                        for(i=0;i<2;i++)
                        {
                                if(i==0)
                        {
                               t.tid=atoi(token);
				 token = strtok(NULL,s);
			
                        } else {
                                t.p=atoi(token);
                        }
                        }
			printf("\n(%d %d is being added...)\n",t.tid,t.p);
			//start timer
			gettimeofday(&t1,NULL);
                        mq=addMQ(mq,t);
			//stop timer
			gettimeofday(&t2,NULL);
			
			//computing the elapsed time
			elapsedTime += (t2.tv_sec-t1.tv_sec)*1000.0;
                        
			printf("the size being%d\n\n",sizeMQ(mq));
                }
        fclose(fp);
	printf(" TOTAL TIME for ADDING THE TASKS IS %lf ms. \n",elapsedTime);

}return mq;
}
MultiQ testDel(MultiQ mq,int num)
{
	for(int i = 0;i<num;i++)
	{
		mq=delNextMQ(mq);
	}
	return mq;
}
		
		
int main(int argc,char *argv[])
{
	
	MultiQ mq=loadData(argv[1]);
	int num_del=5;
	struct timeval t1,t2;
	double elapsedTime;
	//start timer
	gettimeofday(&t1,NULL);
	mq=testDel(mq,num_del);
	//stop timer
	gettimeofday(&t2,NULL);
	//computing time
	elapsedTime=(t2.tv_sec-t1.tv_sec)*1000;
	//printing time of total delete operations
	printf(" THE TOTAL TIME FOR DELETION OF %d OPERATIONS is %lf ms. \n",num_del,elapsedTime);
	//average time
	printf(" average is %lf ms. \n",elapsedTime/num_del);
	
	
	printf("\n\n\n%d size final \n",sizeMQ(mq));

}

