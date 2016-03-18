#include <stdio.h>

int visited[20], order[20], parent[20];
int n, c = 0, cyc=0 ;


int cycle(int **m, int head) {
  int start = -1, i, j;
  visited[head] = 1;
  order[c] = head;
  c++;
  for(i=0; i<n; i++) {
    if(cyc == 1) {
      return 0;
    }
    if ((m[head][i] == 1) && (visited[i]!=1)) {
      parent[i] = head;
      cycle(m, i);
    }else if ((m[head][i] == 1) && (visited[i]==1) && parent[head] != i){
      printf("Cycle formed\n");
      cyc = 1;
      order[c] = i;
      c++;
      for(j=0; j<c; j++) {
        if(order[j] == order[c-1]) {
          start = j;
        }
        if(start != -1) {
          for(j=start; j<c; j++) {
              printf("%d\t", order[j]);
          }
        }
      }

      return 0;
    }
  }
  return 0;
}


main() {

  int  i ,j;
  printf("Enter the no of nodes\n");
  scanf("%d", &n);

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

  printf("Entered graph is : \n");
  for (i=0; i<n; i++) {
    printf("Row=%d\t\t", i);
    for(j=0; j<n; j++) {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }

  printf("Enter the head node\n");
  int head;
  scanf("%d", &head);
  printf("Head = %d\n", head);

  for(i=0; i<n; i++) {
    visited[i] = -1;
    order[i] = -1;
    parent[i] = -1;
  }
  //parent[head] = -1;
  cycle(m, head);

  if(!cyc) {
    printf("No cycle\n");
  }


}
