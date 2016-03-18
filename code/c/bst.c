#include <stdio.h>

struct node {
  int data;
  struct node *left, *right;
}

main() {
  int n, i, d, done, count;
  printf("Enter no of inputs\n" );
  scanf("%d", &n);

  struct node *head, *tmp, *curr;
  head = tmp = curr = NULL;

  for(i=0; i<n; i++) {

    scanf("%d", &d);
    tmp = malloc(sizeof(struct node));
    tmp->data = d;
    tmp->left = NULL;
    tmp->right = NULL;

    if (head == NULL) {
      head = tmp;
    }else{
      //done represents if the data entered or not
      done = 0;

      curr = head;
      while(!done) {
        if(d <= curr->data) {
          if(curr->left==NULL) {
            curr->left = tmp;
            done = 1;
          }else{
            curr = curr->left;
          }
        }else{
          if(curr->right == NULL) {
            curr->right = tmp;
            done++;
          }else{
            curr = curr->right;
          }
        }
      }
    }
  }
  printf("\nPreorder--\n");
  preprint(head);
  printf("\nInorder--\n");
  inprint(head);
  printf("\nPostorder--\n");
  postprint(head);

}


void preprint(struct node *ptr) {
  printf("%d\t", ptr->data);

  if(ptr->left != NULL) {
    preprint(ptr->left);
  }
  if(ptr->right != NULL){
    preprint(ptr->right);
  }


}

void inprint(struct node *ptr) {


  if(ptr->left != NULL) {
    inprint(ptr->left);
  }

  printf("%d\t", ptr->data);

  if(ptr->right != NULL){
    inprint(ptr->right);
  }
}

void postprint(struct node *ptr) {

  if(ptr->left != NULL) {
    postprint(ptr->left);
  }
  if(ptr->right != NULL){
    postprint(ptr->right);
  }
  printf("%d\t", ptr->data);

}
