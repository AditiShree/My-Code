#include<iostream>
using namespace std;

class box
{
	int len;
	public:
		//int len;
		void setl(double length)
		{
			len=length;
		}
		friend void printlen(box bo);

};

		void printlen(box bo)
		{
			cout<<"length="<<bo.len<<endl;
		}


int main()
{
    box bo;
    bo.setl(10.87);
    printlen(bo);

}