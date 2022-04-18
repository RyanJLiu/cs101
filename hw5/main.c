#include<stdio.h>
#include<stdlib.h>

int g_mem[10];

typedef struct my_mm
{
	int m;
	int mo[10];
}my_mm_t;

my_mm_t mms;

void printmm()
{
	int i;
	for(i=0;i<10;i++)
		printf("%d",g_mem[i]);
	printf("\n");
}

int* my_calloc(int n, int size)
{
	int i, e, c;
	size=n*size;
	e=0;
	c=0;
	mms.m=mms.m+1;
	for(i=0;i<10;i++)
	{
		if(mms.mo[i]==0)
			c=c+1;
		else
			c=0;
		if(c==size)
			e=i;
	}
	if(c>=size)
	{
		for(i=e;i>e-size;i--)
		{
			g_mem[i]=1;
			mms.mo[i]=mms.m;
		}
	}
	printmm();
	return mms.m;
}

void my_free(int* p)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(mms.mo[i]==p)
		{
			g_mem[i]=0;
			mms.mo[i]=0;
		}
	}
	printmm();
}

int main()
{
	mms.m=0; 
	int* np1 = my_calloc(1, 1);
	int* np2 = my_calloc(1, 2);
	int* np3 = my_calloc(1, 3);
	int* np4 = my_calloc(1, 4);
	my_free(np1);
	my_free(np4);
	int* np5 = my_calloc(1, 3);
	return 0;
}
