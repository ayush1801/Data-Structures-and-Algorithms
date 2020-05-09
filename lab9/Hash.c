#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int Hash(char *str,int basenum,int tablesize)
{
	int i=0;
	int sum=0;
	while(str[i])
	{
		sum=sum+str[i];
		i++;
	}
	int hash=((sum%basenum)%tablesize);
	return hash;
}

int Collision(char *str[],int strlen,int basenum,int tablesize)
{
	int hasharr[tablesize];
	for(int i=0;i<tablesize;i++) hasharr[i]=0;
	for(int i=0;i<strlen;i++)
	{
		hasharr[Hash(str[i],basenum,tablesize)]++;
	}
	int coll=0;
	for(int i=0;i<tablesize;i++)
	{
		if(hasharr[i]>1) coll=coll+hasharr[i]-1;
	}
	return coll;
}
char ** parse(char file[],int * vallen)
{
	FILE * fptr=fopen(file,"r");
	int cursize=10;
	char ** colstr=(char **)malloc(sizeof(char*)*cursize);
	char curstr[20000]={0};
	int validcount=0;
	while(fscanf(fptr,"%s ",curstr)!=EOF)
	{
		int isok=1;
		int i=0;
		while(curstr[i])
		{
			if((curstr[i]< 'A' || curstr[i]> 'Z') && (curstr[i]<'a' || curstr[i]>'z'))
			{
				isok=0;
				break;
			}
			i++;

		}
		printf("\n");
		if(isok)
		{
			colstr[validcount]=(char*)malloc(sizeof(char)*strlen(curstr)+1);
			strcpy(colstr[validcount],curstr);
			validcount++;
			if(validcount>=cursize)
			{
				cursize*=2;
				colstr=(char**)realloc(colstr,sizeof(char*)*cursize);
			}
		}
	
	}
	fclose(fptr);
	printf("%d\n",validcount);
	*vallen=validcount;
	return colstr;
}
			
// tablesize: 5000,50000,500000
// basenumbers: {7457,9613,9371,6217249,8032489,7284521},{83621,96557,57037,85473389,64957973,75926287},{526283,606311,537899,560659651,730458901,748174813}

void profiler(char * file)
{
	int tablesize[]={5000,50000,500000};
	int basenum[3][6]= {{7457,9613,9371,6217249,8032489,7284521},{83621,96557,57037,85473389,64957973,75926287},{526283,606311,537899,560659651,730458901,748174813}};
	int colls[18];
	int vallen;
	int coll=0;
	char ** colstr=parse(file,&vallen);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<6;j++)
		{
			coll=Collision(colstr,vallen,basenum[i][j],tablesize[i]);
			printf("table: %d base: %d collisioncount: %d\n",tablesize[i],basenum[i][j],coll);
			colls[6*i+j]=coll;
		}
	}
	//finding min collision
	int mini=0;
	for(int i=1;i<18;i++)
	{
		if(colls[i]<colls[mini]) mini=i;
	}
	int baseindex=mini%6;
	int tableindex=(mini-baseindex)/6;
	printf(" baseindex: %d  tableindex: %d\n",baseindex,tableindex);
}
	
int main()
{
 profiler("aliceinwonderland.txt");
}

