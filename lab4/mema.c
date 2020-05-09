#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int bits=0; //global variable
void p(int n);
void g(void);
void h(void);
void d(void);
void p(int n)
{
	int pilani=n;
	if(pilani>10000000000000) return;
	
	int bits=0;
	printf(" \ncalling p()\n ");
	printf(" address of pilani and local(?) bits %p,%p: \n",&pilani,&bits);
	p(n+1);
//	g();
//	h();
//	d();
}
void g(void)
{
	int goa=0;
	printf(" \ncalling g()\n ");
//	p();
	printf(" address of goa and global bits %p,%p: \n",&goa,&bits);
//	h();
//	d();
}
void h(void)
{
	int hyd=0;
	printf(" \ncalling h()\n ");
//	p();
//	g();
	printf(" address of hyderabad and global bits %p,%p: \n",&hyd,&bits);
//	d();
}
void d(void)
{
	int dub=0;
	printf(" \ncalling d()\n ");
//	p();
//	g();
//	h();
	printf(" address of dubai and global bits %p,%p: \n",&dub,&bits);
}
int main(void)
{
	p(0);
	g();
	h();
	d();
}
