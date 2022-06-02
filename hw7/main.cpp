#include<iostream>
#include<stdlib.h>

using namespace std;

class MMmanger
{
	public:
		int* callocMM(int size);
		void free_MM(int* p);
		int get_MMCapacity();
		void print_calloc_array(int flag, int size);
		MMmanger(int size);
		~MMmanger(); 
	private:
		int s;
		int **mem;
		int *memv;
};

int main()
{
	MMmanger mmer(10);
	int* p1 = mmer.callocMM(1);
	int* p2 = mmer.callocMM(2);
	int* p3 = mmer.callocMM(3);
	int* p4 = mmer.callocMM(4);
	mmer.free_MM(p1);
	mmer.free_MM(p4);
	int* p5 = mmer.callocMM(6);
	return 0;
}

MMmanger::MMmanger(int size):s(size)
{
	mem=(int**)calloc(s,sizeof(int));
	memv=(int*)calloc(s,sizeof(int));
	for(int i=0;i<s;i++)
		mem[i]=NULL;
}

MMmanger::~MMmanger()
{
	int i;
	free(memv);
	free(mem);
}

int* MMmanger::callocMM(int size)
{
	int i, e, c, flag;
	e=0;
	c=0;
	flag=0;
	for(i=0;i<s;i++)
	{
		if(!mem[i])
			c=c+1;
		else
			c=0;
		if(c==size)
		{
			e=i;
			i=s;
			flag=1;
		}	
	}
	if(flag==1)
	{
		for(i=e;i>e-size;i--)
		{
			mem[i]=&memv[e];
		}
	}
	print_calloc_array(flag, size);
	return &memv[e];
}

void MMmanger::free_MM(int* p)
{
	int i, t;
	for(i=0;i<10;i++)
	{
		if(mem[i]==p)
			mem[i]=NULL;
	}
	print_calloc_array(1, s);
}

int MMmanger::get_MMCapacity()
{
	int i, c;
	c=0;
	for(i=0;i<s;i++)
	{
		if(!mem[i])
			c=c+1;
	}
	return c;
}

void MMmanger::print_calloc_array(int flag, int size)
{
	int i, c;
	c=get_MMCapacity();
	cout<<"Capacity:"<<c<<" - ";
	for(i=0;i<s;i++)
		if(mem[i])
			cout<<1;
		else
			cout<<0;
	if(flag==0)
		cout<<" <- Out of space: demand "<<size;
	cout<<"\n";
}
