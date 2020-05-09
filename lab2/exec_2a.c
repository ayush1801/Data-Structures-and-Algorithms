#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* arg[])
{
	FILE *fptr1,*fptr2;
	fptr1 = fopen(arg[1],"r");
	fptr2 = fopen(arg[2],"w");
	char c;
	c=fgetc(fptr1);
	if(fptr1==NULL||fptr2==NULL)
	{
		fclose(fptr2);
		fclose(fptr1);
		printf("File not found");
		exit(0);
	}
	while(c!=EOF)
	{
		fputc(c,fptr2);
		c=fgetc(fptr1);
	}
	printf("file copied successfully\n");
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
