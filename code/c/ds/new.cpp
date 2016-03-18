#include <iostream>
using namespace std;
int main() {
  int *p;
  int n;
  cin>>n;

  p = new int[n];
  cout<<"its p"<<p<<endl;
  for (int i=0; i<n; i++) {
    cin>>p[i];
  }
  for (int i=0; i<n; i++) {
    cout<<p[i]<<endl;
  }
}
