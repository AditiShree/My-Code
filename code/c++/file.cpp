#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fobj("qwe.txt");
    int id,num;
    string name;
    cout<<"enter id no"<<endl;
    cin>>num;
    while(fobj>>name>>id)
    {
    	if(id==num)
    		cout<<id<<" "<<name<<"  "<<endl;
    }
}