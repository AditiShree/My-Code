#include <stdio.h>

int visited[20], order[20];
int c = 0, n;

void dfs(int **m, int head) {
  int i;
  visited[head] = 1;
  order[c] = head;
  c++;
  for(i=0; i<n; i++) {
    if ((m[head][i] == 1) && (visited[i]!=1)) {
      dfs(m, i);
    }
  }

}

main() {
  int i, j, head;
  printf("Enter the no of nodes in graph\n");
  scanf("%d", &n);

  int *m[n];
  for(i=0; i<n; i++) {
    m[i] = (int *) malloc(n*sizeof(int));
  }

  printf("Enter %dx%d elem of graph\n", n, n);
  for(i=0; i<n; i++) {
    printf("Start Row - %d\n", i);
    for(j=0; j<n; j++) {
      printf("%d elem of %d row\n", j, i);
      scanf("%d", &m[i][j]);
    }
  }

  printf("Entered %dx%d elem are \n", n, n);
  for(i=0; i<n; i++) {
    printf("Row %d - \t\t", i);
    for(j=0; j<n; j++) {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }

  printf("Enter the vertex node\n");
  scanf("%d", &head);
  if(head>n) {
    printf("Head out of range\n");
  }



  for(i=0; i<n; i++) {
    visited[i] = -1;
    order[i] = -1;
  }

  dfs(m, head);
  printf("Here\n" );
  int brk = 0;
  printf("Visited or not\n" );
  for(i=0; i<n; i++) {
    printf("%d\n", visited[i]);
    if(visited[i]!=1){
      brk = 1;
      printf("Not connected graph\n");
      break;
    }
  }

  if(!brk) {
    printf("Visited in order-\n");
    for(i=0; i<n; i++) {
      printf("%d\t", order[i]);
    }
  }

}
