#include <iostream>
using namespace std;

struct list {
  int data;
  list *next;
};


int main() {

    list *head, *curr;
    head = new list;
    head -> data = 5;
    head -> next = new list;
    curr = head->next;
    curr -> data = 7;
    curr -> next = new list ;
    curr = curr -> next;
    curr -> data = 10;
    curr -> next = NULL;

    curr = head;

    for (int i=0; i<3; i++) {
      cout<<curr->data<<endl;
      curr = curr->next;
    }


  return 0;
}
