#include<iostream>
using namespace std;

int a[100],top=-1;

void pop() {
  if (top==-1)
    cout<<"Stack empty so cant pop man";
  else{
    top--;
    cout<<"its done man";
  }
}

void push() {
  int elem;
  cout<<"enter element to be pushed in stack"<<endl;
  cin>>elem;
  top++;
  a[top] = elem;


}

void print() {
  for(int i=0 ;i<=top; i++) {
    cout<<a[i]<<"\n";
  }
}

int main() {
  int n, elem;
  int out=0;
while(1){
  cout<<"enter the operation you wanna perform"<<endl;
  cout<<"1.Push    2.Pop    3.Print  4. Exit"<<endl;
  cin>>n;


    if (n==1)
      push();
    if (n==2)
      pop();
    if (n==3)
      print();
    if (n==4)
      break;
  }


}
