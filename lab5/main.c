#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int* get_int_array(int n)
{
	return calloc(n, sizeof(int));
}

void set_value(int* p, int v)
{
	*p=v;
}

void print_array(int* p, int n)
{
	int i;
	printf("[");
	for(i=0;i<n;i++)
	{
		printf("%d", *p+i);
		if(i<n-1)
			printf(", ");
	}
	printf("]\n");
}

int main()
{
	int i;
	int n=10;
	int* ip = get_int_array(n);
	for(i=0;i<n;i++)
		set_value(ip+i, i+1);
	print_array(ip, n);
	return 0;
}
