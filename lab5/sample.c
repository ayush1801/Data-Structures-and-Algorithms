#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
unsigned int measure[10];
int index=0;
int main()
{
	callme(10);
	for(int k=1;k<10;k++) printf("%d",measure[k]-measure[k-1]);

}
void callme(int i)
{
	unsigned int k=5;
	measure[index++]=&k;
	if(i>0) callme(--i);
}
