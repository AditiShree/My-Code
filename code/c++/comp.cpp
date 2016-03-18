#include<iostream>
using namespace std;

class complex
{
	int a,b,c;
public:
	complex()
	{

	}
	void getvalue()
	{
		cout<<"enter 2 no"<<endl;
		cin>>a>>b;
	}
	void operator ++()
	{
		a=++a;
		b=++b;
	}
	void operator--()
	{
		a=--a;
		b=--b;
	}
	void display()
	{
		cout<<a<<"\t+\t"<<b<<"i"<<endl;
	}
};

int main()
{
	complex obj;
	obj.getvalue();
	++obj;
	obj.display();
	--obj;
	obj.display();

}