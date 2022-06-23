#include<stdio.h>
#include<stdlib.h>

setMyBit(int a, int b)
{
	a|=(1<<b);
	return a;
}
clearMyBit(int a, int b)
{
	int t=a;
	a&=(1<<b+a);
	return a+t;
}
inverseMyBit(int a, int b)
{
	a^=(1<<b);
	return a;
}

int main()
{
	int a=1;
	int b=3;
	int t=a;
	printf("setMyBit(%d, %d) =%d\n", t, b, setMyBit(a, b));
	t=a;
	printf("clearMyBit(%d, %d) =%d\n", t, b, clearMyBit(a, b));
	t=a;
	printf("inverseMyBit(%d, %d) =%d\n", t, b, inverseMyBit(a, b));
	return 0;
}
