#include <iostream>
using namespace std;

class LinkedList {

private :
 struct list {
    int data;
    list *next;
  }*head,*tail;

public :
  LinkedList() ;
  void append(int x);
  void AddBegin(int x);
  void Print();
  int Delete(int x);
  void Rev();
};

LinkedList::LinkedList(){
  head = tail = NULL;
}

void LinkedList::append(int x) {
  list *temp;
  if (head==NULL) {
    head = new list;
    head -> data = x;
    head -> next = NULL;
    tail = head;
  }else{
      temp = new list;
      temp -> data = x;
      temp -> next = NULL;
      tail -> next = temp;
      tail = temp;
  }
}

void LinkedList::AddBegin(int x) {
  list *temp;
  if (head==NULL) {
    head = new list;
    head -> data = x;
    head -> next = NULL;
    tail = head;
  }else{
    temp = new list;
    temp -> data = x;
    temp -> next = head;
    head = temp;
  }

}


void LinkedList::Rev() {
  list *p,*r,*q;
  if (head==NULL) {
    cout<<"No elem"<<endl;
  }

  q = head->next;
  r = q->next;
  q->next = head;
  p=q;
  while(r!=NULL){
    q = r;

    r = r->next;
    q -> next = p;
    //r->next = q;
    p = q;

  }
  head -> next = NULL;
  head = q;

}



void LinkedList::Print() {
  list *temp;
  if (head==NULL) {
    cout<<"Linked list is empty"<<endl;

  }else{
    //temp = new LinkedList;
    temp = head;
    while(1) {
      cout<<endl;
      cout<<temp -> data<<endl;
      cout<<endl;
      temp = temp -> next;
      if (temp==NULL){
        break;
      }
    }
    //cout<<temp -> data<<endl;
  }
}

int LinkedList::Delete(int x) {
    list *temp1, *temp2;

    if (head==NULL) {
      cout<<"Linked list empty"<<endl;
    }else{
      if(head->data==x) {
        head = head->next;
      }else{
        if(head->next==NULL){
          cout<<"No such elem"<<endl;
          return 0;
        }else{
          temp2 = head;
          temp1 = temp2->next;
          while(temp1->next!=NULL) {
            if (temp1->data==x) {
              temp2->next=temp1->next;
              return 0;
            }else{
              temp2 = temp1;
              temp1 = temp1->next;

            }
          }
          cout<<"no elem "<<endl;
        }


      }
    }

}

int main() {
  int choice;
  int elem, end=0;
  LinkedList lo;

  while (1) {
    cout<<"Enter the operation: "<<endl;
    cout<<"1.Append"<<endl;
    cout<<"2.Add in beginning"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Delete" <<endl;
    cout<<"5.Exit"<<endl;
    cout<<"6.Reverse"<<endl;

    cin>>choice;
    if (choice==1) {
      cout<<"enter elem to append"<<endl;
      cin>>elem;
      lo.append(elem);
    }else if (choice==2) {
      cout<<"enter the elem to add in beginning"<<endl;
      cin>>elem;
      lo.AddBegin(elem);
    }else if (choice==3) {
      lo.Print();
    }else if (choice==4 ){
      cout<<"enter elem to be deleted"<<endl;
      cin>>elem;
      lo.Delete(elem);
    }else if(choice==6) {
      lo.Rev();
    } else{
      break;
    }
  }
return 0;

}
