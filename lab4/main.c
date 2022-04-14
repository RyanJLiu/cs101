#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}

int* get_n(int n[],int num,int size,int *L)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(n[i]==num)
		{
			L=i;
			return &n[i];
		}
	}
	printf("%s is not in the array.", num);
}

void Task1()
{
	int n[]={25,36,9,4,49,81,1,0,64,16};
	int *p;
	int L;
	p=get_n(n,64,10,&L);
	printf("&n[%i]->%p, n[%i]=%i; p->%p, *p=%i\n", L, &p, L, *p, &p, *p);
}

void Task2()
{
	int i,L;
	int n[]={25,36,9,4,49,81,1,0,64,16};
	qsort(n,10,sizeof(int),cmp);
	int *ap[10];
	for(i=0;i<10;i++)
	{
		ap[i]=get_n(n,n[i],10,&L);
		printf("&n[%i]->%p, n[%i]=%i; ap[%i]->%p, *ap[%i]=%i\n", L, &ap[i], L, *ap[i], i, &ap[i], i, *ap[i]);
	}
}

int main()
{
	printf("No.1 -------------------\n");
	Task1();
	printf("No.2 -------------------\n");
	Task2();
	return 0;
}
