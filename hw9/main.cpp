#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>

using namespace std;

class ReplaceMyString
{
	public:
		ReplaceMyString();
		void replaceString(string a, string b);
};

int main()
{
	ReplaceMyString my;
	my.replaceString("IU", "IU is best");
	return 0;
}

ReplaceMyString::ReplaceMyString()
{
}
void ReplaceMyString::replaceString(string a, string b)
{
	ofstream out;
	ifstream in;
	string s;
	cout<<a;
	in.open("main.cpp");
	out.open("Rmain.cpp");
	while(!in.eof())
	{
		in>>s;
		if(!s.find(a))
			s=b;
		out<<s;
		cout<<s<<"\n"; 
	}
	out.close();
	in.close();
}
