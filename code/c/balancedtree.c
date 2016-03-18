#include <stdio.h>

struct node {
  int data;
  int key;
  int rb;
  struct node *left;
  struct node *right;
};

//key stores the height difference for each node

//rb = 0 -->red --> unbalanced node
//rb = 1 -->black --> balanced node

void predisplay(struct node *head) {
  printf("%d\t", head->data);

  if(head->left != NULL)
    predisplay(head->left);

  if(head->right != NULL)
    predisplay(head->right);

}

int height(struct node *pt ) {
  int lh, rh;
  if(pt->left != NULL) {
    lh = height(pt->left);
  }else{
    lh = 0;
  }

  if(pt->right != NULL) {
    rh = height(pt->right);
  }else{
    rh = 0;
  }

  pt->key = abs(lh - rh);

  return (1 + ((lh>rh)?lh:rh));

}

void redblack(struct node *pt) {
  if(pt->left != NULL) {
    redblack(pt->left);
  }
  if(pt->right != NULL) {
    redblack(pt->right);
  }

  if(pt->key > 1) {
    pt->rb = 0;
  }else{
    pt->rb = 1;
  }


}

main() {

  int n, i, d, done, found;
  int new, del;
  printf("Enter the no of elem\n");
  scanf("%d", &n);

  struct node *head, *tmp, *curr;
  head = tmp = curr = NULL;

  printf("Enter %d elem\n", n);
  for (i=0; i<n; i++) {
      scanf("%d", &d);
      tmp = (struct node*) malloc(sizeof(struct node));
      tmp->data = d;
      tmp->left = NULL;
      tmp->right = NULL;

      done = 0;
      curr = head;
      while(!done) {
        if(head == NULL) {
          head = tmp;
          curr = head;
          done++;
        }else{
          if(d <= curr->data) {
            if(curr->left == NULL) {
              curr->left = tmp;

              done++;
            }else{
              curr = curr->left;
            }
          }else{
            //d>curr->data
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

  predisplay(head);


  int h;
  h = height(head);
  printf("Max height = %d\t Root balanced{if 0 or 1} = %d\n", h, head->key);






}
