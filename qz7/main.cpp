#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>

using namespace std;

class myString
{
	public:
		myString();
};

class ReadClass
{
	public:
		ReadClass();
		void showClass();
	private:
		ifstream in;
		string f;
};

int main()
{
	ReadClass rfile;
	rfile.showClass();
	return 0;
}

myString::myString()
{
}

ReadClass::ReadClass()
{
	in.open("main.cpp");
	f="main.cpp";
}

void ReadClass::showClass()
{
	string s;
	int i;
	int r=0;
	int c=0;
	string cl[20];
	in>>s;
	while(s!="main()")
	{
		if(s=="class")
		{
			c=c+1;
			r=1;
		}
		in>>s;
		if(r==1)
		{
			cl[c-1]=s;
			r=0;
		}
	}
	in.close();
	cout<<c<<" class in "<<f<<"\n";
	for(i=0;i<c;i++)
		cout<<"class "<<cl[i]<<"\n";
}
