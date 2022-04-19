#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int* n, int* m)
{
	int t;
	t=*n;
	*n=*m;
	*m=t;
}

void swapArray(int s[], int d[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		swap(&s[i],&d[i]);
	}
}

void printArray(int a[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d", a[i]);
		if(i<size-1)
			printf(", ");
	}
	printf("]\n");
}

char* copy_string(char* s)
{
	int i;
	int size;
	size=strlen(s)+1;
	char* cstr=(char*)calloc(size, sizeof(char*));
	for(i=0;i<size;i++)
		cstr[i]=s[i];
	return cstr;
}

int main()
{
	printf("No.1 -------------------\n");
	int n, m;
	n=1;
	m=2;
	swap(&n, &m);
	printf("after swap, n=%d, m=%d\n", n, m);
	printf("No.2 -------------------\n");
	int size=10;
	int source[10]={0,9,8,7,6,5,4,3,2,1};
	int dest[10]={10,20,30,40,50,60,70,80,90,100};
	swapArray(source, dest, size);
	printf("after swap array, source array = [");
	printArray(source, size);
	printf("after swap array, dest array = [");
	printArray(dest, size);
	printf("No.3 -------------------\n");
	char str[] = "IU!IU!IU!IU!";
	char* cp_str = copy_string(str);
	printf("copy string = %s\n", cp_str);
	free(cp_str);
	return 0;
}
