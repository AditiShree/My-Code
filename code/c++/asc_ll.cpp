#include <iostream>
using namespace std;

class LinkedList {

private:
  struct list {
    int data;
    list *next;
  }*head, *tail;

public:
  LinkedList();
  void append(int x);
  //void AddBegin(int x);
  void Print();
  int Delete(int x);

};

LinkedList::LinkedList(){
  head = tail = NULL;
}

void LinkedList::append(int x) {
  list *temp, *temp2, *temp3;
  if (head==NULL) {
    head = new list;
    head -> data = x;
    head -> next = NULL;
    tail = head;
  }else{

    if (head->next==NULL) {
      temp = new list;
      temp -> data = x;
      if(x < head->data) {
        temp -> next = head;
        head = temp;
      }else{
        temp -> data = x;
        temp -> next = NULL;
        head -> next = temp;
        tail = temp;
      }
      //if next of head is not null
    }else{
      temp = new list;
      //temp2 = head;
      temp -> data = x;
      if (x < head->data) {
        temp -> next = head;
        head = temp;

      }else{
      temp2 = head -> next;
      temp3 = head;

      while(1){
        if (x <= temp2->data && x>=temp3->data) {
          temp -> next = temp2;
          temp3 -> next = temp;
          break;
        }else if(x > temp2->data && temp2->next==NULL) {
          temp2 -> next = temp;
          temp -> next = NULL;
          break;
        }else{
          temp3 = temp2;
          temp2 = temp2->next;
        }
      }
    }
    }



  }
}

/*void LinkedList::AddBegin(int x) {
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

}*/

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
          if (temp1->data == x) {
            temp2->next = NULL;
            return 0;
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
    //cout<<"2.Add in beginning"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Delete" <<endl;
    cout<<"5.Exit"<<endl;

    cin>>choice;
    if (choice==1) {
      cout<<"enter elem to append"<<endl;
      cin>>elem;
      lo.append(elem);
    }/*else if (choice==2) {
      cout<<"enter the elem to add in beginning"<<endl;
      cin>>elem;
      lo.AddBegin(elem);
    }*/else if (choice==3) {
      lo.Print();
    }else if (choice==4 ){
      cout<<"enter elem to be deleted"<<endl;
      cin>>elem;
      lo.Delete(elem);
    } else{
      break;
    }
  }
return 0;

}
