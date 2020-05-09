#include<stdio.h>
#include<stdlib.h>
int main()
{
//	char * arr; //output would be NULL;
//	scanf("%s",arr);
//	printf("%s",arr);

//	char * arr="aaaaaaaa ";  //output is segmentation fault core dumped, memory allocated in code segment;(ROM) only the whole string can be modified
//	scanf("%s",arr);
//	printf("%s",arr);

//	char arr[]=" ";  //output is shown memory is allocated in SS;
//	scanf("%s",arr);
//	printf("%s",arr);

	char arr[10];  //output is shown memory is allocated in SS;
	scanf("%s",arr);
	printf("%s",arr);

//	char u[]="aaaaa"; //output is shown memory is allocated here in SS
//	char * s=u;
//	scanf("%s",s);
//	printf("%s",s);

//	int *arr;   //output is segmentation fault since no memory allocation
//	scanf("%d",arr);
//	printf("%d",*arr);

//	int *arr;  // segmentation fault no address stored; don't know where is it pointing
//	*arr=2;
//	scanf("%d",arr);
//	printf("%d",*arr);

//	int a=2;  //segmentation fault same case
//	int *arr=NULL;
//	*arr=a;
//	scanf("%d",arr);
//	printf("%d",*arr);

//	int a=2;  //correct since address is stored
//	int *arr;
//	arr=&a;
//	scanf("%d",arr);
//	printf("%d",*arr);

}
	
