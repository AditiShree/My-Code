#include <stdio.h>

int visited[20], order[20], tmp[20], parent[20];
int n, c = 0, cyc=0, itrn = 0 ;
int facto, res = 1, factn;

int fact(int facto) {
  while(facto != 1) {
    res = res*facto;
    facto--;
    fact(facto);
  }

  if(facto == 1) {
    return res;
  }
}


int cycle(int **m, int head) {
  int start = -1, i, j, k;
  visited[head] = 1;
  order[c] = head;
  tmp[c] = head;
  c++;

  if(itrn > factn) {
    return 0;
  }

  for(i=0; i<n; i++) {
    cyc = 0;

    if ((m[head][i] == 1) && (visited[i]!=1)) {
      parent[i] = head;
      cycle(m, i);
    }else if ((m[head][i] == 1) && (visited[i]==1) && (parent[head] != i)){
      printf("Cycle formed\n");
      itrn++;
      cyc = 1;
      order[c] = i;
      tmp[c] = i;
      c++;

      //empty the tmp[] where cycle is getting stored
      for(k=0; k<20; k++) {
        tmp[k] = -1;
      }

      //to store the start index of cycle
      for(j=0; j<c; j++) {
        if((tmp[j] == tmp[c-1]) != -1) {
          start = j;
        }

        //if a loop is there print only loop part
        if(start != -1) {
          printf("its srart %d\n", start);
          for(j=start; j<c; j++) {
              printf("%d\t", tmp[j]);
          }
        }
      }

      //return 0;
    }
  }
  //return 0;
}


main() {

  int  i ,j, k;
  printf("Enter the no of nodes\n");
  scanf("%d", &n);

  facto = n;
  factn = fact(n);

  int *m[n];
  for(i=0; i<n; i++) {
    m[i] = (int*) malloc(n*sizeof(int));
  }

  printf("Enter the graph\n");
  for(i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("row - %d \tCol - %d\t\t",i, j);
      scanf("%d", &m[i][j]);
    }
  }

  printf("Enter the head node\n");
  int head;
  scanf("%d", &head);
  printf("Head = %d\n", head);

  for(i=0; i<n; i++) {
    visited[i] = -1;
    order[i] = -1;
    tmp[i] = -1;
    parent[i] = -1;
  }
  //parent[head] = -1;
  cycle(m, head);

  if(!cyc) {
    printf("No cycle\n");
  }


}
