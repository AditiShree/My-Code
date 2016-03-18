#include <stdio.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

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

  }else{

  }

}

main() {

  int n, i, d, done, found;
  int new, del;
  printf("Enter the no of elem\n");
  //Taking no of inputs
  scanf("%d", &n);

  struct node *head, *tmp, *curr;
  head = tmp = curr = NULL;

  printf("Enter %d elem\n", n);
  for (i=0; i<n; i++) {
      scanf("%d", &d);

      //store each input node in tmp until processed
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


  /////inserting a new elem in binary search tree
  printf("enter the new elem\n");
  scanf("%d", &new);
  tmp = (struct node*) malloc(sizeof(struct node));
  curr = head;

  tmp->data = new;
  tmp->left = NULL;
  tmp->right = NULL;

  done = 0;
  while(!done) {
    if(new <= curr->data) {
      if(curr->left == NULL) {
        curr->left = tmp;
        done++;

      }else{
        printf("left\n" );
        curr = curr->left;
      }
    }else{
      if(new > curr->data) {
        if(curr->right == NULL) {
          curr->right = tmp;
          done++;
        }else{
          printf("right\n" );
          curr = curr->right;
        }
      }
    }
  }
  predisplay(head);
  //end of inserting new elem in bst



  //////starting deleting of an elem in bst
  int upos;
  //upos = 0 --> del is left child of parent (uptmp)
  //upos = 1 --> del is right child of parent (uptmp)
  printf("Enter the elem to delete\n");
  scanf("%d", &del);
  struct node *uptmp, *ltmp, *rtmp, *luptmp, *ruptmp;
  //tmp = (struct node*) malloc(sizeof(struct node));
  curr = head;
  found = 0;

  //searching elem in while loop n storing in tmp
  while(!found) {

    if(del == curr->data) {
      tmp = curr;
      found = 1;
    }

    if(del<curr->data) {
      //if del no is less than curr elem
      curr = curr->left;
    }else{
      curr = curr->right;
    }
  }
  printf("after tmp found\n" );

  //finding the parent of del node (if present)
  found = 0;
  //uptmp = (struct node*) malloc(sizeof(struct node));
  uptmp = head;
  while (!found) {
    printf("inside while\n" );

    if(del == uptmp->data) {
      uptmp = NULL;
      found = 1;
      break;
    }

    if(del<uptmp->data){

      if(uptmp->left->data == del){
        found = 1;
        upos = 0;
        break;
      }else{
        uptmp = uptmp->left;
        printf("Else left\n");
      }
    }else{

      if(uptmp->right->data == del){
        found = 1;
        upos = 1;
        break;
      }else{
        uptmp = uptmp->right;
        printf("Else righht\n");
      }
    }

  }
  printf("after parent of tmp found\n" );

  //storing leftmost of right and rightmost of left child node of del(tmp) elem
  //ltmp = (struct node*) malloc(sizeof(struct node));

  if(tmp->left != NULL) {
    luptmp = tmp->left;

    if(luptmp->right == NULL) {
      ltmp = luptmp;
      luptmp = NULL;

    }else{
      found = 0;
      while(!found) {
          if(luptmp->right->right == NULL) {
            found = 1;
            ltmp = luptmp->right;
          }else{
            ltmp = ltmp->right;
          }
      }
    }

  }

  //rtmp = (struct node*) malloc(sizeof(node));

  if(tmp->right != NULL) {
    ruptmp = tmp->right;


    if(ruptmp->left == NULL) {
      rtmp = ruptmp;
      ruptmp = NULL;

    }else{
      found = 0;
      while(!found) {
        if(ruptmp->left->left == NULL) {
          found = 1;
          rtmp = ruptmp->left;
          break;
        }else{
          ruptmp = ruptmp->left;

        }
      }
    }

  }
  //end of storing left n right child

  //algo to delete node

  //if no left subtree
  if((tmp->left == NULL) && (tmp->right != NULL)) {

    tmp->data = rtmp->data;
    //ruptmp->left = NULL;
    ruptmp->left = rtmp->right;

  }

  //if no right subtree
  if ((tmp->left != NULL) && (tmp->right == NULL)) {
    tmp->data = ltmp->data;
    //luptmp->right = NULL;
    luptmp->right = ltmp->left;
  }

  //both null
  if((tmp->left == NULL) && (tmp->right == NULL)) {
    if (upos) {
      //tmp is right child
      uptmp->right = NULL;
    }else{
      uptmp->left = NULL;
    }
  }


  //both subtree is filled
  if((tmp->left != NULL) && (tmp->right != NULL)) {
    printf("Here both nt null\n" );
    if(ruptmp != NULL) {
      tmp->data = rtmp->data;
      if(rtmp->right != NULL){
        ruptmp->left = rtmp->right;
      }else{
        //if rtmp->right is null
        ruptmp->left = NULL;
      }
    }else{
      tmp->data = rtmp->data;
      if(rtmp->right != NULL) {
        //tmp->right = rtmp->right;
        ruptmp->left = rtmp->right;
      }
    }

  }

  predisplay(head);
  ///////ending deleting an elem

}
