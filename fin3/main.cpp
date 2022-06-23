#include<iostream>

using namespace std;

class myArray
{
	public:
		myArray(int s);
		void recInput(int a[], int s);
		int recMax(int s);
		int recSum(int s);
		float recAve(int s);
	private:
		int size;
		int arr[];
};

int main()
{
	int size=5;
	int array[]={500,1,2,3,4};
	myArray A(size);
	A.recInput(array, size);
	cout << " The max is:  " <<A.recMax(size) << endl;
	cout << " The sum is:  " <<A.recSum(size) << endl;
	cout << " The avr is:  " <<A.recAve(size) << endl;
	return 0;
}

myArray::myArray(int s)
{
	size=s;
}

void myArray::recInput(int a[], int s)
{
	
	int i=0;
	for(i=0;i<s;i++)
		arr[i]=a[i];
}

int myArray::recMax(int s)
{
	if (s>0)
	{
		if(recMax(s-1)>arr[s])
			return recMax(s-1);
		else
			return arr[s];
	}
	else
		return arr[s];
}

int myArray::recSum(int s)
{
	s=s-1;
	if (s>0)
		return recSum(s)+arr[s];
	else
		return arr[s];
}
float myArray::recAve(int s)
{
	return float(recSum(s))/float(s);
}
