#include<iostream>
#include<string.h>
using namespace std;

int a[100],top=-1;

int pop() {
  if (top!=-1){
    top--;
    return a[top+1];
  }
}

void push(int elem) {
  top++;
  a[top] = elem;
}

void print() {
  for(int i=0 ;i<=top; i++) {
    cout<<a[i]<<"\n";
  }
}

int main() {
  char b[100];
  char oprnd;
  int aa, op1, op2, result;
  cin>>b;
  aa=0;

  for(int i=0; i<strlen(b); i++){
      if(b[i]>=48 && b[i]<=57) {
        aa = aa*10 + (b[i]-48);

      }else{

          if (b[i]==44) {
            if (aa!=0){
              top++;
              a[top] = aa;
              aa=0;
            }

            continue;
          }else{
            op1 = pop();
            op2 = pop();
            cout<<op1<<endl<<op2<<endl;
            if (b[i]=='+') {
              push(op1+op2);
            }else if(b[i]=='-'){
              push(op1-op2);
            }else if(b[i]=='*'){
              push(op1*op2);
            }else if(b[i]=='/') {
              push(op1/op2);
            }

          }
      }
      cout<<a[top];
    }

}
