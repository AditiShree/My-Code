#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;

int top=-1;
int a[100];

int pop() {
  if (top!=-1) {
    top--;
    return a[top+1];
  }
}

void push(int x) {
  top++;
  a[top] = x;
}

void print() {
  for(int i=0; i<=top; i++) {
    cout<<a[i]<<endl;
  }
}

int main() {
  char b[100];
  int temp[10];
  char *p;
  int t=0, count=0, aa=0, op1, op2;
  cout<<"enter the prefix exprn"<<endl;
  cin>>b;

  for(int i=strlen(b)-1; i>=0; i--) {
    cout<<"checking"<<b[i]<<endl;
    if (b[i]>=48 && b[i]<=57) {
      //aa = 0;
      p = &b[i];
      //cout<<"Its p value    "<<p<<endl;
      aa = atoi(p);
      //temp[t] = atoi(b[i]);
      cout<<"Its temp[t]    "<<t<<"    "<<temp[t]<<endl;
      t++;
      count++;    //for reversing array

      //a[top] = b[i];
    }else if (b[i]==44) {

      if ((b[i+1]!='+') && (b[i+1]!='-') && (b[i+1]!='*') && (b[i+1]!='/')){
        /*for (int i=count-1; i>=0; i--){
          aa = aa*10 + temp[i];
        }*/
        //aa = temp[t-1];
        cout<<"Its aa    "<<aa<<endl;
        push(aa);
        /*top++;
        a[top] = aa;*/

        cout<<"Its stack   "<<endl;
        for (int i=0; i<=top ; i++) {
          cout<<a[i]<<endl;
        }
        aa = 0;
        for(int i=0; i<count; i++) {
          temp[i] = 0;
        }

        count=0;
      }

    }else{

      if (b[i]=='+') {
        op1 = pop();
        op2 = pop();
        push(op1+op2);
      }

      if (b[i]=='-') {
        op1 = pop();
        op2 = pop();
        push(op1-op2);
      }
      if (b[i]=='*') {
        op1 = pop();
        op2 = pop();
        push(op1*op2);
      }
      if (b[i]=='/') {
        op1 = pop();
        op2 = pop();
        push(op1/op2);
      }

    }
  }
  print();


  return 0;
}
