#include <stdio.h>

//using namespace std;

struct node {
  int data;
  struct node *next;
};

main() {
  int n, i, d, done, t;
  //printf("Enter the no of elem to enter\n");
  //scanf("%d", &n);

  struct node *head, *curr, *tmp;
  //head = (struct node*) malloc( sizeof(struct node) );
  //tmp = (struct node*) malloc( sizeof(struct node) );
  //curr =  (struct node*)malloc( sizeof(struct node) );
  head = curr = tmp = NULL;

  printf("Enter elem\n");
  while(1) {
    d = 0;
    scanf("%d", &d);
    if(d == 1234567890) {
      break;
    }
    //printf("Its elem %d\n", d);
    tmp = (struct node*) malloc( sizeof(struct node) );
    tmp->data = d;
    //printf("after input\n");
    tmp->next = NULL;


    done = 0;
    while(!done) {
      printf("inside while\n");
      if(head == NULL) {
        head = tmp;
        curr = head;
        done = 1;
      }else{
        curr->next = tmp;
        curr = curr->next;
        done = 1;
      }

    }

  }


  printf("Entered values are--\n");
  tmp = head;
  do {
      t = tmp->data;
      printf("%d\t", t);
      tmp = tmp->next;
  }while (tmp!=NULL);



}
